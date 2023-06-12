#include "pch.h"
#include "PlayBKG.h"

void PlayBKG::Show(CDC* pDC) {
	if (m_img == nullptr || m_img->IsNull() || !LoadingImg) {
		pDC->Rectangle(m_LeftBorder, m_UpBorder, m_RightBorder, m_DownBorder);
	}
	else {
		pDC->SetStretchBltMode(HALFTONE);//颜色优化
		CRect img_rct(m_LeftBorder, m_UpBorder, m_RightBorder, m_DownBorder);
		m_img->Draw(pDC->GetSafeHdc(), img_rct);
	}
	Timer++;
	if (Timer >= MaxTime)Timer = 0;
}

//bool PlayBKG::LoadBKImage(std::string Dir) {
//	TCHAR cDir[1024];
//	GetModuleFileName(NULL, cDir, 1024);
//	CString strDir(cDir);
//	strDir = strDir.Left(strDir.ReverseFind('\\'));
//	strDir += Dir.c_str();
//	m_img->Load(strDir);
//	if (m_img->IsNull())
//		return false;
//	return true;
//}

void PlayBKG::ShowStartKey(CDC* pDC) {
	if (m_img_stkey_untcd->IsNull() || m_img_stkey_tcd->IsNull() || !LoadingStartKey_tcd || !LoadingStartKey_untcd) {
		pDC->Rectangle(StKeyLeft, StKeyUp, StKeyRight, StKeyDown);
	}
	else {
		pDC->SetStretchBltMode(HALFTONE);//颜色优化
		int touch = JudgeTouched(mouseX, mouseY, StKeyLeft, StKeyUp, StKeyRight, StKeyDown);
		CRect stkey_rct(StKeyLeft, StKeyUp, StKeyRight, StKeyDown);
		if (!touch)m_img_stkey_untcd->Draw(pDC->GetSafeHdc(), stkey_rct);
		else m_img_stkey_tcd->Draw(pDC->GetSafeHdc(), stkey_rct);
	}
}

void PlayBKG::ShowPauseBox(CDC* pDC) {
	if (m_img_psbox == nullptr || m_img_psbox->IsNull() || !LoadingPauseBox) {
		pDC->Rectangle(PsBoxLeft, PsBoxUp, PsBoxRight, PsBoxDown);
	}
	else {
		pDC->SetStretchBltMode(HALFTONE);//颜色优化
		CRect pause_rct(PsBoxLeft, PsBoxUp, PsBoxRight, PsBoxDown);
		m_img_psbox->Draw(pDC->GetSafeHdc(), pause_rct);
	}
	//CPen pen;
	//pen.CreatePen(PS_SOLID, 8, clr);
	//CPen* oldPen = pDC->SelectObject(&pen);
	//pDC->SelectStockObject(NULL_BRUSH);	//将笔刷调为透明，以便显示背景
	//pDC->Rectangle(PsBoxLeft, PsBoxUp, PsBoxRight, PsBoxDown);
	//pDC->SelectObject(oldPen);
	//pen.DeleteObject();
}

void PlayBKG::ShowPauseKey(CDC* pDC) {
	if (m_img_pskey_untcd->IsNull() || m_img_pskey_tcd->IsNull() || !LoadingPauseKey_tcd || !LoadingPauseKey_untcd) {
		pDC->Rectangle(PsKeyLeft, PsKeyUp, PsKeyRight, PsKeyDown);
	}
	else {
		pDC->SetStretchBltMode(HALFTONE);//颜色优化
		int touch = JudgeTouched(mouseX, mouseY, PsKeyLeft, PsKeyUp, PsKeyRight, PsKeyDown);
		CRect pskey_rct(PsKeyLeft, PsKeyUp, PsKeyRight, PsKeyDown);
		if (!touch)m_img_pskey_untcd->Draw(pDC->GetSafeHdc(), pskey_rct);
		else m_img_pskey_tcd->Draw(pDC->GetSafeHdc(), pskey_rct);
	}
}

void PlayBKG::ShowContinueKey(CDC* pDC) {
	if (m_img_ctnkey_untcd->IsNull() || m_img_ctnkey_tcd->IsNull() || !LoadingContinueKey_tcd || !LoadingContinueKey_untcd) {
		pDC->Rectangle(CtnKeyLeft, CtnKeyUp, CtnKeyRight, CtnKeyDown);
	}
	else {
		pDC->SetStretchBltMode(HALFTONE);//颜色优化
		int touch = JudgeTouched(mouseX, mouseY, CtnKeyLeft, CtnKeyUp, CtnKeyRight, CtnKeyDown);
		CRect ctnkey_rct(CtnKeyLeft, CtnKeyUp, CtnKeyRight, CtnKeyDown);
		if (!touch)m_img_ctnkey_untcd->Draw(pDC->GetSafeHdc(), ctnkey_rct);
		else m_img_ctnkey_tcd->Draw(pDC->GetSafeHdc(), ctnkey_rct);
	}
}

void PlayBKG::ShowRestartKey(CDC* pDC) {
	if (m_img_rstkey_untcd->IsNull() || m_img_rstkey_tcd->IsNull() || !LoadingRestartKey_tcd || !LoadingRestartKey_untcd) {
		pDC->Rectangle(RstKeyLeft, RstKeyUp, RstKeyRight, RstKeyDown);
	}
	else {
		pDC->SetStretchBltMode(HALFTONE);//颜色优化
		int touch = JudgeTouched(mouseX, mouseY, RstKeyLeft, RstKeyUp, RstKeyRight, RstKeyDown);
		CRect rstkey_rct(RstKeyLeft, RstKeyUp, RstKeyRight, RstKeyDown);
		if (!touch)m_img_rstkey_untcd->Draw(pDC->GetSafeHdc(), rstkey_rct);
		else m_img_rstkey_tcd->Draw(pDC->GetSafeHdc(), rstkey_rct);
	}
}

void PlayBKG::ShowHomeKey(CDC* pDC) {
	if (m_img_homkey_untcd->IsNull() || m_img_homkey_tcd->IsNull() || !LoadingHomeKey_tcd || !LoadingHomeKey_untcd) {
		pDC->Rectangle(HomKeyLeft, HomKeyUp, HomKeyRight, HomKeyDown);
	}
	else {
		pDC->SetStretchBltMode(HALFTONE);//颜色优化
		int touch = JudgeTouched(mouseX, mouseY, HomKeyLeft, HomKeyUp, HomKeyRight, HomKeyDown);
		CRect homkey_rct(HomKeyLeft, HomKeyUp, HomKeyRight, HomKeyDown);
		if (!touch)m_img_homkey_untcd->Draw(pDC->GetSafeHdc(), homkey_rct);
		else m_img_homkey_tcd->Draw(pDC->GetSafeHdc(), homkey_rct);
	}
}

void PlayBKG::ShowRuleKey(CDC* pDC) {
	if (m_img_rukey_untcd->IsNull() || m_img_rukey_tcd->IsNull() || !LoadingRuleKey_tcd || !LoadingRuleKey_untcd) {
		pDC->Rectangle(RuKeyLeft, RuKeyUp, RuKeyRight, RuKeyDown);
	}
	else {
		pDC->SetStretchBltMode(HALFTONE);//颜色优化
		int touch = JudgeTouched(mouseX, mouseY, RuKeyLeft, RuKeyUp, RuKeyRight, RuKeyDown);
		CRect rukey_rct(RuKeyLeft, RuKeyUp, RuKeyRight, RuKeyDown);
		if (!touch)m_img_rukey_untcd->Draw(pDC->GetSafeHdc(), rukey_rct);
		else m_img_rukey_tcd->Draw(pDC->GetSafeHdc(), rukey_rct);
	}
}
void PlayBKG::ShowRuleKey2(CDC* pDC) {
	if (m_img_rukey_untcd2->IsNull() || m_img_rukey_tcd2->IsNull() || !LoadingRuleKey_tcd2 || !LoadingRuleKey_untcd2) {
		pDC->Rectangle(RuKeyLeft2, RuKeyUp2, RuKeyRight2, RuKeyDown2);
	}
	else {
		pDC->SetStretchBltMode(HALFTONE);//颜色优化
		int touch = JudgeTouched(mouseX, mouseY, RuKeyLeft2, RuKeyUp2, RuKeyRight2, RuKeyDown2);
		CRect rukey_rct2(RuKeyLeft2, RuKeyUp2, RuKeyRight2, RuKeyDown2);
		if (!touch)m_img_rukey_untcd2->Draw(pDC->GetSafeHdc(), rukey_rct2);
		else m_img_rukey_tcd2->Draw(pDC->GetSafeHdc(), rukey_rct2);
	}
}

void PlayBKG::ShowRuleBox(CDC* pDC) {
	if (m_img_rubox == nullptr || m_img_rubox->IsNull() || !LoadingRuleBox) {
		pDC->Rectangle(RuBoxLeft, RuBoxUp, RuBoxRight, RuBoxDown);
	}
	else {
		pDC->SetStretchBltMode(HALFTONE);//颜色优化
		CRect rule_rct(RuBoxLeft, RuBoxUp, RuBoxRight, RuBoxDown);
		m_img_rubox->Draw(pDC->GetSafeHdc(), rule_rct);
	}
	CPen pen;
	pen.CreatePen(PS_SOLID, 8, clr_ruboxb);
	CPen* oldPen = pDC->SelectObject(&pen);
	pDC->SelectStockObject(NULL_BRUSH);	//将笔刷调为透明，以便显示背景
	pDC->Rectangle(RuBoxLeft, RuBoxUp, RuBoxRight, RuBoxDown);
	pDC->SelectObject(oldPen);
	pen.DeleteObject();
}

void PlayBKG::ShowPause(CDC* pDC) {
	if (m_img_pause == nullptr || m_img_pause->IsNull() || !LoadingPauseImg) {
		pDC->Rectangle(PauseLeft, PauseUp, PauseRight, PauseDown);
	}
	else {
		pDC->SetStretchBltMode(HALFTONE);//颜色优化
		CRect paused_rct(PauseLeft, PauseUp, PauseRight, PauseDown);
		m_img_pause->Draw(pDC->GetSafeHdc(), paused_rct);
	}
}

void PlayBKG::ShowOver(CDC* pDC) {
	if (m_img_over == nullptr || m_img_over->IsNull() || !LoadingOverImg) {
		pDC->Rectangle(PauseLeft, PauseUp, PauseRight, PauseDown);
	}
	else {
		pDC->SetStretchBltMode(HALFTONE);//颜色优化
		CRect over_rct(PauseLeft, PauseUp, PauseRight, PauseDown);
		m_img_over->Draw(pDC->GetSafeHdc(), over_rct);
	}
}

void PlayBKG::ShowStrongKey(CDC* pDC) {
	if (m_img_stgkey_untcd->IsNull() || m_img_stgkey_tcd->IsNull() || !LoadingStrongKey_tcd || !LoadingStrongKey_untcd) {
		pDC->Rectangle(StgKeyLeft, StgKeyUp, StgKeyRight, StgKeyDown);
	}
	else {
		pDC->SetStretchBltMode(HALFTONE);//颜色优化
		int touch = JudgeTouched(mouseX, mouseY, StgKeyLeft, StgKeyUp, StgKeyRight, StgKeyDown);
		CRect stgkey_rct(StgKeyLeft, StgKeyUp, StgKeyRight, StgKeyDown);
		if (!touch)m_img_stgkey_untcd->Draw(pDC->GetSafeHdc(), stgkey_rct);
		else m_img_stgkey_tcd->Draw(pDC->GetSafeHdc(), stgkey_rct);
	}
}

void PlayBKG::ShowStrongBox(CDC* pDC) {
	if (m_img_stgbox == nullptr || m_img_stgbox->IsNull() || !LoadingStrongBox) {
		pDC->Rectangle(StgBoxLeft, StgBoxUp, StgBoxRight, StgBoxDown);
	}
	else {
		pDC->SetStretchBltMode(HALFTONE);//颜色优化
		CRect strong_rct(StgBoxLeft, StgBoxUp, StgBoxRight, StgBoxDown);
		m_img_stgbox->Draw(pDC->GetSafeHdc(), strong_rct);
	}
	CPen pen;
	pen.CreatePen(PS_SOLID, 8, clr_stgbox);
	CPen* oldPen = pDC->SelectObject(&pen);
	pDC->SelectStockObject(NULL_BRUSH);	//将笔刷调为透明，以便显示背景
	pDC->Rectangle(StgBoxLeft, StgBoxUp, StgBoxRight, StgBoxDown);
	pDC->SelectObject(oldPen);
	pen.DeleteObject();
}