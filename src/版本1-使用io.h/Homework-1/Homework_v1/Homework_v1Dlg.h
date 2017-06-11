
// Homework_v1Dlg.h : 头文件
//

#pragma once
#include "afxeditbrowsectrl.h"


// CHomework_v1Dlg 对话框
class CHomework_v1Dlg : public CDialogEx
{
// 构造
public:
	CHomework_v1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HOMEWORK_V1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_Path;
	afx_msg void OnEnChangeMfceditbrowse2();
	CMFCEditBrowseCtrl m_EditBrowse;
	afx_msg void OnBnClickedButton1();
	CString m_result;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	CString m_status;
	afx_msg void OnNMClickSyslink1(NMHDR *pNMHDR, LRESULT *pResult);
};
