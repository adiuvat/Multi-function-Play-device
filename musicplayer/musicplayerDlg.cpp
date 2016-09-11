
// musicplayerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "musicplayer.h"
#include "musicplayerDlg.h"
#include "afxdialogex.h"
#include <atlconv.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int INSERT = 1;
int PLAY = 1;
string notelist[128] = {
	"C-1","C#-1","D-1","D#-1","E-1","F-1","F#-1","G-1",
	"G#-1","A-1","A#-1","B-1","C0","C#0","D0","D#0",
	"E0","F0","F#0","G0","G#0","A0","A#0","B0",
	"C1","C#1","D1","D#1","E1","F1","F#1","G1",
	"G#1","A1","A#1","B1","C2","C#2","D2","D#2",
	"E2","F2","F#2","G2","G#2","A2","A#2","B2",
	"C3","C#3","D3","D#3","E3","F3","F#3","G3",
	"G#3","A3","A#3","B3","C4","C#4","D4","D#4",
	"E4","F4","F#4","G4","G#4","A4","A#4","B4",
	"C5","C#5","D5","D#5","E5","F5","F#5","G5",
	"G#5","A5","A#5","B5","C6","C#6","D6","D#6",
	"E6","F6","F#6","G6","G#6","A6","A#6","B6",
	"C7","C#7","D7","D#7","E7","F7","F#7","G7",
	"G#7","A7","A#7","B5","C8","C#8","D8","D#8",
	"E8","F8","F#8","G8","G#8","A8","A#8","B8",
	"C9","C#9","D9","D#9","E9","F9","F#9","G9"
};
CString a[2] =
{
	_T("大钢琴"),
	_T("亮音大钢琴")
};
CString MidiToneType[128] =
{
	_T("大钢琴"),
	_T("亮音大钢琴") ,
	_T("电钢琴"),
	_T("酒吧钢琴"),
	_T("练习音钢琴"),
	_T("合唱加钢琴"),
	_T("拨弦古钢琴"),
	_T("击弦古钢琴") ,
	_T("钢片琴"),
	_T("钟琴"),
	_T("八音盒"),
	_T("电颤琴"),
	_T("马林巴"),
	_T("木琴"),
	_T("管钟"),
	_T("扬琴"),
	_T("击杆风琴"),
	_T("打击型风琴"),
	_T("摇滚风琴"),
	_T("管风琴"),
	_T("簧风琴"),
	_T("手风琴"),
	_T("口琴"),
	_T("探戈手风琴"),
	_T("尼龙弦吉他"),
	_T("钢弦吉他"),
	_T("爵士乐电吉他"),
	_T("清音电吉他"),
	_T("弱音电吉他"),
	_T("驱动音效吉他"),
	_T("失真音效吉他"),
	_T("吉他泛音"),
	_T("原声贝司"),
	_T("指拨电贝司"),
	_T("拨片拨电贝司"),
	_T("无品贝司"),
	_T("击弦贝司1"),
	_T("击弦贝司2"),
	_T("合成贝司1"),
	_T("合成贝司2"),
	_T("小提琴"),
	_T("中提琴"),
	_T("大提琴"),
	_T("低音提琴"),
	_T("弦乐震音"),
	_T("弦乐拨奏"),
	_T("竖琴"),
	_T("定音鼓"),
	_T("弦乐合奏1"),
	_T("弦乐合奏2"),
	_T("合成弦乐1"),
	_T("合成弦乐2"),
	_T("合唱啊音"),
	_T("人声嘟音"),
	_T("合成人声"),
	_T("乐队打击乐"),
	_T("小号"),
	_T("长号"),
	_T("大号"),
	_T("弱音小号"),
	_T("圆号"),
	_T("铜管组"),
	_T("合成铜管1"),
	_T("合成铜管2"),
	_T("高音萨克斯"),
	_T("中音萨克斯"),
	_T("次中音萨克斯"),
	_T("上低音萨克斯"),
	_T("双簧管"),
	_T("英国管"),
	_T("大管"),
	_T("单簧管"),
	_T("短笛"),
	_T("长笛"),
	_T("竖笛"),
	_T("排笛"),
	_T("吹瓶口"),
	_T("尺八"),
	_T("哨"),
	_T("洋埙"),
	_T("合成主音1方波"),
	_T("合成主音2锯齿波"),
	_T("合成主音3汽笛风琴"),
	_T("合成主音4吹管"),
	_T("合成主音5吉他"),
	_T("合成主音6人声"),
	_T("合成主音7五度"),
	_T("合成主音8低音加主音"),
	_T("合成柔音1新时代"),
	_T("合成柔音暖音"),
	_T("合成柔音3复合成"),
	_T("合成柔音4合唱"),
	_T("合成柔音5弓弦"),
	_T("合成柔音6金属"),
	_T("合成柔音7光环"),
	_T("合成柔音8扫弦"),
	_T("合成特效1雨"),
	_T("合成特效2音轨"),
	_T("合成特效3水晶"),
	_T("合成特效4大气"),
	_T("合成特效5亮音"),
	_T("合成特效6小妖"),
	_T("合成特效7回声"),
	_T("合成特效8科幻"),
	_T("锡塔尔"),
	_T("班卓"),
	_T("三味线"),
	_T("筝"),
	_T("卡林巴"),
	_T("风笛"),
	_T("古提琴"),
	_T("唢呐"),
	_T("铃铛"),
	_T("拉丁打铃"),
	_T("钢鼓"),
	_T("木块"),
	_T("太鼓"),
	_T("嗵鼓"),
	_T("合成鼓"),
	_T("镲波形反转"),
	_T("磨弦声"),
	_T("呼吸声"),
	_T("海浪声"),
	_T("鸟鸣声"),
	_T("电话铃声"),
	_T("直升机声"),
	_T("鼓掌声"),
	_T("枪声")
};
typedef union _midi {
	DWORD dwData;
	BYTE bData[4];
} MIDI;

struct NODE
{
	CString note;
	double time;
	struct NODE* next, *pre;
};
int index = 0;//用于演奏时记录演奏到了第几个音符
NODE * head = NULL, *cur = NULL, *tail = NULL, *p = NULL;
int pos1, pos2, pos3;
void createlist()
{
	NODE * tmp1 = NULL;
	NODE * tmp2 = NULL;
	tmp1 = new NODE;
	tmp2 = new NODE;
	tmp1->next = tmp2;
	tmp1->pre = NULL;
	tmp2->next = NULL;
	tmp2->pre = tmp1;
	head = tmp1;
	tail = tmp2;
	p = cur = head;
	pos1 = 0;
	pos2 = 0;
	pos3 = 0;
}

void insertnode(CString str)
{
	if (head->next == tail)
		cur = head;
	NODE* tmp = new NODE;
	tmp->note = str;
	tmp->next = cur->next;
	tmp->pre = cur;
	cur->next->pre = tmp;
	cur->next = tmp;
	cur = tmp;

}

NODE* deletenode(NODE * pt)
{
	if (pt == head)
	{
		cur = head;
		return head;
	}
	NODE*tmp = pt;
	pt->pre->next = pt->next;
	pt->next->pre = pt->pre;
	pt = pt->pre;
	delete tmp;
	return pt;
}

void deletelist()
{
	if (head == NULL)
		return;
	for (NODE* pt = head->next; pt != tail; pt = pt->next)
	{
		deletenode(pt);
	}
	delete head;
	delete tail;
	head = NULL;
	tail = NULL;
	pos1 = pos2 = 0;
}



unsigned long result;
HMIDIOUT handle;
MIDI midi;

DWORD pre[10];

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
public:
	//	virtual BOOL PreTranslateMessage(MSG* pMsg);
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


// CmusicplayerDlg 对话框



CmusicplayerDlg::CmusicplayerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MUSICPLAYER_DIALOG, pParent)
	, is_loaded(false)
	, m_status(0)
	, amount(0)
	, time(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	ZeroMemory(&m_cf, sizeof(CHARFORMAT));
	m_cf.cbSize = sizeof(CHARFORMAT);
	m_cf.dwMask = CFM_COLOR;
	m_cf.dwEffects &= ~CFE_AUTOCOLOR;
	m_cf.crTextColor = RGB(0, 255, 0);
}

void CmusicplayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, m_cb);
	DDX_Control(pDX, IDC_SLIDER1, m_sld);
	//  DDX_Control(pDX, IDC_1, m_b1);
	DDX_Control(pDX, IDC_LISTEN, m_play);
	DDX_Control(pDX, IDC_NOTES, m_edit);
	//  DDX_Control(pDX, IDC_PLAY, m_playbtn);
}

BEGIN_MESSAGE_MAP(CmusicplayerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN_BUTTON, &CmusicplayerDlg::OnBnClickedOpenButton)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CmusicplayerDlg::OnCbnSelchangeCombo2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CmusicplayerDlg::OnNMCustomdrawSlider1)

	ON_BN_CLICKED(IDC_1, &CmusicplayerDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CmusicplayerDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_4, &CmusicplayerDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CmusicplayerDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CmusicplayerDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_8, &CmusicplayerDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CmusicplayerDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_jian, &CmusicplayerDlg::OnBnClickedjian)
	ON_BN_CLICKED(IDC_jia, &CmusicplayerDlg::OnBnClickedjia)
	ON_BN_CLICKED(IDC_BACK, &CmusicplayerDlg::OnBnClickedButton52)
	ON_BN_CLICKED(IDC_TAB, &CmusicplayerDlg::OnBnClickedTab)
	ON_BN_CLICKED(IDC_Q, &CmusicplayerDlg::OnBnClickedQ)
	ON_BN_CLICKED(IDC_W, &CmusicplayerDlg::OnBnClickedW)
	ON_BN_CLICKED(IDC_E, &CmusicplayerDlg::OnBnClickedE)
	ON_BN_CLICKED(IDC_R, &CmusicplayerDlg::OnBnClickedR)
	ON_BN_CLICKED(IDC_T, &CmusicplayerDlg::OnBnClickedT)
	ON_BN_CLICKED(IDC_Y, &CmusicplayerDlg::OnBnClickedY)
	ON_BN_CLICKED(IDC_U, &CmusicplayerDlg::OnBnClickedU)
	ON_BN_CLICKED(IDC_I, &CmusicplayerDlg::OnBnClickedI)
	ON_BN_CLICKED(IDC_O, &CmusicplayerDlg::OnBnClickedO)
	ON_BN_CLICKED(IDC_P, &CmusicplayerDlg::OnBnClickedP)
	ON_BN_CLICKED(IDC_LEFT, &CmusicplayerDlg::OnBnClickedLeft)
	ON_BN_CLICKED(IDC_RIGHT, &CmusicplayerDlg::OnBnClickedRight)
	ON_BN_CLICKED(IDC_BUTTON53, &CmusicplayerDlg::OnBnClickedButton53)
	ON_BN_CLICKED(IDC_CAPS, &CmusicplayerDlg::OnBnClickedCaps)
	ON_BN_CLICKED(IDC_S, &CmusicplayerDlg::OnBnClickedS)
	ON_BN_CLICKED(IDC_D, &CmusicplayerDlg::OnBnClickedD)
	ON_BN_CLICKED(IDC_F, &CmusicplayerDlg::OnBnClickedF)
	ON_BN_CLICKED(IDC_H, &CmusicplayerDlg::OnBnClickedH)
	ON_BN_CLICKED(IDC_J, &CmusicplayerDlg::OnBnClickedJ)
	ON_BN_CLICKED(IDC_L, &CmusicplayerDlg::OnBnClickedL)
	ON_BN_CLICKED(IDC_FEN, &CmusicplayerDlg::OnBnClickedFen)
	ON_BN_CLICKED(IDC_YIN, &CmusicplayerDlg::OnBnClickedYin)
	ON_BN_CLICKED(IDC_LSHIFT, &CmusicplayerDlg::OnBnClickedLshift)
	ON_BN_CLICKED(IDC_Z, &CmusicplayerDlg::OnBnClickedZ)
	ON_BN_CLICKED(IDC_X, &CmusicplayerDlg::OnBnClickedX)
	ON_BN_CLICKED(IDC_C, &CmusicplayerDlg::OnBnClickedC)
	ON_BN_CLICKED(IDC_V, &CmusicplayerDlg::OnBnClickedV)
	ON_BN_CLICKED(IDC_B, &CmusicplayerDlg::OnBnClickedB)
	ON_BN_CLICKED(IDC_N, &CmusicplayerDlg::OnBnClickedN)
	ON_BN_CLICKED(IDC_M, &CmusicplayerDlg::OnBnClickedM)
	ON_BN_CLICKED(IDC_DOU, &CmusicplayerDlg::OnBnClickedDou)
	ON_BN_CLICKED(IDC_JU, &CmusicplayerDlg::OnBnClickedJu)
	ON_BN_CLICKED(IDC_GANG, &CmusicplayerDlg::OnBnClickedGang)
	ON_BN_CLICKED(IDC_RSHIFT, &CmusicplayerDlg::OnBnClickedRshift)
	//	ON_WM_KEYUP()
	ON_BN_CLICKED(IDC_SAVE, &CmusicplayerDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_LISTEN, &CmusicplayerDlg::OnBnClickedListen)
	ON_BN_CLICKED(IDC_10, &CmusicplayerDlg::OnBnClicked10)
	ON_BN_CLICKED(IDC_jian2, &CmusicplayerDlg::OnBnClickedjian2)
	ON_BN_CLICKED(IDC_11, &CmusicplayerDlg::OnBnClicked11)
	ON_BN_CLICKED(IDC_jian3, &CmusicplayerDlg::OnBnClickedjian3)
	ON_BN_CLICKED(IDC_jia3, &CmusicplayerDlg::OnBnClickedjia3)
	ON_BN_CLICKED(IDC_12, &CmusicplayerDlg::OnBnClicked12)
	ON_BN_CLICKED(IDC_jian4, &CmusicplayerDlg::OnBnClickedjian4)
	ON_BN_CLICKED(IDC_jia4, &CmusicplayerDlg::OnBnClickedjia4)
	ON_BN_CLICKED(IDC_13, &CmusicplayerDlg::OnBnClicked13)
	ON_BN_CLICKED(IDC_jian5, &CmusicplayerDlg::OnBnClickedjian5)
	ON_BN_CLICKED(IDC_jia5, &CmusicplayerDlg::OnBnClickedjia5)
	ON_BN_CLICKED(IDC_14, &CmusicplayerDlg::OnBnClicked14)
	ON_BN_CLICKED(IDC_jian6, &CmusicplayerDlg::OnBnClickedjian6)
	ON_BN_CLICKED(IDC_15, &CmusicplayerDlg::OnBnClicked15)
	ON_BN_CLICKED(IDC_jian7, &CmusicplayerDlg::OnBnClickedjian7)
	ON_BN_CLICKED(IDC_jia7, &CmusicplayerDlg::OnBnClickedjia7)
	ON_BN_CLICKED(IDC_DELETE, &CmusicplayerDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_LISTEN2, &CmusicplayerDlg::OnBnClickedListen2)
	ON_BN_CLICKED(IDC_BUTTON3, &CmusicplayerDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_CLEARALL, &CmusicplayerDlg::OnBnClickedClearall)
	ON_BN_CLICKED(IDC_KEYBOARD, &CmusicplayerDlg::OnBnClickedKeyboard)
	ON_COMMAND(ID_32786, &CmusicplayerDlg::OnYANZOU)
	ON_COMMAND(ID_32787, &CmusicplayerDlg::OnBIANJI)
	ON_UPDATE_COMMAND_UI(ID_32786, &CmusicplayerDlg::OnUpdateYANZOU)
	ON_WM_INITMENUPOPUP()
	ON_UPDATE_COMMAND_UI(ID_32787, &CmusicplayerDlg::OnUpdate32787)
	ON_COMMAND(ID_32788, &CmusicplayerDlg::OnBOFANG)
	ON_UPDATE_COMMAND_UI(ID_32788, &CmusicplayerDlg::OnUpdateBOFANG)
	ON_BN_CLICKED(IDC_Play, &CmusicplayerDlg::OnBnClickedPlay)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CmusicplayerDlg 消息处理程序

BOOL CmusicplayerDlg::OnInitDialog()
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

	OnBnClickedKeyboard();
	OnYANZOU();
	//m_hAcc = LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR1));
	//EnableWindow(FALSE);
	CFont *m_Font;
	m_Font = new CFont;
	m_Font->CreateFont(30, 20, 0, 0, 100,
		FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, _T("Arial"));
	CEdit *m_Edit = (CEdit *)GetDlgItem(IDC_NOTES);
	m_Edit->SetFont(m_Font, FALSE);
	GetDlgItem(IDC_NOTES)->SetFont(m_Font);

	createlist();

	addDevice();
	m_cb.SetCurSel(0);
	m_sld.SetRange(0, 100);
	m_sld.SetPos(vol);
	//GetDlgItem(IDC_BUTTON2)->SetFocus();

	result = midiOutOpen(&handle, 0, 0, 0, CALLBACK_NULL);
	if (result)
	{
		MessageBox(_T("There is an error opening the default MIDI out device!/n"));
	}
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmusicplayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CmusicplayerDlg::OnPaint()
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
HCURSOR CmusicplayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmusicplayerDlg::OnBnClickedOpenButton()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	GetDlgItem(IDC_BUTTON2)->SetFocus();
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;
	CString strFileName;
	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里 
		deletelist();
		createlist();
		strFilePath = fileDlg.GetPathName();
		strFileName = fileDlg.GetFileName();
		SetDlgItemText(IDC_OPEN_EDIT, strFileName);

		while (!text.empty())
			text.pop();
		ifstream ifile(strFilePath);
		int flag = 0;
		while (1)
		{
			if (flag == 1) break;
			ostringstream buf;
			char ch;
			while (ifile.get(ch) && (ch == 32 || ch == 13 || ch == 10));
			buf.put(ch);
			while (ifile.get(ch) && ch != 32 && ch != 13 && ch != 10)
			{
				if (ch == ';')
				{
					flag = 1;
					break;
				}
				buf.put(ch);
			}
			string note;
			note = buf.str();
			CString NOTE(note.c_str());
			text.push(note);
			insertnode(NOTE);
			amount++;
		}
		if (m_status == YANZOU || m_status == BOFANG)
		{
			time = new int[amount];
			index = -1;
			if (m_status == BOFANG)
			{
				char s[1000];
				//	ifile.getline(s, 1000);
				for (int i = 0; i < amount; i++)
					ifile >> time[i];
			}
		}

		midiOutClose(handle);
		result = midiOutOpen(&handle, 0, 0, 0, CALLBACK_NULL);
		if (result)
		{
			MessageBox(_T("There is an error opening the default MIDI out device!/n"));
		}
		is_loaded = TRUE;
		shownote();
	}

}



bool CmusicplayerDlg::playsound(string note)
{
	//if(is_cont==FALSE)

	midiOutShortMsg(handle, midi.dwData & 0xff00ffff);




	midi.bData[1] = device;
	midi.bData[0] = 0xc0;
	midi.bData[2] = 0;
	midi.bData[3] = 0;
	midiOutShortMsg(handle, midi.dwData);
	//midiOutSetVolume(handle, 0xffffffff);
	//midiOutGetVolume(handle, &result); 
	for (int i = 0; i < 128; i++)
	{
		if (note == notelist[i])
		{
			midi.bData[0] = 0x90;
			midi.bData[1] = i;
			midi.bData[2] = vol;
			midi.bData[3] = 0;
			midiOutShortMsg(handle, midi.dwData);

			return true;
		}
	}

	return false;
}


BOOL CmusicplayerDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	string str;
	static BOOL status = FALSE;

	if (pMsg->message == WM_KEYDOWN)
	{

		switch (pMsg->wParam)
		{
		case VK_SPACE:

			if (is_loaded == TRUE&&status == FALSE&&m_status == YANZOU)
			{
				static int pre = GetTickCount();
				static int aft;

				aft = GetTickCount();
				if (index != -1)
					time[index] = aft - pre;
				pre = aft;
				index++;
				p = p->next;
				if (p == tail)
				{
					if (IDYES == MessageBox(_T("演奏完成，是否保存？"), 0, MB_YESNO))
					{
						OnBnClickedSave();
					}
					MessageBox(_T("您可以继续演奏"));
					p = head;
					pos1 = pos2 = 0;
					shownote();
					index = -1;
					break;
				}

				USES_CONVERSION;
				string note = W2CA((LPCWSTR)p->note);

				if (playsound(note) == false)
					MessageBox(_T("曲谱有误请检查"));
				pos1 = pos2; pos2 += p->note.GetLength() + 1;
				shownote();
				status = TRUE;
			}
			break;
		case '1':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClicked1();
				status = TRUE;
			}
			break;
		case '2':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClicked2();
				status = TRUE;
			}
			break;
		case '4':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClicked4();
				status = TRUE;
			}
			break;
		case '5':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClicked5();
				status = TRUE;
			}
			break;
		case '6':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClicked6();
				status = TRUE;
			}
			break;
		case '8':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClicked8();
				status = TRUE;
			}
			break;
		case '9':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClicked9();
				status = TRUE;
			}
			break;
		case 189:
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedjian();
				status = TRUE;
			}
			break;
		case 187:
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedjia();
				status = TRUE;
			}
			break;
		case VK_BACK:
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedButton52();
				status = TRUE;
			}
			break;

		case 'Q':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedQ();
				status = TRUE;
			}
			break;
		case 'W':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedW();
				status = TRUE;
			}
			break;
		case 'E':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedE();
				status = TRUE;
			}
			break;
		case 'R':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedR();
				status = TRUE;
			}
			break;
		case 'T':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedT();
				status = TRUE;
			}
			break;
		case 'Y':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedY();
				status = TRUE;
			}
			break;
		case 'U':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedU();
				status = TRUE;
			}
			break;
		case 'I':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedI();
				status = TRUE;
			}
			break;
		case 'O':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedO();
				status = TRUE;
			}
			break;
		case 'P':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedP();
				status = TRUE;
			}
			break;
		case VK_OEM_4:
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedLeft();
				status = TRUE;
			}
			break;
		case VK_OEM_6:
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedRight();
				status = TRUE;
			}
			break;
		case VK_OEM_5:
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedButton53();
				status = TRUE;
			}
			break;
		case VK_TAB:
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedTab();
				status = TRUE;
			}
			break;
		case VK_CAPITAL:
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedTab();
				status = TRUE;
			}
			break;
		case 'S':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedS();
				status = TRUE;
			}
			break;
		case 'D':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedD();
				status = TRUE;
			}
			break;
		case 'F':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedF();
				status = TRUE;
			}
			break;
		case 'H':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedH();
				status = TRUE;
			}
			break;
		case 'J':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedJ();
				status = TRUE;
			}
			break;
		case 'L':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedL();
				status = TRUE;
			}
			break;
		case VK_OEM_1:
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedFen();
				status = TRUE;
			}
			break;
		case 222:
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedYin();
				status = TRUE;
			}
			break;
		case 'Z':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedZ();
				status = TRUE;
			}
			break;
		case 'X':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedX();
				status = TRUE;
			}
			break;
		case 'C':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedC();
				status = TRUE;
			}
			break;
		case 'V':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedV();
				status = TRUE;
			}
			break;
		case 'B':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedB();
				status = TRUE;
			}
			break;
		case 'N':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedN();
				status = TRUE;
			}
			break;
		case 'M':
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedM();
				status = TRUE;
			}
			break;
		case 188:
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedDou();
				status = TRUE;
			}
			break;
		case 190:
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedJu();
				status = TRUE;
			}
			break;
		case 191:
			if (status == FALSE&&m_status == BIANJI)
			{
				OnBnClickedGang();
				status = TRUE;
			}
			break;
		case VK_SHIFT:
			if (status == FALSE&&m_status == BIANJI)
			{

				OnBnClickedRshift();
				status = TRUE;
			}
			break;
		default:
			break;
		}
		return TRUE;
	}
	if (pMsg->message == WM_KEYUP)
	{
		status = FALSE;
		switch (pMsg->wParam)
		{
		case VK_SPACE:
			if ((device >= 40 && device <= 45) || (device >= 48 && device <= 103))
				if (m_status == YANZOU)
					midiOutShortMsg(handle, midi.dwData & 0xff00ffff);
			break;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CmusicplayerDlg::addDevice()
{
	for (int i = 0; i < 128; i++)
	{
		CString str;
		//str.Format(_T("%s"), MidiToneType[i].c_str());
		m_cb.AddString(MidiToneType[i]);
	}
}


void CmusicplayerDlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	device = m_cb.GetCurSel();
	GetDlgItem(IDC_BUTTON2)->SetFocus();
}


void CmusicplayerDlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	CString str;
	vol = m_sld.GetPos();



	*pResult = 0;
}


//void CmusicplayerDlg::OnBnClicked1()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	m_b1.SetButtonStyle(1, 1);
//}

void CmusicplayerDlg::OnBnClicked1()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("C#3");
	insertnode(_T("C#3"));
	shownote();

}


void CmusicplayerDlg::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("D#3");
	insertnode(_T("D#3"));
	shownote();
}


void CmusicplayerDlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("F#3");
	insertnode(_T("F#3"));
	shownote();
}


void CmusicplayerDlg::OnBnClicked5()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("G#3");
	insertnode(_T("G#3"));
	shownote();
}


void CmusicplayerDlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("A#3");
	insertnode(_T("A#3"));
	shownote();
}


void CmusicplayerDlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("C#4");
	insertnode(_T("C#4"));
	shownote();
}


void CmusicplayerDlg::OnBnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("D#4");
	insertnode(_T("D#4"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedjian()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("F#4");
	insertnode(_T("F#4"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedjia()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("G#4");
	insertnode(_T("G#4"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedButton52()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("A#4");
	insertnode(_T("A#4"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedTab()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("C3");
	insertnode(_T("C3"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedQ()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("C3");
	insertnode(_T("D3"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedW()
{
	// TODO: 在此添加控件通知处理程序代码
	insertnode(_T("E3"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedE()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("F3");
	insertnode(_T("F3"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedR()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("G3");
	insertnode(_T("G3"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedT()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("A3");
	insertnode(_T("A3"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedY()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("B3");
	insertnode(_T("B3"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedU()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("C4");
	insertnode(_T("C4"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedI()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("D4");
	insertnode(_T("D4"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedO()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("E4");
	insertnode(_T("E4"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedP()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("F4");
	insertnode(_T("F4"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedLeft()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("G4");
	insertnode(_T("G4"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedRight()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("A4");
	insertnode(_T("A4"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedButton53()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("B4");
	insertnode(_T("B4"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedCaps()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("D#1");
	insertnode(_T("D#1"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedS()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("F#1");
	insertnode(_T("F#1"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedD()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("G#1");
	insertnode(_T("G#1"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedF()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("A#1");
	insertnode(_T("A#1"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedH()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("C#2");
	insertnode(_T("C#2"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedJ()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("D#2");
	insertnode(_T("D#2"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedL()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("F#2");
	insertnode(_T("F#2"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedFen()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("G#2");
	insertnode(_T("G#2"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedYin()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("A#2");
	insertnode(_T("A#2"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedLshift()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("E1");
	insertnode(_T("E1"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedZ()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("F1");
	insertnode(_T("F1"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedX()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("G1");
	insertnode(_T("G1"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedC()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("A1");
	insertnode(_T("A1"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedV()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("B1");
	insertnode(_T("B1"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedB()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("C2");
	insertnode(_T("C2"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedN()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("D2");
	insertnode(_T("D2"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedM()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("E2");
	insertnode(_T("E2"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedDou()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("F2");
	insertnode(_T("F2"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedJu()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("G2");
	insertnode(_T("G2"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedGang()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("A2");
	insertnode(_T("A2"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedRshift()
{
	// TODO: 在此添加控件通知处理程序代码
	playsound("B2");
	insertnode(_T("B2"));
	shownote();
}


//void CmusicplayerDlg::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//
//	CDialogEx::OnKeyUp(nChar, nRepCnt, nFlags);
//}


void CmusicplayerDlg::OnBnClickedSave()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(FALSE, _T("txt"), NULL, 0, szFilter, this);

	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		CString notes;
		for (NODE* p = head->next; p != tail->pre; p = p->next)
		{
			notes += p->note;
			notes += " ";
		}
		notes += tail->pre->note;
		notes += ";";
		ofstream	ofs(fileDlg.GetPathName());
		USES_CONVERSION;

		string str = W2CA((LPCWSTR)notes);
		ofs << str;
		ofs << endl;
		if (m_status == YANZOU)
		{
			for (int i = 0; i < amount - 1; i++)
				ofs << time[i] << ' ';
			ofs << time[amount - 1] << ';';
		}
		ofs.flush();
		ofs.close();
		MessageBox(_T("保存成功！"));
	}
}


void CmusicplayerDlg::OnBnClickedListen()
{
	// TODO: 在此添加控件通知处理程序代码







	if (p->next == tail)
	{
		p = head;
		pos1 = pos2 = 0;

	}
	p = p->next;
	pos1 = pos2; pos2 += p->note.GetLength() + 1;
	shownote();
	USES_CONVERSION;
	string note = W2CA((LPCWSTR)p->note);
	playsound(note);
}


void CmusicplayerDlg::shownote()
{
	CString notes;
	NODE * i = head;
	for (; i != tail; i = i->next)
	{
		notes += i->note;
		notes += " ";
	}
	GetDlgItem(IDC_NOTES)->SetWindowTextW(notes);
	m_edit.SetSel(pos1, pos2);
	m_cf.crTextColor = RGB(0, 255, 0);
	m_edit.SetSelectionCharFormat(m_cf);
	if (INSERT == 2)
	{
		pos3 += cur->note.GetLength() + 1;
		m_edit.SetSel(pos2, pos3);
		m_cf.crTextColor = RGB(255, 0, 0);
		m_edit.SetSelectionCharFormat(m_cf);
	}
}


void CmusicplayerDlg::OnBnClicked10()
{
	// TODO: 在此添加控件通知处理程序代码
	insertnode(_T("C#5"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedjian2()
{
	// TODO: 在此添加控件通知处理程序代码
	insertnode(_T("D#5"));
	shownote();
}


void CmusicplayerDlg::OnBnClicked11()
{
	// TODO: 在此添加控件通知处理程序代码
	insertnode(_T("C5"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedjian3()
{
	// TODO: 在此添加控件通知处理程序代码
	insertnode(_T("D5"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedjia3()
{
	// TODO: 在此添加控件通知处理程序代码
	insertnode(_T("E5"));
	shownote();
}


void CmusicplayerDlg::OnBnClicked12()
{
	// TODO: 在此添加控件通知处理程序代码
	insertnode(_T("F#5"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedjian4()
{
	// TODO: 在此添加控件通知处理程序代码
	insertnode(_T("G#5"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedjia4()
{
	// TODO: 在此添加控件通知处理程序代码
	insertnode(_T("A#5"));
	shownote();
}


void CmusicplayerDlg::OnBnClicked13()
{
	// TODO: 在此添加控件通知处理程序代码
	insertnode(_T("F5"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedjian5()
{
	// TODO: 在此添加控件通知处理程序代码
	insertnode(_T("F5"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedjia5()
{
	// TODO: 在此添加控件通知处理程序代码
	insertnode(_T("A5"));
	shownote();
}


void CmusicplayerDlg::OnBnClicked14()
{
	// TODO: 在此添加控件通知处理程序代码
	insertnode(_T("C#6"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedjian6()
{
	// TODO: 在此添加控件通知处理程序代码
	insertnode(_T("D#6"));
	shownote();
}


void CmusicplayerDlg::OnBnClicked15()
{
	// TODO: 在此添加控件通知处理程序代码
	insertnode(_T("C6"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedjian7()
{
	// TODO: 在此添加控件通知处理程序代码
	insertnode(_T("D6"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedjia7()
{
	// TODO: 在此添加控件通知处理程序代码
	insertnode(_T("E6"));
	shownote();
}


void CmusicplayerDlg::OnBnClickedDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	if (p == head)
	{
		p = deletenode(p);
		return;
	}
	p = deletenode(p);
	pos2 = pos1;
	pos1 -= (p->note.GetLength() + 1);

	shownote();
}


void CmusicplayerDlg::OnBnClickedListen2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (p->pre == head)
	{
		p = tail;
		int POS = 0;
		for (NODE*pt = head->next; pt != tail; pt = pt->next)
			POS += pt->note.GetLength() + 1;
		pos1 = pos2 = POS;
	}
	p = p->pre;
	pos2 = pos1; pos1 -= p->note.GetLength() + 1;
	m_edit.SetSel(pos1, pos2);
	shownote();
	m_edit.SetSelectionCharFormat(m_cf);
	USES_CONVERSION;
	string note = W2CA((LPCWSTR)p->note);
	playsound(note);
}


void CmusicplayerDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	if (INSERT == 1)
	{
		SetDlgItemText(IDC_BUTTON3, _T("完成"));
		GetDlgItem(IDC_DELETE)->EnableWindow(FALSE);
		GetDlgItem(IDC_SAVE)->EnableWindow(FALSE);
		GetDlgItem(IDC_LISTEN)->EnableWindow(FALSE);
		GetDlgItem(IDC_LISTEN2)->EnableWindow(FALSE);
		GetDlgItem(IDC_CLEARALL)->EnableWindow(FALSE);
		cur = p;
		INSERT = 2;
		pos3 = pos2;
	}
	else
	{
		SetDlgItemText(IDC_BUTTON3, _T("从当前位置插入"));
		GetDlgItem(IDC_DELETE)->EnableWindow(TRUE);
		GetDlgItem(IDC_SAVE)->EnableWindow(TRUE);
		GetDlgItem(IDC_LISTEN)->EnableWindow(TRUE);
		GetDlgItem(IDC_LISTEN2)->EnableWindow(TRUE);
		GetDlgItem(IDC_CLEARALL)->EnableWindow(TRUE);
		cur = tail->pre;
		INSERT = 1;

		shownote();
	}
}


void CmusicplayerDlg::OnBnClickedClearall()
{
	// TODO: 在此添加控件通知处理程序代码
	deletelist();
	createlist();
	p = head;
	shownote();
}


void CmusicplayerDlg::OnBnClickedKeyboard()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	static CRect rectlarge;      //定义没有切割的（即全部的）矩形         
	static CRect rectsmall;      //定义剩余的小矩形
	if (rectlarge.IsRectEmpty())  //如果还没有给大矩形的大小赋值的话，在｛｝中赋值
	{                               //注意相关函数的用法
		GetWindowRect(&rectlarge);
		CRect rectseperator;
		GetDlgItem(IDC_SEPERATOR)->GetWindowRect(&rectseperator);
		rectsmall.left = rectlarge.left;
		rectsmall.top = rectlarge.top;
		rectsmall.right = rectlarge.right;
		rectsmall.bottom = rectseperator.bottom;
	}
	if (GetDlgItemText(IDC_KEYBOARD, str), str == "收起键盘") //如果为收缩的话，要设置激活窗口为小窗口
	{
		SetWindowPos(NULL, 0, 0, rectsmall.Width(), rectsmall.Height(), SWP_NOMOVE | SWP_NOZORDER);
		SetDlgItemText(IDC_KEYBOARD, _T("展开键盘"));
	}
	else               //反之，设置为大窗口
	{
		SetWindowPos(NULL, 0, 0, rectlarge.Width(), rectlarge.Height(), SWP_NOMOVE | SWP_NOZORDER);
		SetDlgItemText(IDC_KEYBOARD, _T("收起键盘"));
	}
}

//演奏菜单选中
void CmusicplayerDlg::OnYANZOU()
{
	// TODO: 在此添加命令处理程序代码
	if (m_status != YANZOU)
	{
		GetMenu()->CheckMenuRadioItem(0, 1, 0, MF_BYPOSITION);
		m_status = YANZOU;
		CString str;
		if (GetDlgItemText(IDC_KEYBOARD, str), str == "收起键盘")
			OnBnClickedKeyboard();
		GetDlgItem(IDC_KEYBOARD)->EnableWindow(FALSE);
		GetDlgItem(IDC_DELETE)->EnableWindow(FALSE);
		GetDlgItem(IDC_SAVE)->EnableWindow(FALSE);
		GetDlgItem(IDC_LISTEN)->EnableWindow(FALSE);
		GetDlgItem(IDC_LISTEN2)->EnableWindow(FALSE);
		GetDlgItem(IDC_CLEARALL)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
		GetDlgItem(IDC_Play)->EnableWindow(FALSE);
		deletelist();
		shownote();

	}
}


void CmusicplayerDlg::OnBIANJI()
{
	// TODO: 在此添加命令处理程序代码
	if (m_status != BIANJI)
	{
		m_status = BIANJI;
		CString str;
		GetDlgItem(IDC_KEYBOARD)->EnableWindow(TRUE);
		GetDlgItem(IDC_DELETE)->EnableWindow(TRUE);
		GetDlgItem(IDC_SAVE)->EnableWindow(TRUE);
		GetDlgItem(IDC_LISTEN)->EnableWindow(TRUE);
		GetDlgItem(IDC_LISTEN2)->EnableWindow(TRUE);
		GetDlgItem(IDC_CLEARALL)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
		GetDlgItem(IDC_Play)->EnableWindow(FALSE);
		p = head;
		pos1 = 0; pos2 = 0;
		shownote();

	}
}
void CmusicplayerDlg::OnBOFANG()
{
	// TODO: 在此添加命令处理程序代码
	m_status = BOFANG;
	CString str;
	if (GetDlgItemText(IDC_KEYBOARD, str), str == "收起键盘")
		OnBnClickedKeyboard();
	GetDlgItem(IDC_KEYBOARD)->EnableWindow(FALSE);
	GetDlgItem(IDC_DELETE)->EnableWindow(FALSE);
	GetDlgItem(IDC_SAVE)->EnableWindow(FALSE);
	GetDlgItem(IDC_LISTEN)->EnableWindow(FALSE);
	GetDlgItem(IDC_LISTEN2)->EnableWindow(FALSE);
	GetDlgItem(IDC_CLEARALL)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	GetDlgItem(IDC_Play)->EnableWindow(TRUE);
	deletelist();
	shownote();
	pos1 = 0; pos2 = 0;
}


void CmusicplayerDlg::OnUpdateYANZOU(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (m_status == YANZOU)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}

void CmusicplayerDlg::OnUpdate32787(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (m_status == BIANJI)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}




void CmusicplayerDlg::OnUpdateBOFANG(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (m_status == BOFANG)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}

void CmusicplayerDlg::OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu)
{
	CDialogEx::OnInitMenuPopup(pPopupMenu, nIndex, bSysMenu);
	ASSERT(pPopupMenu != NULL);
	// Check the enabled state of various menu items.

	CCmdUI state;
	state.m_pMenu = pPopupMenu;
	ASSERT(state.m_pOther == NULL);
	ASSERT(state.m_pParentMenu == NULL);

	// Determine if menu is popup in top-level menu and set m_pOther to
	// it if so (m_pParentMenu == NULL indicates that it is secondary popup).
	HMENU hParentMenu;
	if (AfxGetThreadState()->m_hTrackingMenu == pPopupMenu->m_hMenu)
		state.m_pParentMenu = pPopupMenu;    // Parent == child for tracking popup.
	else if ((hParentMenu = ::GetMenu(m_hWnd)) != NULL)
	{
		CWnd* pParent = this;
		// Child windows don't have menus--need to go to the top!
		if (pParent != NULL &&
			(hParentMenu = ::GetMenu(pParent->m_hWnd)) != NULL)
		{
			int nIndexMax = ::GetMenuItemCount(hParentMenu);
			for (int nIndex = 0; nIndex < nIndexMax; nIndex++)
			{
				if (::GetSubMenu(hParentMenu, nIndex) == pPopupMenu->m_hMenu)
				{
					// When popup is found, m_pParentMenu is containing menu.
					state.m_pParentMenu = CMenu::FromHandle(hParentMenu);
					break;
				}
			}
		}
	}

	state.m_nIndexMax = pPopupMenu->GetMenuItemCount();
	for (state.m_nIndex = 0; state.m_nIndex < state.m_nIndexMax;
	state.m_nIndex++)
	{
		state.m_nID = pPopupMenu->GetMenuItemID(state.m_nIndex);
		if (state.m_nID == 0)
			continue; // Menu separator or invalid cmd - ignore it.

		ASSERT(state.m_pOther == NULL);
		ASSERT(state.m_pMenu != NULL);
		if (state.m_nID == (UINT)-1)
		{
			// Possibly a popup menu, route to first item of that popup.
			state.m_pSubMenu = pPopupMenu->GetSubMenu(state.m_nIndex);
			if (state.m_pSubMenu == NULL ||
				(state.m_nID = state.m_pSubMenu->GetMenuItemID(0)) == 0 ||
				state.m_nID == (UINT)-1)
			{
				continue;       // First item of popup can't be routed to.
			}
			state.DoUpdate(this, TRUE);   // Popups are never auto disabled.
		}
		else
		{
			// Normal menu item.
			// Auto enable/disable if frame window has m_bAutoMenuEnable
			// set and command is _not_ a system command.
			state.m_pSubMenu = NULL;
			state.DoUpdate(this, FALSE);
		}

		// Adjust for menu deletions and additions.
		UINT nCount = pPopupMenu->GetMenuItemCount();
		if (nCount < state.m_nIndexMax)
		{
			state.m_nIndex -= (state.m_nIndexMax - nCount);
			while (state.m_nIndex < nCount &&
				pPopupMenu->GetMenuItemID(state.m_nIndex) == state.m_nID)
			{
				state.m_nIndex++;
			}
		}
		state.m_nIndexMax = nCount;
	}

	// TODO: 在此处添加消息处理程序代码
}








void CmusicplayerDlg::OnBnClickedPlay()
{
	// TODO: 在此添加控件通知处理程序代码
	if (is_loaded == TRUE&&m_status == BOFANG)
	{

		if (PLAY == 1)
		{
			PLAY = 2;
			GetDlgItem(IDC_Play)->SetWindowTextW(_T("暂停"));

			if (index == -1)
				index = 0;
			if (p == head)
			{
				p = p->next;
				pos1 = pos2;
				pos2 += p->note.GetLength() + 1;
			}

			shownote();
			SetTimer(1, 0, NULL);
		}
		else
		{
			PLAY = 1;
			KillTimer(1);
			GetDlgItem(IDC_Play)->SetWindowTextW(_T("播放"));
		}






	}
}


void CmusicplayerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (p == tail)
	{
		midiOutShortMsg(handle, midi.dwData & 0xff00ffff);
		KillTimer(1);
		GetDlgItem(IDC_Play)->SetWindowTextW(_T("播放"));
		PLAY = 1;
		MessageBox(_T("播放结束"));
		p = head;
		pos1 = pos2 = 0;
		index = 0;
		return;
		//shownote();
	}
	USES_CONVERSION;
	string note = W2CA((LPCWSTR)p->note);
	pos1 = pos2;
	pos2 += p->next->note.GetLength() + 1;
	shownote();
	playsound(note);


	p = p->next;

	Sleep(time[index]);
	index++;

	CDialogEx::OnTimer(nIDEvent);
}