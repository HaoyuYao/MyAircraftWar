
// Bodhi_AircraftBattleView.h: CBodhiAircraftBattleView 类的接口
//

#pragma once
#include <thread>
#include <string>
#include <vector>
#include "Objects.h"
#include "PlayBKG.h"
#include "Player.h"
#include "Shell.h"
#include "Bomb.h"
#include "SmallEnemy.h"
#include "MiddleEnemy.h"
#include "HugeEnemy.h"
#include "GiftHeal.h"
#include "GiftEXPGrain.h"
#include "DamNumber.h"
#include <Mmsystem.h>
#include "Resource.h"
#pragma comment(lib, "Winmm.lib")


class CBodhiAircraftBattleView : public CView
{
protected: // 仅从序列化创建
	CBodhiAircraftBattleView() noexcept;
	DECLARE_DYNCREATE(CBodhiAircraftBattleView)

// 特性
public:
	CBodhiAircraftBattleDoc* GetDocument() const;

// 操作
public:
	CString strScore;
	PlayBKG m_BKG;
	int mouse_x, mouse_y;
	Player m_Player;
	bool AutoFire = false;
	SmallEnemy m_SmaEnemy;
	std::vector<SmallEnemy> m_vecSmaEnemy;
	MiddleEnemy m_MidEnemy;
	std::vector<MiddleEnemy> m_vecMidEnemy;
	HugeEnemy m_HugEnemy;
	std::vector<HugeEnemy> m_vecHugEnemy;
	GiftHeal m_Heal;
	std::vector<GiftHeal> m_vecHeal;
	bool GameStart = false;
	bool GameFail = false;
	bool GameRunning = false;
	bool ShowRuleBox = false;
	bool ShowRuleBox2 = false;
	bool ShowStrongBox = false;
	CFont font;
	CFont* oldfont;
	DamNumber m_Number;
	int RuleGas = 32;
public:
	CString snd_HitTarget = _T("\\sounds\\sambai.wav");
	CString snd_Failed = _T("\\sounds\\niganma.wav");
	CString snd_lt = _T("\\sounds\\lt_dame.wav");
	CString snd_CBTW = _T("\\sounds\\CombatBtheW.wav");
	//CString snd_Heal = _T("\\sounds\\heal.wav");
	CString snd_Fire = _T("\\sounds\\bullet.wav");
	CString snd_FireBomb = _T("\\sounds\\use_bomb.wav");
	CString snd_Laser = _T("\\sounds\\laser.wav");
	CString snd_Heal = _T("\\sounds\\upgrade.wav");
public:
	CString snd_SmaEnemyDown = _T("\\sounds\\enemydown\\enemy1_down.wav");
	CString snd_MidEnemyDown = _T("\\sounds\\enemydown\\enemy2_down.wav");
	CString snd_HugEnemyDown = _T("\\sounds\\enemydown\\enemy3_down.wav");
public:
	int k = 0;
	int ticker = 0;
	

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CBodhiAircraftBattleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual void OnInitialUpdate();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // Bodhi_AircraftBattleView.cpp 中的调试版本
inline CBodhiAircraftBattleDoc* CBodhiAircraftBattleView::GetDocument() const
   { return reinterpret_cast<CBodhiAircraftBattleDoc*>(m_pDocument); }
#endif

