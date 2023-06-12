#include "pch.h"
#include "Objects.h"

void Objects::Show(CDC* pDC) {
	if (m_img->IsNull() || !LoadingImg) {
		pDC->Ellipse(m_x - m_nR, m_y - m_nR, m_x + m_nR, m_y + m_nR);
	}
	else {
		pDC->SetStretchBltMode(HALFTONE);//ÑÕÉ«ÓÅ»¯
		CRect img_rct(m_x - m_imgWidth / 2, m_y - m_imgHeight / 2,
			m_x + m_imgWidth / 2, m_y + m_imgHeight);
		m_img->Draw(pDC->GetSafeHdc(), img_rct);
	}
}

void Objects::LoadmyImage(pCImage& m_img,std::string strPlus,bool& LoadingImg) {
	m_img = new CImage;
	TCHAR cDir[1024];
	GetModuleFileName(NULL, cDir, 1024);
	CString strDir(cDir);
	strDir = strDir.Left(strDir.ReverseFind('\\'));
	strDir += strPlus.c_str();
	m_img->Load(strDir);
	if (m_img->IsNull())
		LoadingImg = false;
	else
		LoadingImg = true;
}

void Objects::UpdatePos(int nDir) {};