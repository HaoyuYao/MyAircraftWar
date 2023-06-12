
// Bodhi_AircraftBattleView.cpp: CBodhiAircraftBattleView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Bodhi_AircraftBattle.h"
#endif

#include "Bodhi_AircraftBattleDoc.h"
#include "Bodhi_AircraftBattleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBodhiAircraftBattleView

IMPLEMENT_DYNCREATE(CBodhiAircraftBattleView, CView)

BEGIN_MESSAGE_MAP(CBodhiAircraftBattleView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBodhiAircraftBattleView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CBodhiAircraftBattleView 构造/析构

CBodhiAircraftBattleView::CBodhiAircraftBattleView() noexcept
{
	// TODO: 在此处添加构造代码

}

CBodhiAircraftBattleView::~CBodhiAircraftBattleView()
{
}

BOOL CBodhiAircraftBattleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CBodhiAircraftBattleView 绘图
//void PlayBGM(CBodhiAircraftBattleView* pThis) {
//	PlaySound(LPWSTR(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
//}
void CBodhiAircraftBattleView::OnDraw(CDC* pDC)
{
	CBodhiAircraftBattleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CMemDC mDC(*pDC, this);    //解决闪烁问题
	CDC* pmDC = &mDC.GetDC();    //将原指针变为双缓存指针mDC，再将mDC中的双缓存画笔取出赋给pmDC
	pmDC->Rectangle(0, 0, 2000, 2000);     //画一个巨大的白色背景板
	TCHAR cDir1[1024];
	GetModuleFileName(NULL, cDir1, 1024);
	CString strDir1(cDir1);
	strDir1 = strDir1.Left(strDir1.ReverseFind('\\'));
	if (k == 0) {
		//PlaySound(LPWSTR(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
		mciSendString("open "+strDir1+snd_CBTW+" alias BGM", 0, 0, 0);
		k++;
	}
	if (ticker == 0) {
		mciSendString("play BGM", 0, 0, 0);
	}
	else if (ticker >= 24700) {
		//mciSendString("stop BGM", 0, 0, 0);
		mciSendString("close BGM", 0, 0, 0);
		//ticker = 0;
	}
	else {
		ticker++;
	}
	/*std::thread th_ShowBKG(&PlayBKG::Show,m_BKG,pmDC);
	th_ShowBKG.detach();*/
	m_BKG.Show(pmDC);
	m_Player.Show(pmDC);
	if (GameStart == true) {
		m_Player.ShowHP(pmDC);
		m_Player.ShowShell(pmDC);//子弹显示
		m_Player.ShowBomb(pmDC);
		m_Player.ShowLaser(pmDC);
		font.CreatePointFont(200, _T("华文琥珀"), NULL);
		oldfont = pmDC->SelectObject(&font);
		pmDC->SetTextColor(RGB(255, 240, 83));   //设置字体颜色
		pmDC->SetBkMode(TRANSPARENT);
		strScore.Format(_T("%d"), pDoc->m_nScore);
		pmDC->TextOutA(m_BKG.GetLeft() + 10, m_BKG.GetUp() + 10, _T("Score：") + strScore);
		pmDC->SelectObject(oldfont);
		font.DeleteObject();
		if (m_Player.GetHP() <= 0) {
			//pmDC->TextOutW(m_BKG.GetLeft() + 1, m_BKG.GetUp(), _T("你死了"));
			pDoc->m_nScore=0;
			ShowRuleBox2 = false;
			GameRunning = false;
			GameFail = true;
			Invalidate();
		}
		for (auto m_SEnemy : m_vecSmaEnemy) {//敌人显示
			m_SEnemy.Show(pmDC);
			//m_SEnemy.ShowHP(pmDC);
		}
		for (auto& m_MidEnemy : m_vecMidEnemy) {
			m_MidEnemy.ShowShell(pmDC);
			m_MidEnemy.Show(pmDC);
			m_MidEnemy.ShowHP(pmDC);
		}
		for (auto& m_HugEnemy : m_vecHugEnemy) {
			m_HugEnemy.ShowShell(pmDC);
			m_HugEnemy.Show(pmDC);
			m_HugEnemy.ShowHP(pmDC);
		}
		for (auto& m_Heal : m_vecHeal) {
			m_Heal.Show(pmDC);
		}
		
		if (GameFail == false) {
			m_BKG.ShowRuleKey2(pmDC);
			m_BKG.ShowStrongKey(pmDC);
			if (GameRunning == true) {
				m_BKG.ShowPauseKey(pmDC);
				for (auto& m_SmaEnemy : m_vecSmaEnemy) {//敌人生命值更新
					if (m_Player.HitTarget(m_SmaEnemy)) {//击中小敌人
						m_Number.OccurEDam(m_SmaEnemy.GetX(), m_SmaEnemy.GetY(), m_Player.GetShellDam());
						m_SmaEnemy.SetHP(m_SmaEnemy.GetHP() - m_Player.GetShellDam());
					}
					if (m_Player.BombHitTarget(m_SmaEnemy) || m_Player.BombEffected(m_SmaEnemy)) {//炸弹击中小敌人或爆炸波及
						m_Number.OccurEDam(m_SmaEnemy.GetX(), m_SmaEnemy.GetY(), m_Player.GetBombDam());
						m_SmaEnemy.SetHP(m_SmaEnemy.GetHP() - m_Player.GetBombDam());
					}
					if (m_Player.LaserHitTarget(m_SmaEnemy)) {//镭射击中小敌人
						m_Number.OccurEDam(m_SmaEnemy.GetX(), m_SmaEnemy.GetY(), m_Player.GetLaserDam());
						m_SmaEnemy.SetHP(m_SmaEnemy.GetHP() - m_Player.GetLaserDam());
					}
					if (m_Player.Collide(m_SmaEnemy)) {//小敌人与玩家碰撞
						m_SmaEnemy.SetHP(0);
						m_Player.SetHP(m_Player.GetHP() - m_SmaEnemy.GetDam());
						m_Number.OccurPDam(m_Player.GetX(), m_Player.GetY(), m_SmaEnemy.GetDam());
					}
					if (m_SmaEnemy.GetHP() <= 0) {//死亡敌人设置为不存在
						sndPlaySound(strDir1 + snd_SmaEnemyDown, SND_ASYNC);
						m_SmaEnemy.SetExists(false);
						pDoc->m_nScore++;
					}
					if (m_SmaEnemy.OutofPlace())//将出界的敌人设置为不存在
						m_SmaEnemy.SetExists(false);
				}
				for (auto& m_MidEnemy : m_vecMidEnemy) {//2级敌人生命值更新
					if (m_Player.HitTarget(m_MidEnemy)) {//击中中等敌人
						m_Number.OccurEDam(m_MidEnemy.GetX(), m_MidEnemy.GetY(), m_Player.GetShellDam());
						m_MidEnemy.SetHP(m_MidEnemy.GetHP() - m_Player.GetShellDam());
					}
					if (m_Player.BombHitTarget(m_MidEnemy) || m_Player.BombEffected(m_MidEnemy)) {//炸弹击中中等敌人或爆炸波及
						m_Number.OccurEDam(m_MidEnemy.GetX(), m_MidEnemy.GetY(), m_Player.GetBombDam());
						m_MidEnemy.SetHP(m_MidEnemy.GetHP() - m_Player.GetBombDam());
					}
					if (m_Player.LaserHitTarget(m_MidEnemy)) {//镭射击中中等敌人
						m_Number.OccurEDam(m_MidEnemy.GetX(), m_MidEnemy.GetY(), m_Player.GetLaserDam());
						m_MidEnemy.SetHP(m_MidEnemy.GetHP() - m_Player.GetLaserDam());
					}
					if (m_MidEnemy.HitTarget(m_Player)) {//中等敌人击中玩家
						m_Player.SetHP(m_Player.GetHP() - m_MidEnemy.GetShellDam());
						m_Number.OccurPDam(m_Player.GetX(), m_Player.GetY(), m_MidEnemy.GetShellDam());
					}
					if (m_Player.Collide(m_MidEnemy)) {//中等敌人与玩家碰撞
						m_MidEnemy.SetHP(0);
						m_Player.SetHP(m_Player.GetHP() - m_MidEnemy.GetDam());
						m_Number.OccurPDam(m_Player.GetX(), m_Player.GetY(), m_MidEnemy.GetDam());
					}
					if (m_MidEnemy.GetHP() <= 0) {
						sndPlaySound(strDir1 + snd_MidEnemyDown, SND_ASYNC);
						//sndPlaySound(strDir1 + snd_Failed, SND_ASYNC);
						m_MidEnemy.SetExists(false);//将死亡的敌人设置为不存在
						pDoc->m_nScore += 10;
					}
					if (m_MidEnemy.OutofPlace())
						m_MidEnemy.SetExists(false);
				}
				for (auto& m_HugEnemy : m_vecHugEnemy) {//3级敌人生命值更新
					if (m_Player.HitTarget(m_HugEnemy)) {//击中高等敌人
						m_Number.OccurEDam(m_HugEnemy.GetX(), m_HugEnemy.GetY(), m_Player.GetShellDam());
						m_HugEnemy.SetHP(m_HugEnemy.GetHP() - m_Player.GetShellDam());
					}
					if (m_Player.BombHitTarget(m_HugEnemy) || m_Player.BombEffected(m_HugEnemy)) {//炸弹击中高等敌人或爆炸波及
						m_Number.OccurEDam(m_HugEnemy.GetX(), m_HugEnemy.GetY(), m_Player.GetBombDam());
						m_HugEnemy.SetHP(m_HugEnemy.GetHP() - m_Player.GetBombDam());
					}
					if (m_Player.LaserHitTarget(m_HugEnemy)) {//镭射击中高等敌人
						m_Number.OccurEDam(m_HugEnemy.GetX(), m_HugEnemy.GetY(), m_Player.GetLaserDam());
						m_HugEnemy.SetHP(m_HugEnemy.GetHP() - m_Player.GetLaserDam());
					}
					if (m_HugEnemy.HitTarget(m_Player)) {//高等敌人击中玩家
						m_Player.SetHP(m_Player.GetHP() - m_HugEnemy.GetShellDam());
						m_Number.OccurPDam(m_Player.GetX(), m_Player.GetY(), m_HugEnemy.GetShellDam());
					}
					if (m_Player.Collide(m_HugEnemy)) {//高等敌人与玩家碰撞
						m_HugEnemy.SetHP(0);
						m_Player.SetHP(m_Player.GetHP() - m_HugEnemy.GetDam());
						m_Number.OccurPDam(m_Player.GetX(), m_Player.GetY(), m_HugEnemy.GetDam());
					}
					if (m_HugEnemy.GetHP() <= 0) {
						//sndPlaySound(strDir1 + snd_HitTarget, SND_ASYNC);
						sndPlaySound(strDir1 + snd_HugEnemyDown, SND_ASYNC);
						m_HugEnemy.SetExists(false);//将死亡的敌人设置为不存在
						pDoc->m_nScore += 20;
					}
					if (m_HugEnemy.OutofPlace())
						m_HugEnemy.SetExists(false);
				}
				for (auto& m_Heal : m_vecHeal) {//玩家与治疗球发生碰撞
					if (m_Player.Collide(m_Heal)) {
						m_Number.OccurPHea(m_Player.GetX(), m_Player.GetY(), m_Heal.GetHeal());
						sndPlaySound(strDir1 + snd_Heal, SND_ASYNC);
						m_Heal.SetExists(false);
						if (m_Player.GetHP() + m_Heal.GetHeal() <= 10)
							m_Player.SetHP(m_Player.GetHP() + m_Heal.GetHeal());
						else
							m_Player.SetHP(m_Player.GetIniHP());
					}
					if (m_Heal.OutofPlace()) {
						m_Heal.SetExists(false);
					}
				}
				int i = 0;
				for (auto m_SmaEnemy : m_vecSmaEnemy) {//1级敌人更新
					if (!m_SmaEnemy.GetExists()) {
						m_vecSmaEnemy.erase(m_vecSmaEnemy.begin() + i);
					}
					else
						i++;
				}
				i = 0;
				for (auto m_MidEnemy : m_vecMidEnemy) {//2级敌人更新
					if (!m_MidEnemy.GetExists()) {
						m_vecMidEnemy.erase(m_vecMidEnemy.begin() + i);
					}
					else
						i++;
				}
				i = 0;
				for (auto m_HugEnemy : m_vecHugEnemy) {//3级敌人更新
					if (!m_HugEnemy.GetExists()) {
						m_vecHugEnemy.erase(m_vecHugEnemy.begin() + i);
					}
					else
						i++;
				}
				i = 0;
				for (auto m_Heal : m_vecHeal) {//治疗奖励球更新
					if (!m_Heal.GetExists()) {
						m_vecHeal.erase(m_vecHeal.begin() + i);
					}
					else
						i++;
				}
				//font.CreatePointFont(200, _T("华文琥珀"), NULL);
				//oldfont = pmDC->SelectObject(&font);
				//pmDC->SetTextColor(RGB(255, 240, 83));   //设置字体颜色
				//pmDC->SetBkMode(TRANSPARENT);
				//strScore.Format(_T("%d"), pDoc->m_nScore);
				//pmDC->TextOutA(m_BKG.GetLeft() + 10, m_BKG.GetUp() + 10, _T("Score：") + strScore);
				//pmDC->SelectObject(oldfont);
				//font.DeleteObject();
				m_Number.ShowEDam(pmDC);
				m_Number.ShowPDam(pmDC);
				m_Number.ShowHeal(pmDC);
			}
			else {
				//font.CreatePointFont(200, _T("华文琥珀"), NULL);
				//oldfont = pmDC->SelectObject(&font);
				//pmDC->SetTextColor(RGB(255, 240, 83));   //设置字体颜色
				//pmDC->SetBkMode(TRANSPARENT);
				m_BKG.ShowPauseBox(pmDC);//显示暂停框
				m_BKG.ShowContinueKey(pmDC);//显示继续按钮
				m_BKG.ShowRestartKey(pmDC);//显示重新开始按钮
				m_BKG.ShowHomeKey(pmDC);//显示主页键
				m_BKG.ShowPause(pmDC);//显示“游戏暂停”
				/*pmDC->TextOutA((m_BKG.GetPauseLeft() + m_BKG.GetPauseRight()) / 2 - 105,
					m_BKG.GetPauseUp()+10, _T("Paused"));
				pmDC->SelectObject(oldfont);
				font.DeleteObject();*/
			}
		}
		else {
			m_BKG.ShowPauseBox(pmDC);//显示暂停框
			m_BKG.ShowRestartKey(pmDC);//显示重新开始按钮
			m_BKG.ShowHomeKey(pmDC);//显示主页键
			m_BKG.ShowOver(pmDC);//显示“游戏结束”
		}
	}
	else {
		m_BKG.ShowStartKey(pmDC);
		m_BKG.ShowRuleKey(pmDC);
	}
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(255,255,255));
	CPen* oldPen = pDC->SelectObject(&pen);
	pmDC->Rectangle(0, 0, m_BKG.GetRight()+100, m_BKG.GetUp());//四周遮蔽框：上
	pmDC->Rectangle(0, 0, m_BKG.GetLeft(), m_BKG.GetDown() +100);//左
	pmDC->Rectangle(0, m_BKG.GetDown(), m_BKG.GetRight()+100, m_BKG.GetDown() +100);//下
	pmDC->Rectangle(m_BKG.GetRight(), 0, m_BKG.GetRight()+100, m_BKG.GetDown()+100);//右
	pDC->SelectObject(oldPen);
	pen.DeleteObject();
	if (ShowRuleBox == true) {
		m_BKG.ShowRuleBox(pmDC);
		font.CreatePointFont(200, _T("黑体"), NULL);
		oldfont = pmDC->SelectObject(&font);
		pmDC->SetTextColor(RGB(255, 255, 255));   //设置字体颜色
		pmDC->SetBkMode(TRANSPARENT);
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10,
			_T("游戏规则："));
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10 + RuleGas,
			_T("1.鼠标控制飞机移动，左键开火"));
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10 + RuleGas * 2,
			_T("2.Q键切换“单发”/“自动连发”模式"));
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10 + RuleGas * 3,
			_T("3.B键发射导弹"));
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10 + RuleGas * 4,
			_T("4.L键发射镭射光线"));
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10 + RuleGas * 5,
			_T("5.初级敌人血量为1，撞机伤害为1"));
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10 + RuleGas * 6,
			_T("    击败后获得1积分"));
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10 + RuleGas * 7,
			_T("    初级敌人刷新时间为0.5秒"));
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10 + RuleGas * 8,
			_T("6.中级敌人血量为20，撞机伤害"));
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10 + RuleGas * 9,
			_T("    为3，会发射一枚子弹，伤害为1"));
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10 + RuleGas * 10,
			_T("    击败后获得10积分"));
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10 + RuleGas * 11,
			_T("    中级敌人刷新时间为10秒"));
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10 + RuleGas * 12,
			_T("7.高级敌人血量为60，撞机伤害"));
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10 + RuleGas * 13,
			_T("    为9，会发射三枚子弹，伤害各为1"));
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10 + RuleGas * 14,
			_T("    击败后获得20积分"));
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10 + RuleGas * 15,
			_T("    高级敌人刷新时间为25秒"));
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10 + RuleGas * 16,
			_T("8.血量球可恢复5点血量"));
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10 + RuleGas * 17,
			_T("    血量球刷新时间为8秒"));
		pmDC->TextOutA(m_BKG.GetRuleBoxLeft() + 10, m_BKG.GetRuleBoxUp() + 10 + RuleGas * 18,
			_T("9.R键唤起规则提示框"));
		pmDC->SelectObject(oldfont);
		font.DeleteObject();
	}
	if (ShowStrongBox == true) {
		m_BKG.ShowStrongBox(pmDC);
	}
}


// CBodhiAircraftBattleView 打印


void CBodhiAircraftBattleView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBodhiAircraftBattleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CBodhiAircraftBattleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CBodhiAircraftBattleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CBodhiAircraftBattleView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBodhiAircraftBattleView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CBodhiAircraftBattleView 诊断

#ifdef _DEBUG
void CBodhiAircraftBattleView::AssertValid() const
{
	CView::AssertValid();
}

void CBodhiAircraftBattleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBodhiAircraftBattleDoc* CBodhiAircraftBattleView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBodhiAircraftBattleDoc)));
	return (CBodhiAircraftBattleDoc*)m_pDocument;
}
#endif //_DEBUG


// CBodhiAircraftBattleView 消息处理程序

const int TIMER_FOR_ALL = 101;
const int TIMER_AUTOFIRE = 102;
const int TIMER_ENEMY_CREATE = 103;
const int TIMER_MIDDIUMEN_CREATE = 104;
const int TIMER_MIDDIUMEN_FIRE = 105;
const int TIMER_HUGEENEMY_CREATE = 106;
const int TIMER_HUGEENEMY_FIRE = 107;
const int TIMER_GIFTHEAL_CREATE = 108;
void CBodhiAircraftBattleView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	SetTimer(TIMER_FOR_ALL, 10, NULL);
	SetTimer(TIMER_AUTOFIRE, 100, NULL);
	SetTimer(TIMER_ENEMY_CREATE, m_SmaEnemy.GetRate(), NULL);
	SetTimer(TIMER_MIDDIUMEN_CREATE, m_MidEnemy.GetRate(), NULL);
	SetTimer(TIMER_MIDDIUMEN_FIRE, m_MidEnemy.GetInt(), NULL);
	SetTimer(TIMER_HUGEENEMY_CREATE, m_HugEnemy.GetRate(), NULL);
	SetTimer(TIMER_HUGEENEMY_FIRE, m_HugEnemy.GetInt(), NULL);
	SetTimer(TIMER_GIFTHEAL_CREATE, m_Heal.GetRate(), NULL);
}

void CBodhiAircraftBattleView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	TCHAR cDir1[1024];
	GetModuleFileName(NULL, cDir1, 1024);
	CString strDir1(cDir1);
	strDir1 = strDir1.Left(strDir1.ReverseFind('\\'));
	double dDir, tandDir;
	_int64 tmCurrent = GetTickCount64() / 1000;
	int rand_x = rand() * tmCurrent % (m_BKG.GetRight() - m_BKG.GetLeft()) + m_BKG.GetLeft();
	int rand_x2 = rand() * (tmCurrent+10) % (m_BKG.GetRight() - m_BKG.GetLeft()) + m_BKG.GetLeft();
	int rand_x3= rand() * (tmCurrent + 20) % (m_BKG.GetRight() - m_BKG.GetLeft()) + m_BKG.GetLeft();
	int rand_x4= rand() * (tmCurrent + 50) % (m_BKG.GetRight() - m_BKG.GetLeft()) + m_BKG.GetLeft();
	int rand_hmove = rand() * (tmCurrent + 50) % 5;
	//int rand_memove = rand() * (tmCurrent + 50) % 3;
	//int rand_hemove = rand() * (tmCurrent + 50) % 6;
	switch (nIDEvent) {
	case TIMER_FOR_ALL:
		if (GameRunning == true) {
			//玩家移动
			dDir = sqrt((mouse_y - m_Player.GetY()) * (mouse_y - m_Player.GetY()) +
				(mouse_x - m_Player.GetX()) * (mouse_x - m_Player.GetX()));
			tandDir = atan2(mouse_y - m_Player.GetY(), mouse_x - m_Player.GetX());
			if (dDir > 5.0) {
				m_Player.UpdatePos(tandDir, mouse_x, mouse_y);
			}
			//子弹移动
			m_Player.ShellMove(1);
			m_Player.BombMove(1);
			m_Player.LaserMove();
			for (auto& m_MidEnemy : m_vecMidEnemy)
				m_MidEnemy.ShellMove(2);
			for (auto& m_HugEnemy : m_vecHugEnemy)
				m_HugEnemy.ShellMove(2);
			//敌人移动
			for (auto& m_Enemy : m_vecSmaEnemy)
				m_Enemy.UpdatePos();
			for (auto& m_MidEnemy : m_vecMidEnemy)
				m_MidEnemy.UpdatePos();
			for (auto& m_HugEnemy : m_vecHugEnemy) {
				if (m_HugEnemy.GetETimer() < m_HugEnemy.GetETop()/4) {
					m_HugEnemy.UpdatePos();
				}
				if (m_HugEnemy.GetETimer() >= m_HugEnemy.GetETop()) {
					m_HugEnemy.SetETimer(0);
				}
				m_HugEnemy.UpdateETimer();
			}
			//奖励移动
			for (auto& m_Heal : m_vecHeal) {
				switch (rand_hmove) {
				case 1:
					m_Heal.UpdatePos(3);
					break;
				case 3:
					m_Heal.UpdatePos(4);
					break;
				default:
					m_Heal.UpdatePos(2);
					break;
				}
			}
		}
		Invalidate();
		break;
	case TIMER_AUTOFIRE://玩家自动发射子弹
		if (GameRunning == true) {
			if (AutoFire == true) {
				sndPlaySound(strDir1 + snd_Fire, SND_ASYNC);
				m_Player.FireShell();
				Invalidate();
			}
		}
		break;
	case TIMER_ENEMY_CREATE://普通敌人生成
		if (GameRunning == true) {
			m_SmaEnemy.SetPos(rand_x, m_BKG.GetUp() + 1);
			m_vecSmaEnemy.push_back(m_SmaEnemy);
			Invalidate();
			break;
		}
	case TIMER_MIDDIUMEN_CREATE://2级敌人生成
		if (GameRunning == true) {
			m_MidEnemy.SetPos(rand_x2, m_BKG.GetUp() + 1);
			m_vecMidEnemy.push_back(m_MidEnemy);
			Invalidate();
			break;
		}
	case TIMER_MIDDIUMEN_FIRE://2级敌人发射子弹
		if (GameRunning == true) {
			for (auto& m_MidEnemy : m_vecMidEnemy)
				m_MidEnemy.FireShell();
			Invalidate();
			break;
		}
	case TIMER_HUGEENEMY_CREATE://3级敌人生成
		if (GameRunning == true) {
			m_HugEnemy.SetPos(rand_x3, m_BKG.GetUp() + 1);
			m_vecHugEnemy.push_back(m_HugEnemy);
			Invalidate();
			break;
		}
	case TIMER_HUGEENEMY_FIRE://3级敌人发射子弹
		if (GameRunning == true) {
			for (auto& m_HugEnemy : m_vecHugEnemy)
				m_HugEnemy.FireShell();
			Invalidate();
			break;
		}
	case TIMER_GIFTHEAL_CREATE://生成治疗奖励
		if (GameRunning == true) {
			m_Heal.SetPos(rand_x4, m_BKG.GetUp() + 1);
			m_vecHeal.push_back(m_Heal);
			Invalidate();
			break;
		}
	default:
		break;
	}
	CView::OnTimer(nIDEvent);
}


BOOL CBodhiAircraftBattleView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	return TRUE;
	//return CView::OnEraseBkgnd(pDC);
}


void CBodhiAircraftBattleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	TCHAR cDir1[1024];
	GetModuleFileName(NULL, cDir1, 1024);
	CString strDir1(cDir1);
	strDir1 = strDir1.Left(strDir1.ReverseFind('\\'));
	if (GameStart == false) {
		if (m_BKG.JudgeTouched(point.x, point.y, m_BKG.GetStartKeyLeft(), m_BKG.GetStartKeyUp(), m_BKG.GetStartKeyRight(), m_BKG.GetStartKeyDown())) {
			GameStart = true;
			GameRunning = true;
			Invalidate();
		}
	}
	else {
		if (GameFail == false) {
			if (m_BKG.JudgeTouched(point.x, point.y, m_BKG.GetRuleKeyLeft2(), m_BKG.GetRuleKeyUp2(), m_BKG.GetRuleKeyRight2(), m_BKG.GetRuleKeyDown2())) {
				if (!ShowRuleBox) {
					ShowRuleBox = true;
				}
				else if (ShowRuleBox) {
					ShowRuleBox = false;
				}
				Invalidate();
			}
			if (m_BKG.JudgeTouched(point.x, point.y, m_BKG.GetStrongKeyLeft(), m_BKG.GetStrongKeyUp(), m_BKG.GetStrongKeyRight(), m_BKG.GetStrongKeyDown())) {
				if (!ShowStrongBox) {
					ShowStrongBox = true;
				}
				else if (ShowStrongBox) {
					ShowStrongBox = false;
				}
				Invalidate();
			}
			if (GameRunning == true) {
				if (m_BKG.JudgeTouched(point.x, point.y, m_BKG.GetPauseKeyLeft(), m_BKG.GetPauseKeyUp(), m_BKG.GetPauseKeyRight(), m_BKG.GetPauseKeyDown())) {
					GameRunning = false;
					Invalidate();
				}
				sndPlaySound(strDir1 + snd_Fire, SND_ASYNC);
				m_Player.FireShell();
				Invalidate();
			}
			else {
				if (m_BKG.JudgeTouched(point.x, point.y, m_BKG.GetContinueKeyLeft(), m_BKG.GetContinueKeyUp(), m_BKG.GetContinueKeyRight(), m_BKG.GetContinueKeyDown())) {
					GameRunning = true;
				}
				if (m_BKG.JudgeTouched(point.x, point.y, m_BKG.GetRestartKeyLeft(), m_BKG.GetRestartKeyUp(), m_BKG.GetRestartKeyRight(), m_BKG.GetRestartKeyDown())) {
					m_Player.ClearShell();
					m_Player.ClearBomb();
					m_Player.SetHP(m_Player.GetIniHP());
					m_vecSmaEnemy.clear();
					m_vecMidEnemy.clear();
					m_vecHugEnemy.clear();
					m_Player.SetPos((m_BKG.GetLeft() + m_BKG.GetRight()) / 2, m_BKG.GetDown());
					GameRunning = true;
					Invalidate();
				}
				if (m_BKG.JudgeTouched(point.x, point.y, m_BKG.GetHomeKeyLeft(), m_BKG.GetHomeKeyUp(), m_BKG.GetHomeKeyRight(), m_BKG.GetHomeKeyDown())) {
					m_Player.ClearShell();
					m_Player.ClearBomb();
					m_Player.SetHP(m_Player.GetIniHP());
					m_vecSmaEnemy.clear();
					m_vecMidEnemy.clear();
					m_vecHugEnemy.clear();
					m_Player.SetPos((m_BKG.GetLeft() + m_BKG.GetRight()) / 2, m_BKG.GetDown());
					GameStart = false;
					GameRunning = false;
					Invalidate();
				}
			}
		}
		else {
			if (m_BKG.JudgeTouched(point.x, point.y, m_BKG.GetRestartKeyLeft(), m_BKG.GetRestartKeyUp(), m_BKG.GetRestartKeyRight(), m_BKG.GetRestartKeyDown())) {
				m_Player.ClearShell();
				m_Player.ClearBomb();
				m_Player.SetHP(m_Player.GetIniHP());
				m_vecSmaEnemy.clear();
				m_vecMidEnemy.clear();
				m_vecHugEnemy.clear();
				m_Player.SetPos((m_BKG.GetLeft() + m_BKG.GetRight()) / 2, m_BKG.GetDown());
				GameRunning = true;
				GameFail = false;
				Invalidate();
			}
			if (m_BKG.JudgeTouched(point.x, point.y, m_BKG.GetHomeKeyLeft(), m_BKG.GetHomeKeyUp(), m_BKG.GetHomeKeyRight(), m_BKG.GetHomeKeyDown())) {
				m_Player.ClearShell();
				m_Player.ClearBomb();
				m_Player.SetHP(m_Player.GetIniHP());
				m_vecSmaEnemy.clear();
				m_vecMidEnemy.clear();
				m_vecHugEnemy.clear();
				m_Player.SetPos((m_BKG.GetLeft() + m_BKG.GetRight()) / 2, m_BKG.GetDown());
				GameStart = false;
				GameRunning = false;
				GameFail = false;
				Invalidate();
			}
		}
	}
	CView::OnLButtonDown(nFlags, point);
}


void CBodhiAircraftBattleView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	mouse_x = point.x;
	mouse_y = point.y;
	m_BKG.SetMouse(point.x, point.y);
	if (GameStart == false) {
		if (m_BKG.JudgeTouched(point.x, point.y, m_BKG.GetRuleKeyLeft(), m_BKG.GetRuleKeyUp(), m_BKG.GetRuleKeyRight(), m_BKG.GetRuleKeyDown())) {
			ShowRuleBox = true;
		}
		else
			ShowRuleBox = false;
	}
	CView::OnMouseMove(nFlags, point);
}


void CBodhiAircraftBattleView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	TCHAR cDir1[1024];
	GetModuleFileName(NULL, cDir1, 1024);
	CString strDir1(cDir1);
	strDir1 = strDir1.Left(strDir1.ReverseFind('\\'));
	if (GameFail == false && GameStart == true) {
		if (nChar == 'r' || nChar == 'R') {
			if (ShowRuleBox == false) {
				ShowRuleBox = true;
			}
			else
				ShowRuleBox = false;
		}
		if (GameRunning == true) {
			switch (nChar) {
			case'q':
			case'Q':
				if (!AutoFire)
					AutoFire = true;
				else
					AutoFire = false;
				Invalidate();
				break;
			case 'p':
			case'P':
				GameRunning = false;
				Invalidate();
				break;
			case 'b':
			case 'B':
				sndPlaySound(strDir1 + snd_FireBomb, SND_ASYNC);
				m_Player.FireBomb();
				Invalidate();
				break;
			case 'l':
			case 'L':
				sndPlaySound(strDir1 + snd_Laser, SND_ASYNC);
				m_Player.FireLaser();
				Invalidate();
				break;
			default:
				break;
			}
		}
		else {
			if (nChar == 'p' || nChar == 'P') {
				GameRunning = true;
				Invalidate();
			}
		}
	}
	if (GameFail == true) {
		if (nChar == 'y' || nChar == 'Y') {
			m_Player.ClearShell();
			m_Player.ClearBomb();
			m_Player.SetHP(m_Player.GetIniHP());
			m_vecSmaEnemy.clear();
			m_vecMidEnemy.clear();
			m_vecHugEnemy.clear();
			m_Player.SetPos((m_BKG.GetLeft() + m_BKG.GetRight()) / 2, m_BKG.GetDown());
			GameFail = false;
			GameRunning = true;
			Invalidate();
		}
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}
