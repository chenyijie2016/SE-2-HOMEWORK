#include "stdafx.h"
#include "FileFinder.h"
using namespace std;

void FileFinder(CString strDir, vector<CString> &fileList)
{
	CFileFind ff;
	CString szDir = strDir;
	if (szDir.Right(1) != "\\")
		szDir += "\\";

	szDir += "*.*";

	BOOL res = ff.FindFile(szDir);

	while (res)
	{
		res = ff.FindNextFile();
		
		
		//找到了，加入列表框中
		if (!ff.IsDirectory())
		{
			fileList.push_back(ff.GetFilePath());
		}
		
		if (ff.IsDirectory() && !ff.IsDots())
		{
			//如果是一个子目录，用递归继续往深一层找
			FileFinder(ff.GetFilePath(), fileList);
		}
	}
	ff.Close();//关闭
}
