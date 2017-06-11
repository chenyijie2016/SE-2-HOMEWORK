// FileFind.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "FileFind.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // ��ʼ�� MFC ����ʧ��ʱ��ʾ����
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: ���Ĵ�������Է���������Ҫ
            wprintf(L"����: MFC ��ʼ��ʧ��\n");
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
			cout << "�����ļ���Ŀ: "<<fileList.size();
			system("pause");
			

            // TODO: �ڴ˴�ΪӦ�ó������Ϊ��д���롣
        }
    }
    else
    {
        // TODO: ���Ĵ�������Է���������Ҫ
        wprintf(L"����: GetModuleHandle ʧ��\n");
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
	wcout <<"Ŀ¼: " << LPCTSTR(szDir) << endl;
	if (szDir.Right(1) != "\\")
		szDir += "\\";

	szDir += "*.*";

	BOOL res = ff.FindFile(szDir);
	while (res)
	{
		res = ff.FindNextFile();


		//�ҵ��ˣ������ļ��б���
		if (!ff.IsDirectory() && !ff.IsDots())
		{
			wcout <<"�ļ�: "<< LPCTSTR(ff.GetFilePath()) << endl;
			fileList.push_back(ff.GetFilePath());
		}


		if (ff.IsDirectory() && !ff.IsDots())
		{
			//�����һ����Ŀ¼���õݹ��������һ����
			FindFile_MY(ff.GetFilePath(), fileList);
		}
	}
	ff.Close();//�ر�

}
