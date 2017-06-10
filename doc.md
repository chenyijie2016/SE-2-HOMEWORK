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
- [哈希散列算法简介](#哈希散列算法简介)
- [MFC文件选取控件简介](#哈希散列算法简介)

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


### ``IsDirectory``、``IsDots``介绍

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

