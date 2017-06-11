
// Homework_v1Dlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CHomework_v1Dlg 对话框



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


// CHomework_v1Dlg 消息处理程序

BOOL CHomework_v1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CHomework_v1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CHomework_v1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHomework_v1Dlg::OnEnChangeMfceditbrowse2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);

}


void CHomework_v1Dlg::OnBnClickedButton1()
{

	m_result.Empty();//输出结果清空

	MD5 md5;

	vector<string> no_repeat_md5_value;
	no_repeat_md5_value.empty();//初始化存储不重复MD5值的vector
	vector<string> all_md5_value;
	all_md5_value.empty(); //初始化存储所有MD5值的vector

	string filePath;

	USES_CONVERSION;
	filePath = W2CA((LPCWSTR)m_Path);//将CString转化为string

	if (filePath.length() == 0)
	{
		MessageBox(TEXT("请选择路径！"), TEXT("ERROR!"), MB_OK | MB_ICONWARNING);
		return;
	}

	vector<string> files;

	//getFilesall(filePath, files);//获取所有文件绝对路径

	vector<CString> cs_files;//存储所有文件绝对路径

	FileFinder(m_Path, cs_files);

	vector<CString>::iterator r;

	for (r = cs_files.begin(); r != cs_files.end(); r++)
	{
		files.push_back(W2CA(LPCWSTR(*r)));
	}

		int size = files.size();

	m_result.Format(_T("共有%d个文件\r\n"), size);

	CEdit *p = (CEdit*)GetDlgItem(IDC_EDIT2);
	for (int i = 0; i < size; i++)
	{
		//输出中间结果
		m_status.Format(_T("完成度%d/%d"), i + 1, size);


		//清空
		md5.reset();

		//以二进制形式打开文件流
		ifstream temp(files[i], ios::binary);

		//更新MD5
		md5.update(temp);

		//搜寻该文件的MD5值是否在之前出现过
		vector<string>::iterator result = find(no_repeat_md5_value.begin(), no_repeat_md5_value.end(), md5.toString());


		all_md5_value.push_back(md5.toString());
		if (result == no_repeat_md5_value.end())//搜寻到vector末端，说明还未出现
		{
			no_repeat_md5_value.push_back(md5.toString());//添加进去
		}
		else
		{

			vector<string>::iterator same_md5 = find(all_md5_value.begin(), all_md5_value.end(), md5.toString());
			//在所有文件的MD5中找与之相同的那一个,用于确定下标(找到相同的文件的文件名)


			//生成对比结果，等待输出			
			CString temp3;
			temp3 = files[i].c_str();
			CString temp4("和文件");
			CString temp1("相同\r\n");
			CString temp2;
			temp2 = files[same_md5 - all_md5_value.begin()].c_str();

			m_result = m_result + temp3 + temp4 + temp2 + temp1;


			//以下是数据的更新显示
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

	CString end__("查找结束！");

	m_result = m_result + end__;

	UpdateData(FALSE);

	CEdit*pedit = (CEdit*)GetDlgItem(IDC_EDIT2);

	int   nline = pedit->GetLineCount();
	pedit->LineScroll(nline - 1);
	// TODO: 在此添加控件通知处理程序代码
}


void CHomework_v1Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


void CHomework_v1Dlg::OnBnClickedButton4()
{
	MessageBox(TEXT("文件查重 v1.0\n制作者:陈亦捷"), TEXT("关于"), MB_OK);
	// TODO: 在此添加控件通知处理程序代码
}


void CHomework_v1Dlg::OnNMClickSyslink1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
