
// musicplayerDlg.h : 头文件
//

#pragma once
#include <queue>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include "afxcmn.h"
#include "afxwin.h"
#pragma comment(lib,"winmm.lib")
using namespace std;
#define YANZOU 1
#define BIANJI 2
#define BOFANG 3
// CmusicplayerDlg 对话框
class CmusicplayerDlg : public CDialogEx
{
	// 构造
public:
	CmusicplayerDlg(CWnd* pParent = NULL);	// 标准构造函数
private:
	queue<string> text;
	int device = 0;
	int vol = 40;
	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MUSICPLAYER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


														// 实现
protected:
	HICON m_hIcon;
	HACCEL m_hAcc;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpenButton();
	bool CmusicplayerDlg::playsound(string note);
	//	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	//	CComboBox m_cb;
	void addDevice();

	CComboBox m_cb;
	afx_msg void OnCbnSelchangeCombo2();
private:
	BOOL is_loaded = FALSE;
	BOOL is_cont = TRUE;
public:
	CSliderCtrl m_sld;
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	//	afx_msg void OnBnClicked1();
	//	CButton m_b1;
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClickedjian();
	afx_msg void OnBnClickedjia();
	afx_msg void OnBnClickedButton52();
	afx_msg void OnBnClickedTab();
	afx_msg void OnBnClickedQ();
	afx_msg void OnBnClickedW();
	afx_msg void OnBnClickedE();
	afx_msg void OnBnClickedR();
	afx_msg void OnBnClickedT();
	afx_msg void OnBnClickedY();
	afx_msg void OnBnClickedU();
	afx_msg void OnBnClickedI();
	afx_msg void OnBnClickedO();
	afx_msg void OnBnClickedP();
	afx_msg void OnBnClickedLeft();
	afx_msg void OnBnClickedRight();
	afx_msg void OnBnClickedButton53();
	afx_msg void OnBnClickedCaps();
	afx_msg void OnBnClickedS();
	afx_msg void OnBnClickedD();
	afx_msg void OnBnClickedF();
	afx_msg void OnBnClickedH();
	afx_msg void OnBnClickedJ();
	afx_msg void OnBnClickedL();
	afx_msg void OnBnClickedFen();
	afx_msg void OnBnClickedYin();
	afx_msg void OnBnClickedLshift();
	afx_msg void OnBnClickedZ();
	afx_msg void OnBnClickedX();
	afx_msg void OnBnClickedC();
	afx_msg void OnBnClickedV();
	afx_msg void OnBnClickedB();
	afx_msg void OnBnClickedN();
	afx_msg void OnBnClickedM();
	afx_msg void OnBnClickedDou();
	afx_msg void OnBnClickedJu();
	afx_msg void OnBnClickedGang();
	afx_msg void OnBnClickedRshift();
	//	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedListen();
	void shownote();
	afx_msg void OnBnClicked10();
	afx_msg void OnBnClickedjian2();
	afx_msg void OnBnClicked11();
	afx_msg void OnBnClickedjian3();
	afx_msg void OnBnClickedjia3();
	afx_msg void OnBnClicked12();
	afx_msg void OnBnClickedjian4();
	afx_msg void OnBnClickedjia4();
	afx_msg void OnBnClicked13();
	afx_msg void OnBnClickedjian5();
	afx_msg void OnBnClickedjia5();
	afx_msg void OnBnClicked14();
	afx_msg void OnBnClickedjian6();
	afx_msg void OnBnClicked15();
	afx_msg void OnBnClickedjian7();
	afx_msg void OnBnClickedjia7();
	CButton m_play;
	CRichEditCtrl m_edit;

	CHARFORMAT m_cf;
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedListen2();
	afx_msg void OnBnClickedButton3();

	afx_msg void OnBnClickedClearall();
	afx_msg void OnBnClickedKeyboard();
	afx_msg void OnYANZOU();
	int m_status;
	afx_msg void OnBIANJI();
	afx_msg void OnUpdateYANZOU(CCmdUI *pCmdUI);
	afx_msg void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);
	afx_msg void OnUpdate32787(CCmdUI *pCmdUI);
	//  音符个数
	int amount;
	int *time;
	afx_msg void OnBOFANG();
	afx_msg void OnUpdateBOFANG(CCmdUI *pCmdUI);
	afx_msg void OnBnClickedPlay();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//	CButton m_playbtn;
};
