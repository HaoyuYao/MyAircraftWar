#pragma once
#include <string>
typedef CImage* pCImage;
class PlayBKG
{
public:
	PlayBKG() {
		LoadmyImage(m_img, "\\images\\ui\\background.jpg", LoadingImg);
		LoadmyImage(m_img_stkey_untcd, "\\images\\ui\\start_key_untcd1.png", LoadingStartKey_untcd);
		LoadmyImage(m_img_stkey_tcd, "\\images\\ui\\start_key_tcd1.png", LoadingStartKey_tcd);
		LoadmyImage(m_img_psbox,"\\images\\ui\\pausebox.png",LoadingPauseBox);
		LoadmyImage(m_img_pskey_untcd, "\\images\\ui\\pause_key_untcd1.png", LoadingPauseKey_untcd);
		LoadmyImage(m_img_pskey_tcd,"\\images\\ui\\pause_key_tcd1.png",LoadingPauseKey_tcd);
		LoadmyImage(m_img_ctnkey_untcd, "\\images\\ui\\continue_key_untcd1.png", LoadingContinueKey_untcd);
		LoadmyImage(m_img_ctnkey_tcd, "\\images\\ui\\continue_key_tcd1.png", LoadingContinueKey_tcd);
		LoadmyImage(m_img_rstkey_untcd, "\\images\\ui\\restart_key_unctd1.png", LoadingRestartKey_untcd);
		LoadmyImage(m_img_rstkey_tcd, "\\images\\ui\\restart_key_ctd1.png", LoadingRestartKey_tcd);
		LoadmyImage(m_img_homkey_untcd, "\\images\\ui\\home_key_untcd.png", LoadingHomeKey_untcd);
		LoadmyImage(m_img_homkey_tcd, "\\images\\ui\\home_key_tcd.png", LoadingHomeKey_tcd);
		LoadmyImage(m_img_rukey_untcd, "\\images\\ui\\rule_key_untcd.png", LoadingRuleKey_untcd);
		LoadmyImage(m_img_rukey_tcd, "\\images\\ui\\rule_key_tcd.png", LoadingRuleKey_tcd);
		LoadmyImage(m_img_rukey_untcd2, "\\images\\ui\\rule_key_untcd2.png", LoadingRuleKey_untcd2);
		LoadmyImage(m_img_rukey_tcd2, "\\images\\ui\\rule_key_tcd2.png", LoadingRuleKey_tcd2);
		LoadmyImage(m_img_stgkey_untcd, "\\images\\ui\\strong_key_untcd.png", LoadingStrongKey_untcd);
		LoadmyImage(m_img_stgkey_tcd, "\\images\\ui\\strong_key_tcd.png", LoadingStrongKey_tcd);
		LoadmyImage(m_img_stgbox, "\\images\\ui\\strongbox.png", LoadingStrongBox);
		LoadmyImage(m_img_rubox, "\\images\\ui\\rulebox.jpg", LoadingRuleBox);
		LoadmyImage(m_img_pause, "\\images\\ui\\paused.png", LoadingPauseImg);
		LoadmyImage(m_img_over, "\\images\\ui\\gameover.png", LoadingOverImg);
		SetTimer(0);
	};
	~PlayBKG() {};
public:
	void Show(CDC* pDC);
	void LoadmyImage(pCImage& m_img, std::string strPlus, bool& LoadingImg) {
		m_img = new CImage;
		TCHAR cDir[1024];
		GetModuleFileName(NULL, cDir, 1024);
		CString strDir(cDir);
		strDir = strDir.Left(strDir.ReverseFind('\\'));
		strDir += strPlus.c_str();
		m_img->Load(strDir);
		if (m_img->IsNull())
			LoadingImg = false;
		LoadingImg = true;
	}
	void ShowStartKey(CDC* pDC);
	void ShowPauseBox(CDC* pDC);
	void ShowPauseKey(CDC* pDC);
	void ShowContinueKey(CDC* pDC);
	void ShowRestartKey(CDC* pDC);
	void ShowHomeKey(CDC* pDC);
	void ShowRuleKey(CDC* pDC);
	void ShowStrongKey(CDC* pDC);
	void ShowRuleKey2(CDC* pDC);
	void ShowRuleBox(CDC* pDC);
	void ShowStrongBox(CDC* pDC);
	void ShowPause(CDC* pDC);
	void ShowOver(CDC* pDC);
	bool JudgeTouched(int x, int y, int left, int up, int right, int down) {
		bool Judge;
		if (x >= left && x <= right && y >= up && y <= down)Judge = true;
		else Judge = false;
		return Judge;
	}
	void GetBorder(int& left, int& up, int& right, int& down) {
		left = m_LeftBorder;
		up = m_UpBorder;
		right = m_RightBorder;
		down = m_DownBorder;
	}
	void SetMouse(int x, int y) {
		mouseX = x;
		mouseY = y;
	}
	int GetLeft() {
		return m_LeftBorder;
	}
	int GetUp() {
		return m_UpBorder;
	}
	int GetRight() {
		return m_RightBorder;
	}
	int GetDown() {
		return m_DownBorder;
	}
	int GetStartKeyLeft() {
		return StKeyLeft;
	}
	int GetStartKeyUp() {
		return StKeyUp;
	}
	int GetStartKeyRight() {
		return StKeyRight;
	}
	int GetStartKeyDown() {
		return StKeyDown;
	}
	int GetPauseLeft() {
		return PsBoxLeft;
	}
	int GetPauseUp() {
		return PsBoxUp;
	}
	int GetPauseRight() {
		return PsBoxRight;
	}
	int GetPauseDown() {
		return PsBoxDown;
	}
	int GetPauseKeyLeft() {
		return PsKeyLeft;
	}
	int GetPauseKeyUp() {
		return PsKeyUp;
	}
	int GetPauseKeyRight() {
		return PsKeyRight;
	}
	int GetPauseKeyDown() {
		return PsKeyDown;
	}
	int GetContinueKeyLeft() {
		return CtnKeyLeft;
	}
	int GetContinueKeyUp() {
		return CtnKeyUp;
	}
	int GetContinueKeyRight() {
		return CtnKeyRight;
	}
	int GetContinueKeyDown() {
		return CtnKeyDown;
	}
	int GetRestartKeyLeft() {
		return RstKeyLeft;
	}
	int GetRestartKeyUp() {
		return RstKeyUp;
	}
	int GetRestartKeyRight() {
		return RstKeyRight;
	}
	int GetRestartKeyDown() {
		return RstKeyDown;
	}
	int GetHomeKeyLeft() {
		return HomKeyLeft;
	}
	int GetHomeKeyUp() {
		return HomKeyUp;
	}
	int GetHomeKeyRight() {
		return HomKeyRight;
	}
	int GetHomeKeyDown() {
		return HomKeyDown;
	}
	int GetRuleKeyLeft() {
		return RuKeyLeft;
	}
	int GetRuleKeyUp() {
		return RuKeyUp;
	}
	int GetRuleKeyRight() {
		return RuKeyRight;
	}
	int GetRuleKeyDown() {
		return RuKeyDown;
	}
	int GetRuleBoxLeft() {
		return RuBoxLeft;
	}
	int GetRuleBoxUp() {
		return RuBoxUp;
	}
	int GetRuleBoxRight() {
		return RuBoxRight;
	}
	int GetRuleBoxDown() {
		return RuBoxDown;
	}
	void SetTimer(int timer) {
		Timer = timer;
	}
	int GetTimer() {
		return Timer;
	}
	int GetRuleKeyLeft2() {
		return RuKeyLeft2;
	}
	int GetRuleKeyUp2() {
		return RuKeyUp2;
	}
	int GetRuleKeyRight2() {
		return RuKeyRight2;
	}
	int GetRuleKeyDown2() {
		return RuKeyDown2;
	}
	int GetStrongKeyLeft() {
		return StgKeyLeft;
	}
	int GetStrongKeyUp() {
		return StgKeyUp;
	}
	int GetStrongKeyRight() {
		return StgKeyRight;
	}
	int GetStrongKeyDown() {
		return StgKeyDown;
	}
	int GetStrongBoxLeft() {
		return StgBoxLeft;
	}
	int GetStrongBoxUp() {
		return StgBoxUp;
	}
	int GetStrongBoxRight() {
		return StgBoxRight;
	}
	int GetStrongBoxDown() {
		return StgBoxDown;
	}
protected:
	int mouseX = 0, mouseY = 0;
	int m_UpBorder = 10;
	int m_DownBorder = 710;
	int m_LeftBorder = 10;
	int m_RightBorder = 890;
	int m_Width = m_RightBorder - m_LeftBorder;//880
	int m_Height = m_DownBorder - m_UpBorder;//700
	CImage* m_img = new CImage;
	bool LoadingImg = false;
protected:
	int StKeyLeft = m_LeftBorder + m_Width / 2 - 130;//
	int StKeyRight = m_LeftBorder + m_Width / 2 + 130;//
	int StKeyUp = m_UpBorder + m_Height / 2 - 50-100;
	int StKeyDown = m_UpBorder + m_Height / 2 + 50-100;
	CImage* m_img_stkey_untcd = new CImage;
	CImage* m_img_stkey_tcd = new CImage;
	bool LoadingStartKey_tcd = false;
	bool LoadingStartKey_untcd = false;
protected:
	int RuKeyLeft = m_LeftBorder + m_Width / 2 - 130;
	int RuKeyRight = m_LeftBorder + m_Width / 2 + 130;
	int RuKeyUp = m_UpBorder + m_Height / 2 - 50+100;
	int RuKeyDown = m_UpBorder + m_Height / 2 + 50+100;

	int RuKey2Width = 120;
	int RuKey2Height = 70;
	int RuKeyLeft2 = m_RightBorder-RuKey2Width - 70;
	int RuKeyRight2 = m_RightBorder - 70;
	int RuKeyUp2= m_DownBorder - 5 - RuKey2Height;
	int RuKeyDown2= m_DownBorder - 5;
	CImage* m_img_rukey_untcd = new CImage;
	CImage* m_img_rukey_tcd = new CImage;
	bool LoadingRuleKey_tcd = false;
	bool LoadingRuleKey_untcd = false;
	CImage* m_img_rukey_untcd2 = new CImage;
	CImage* m_img_rukey_tcd2 = new CImage;
	bool LoadingRuleKey_tcd2 = false;
	bool LoadingRuleKey_untcd2 = false;
protected:
	int RuBoxWidth = 590;
	int RuBoxHeight = 650;
	int RuBoxLeft = m_RightBorder + 10;
	int RuBoxUp = m_UpBorder;
	int RuBoxRight = RuBoxLeft + RuBoxWidth;
	int RuBoxDown = RuBoxUp + RuBoxHeight;
	CImage* m_img_rubox = new CImage;
	bool LoadingRuleBox = false;
	COLORREF clr_ruboxb = RGB(1, 2, 3);
protected:
	int PsBoxLeft = m_LeftBorder + m_Width / 2 - 250;
	int PsBoxRight = m_LeftBorder + m_Width / 2 + 250;
	int PsBoxUp = m_UpBorder + m_Height / 2 - 120;
	int PsBoxDown = m_UpBorder + m_Height / 2 + 120;
	CImage* m_img_psbox = new CImage;
	bool LoadingPauseBox = false;
	int gray = 127;
	COLORREF clr = RGB(101, 45, 30);
protected:
	int PsKeySize = 60;
	int PsKeyLeft = m_RightBorder - 5 - PsKeySize;
	int PsKeyRight = m_RightBorder - 5;
	int PsKeyUp = m_DownBorder - 5 - PsKeySize;
	int PsKeyDown = m_DownBorder -5;
	CImage* m_img_pskey_untcd = new CImage;
	CImage* m_img_pskey_tcd = new CImage;
	bool LoadingPauseKey_untcd = false;
	bool LoadingPauseKey_tcd = false;
protected:
	int CtnKeySize = 60;
	int CtnKeyLeft = (PsBoxLeft + PsBoxRight)/2 - CtnKeySize / 2;
	int CtnKeyRight= (PsBoxLeft + PsBoxRight) / 2 + CtnKeySize / 2;
	int CtnKeyUp = (PsBoxUp + PsBoxDown) / 2 - CtnKeySize / 2;
	int CtnKeyDown= (PsBoxUp + PsBoxDown) / 2 + CtnKeySize / 2;
	CImage* m_img_ctnkey_untcd = new CImage;
	CImage* m_img_ctnkey_tcd = new CImage;
	bool LoadingContinueKey_untcd = false;
	bool LoadingContinueKey_tcd = false;
protected:
	int RstKeySize = 60;
	int RstKeyLeft = CtnKeyLeft - CtnKeySize - RstKeySize / 2;
	int RstKeyRight = CtnKeyLeft - CtnKeySize + RstKeySize / 2;
	int RstKeyUp = (PsBoxUp + PsBoxDown) / 2 - RstKeySize / 2;
	int RstKeyDown = (PsBoxUp + PsBoxDown) / 2 + RstKeySize / 2;
	CImage* m_img_rstkey_untcd = new CImage;
	CImage* m_img_rstkey_tcd = new CImage;
	bool LoadingRestartKey_untcd = false;
	bool LoadingRestartKey_tcd = false;
protected:
	int HomKeySize = 60;
	int HomKeyLeft = CtnKeyRight + CtnKeySize - RstKeySize / 2;
	int HomKeyRight = CtnKeyRight + CtnKeySize + RstKeySize / 2;
	int HomKeyUp = (PsBoxUp + PsBoxDown) / 2 - HomKeySize / 2;
	int HomKeyDown = (PsBoxUp + PsBoxDown) / 2 + HomKeySize / 2;
	CImage* m_img_homkey_untcd = new CImage;
	CImage* m_img_homkey_tcd = new CImage;
	bool LoadingHomeKey_untcd = false;
	bool LoadingHomeKey_tcd = false;
protected:
	int PauseWidth = 106*2;
	int PauseHeight = 34*2;
	int PauseLeft = (PsBoxLeft + PsBoxRight) / 2 - PauseWidth / 2+15;
	int PauseRight= (PsBoxLeft + PsBoxRight) / 2 + PauseWidth / 2+15;
	int PauseUp = PsBoxUp;
	int PauseDown= PsBoxUp + PauseHeight;
	CImage* m_img_pause = new CImage;
	bool LoadingPauseImg = false;
	CImage* m_img_over = new CImage;
	bool LoadingOverImg = false;
protected:
	int StgKeyWidth = 120;
	int StgKeyHeight = 70;
	int StgKeyLeft = m_RightBorder - RuKey2Width -StgKeyWidth- 70-10;
	int StgKeyRight = m_RightBorder - 70-RuKey2Width-10;
	int StgKeyUp = m_DownBorder - 5 - StgKeyHeight;
	int StgKeyDown = m_DownBorder - 5;
	CImage* m_img_stgkey_untcd = new CImage;
	CImage* m_img_stgkey_tcd = new CImage;
	bool LoadingStrongKey_tcd = false;
	bool LoadingStrongKey_untcd = false;
protected:
	int StgBoxWidth = 330;
	int StgBoxHeight = 450;
	int StgBoxLeft = m_RightBorder + RuBoxWidth/2-StgBoxWidth/2;
	int StgBoxUp = m_UpBorder+RuBoxHeight/2-StgBoxHeight/2;
	int StgBoxRight = m_RightBorder + RuBoxWidth / 2 + StgBoxWidth / 2;
	int StgBoxDown = m_UpBorder + RuBoxHeight / 2 + StgBoxHeight / 2;
	CImage* m_img_stgbox = new CImage;
	bool LoadingStrongBox = false;
	COLORREF clr_stgbox = RGB(1, 2, 3);
protected:
	int Timer = 0;
	int MaxTime = 100;
};
