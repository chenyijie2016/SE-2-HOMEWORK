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
		
		
		//�ҵ��ˣ������б����
		if (!ff.IsDirectory())
		{
			fileList.push_back(ff.GetFilePath());
		}
		
		if (ff.IsDirectory() && !ff.IsDots())
		{
			//�����һ����Ŀ¼���õݹ��������һ����
			FileFinder(ff.GetFilePath(), fileList);
		}
	}
	ff.Close();//�ر�
}
