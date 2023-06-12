#pragma once
#include "Objects.h"
#include "DamNum.h"
#include <vector>
class DamNumber :
    public Objects
{
public:
    DamNumber() {
        LoadmyImage(img_edam0, "\\images\\num\\edam0.png", LoadingEDam0);
        LoadmyImage(img_edam1, "\\images\\num\\edam1.png", LoadingEDam1);
        LoadmyImage(img_edam2, "\\images\\num\\edam2.png", LoadingEDam2);
        LoadmyImage(img_edam3, "\\images\\num\\edam3.png", LoadingEDam3);
        LoadmyImage(img_edam4, "\\images\\num\\edam4.png", LoadingEDam4);
        LoadmyImage(img_edam5, "\\images\\num\\edam5.png", LoadingEDam5);
        LoadmyImage(img_edam6, "\\images\\num\\edam6.png", LoadingEDam6);
        LoadmyImage(img_edam7, "\\images\\num\\edam7.png", LoadingEDam7);
        LoadmyImage(img_edam8, "\\images\\num\\edam8.png", LoadingEDam8);
        LoadmyImage(img_edam9, "\\images\\num\\edam9.png", LoadingEDam9);

        LoadmyImage(img_pdam0, "\\images\\num\\pdam0.png", LoadingPDam0);
        LoadmyImage(img_pdam1, "\\images\\num\\pdam1.png", LoadingPDam1);
        LoadmyImage(img_pdam2, "\\images\\num\\pdam2.png", LoadingPDam2);
        LoadmyImage(img_pdam3, "\\images\\num\\pdam3.png", LoadingPDam3);
        LoadmyImage(img_pdam4, "\\images\\num\\pdam4.png", LoadingPDam4);
        LoadmyImage(img_pdam5, "\\images\\num\\pdam5.png", LoadingPDam5);
        LoadmyImage(img_pdam6, "\\images\\num\\pdam6.png", LoadingPDam6);
        LoadmyImage(img_pdam7, "\\images\\num\\pdam7.png", LoadingPDam7);
        LoadmyImage(img_pdam8, "\\images\\num\\pdam8.png", LoadingPDam8);
        LoadmyImage(img_pdam9, "\\images\\num\\pdam9.png", LoadingPDam9);

        LoadmyImage(img_phea0, "\\images\\num\\heal0.png", LoadingPHea0);
        LoadmyImage(img_phea1, "\\images\\num\\heal1.png", LoadingPHea1);
        LoadmyImage(img_phea2, "\\images\\num\\heal2.png", LoadingPHea2);
        LoadmyImage(img_phea3, "\\images\\num\\heal3.png", LoadingPHea3);
        LoadmyImage(img_phea4, "\\images\\num\\heal4.png", LoadingPHea4);
        LoadmyImage(img_phea5, "\\images\\num\\heal5.png", LoadingPHea5);
        LoadmyImage(img_phea6, "\\images\\num\\heal6.png", LoadingPHea6);
        LoadmyImage(img_phea7, "\\images\\num\\heal7.png", LoadingPHea7);
        LoadmyImage(img_phea8, "\\images\\num\\heal8.png", LoadingPHea8);
        LoadmyImage(img_phea9, "\\images\\num\\heal9.png", LoadingPHea9);

        SetSize(20);
    };
    ~DamNumber() {};
public:
    void ShowEDam(CDC* pDC) {
        int k = 0;
        for (auto& m_Num : m_vecPt_Edam) {
            CRect img_rct(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
            if (m_Num.GetTimer() < Lasting) {
                switch (m_Num.GetNum()) {
                case 0:
                    if (img_edam0->IsNull() || !LoadingEDam0) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_edam0->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 1:
                    if (img_edam1->IsNull() || !LoadingEDam1) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_edam1->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 2:
                    if (img_edam2->IsNull() || !LoadingEDam2) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_edam2->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 3:
                    if (img_edam3->IsNull() || !LoadingEDam3) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_edam3->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 4:
                    if (img_edam4->IsNull() || !LoadingEDam4) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_edam4->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 5:
                    if (img_edam5->IsNull() || !LoadingEDam5) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_edam5->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 6:
                    if (img_edam6->IsNull() || !LoadingEDam6) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_edam6->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 7:
                    if (img_edam7->IsNull() || !LoadingEDam7) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_edam7->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 8:
                    if (img_edam8->IsNull() || !LoadingEDam8) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_edam8->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 9:
                    if (img_edam9->IsNull() || !LoadingEDam9) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_edam9->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                default:
                    pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    break;
                }
                k++;
                m_Num.UpdateTimer();
            }
            else {
                m_vecPt_Edam.erase(m_vecPt_Edam.begin() + k);
            }
        }
    }
    void ShowPDam(CDC* pDC) {
        int k = 0;
        for (auto& m_Num : m_vecPt_Pdam) {
            CRect img_rct(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
            if (m_Num.GetTimer() < Lasting) {
                switch (m_Num.GetNum()) {
                case 0:
                    if (img_pdam0->IsNull() || !LoadingPDam0) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_pdam0->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 1:
                    if (img_pdam1->IsNull() || !LoadingPDam1) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_pdam1->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 2:
                    if (img_pdam2->IsNull() || !LoadingPDam2) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_pdam2->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 3:
                    if (img_pdam3->IsNull() || !LoadingPDam3) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_pdam3->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 4:
                    if (img_pdam4->IsNull() || !LoadingPDam4) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_pdam4->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 5:
                    if (img_pdam5->IsNull() || !LoadingPDam5) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_pdam5->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 6:
                    if (img_pdam6->IsNull() || !LoadingPDam6) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_pdam6->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 7:
                    if (img_pdam7->IsNull() || !LoadingPDam7) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_pdam7->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 8:
                    if (img_pdam8->IsNull() || !LoadingPDam8) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_pdam8->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 9:
                    if (img_pdam9->IsNull() || !LoadingPDam9) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_pdam9->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                default:
                    pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    break;
                }
                k++;
                m_Num.UpdateTimer();
            }
            else {
                m_vecPt_Pdam.erase(m_vecPt_Pdam.begin() + k);
            }
        }
    }
    void ShowHeal(CDC* pDC) {
        int k = 0;
        for (auto& m_Num : m_vecPt_Phea) {
            CRect img_rct(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
            if (m_Num.GetTimer() < Lasting) {
                switch (m_Num.GetNum()) {
                case 0:
                    if (img_phea0->IsNull() || !LoadingPHea0) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_phea0->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 1:
                    if (img_phea1->IsNull() || !LoadingPHea1) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_phea1->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 2:
                    if (img_phea2->IsNull() || !LoadingPHea2) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_phea2->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 3:
                    if (img_phea3->IsNull() || !LoadingPHea3) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_phea3->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 4:
                    if (img_phea4->IsNull() || !LoadingPHea4) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_phea4->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 5:
                    if (img_phea5->IsNull() || !LoadingPHea5) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_phea5->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 6:
                    if (img_phea6->IsNull() || !LoadingPHea6) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_phea6->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 7:
                    if (img_phea7->IsNull() || !LoadingPHea7) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_phea7->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 8:
                    if (img_phea8->IsNull() || !LoadingPHea8) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_phea8->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                case 9:
                    if (img_phea9->IsNull() || !LoadingPHea9) {
                        pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    }
                    else {
                        pDC->SetStretchBltMode(HALFTONE);//颜色优化
                        img_phea9->Draw(pDC->GetSafeHdc(), img_rct);
                    }
                    break;
                default:
                    pDC->Ellipse(m_Num.GetX() - m_nR, m_Num.GetY() - m_nR, m_Num.GetX() + m_nR, m_Num.GetY() + m_nR);
                    break;
                }
                k++;
                m_Num.UpdateTimer();
            }
            else {
                m_vecPt_Phea.erase(m_vecPt_Phea.begin() + k);
            }
        }
    }
    void OccurEDam(int x, int y, int num) {
        int r = rand() % 60;
        m_Num.SetX(x+r);
        m_Num.SetY(y);
        m_Num.SetNum(num);
        m_vecPt_Edam.push_back(m_Num);
    }
    void OccurPDam(int x, int y, int num) {
        int r = rand() % 60;
        m_Num.SetX(x + r);
        m_Num.SetY(y);
        m_Num.SetNum(num);
        m_vecPt_Pdam.push_back(m_Num);
    }
    void OccurPHea(int x, int y, int num) {
        int r = rand() % 60;
        m_Num.SetX(x + r);
        m_Num.SetY(y);
        m_Num.SetNum(num);
        m_vecPt_Phea.push_back(m_Num);
    }
protected:
    CImage* img_edam0 = new CImage;
    CImage* img_edam1 = new CImage;
    CImage* img_edam2 = new CImage;
    CImage* img_edam3 = new CImage;
    CImage* img_edam4 = new CImage;
    CImage* img_edam5 = new CImage;
    CImage* img_edam6 = new CImage;
    CImage* img_edam7 = new CImage;
    CImage* img_edam8 = new CImage;
    CImage* img_edam9 = new CImage;
    bool LoadingEDam0 = false;
    bool LoadingEDam1 = false;
    bool LoadingEDam2 = false;
    bool LoadingEDam3 = false;
    bool LoadingEDam4 = false;
    bool LoadingEDam5 = false;
    bool LoadingEDam6 = false;
    bool LoadingEDam7 = false;
    bool LoadingEDam8 = false;
    bool LoadingEDam9 = false;
protected:
    CImage* img_pdam0 = new CImage;
    CImage* img_pdam1 = new CImage;
    CImage* img_pdam2 = new CImage;
    CImage* img_pdam3 = new CImage;
    CImage* img_pdam4 = new CImage;
    CImage* img_pdam5 = new CImage;
    CImage* img_pdam6 = new CImage;
    CImage* img_pdam7 = new CImage;
    CImage* img_pdam8 = new CImage;
    CImage* img_pdam9 = new CImage;
    bool LoadingPDam0 = false;
    bool LoadingPDam1 = false;
    bool LoadingPDam2 = false;
    bool LoadingPDam3 = false;
    bool LoadingPDam4 = false;
    bool LoadingPDam5 = false;
    bool LoadingPDam6 = false;
    bool LoadingPDam7 = false;
    bool LoadingPDam8 = false;
    bool LoadingPDam9 = false;
protected:
    CImage* img_phea0 = new CImage;
    CImage* img_phea1 = new CImage;
    CImage* img_phea2 = new CImage;
    CImage* img_phea3 = new CImage;
    CImage* img_phea4 = new CImage;
    CImage* img_phea5 = new CImage;
    CImage* img_phea6 = new CImage;
    CImage* img_phea7 = new CImage;
    CImage* img_phea8 = new CImage;
    CImage* img_phea9 = new CImage;
    bool LoadingPHea0 = false;
    bool LoadingPHea1 = false;
    bool LoadingPHea2 = false;
    bool LoadingPHea3 = false;
    bool LoadingPHea4 = false;
    bool LoadingPHea5 = false;
    bool LoadingPHea6 = false;
    bool LoadingPHea7 = false;
    bool LoadingPHea8 = false;
    bool LoadingPHea9 = false;
protected:
    DamNum m_Num;
    std::vector<DamNum> m_vecPt_Edam;
    std::vector<DamNum> m_vecPt_Pdam;
    std::vector<DamNum> m_vecPt_Phea;
    int Lasting = 50;
};

