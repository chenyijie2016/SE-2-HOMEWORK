软件工程(2)大作业说明文档
====

参考选题8.2(文件查重)
----

> 姓名:陈亦捷

> 学号:2016013233

> 电话号码:13627906396

> Email:chenyijiethu@gmail.com

------

## 目录

- [文件遍历及路径处理](#文件遍历及路径处理)
	- [CFileFind类的基本介绍](#CFileFind类的基本介绍)
	- [使用实例](#具体使用(遍历文件夹及子目录))
- [散列函数简介](#散列函数简介)  
    - [定义](#散列函数定义)
    - [性质](#基本性质)
    - [应用](#应用(密码散列函数))
    - [在本项目中的应用](#在本项目中的应用)
    - [MD5算法过程](#MD5算法过程)
- [MFC文件选取控件简介](#MFC文件选取控件简介)
- [参考文献](#参考文献)
## 文件遍历及路径处理

> 由于我在大作业讨论区中发现已经有人完成了文件路径处理的一部分工作。其使用了``io.h``这一处理文件的库。我之前版本也使用了相同的文件路径处理方法，为避免重复，我将使用MFC中的``CFileFind``类进行介绍。

### CFileFind类的基本介绍

先来看一下[MSDN](https://msdn.microsoft.com/en-us/library/f33e1618.aspx)上关于``CFileFind``类的文档

> 以下均省略类名``CFileFind``

* 公共构造函数

|     名称     |             备注              | 
| :----------: | :--------------------------: |
| CFileFind | Constructs a ``CFileFind`` object. |

* 公共方法

|     名称     |             备注              | 
| :----------: | :--------------------------: |
| Close | Closes the search request. |
| FindFile | Searches a directory for a specified file name. |
| FindNextFile | Continues a file search from a previous call to FindFile. |
| GetCreationTime | Gets the time the file was created. |
| GetFileName | Gets the name, including the extension, of the found file |
| GetFilePath | Gets the whole path of the found file. |
| GetFileTitle | Gets the title of the found file. The title does not include the extension. |
| GetFileURL | Gets the URL, including the file path, of the found file. |
| GetLastAccessTime | Gets the time that the file was last accessed. |
| GetLastWriteTime | Gets the time the file was last changed and saved. |
| GetLength | Gets the length of the found file, in bytes. |
| GetRoot | Gets the root directory of the found file. |
| IsArchived | Determines if the found file is archived. |
| IsCompressed | Determines if the found file is compressed. |
| IsDirectory |　Determines if the found file is a directory.　|
| IsDots | Determines if the name of the found file has the name "." or "..", indicating that is actually a directory.|
| IsHidden | Determines if the found file is hidden.| 
| IsNormal | Determines if the found file is normal (in other words, has no other attributes).|
| IsReadOnly | 	Determines if the found file is read-only. |
| IsSystem | Determines if the found file is a system file. |
| IsTemporary | Determines if the found file is temporary.|
| MatchesMask | Indicates the desired file attributes of the file to be found.| 

* 受保护方法

|     名称     |             备注              | 
| :----------: | :--------------------------: |
| CloseContext | Closes the file specified by the current search handle.|

* 受保护的数据成员

|     名称     |             备注              | 
| :----------: | :--------------------------: |
| m_pTM | Pointer to a ``CAtlTransactionManager`` object. |

受于内容相关性及研究深度所限，我只打算对我们需要在文件遍历中使用的方法进行介绍，包括以下内容

``FindFile``、``GetFileName``、``FindNextFile``、``GetFilePath``、``IsDots`` 、``IsDirectory``

### 函数原型介绍

#### ``FindFile``介绍
```c++
    virtual BOOL FindFile(
    LPCTSTR pstrName = NULL,  
    DWORD dwUnused = 0);
``` 
参数说明:

* pstrName: A pointer to a string containing the name of the file to find. If you pass NULL for pstrName, FindFile does a wildcard (*.*) search.

* dwUnused: Reserved to make FindFile polymorphic with derived classes. Must be 0.

#### ``GetFileName``、``GetFilePath``、``GetFileTitle`` 介绍
```c++
    virtual CString GetFileName() const;  
    
    virtual CString GetFilePath() const; 
    
    virtual CString GetFileTitle() const;  
```
区别与联系:  

> 以``c:\myhtml\myfile.txt``文件为例

* ``GetFileName`` 返回完整文件名:``myfile.txt``
* ``GetFilePath`` 返回文件名及完整路径:``c:\myhtml\myfile.txt``
* ``GetFileTitle`` 返回文件名(不带扩展名):``myfile``


#### ``IsDirectory``、``IsDots``介绍

```c++
    BOOL IsDirectory() const;
    virtual BOOL IsDots() const;
```

说明:
* ``IsDirectory``用于判断该当前对象是不是一个文件夹
* ``IsDots`` 用于判断该当前对象是不是 "." 或者 ".."


### 具体使用(遍历文件夹及子目录)

```c++
//需要在MFC环境中运用

#include <vector>
#include "stdafx.h"

//************************************
// FullName:  FindFile
// Returns:   void
// Parameter: CString strDir: 需要遍历的文件夹
// Parameter: vector<CString> & fileList :存储该文件夹及子文件夹中所有文件的绝对路径
//************************************
void FindFile(CString strDir, vector<CString> & fileList)
{

	CFileFind ff;
	CString szDir = strDir;
	
	wcout <<"目录: " << LPCTSTR(szDir) << endl;
	
	//如果目录最后不是"\\"就添加上(windows系统)
	if (szDir.Right(1) != "\\")
		szDir += "\\";
	//加上"*.*"表示查找所有文件、文件夹
	szDir += "*.*";
    
    
	BOOL res = ff.FindFile(szDir);
	wcout << res;
	
	while (res)//如果该目录下还存在文件就继续遍历
	{
                //继续寻找下一个文件
		res = ff.FindNextFile();
		
		//如果不是文件夹
		if (!ff.IsDirectory())
		{
			wcout <<"文件: "<< LPCTSTR(ff.GetFileName()) << endl;
			//找到了，加入文件列表中
			fileList.push_back(ff.GetFilePath());
		}

		if (ff.IsDirectory() && !ff.IsDots())
		{
			//如果是一个子目录，用递归继续往深一层找
			FindFile(ff.GetFilePath(), fileList);
		}
	}
	ff.Close();//关闭
}
    
```


## 散列函数简介  

### 散列函数定义

散列函数（或散列算法，又称哈希函数，英语：Hash Function）是一种从任何一种数据中创建小的数字“指纹”的方法。  
散列函数把消息或数据压缩成摘要，使得数据量变小，将数据的格式固定下来。该函数将数据打乱混合，重新创建一个叫做``散列值``的指纹。``散列值``通常用一个短的随机字母和数字组成的字符串来代表。

### 基本性质

所有散列函数都有如下一个基本特性：如果两个``散列值``是不相同的（根据同一函数），那么这两个``散列值``的原始输入也是不相同的。这个特性是散列函数具有确定性的结果，具有这种性质的散列函数称为单向散列函数。  
但另一方面，散列函数的输入和输出不是唯一对应关系的，如果两个``散列值``相同，两个输入值很可能是相同的，但也可能不同，这种情况称为“哈希碰撞”，这通常是两个不同长度的输入值，刻意计算出相同的输出值。输入一些数据计算出``散列值``，然后部分改变输入值，一个具有强混淆特性的散列函数会产生一个完全不同的``散列值``

> 以上内容来自[维基百科-散列函数](https://zh.wikipedia.org/wiki/%E6%95%A3%E5%88%97%E5%87%BD%E6%95%B8)

### 应用(密码散列函数)

* 信息加密
* 文件校验
* 数字签名
* ......

### 在本项目中的应用

> 在本项目中，我使用了密码散列函数中的``MD5``算法  

> MD5消息摘要算法（英语：MD5 Message-Digest Algorithm），一种被广泛使用的密码散列函数，可以产生出一个128位（16字节）的散列值（hash value），用于确保信息传输完整一致。MD5由罗纳德·李维斯特设计，于1992年公开，用以取代MD4算法。这套算法的程序在 RFC 1321 中被加以规范。

#### MD5算法过程

> 由于MD5算法过程较为复杂且基于较多的常量，在此只为简单介绍

1. 填充

在MD5算法中，首先需要对信息进行填充，使其位长对512求余的结果等于448，并且填充必须进行，即使其位长对512求余的结果等于448。因此，信息的位长（Bits Length）将被扩展至N*512+448，N为一个非负整数，N可以是零。
填充的方法如下：
1) 在信息的后面填充一个1和无数个0，直到满足上面的条件时才停止用0对信息的填充。
2) 在这个结果后面附加一个以64位二进制表示的填充前信息长度（单位为Bit），如果二进制表示的填充前信息长度超过64位，则取低64位。

经过这两步的处理，信息的位长=N*512+448+64=(N+1）*512，即长度恰好是512的整数倍。这样做的原因是为满足后面处理中对信息长度的要求。

2. 初始化变量

初始的128位值为初试链接变量，这些参数用于第一轮的运算，以大端字节序来表示，他们分别为： A=0x01234567，B=0x89ABCDEF，C=0xFEDCBA98，D=0x76543210。

3. 处理分组数据
每一分组的算法流程如下:

第一分组需要将上面四个链接变量复制到另外四个变量中：A到a，B到b，C到c，D到d。从第二分组开始的变量为上一分组的运算结果，即A = a， B = b， C = c， D = d。

主循环有四轮，每轮循环都很相似。第一轮进行16次操作。每次操作对a、b、c和d中的其中三个作一次非线性函数运算，然后将所得结果加上第四个变量，文本的一个子分组和一个常数。再将所得结果向左环移一个不定的数，并加上a、b、c或d中之一。最后用该结果取代a、b、c或d中之一。

非线性函数:

![图片](https://wikimedia.org/api/rest_v1/media/math/render/svg/b105d494a376d11f2eefd810082e1944cd8e2dc4)

> 图片来源:[维基百科-MD5](https://en.wikipedia.org/wiki/MD5)

4. 输出

最后的输出是a、b、c和d的级联。

> 以上文字内容来自[百度百科-MD5](http://baike.baidu.com/item/MD5)(有删改)

## MFC文件选取控件简介

> 由于我设计的是基于MFC的文件查重软件，而MFC中已经具有可以选择文件路径或者文件的控件，使用它可以极大的简化用户输入文件夹路径的过程。
> 因此，我将对该控件进行一些介绍




## 参考文献