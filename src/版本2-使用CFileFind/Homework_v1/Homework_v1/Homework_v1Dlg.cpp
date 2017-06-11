
// Homework_v1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Homework_v1.h"
#include "Homework_v1Dlg.h"
#include "afxdialogex.h"

#include "md5.h"
#include <atlconv.h>
#include "FileFinder.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CHomework_v1Dlg �Ի���



CHomework_v1Dlg::CHomework_v1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_HOMEWORK_V1_DIALOG, pParent)
	, m_Path(_T(""))
	, m_result(_T(""))
	, m_status(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CHomework_v1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MFCEDITBROWSE2, m_Path);
	DDX_Control(pDX, IDC_MFCEDITBROWSE2, m_EditBrowse);

	DDX_Text(pDX, IDC_EDIT2, m_result);
	DDX_Text(pDX, IDC_EDIT1, m_status);
}

BEGIN_MESSAGE_MAP(CHomework_v1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_MFCEDITBROWSE2, &CHomework_v1Dlg::OnEnChangeMfceditbrowse2)
	ON_BN_CLICKED(IDC_BUTTON1, &CHomework_v1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CHomework_v1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CHomework_v1Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CHomework_v1Dlg ��Ϣ�������

BOOL CHomework_v1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CHomework_v1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CHomework_v1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CHomework_v1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHomework_v1Dlg::OnEnChangeMfceditbrowse2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

}


void CHomework_v1Dlg::OnBnClickedButton1()
{

	m_result.Empty();//���������

	MD5 md5;

	vector<string> no_repeat_md5_value;
	no_repeat_md5_value.empty();//��ʼ���洢���ظ�MD5ֵ��vector
	vector<string> all_md5_value;
	all_md5_value.empty(); //��ʼ���洢����MD5ֵ��vector

	string filePath;

	USES_CONVERSION;
	filePath = W2CA((LPCWSTR)m_Path);//��CStringת��Ϊstring

	if (filePath.length() == 0)
	{
		MessageBox(TEXT("��ѡ��·����"), TEXT("ERROR!"), MB_OK | MB_ICONWARNING);
		return;
	}

	vector<string> files;

	//getFilesall(filePath, files);//��ȡ�����ļ�����·��

	vector<CString> cs_files;//�洢�����ļ�����·��

	FileFinder(m_Path, cs_files);

	vector<CString>::iterator r;

	for (r = cs_files.begin(); r != cs_files.end(); r++)
	{
		files.push_back(W2CA(LPCWSTR(*r)));
	}

		int size = files.size();

	m_result.Format(_T("����%d���ļ�\r\n"), size);

	CEdit *p = (CEdit*)GetDlgItem(IDC_EDIT2);
	for (int i = 0; i < size; i++)
	{
		//����м���
		m_status.Format(_T("��ɶ�%d/%d"), i + 1, size);


		//���
		md5.reset();

		//�Զ�������ʽ���ļ���
		ifstream temp(files[i], ios::binary);

		//����MD5
		md5.update(temp);

		//��Ѱ���ļ���MD5ֵ�Ƿ���֮ǰ���ֹ�
		vector<string>::iterator result = find(no_repeat_md5_value.begin(), no_repeat_md5_value.end(), md5.toString());


		all_md5_value.push_back(md5.toString());
		if (result == no_repeat_md5_value.end())//��Ѱ��vectorĩ�ˣ�˵����δ����
		{
			no_repeat_md5_value.push_back(md5.toString());//��ӽ�ȥ
		}
		else
		{

			vector<string>::iterator same_md5 = find(all_md5_value.begin(), all_md5_value.end(), md5.toString());
			//�������ļ���MD5������֮��ͬ����һ��,����ȷ���±�(�ҵ���ͬ���ļ����ļ���)


			//���ɶԱȽ�����ȴ����			
			CString temp3;
			temp3 = files[i].c_str();
			CString temp4("���ļ�");
			CString temp1("��ͬ\r\n");
			CString temp2;
			temp2 = files[same_md5 - all_md5_value.begin()].c_str();

			m_result = m_result + temp3 + temp4 + temp2 + temp1;


			//���������ݵĸ�����ʾ
			UpdateData(FALSE);
			MSG   msg;

			while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			CEdit*pedit = (CEdit*)GetDlgItem(IDC_EDIT2);
			int   nline = pedit->GetLineCount() - 1;

			pedit->LineScroll(nline);
		}



	}

	CString end__("���ҽ�����");

	m_result = m_result + end__;

	UpdateData(FALSE);

	CEdit*pedit = (CEdit*)GetDlgItem(IDC_EDIT2);

	int   nline = pedit->GetLineCount();
	pedit->LineScroll(nline - 1);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CHomework_v1Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}


void CHomework_v1Dlg::OnBnClickedButton4()
{
	MessageBox(TEXT("�ļ����� v1.0\n������:�����"), TEXT("����"), MB_OK);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CHomework_v1Dlg::OnNMClickSyslink1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
