
// LuckyWheelDlg.h: 头文件
//

#pragma once
#include <map>
#include <vector>
#include <random>
using namespace std;

// CLuckyWheelDlg 对话框
class CLuckyWheelDlg : public CDialogEx
{
// 构造
public:
	CLuckyWheelDlg(CWnd* pParent = nullptr);	// 标准构造函数
	map<CString,UINT> Map;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LUCKYWHEEL_DIALOG };
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
	
	CListCtrl m_ListCtrl;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedOk();
	afx_msg void OnItemactivateList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton5();
	void EnumKeyAndPush(HKEY rootKey, const TCHAR* path);
	long DeleteBackup();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
};
