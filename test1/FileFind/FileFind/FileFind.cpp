// FileFind.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "FileFind.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // 初始化 MFC 并在失败时显示错误
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: 更改错误代码以符合您的需要
            wprintf(L"错误: MFC 初始化失败\n");
            nRetCode = 1;
        }
        else
        {
			char m_path[50];
			cin >> m_path;
			vector<CString> fileList;
			CString PATH(m_path);
			FindFile_MY(PATH, fileList);

			vector<CString>::iterator r;

			for (r = fileList.begin(); r != fileList.end();r++)
			{
				//wcout << LPCTSTR(*r) << endl;
			}


			cout << endl;
			cout << "共有文件数目: "<<fileList.size();
			system("pause");
			

            // TODO: 在此处为应用程序的行为编写代码。
        }
    }
    else
    {
        // TODO: 更改错误代码以符合您的需要
        wprintf(L"错误: GetModuleHandle 失败\n");
        nRetCode = 1;
    }

    return nRetCode;
}

//************************************
// Method:    FindFile
// FullName:  FindFile
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: CString strDir
// Parameter: vector<CString> & fileList
//************************************
void FindFile_MY(CString strDir, vector<CString> & fileList)
{

	CFileFind ff;
	CString szDir = strDir;
	wcout <<"目录: " << LPCTSTR(szDir) << endl;
	if (szDir.Right(1) != "\\")
		szDir += "\\";

	szDir += "*.*";

	BOOL res = ff.FindFile(szDir);
	while (res)
	{
		res = ff.FindNextFile();


		//找到了，加入文件列表中
		if (!ff.IsDirectory() && !ff.IsDots())
		{
			wcout <<"文件: "<< LPCTSTR(ff.GetFilePath()) << endl;
			fileList.push_back(ff.GetFilePath());
		}


		if (ff.IsDirectory() && !ff.IsDots())
		{
			//如果是一个子目录，用递归继续往深一层找
			FindFile_MY(ff.GetFilePath(), fileList);
		}
	}
	ff.Close();//关闭

}
