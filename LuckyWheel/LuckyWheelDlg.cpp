
// LuckyWheelDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "LuckyWheel.h"
#include "LuckyWheelDlg.h"
#include "afxdialogex.h"
#include "resource.h"

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


// CLuckyWheelDlg 对话框



CLuckyWheelDlg::CLuckyWheelDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LUCKYWHEEL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CLuckyWheelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
}

BEGIN_MESSAGE_MAP(CLuckyWheelDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CLuckyWheelDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON1, &CLuckyWheelDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CLuckyWheelDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CLuckyWheelDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDOK, &CLuckyWheelDlg::OnBnClickedOk)
	ON_NOTIFY(LVN_ITEMACTIVATE, IDC_LIST1, &CLuckyWheelDlg::OnItemactivateList1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLuckyWheelDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CLuckyWheelDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CLuckyWheelDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CLuckyWheelDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CLuckyWheelDlg 消息处理程序

BOOL CLuckyWheelDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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
	m_ListCtrl.SetExtendedStyle(m_ListCtrl.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_ListCtrl.InsertColumn(0, TEXT("显示名"), LVCFMT_LEFT, 100);
	m_ListCtrl.InsertColumn(1, TEXT("概率"), LVCFMT_LEFT, 100);
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLuckyWheelDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLuckyWheelDlg::OnPaint()
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
HCURSOR CLuckyWheelDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int FindItem(CListCtrl& List,CString text)
{
	for (int i = 0; i < List.GetItemCount(); i++)
	{
		if (text == List.GetItemText(i, 0))return i;
	}
	return -1;
}

void CLuckyWheelDlg::OnBnClickedButton1()
{
	CString text; UINT probability = 0;
	GetDlgItemText(IDC_EDIT1, text);
	probability = GetDlgItemInt(IDC_EDIT2);
	if (FindItem(m_ListCtrl, text) == -1)
	{
		//Map.insert(pair<CString, UINT>(text, probability));
		Map[text] = probability;
		int index = m_ListCtrl.GetItemCount() + 1;
		m_ListCtrl.InsertItem(index, text);
		CString tmp;
		tmp.Format(_T("%d"), probability);
		m_ListCtrl.SetItemText(index - 1, 1, tmp);
	}
	else
	{
		Map[text] += probability;
		int index = FindItem(m_ListCtrl, text);
		CString tmp;
		tmp.Format(_T("%d"), probability + _ttoi(m_ListCtrl.GetItemText(index,1)));
		m_ListCtrl.SetItemText(index, 1, tmp);
	}
	SetDlgItemText(IDC_EDIT1, L"");
	SetDlgItemText(IDC_EDIT2, L"");
}


void CLuckyWheelDlg::OnBnClickedButton4()
{
	POSITION pos = m_ListCtrl.GetFirstSelectedItemPosition();
	int index = m_ListCtrl.GetNextSelectedItem(pos);

	CString text; UINT probability = 0;
	GetDlgItemText(IDC_EDIT4, text);
	probability = GetDlgItemInt(IDC_EDIT5);
	Map[text] = probability;
	CString tmp;
	tmp.Format(_T("%d"), probability);
	m_ListCtrl.SetItemText(index, 0, text);
	m_ListCtrl.SetItemText(index, 1, tmp);
}


void CLuckyWheelDlg::OnBnClickedButton3()
{
	POSITION pos = m_ListCtrl.GetFirstSelectedItemPosition();
	int index = m_ListCtrl.GetNextSelectedItem(pos);
	m_ListCtrl.DeleteItem(index);
	Map.erase(m_ListCtrl.GetItemText(index, 0));
}


void CLuckyWheelDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	begin:
	int sum = 0;
	for (auto it : Map)
	{
		sum += it.second;
	}
	CString texts[1024];
	int index = 0;
	for (auto it : Map)
	{
		for (int j = 0; j < it.second; j++,index++)
		{
			texts[index+j] = it.first;
		}
	}
	srand(__rdtsc());
	int res = rand() % sum;
	if (texts[res] == L"")goto begin;
	MessageBox(CString(L"本次结果：") + texts[res], L"幸运大转盘", MB_ICONINFORMATION);
}


void CLuckyWheelDlg::OnItemactivateList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMIA = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	float sum = 0;
	for (auto it : Map)
	{
		sum += it.second;
	}
	POSITION pos = m_ListCtrl.GetFirstSelectedItemPosition();
	int index = m_ListCtrl.GetNextSelectedItem(pos);

	SetDlgItemText(IDC_EDIT4,m_ListCtrl.GetItemText(index, 0));
	SetDlgItemInt(IDC_EDIT5, _ttoi(m_ListCtrl.GetItemText(index, 1)));

	float probability = _ttoi(m_ListCtrl.GetItemText(index, 1));
	float percentage = probability / sum * 100.0;
	CString tmp;
	tmp.Format(_T("%d/%d(%.2f%%)"), int(probability), int(sum), percentage);
	SetDlgItemText(IDC_EDIT3, tmp);
}

void CLuckyWheelDlg::EnumKeyAndPush(HKEY rootKey, const TCHAR* path)
{
	HKEY hKey;
	Map.clear(); m_ListCtrl.DeleteAllItems();
	if (RegOpenKeyEx(rootKey, path, 0, KEY_READ, &hKey) != ERROR_SUCCESS)
	{
		RegCloseKey(hKey);
		return;
	}

	//TCHAR    achKey[MAX_KEY_LENGTH];   // buffer for subkey name  
	//DWORD    cbName;                   // size of name string   
	TCHAR    achClass[MAX_PATH] = TEXT("");  // buffer for class name   
	DWORD    cchClassName = MAX_PATH;  // size of class string   
	DWORD    cSubKeys = 0;               // number of subkeys   
	DWORD    cbMaxSubKey;              // longest subkey size   
	DWORD    cchMaxClass;              // longest class string   
	DWORD    cValues;              // number of values for key   
	DWORD    cchMaxValue;          // longest value name   
	DWORD    cbMaxValueData;       // longest value data   
	DWORD    cbSecurityDescriptor; // size of security descriptor   
	FILETIME ftLastWriteTime;      // last write time   

	DWORD i, retCode;

	TCHAR  achValue[16383];
	DWORD cchValue = 16383;

	// Get the class name and the value count.   
	retCode = RegQueryInfoKey(
		hKey,                    // key handle   
		achClass,                // buffer for class name   
		&cchClassName,           // size of class string   
		NULL,                    // reserved   
		&cSubKeys,               // number of subkeys   
		&cbMaxSubKey,            // longest subkey size   
		&cchMaxClass,            // longest class string   
		&cValues,                // number of values for this key   
		&cchMaxValue,            // longest value name   
		&cbMaxValueData,         // longest value data   
		&cbSecurityDescriptor,   // security descriptor   
		&ftLastWriteTime);       // last write time   

	DWORD dwType = REG_BINARY | REG_DWORD | REG_EXPAND_SZ | REG_MULTI_SZ | REG_NONE | REG_SZ;

	// Enumerate the key values.   
	if (cValues)
	{
		for (i = 0, retCode = ERROR_SUCCESS; i < cValues; i++)
		{
			cchValue = 16383;
			achValue[0] = '\0';
			//unsigned char vari[70];
			retCode = RegEnumValue(hKey, i, achValue, &cchValue, NULL, NULL, NULL, NULL);
			if (retCode == ERROR_SUCCESS)
			{
				DWORD dwValue = 0;
				DWORD dwNameLen = sizeof(DWORD);
				DWORD rQ = RegQueryValueEx(hKey, achValue, 0, &dwType, (LPBYTE)&dwValue, &dwNameLen);
				if (rQ == ERROR_SUCCESS)
				{
					
					//_tprintf(TEXT("(%d) %s %d\n"), i + 1, achValue, dwValue);
					DWORD probability = dwValue; CString name = achValue;
					
					Map.insert(pair<CString, UINT>(name, probability));
					int index = m_ListCtrl.GetItemCount() + 1;
					m_ListCtrl.InsertItem(index, name);
					CString tmp;
					tmp.Format(_T("%d"), probability);
					m_ListCtrl.SetItemText(index - 1, 1, tmp);
					
					SetDlgItemText(IDC_EDIT1, L"");
					SetDlgItemText(IDC_EDIT2, L"");
				}

			}
		}
	}
	//release.
	RegCloseKey(hKey);
}

void CLuckyWheelDlg::OnBnClickedButton2()
{
	//导入
	if(MessageBox(TEXT("此操作会加载本地系统中的备份，将会覆盖当前数据。\r\n注意！此操作不可逆！"), TEXT("幸运大转盘-导入"), MB_OKCANCEL | MB_ICONWARNING)==IDOK)
		EnumKeyAndPush(HKEY_CURRENT_USER, TEXT("Software\\Duany\\LuckyWheel"));
}


void CLuckyWheelDlg::OnBnClickedButton5()
{
	//导出
	if (MessageBox(TEXT("此操作会修改本地系统中的备份，将会覆盖之前的备份数据。\r\n注意！此操作不可逆！"), TEXT("幸运大转盘-导出"), MB_OKCANCEL | MB_ICONWARNING) != IDOK)return;
	DeleteBackup();
	HKEY hKey = 0;
	DWORD dwErrorCode = RegCreateKeyEx(HKEY_CURRENT_USER, L"Software\\Duany\\LuckyWheel", 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);
	if (dwErrorCode == 0)
	{
		for (auto it : Map)
		{
			RegSetValueExW(hKey, it.first, 0, REG_DWORD, PBYTE(&(it.second)), sizeof(it.second));
		}
		RegCloseKey(hKey);
	}
	else
	{
		CString tmp;
		tmp.Format(_T("%d"), dwErrorCode);
		AfxMessageBox(L"操作注册表时失败！" + tmp, 0, MB_ICONERROR);
	}
}


long CLuckyWheelDlg::DeleteBackup()
{
	return RegDeleteKey(HKEY_CURRENT_USER, TEXT("Software\\Duany\\LuckyWheel"));;
}


void CLuckyWheelDlg::OnBnClickedButton6()
{
	DeleteBackup();
}


void CLuckyWheelDlg::OnBnClickedButton7()
{
	m_ListCtrl.DeleteAllItems();
	Map.clear();
}
