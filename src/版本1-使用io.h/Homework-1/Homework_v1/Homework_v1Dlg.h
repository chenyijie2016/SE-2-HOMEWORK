
// Homework_v1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxeditbrowsectrl.h"


// CHomework_v1Dlg �Ի���
class CHomework_v1Dlg : public CDialogEx
{
// ����
public:
	CHomework_v1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HOMEWORK_V1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
