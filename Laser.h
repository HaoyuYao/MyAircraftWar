#pragma once
#include "Objects.h"
#include "PlayBKG.h"
class Laser :
    public Objects
{
public:
    Laser() {
        LoadmyImage(img_s1, "\\images\\laser\\laser_storing1.png", LoadingS1);
        LoadmyImage(img_s2, "\\images\\laser\\laser_storing2.png", LoadingS2);
        LoadmyImage(img_s3, "\\images\\laser\\laser_storing3.png", LoadingS3);
        LoadmyImage(img_s4, "\\images\\laser\\laser_storing4.png", LoadingS4);
        LoadmyImage(img_s5, "\\images\\laser\\laser_storing5.png", LoadingS5);
        LoadmyImage(img_s6, "\\images\\laser\\laser_storing6.png", LoadingS6);
        LoadmyImage(img_s7, "\\images\\laser\\laser_storing7.png", LoadingS7);

        LoadmyImage(img_f1, "\\images\\laser\\laser_fire1.png", LoadingF1);
        LoadmyImage(img_f2, "\\images\\laser\\laser_fire2.png", LoadingF2);
        LoadmyImage(img_f3, "\\images\\laser\\laser_fire3.png", LoadingF3);
        LoadmyImage(img_f4, "\\images\\laser\\laser_fire4.png", LoadingF4);

        LoadmyImage(img_l1, "\\images\\laser\\laser1.png", LoadingL1);
        LoadmyImage(img_l2, "\\images\\laser\\laser2.png", LoadingL2);
        LoadmyImage(img_l3, "\\images\\laser\\laser3.png", LoadingL3);
        LoadmyImage(img_l4, "\\images\\laser\\laser4.png", LoadingL4);
        LoadmyImage(img_l5, "\\images\\laser\\laser5.png", LoadingL5);

        SetLaserWidth(30);
    }
    ~Laser() {};
public:
    void Show(CDC* pDC,int UpBorder) {
        CRect img_rcts(m_x - SWidth / 2, m_y - SHeight / 2-10, m_x + SWidth / 2, m_y -10);
        CRect img_rctf(m_x - SWidth / 2, m_y - SHeight / 2-10, m_x + SWidth / 2, m_y -10);
        CRect img_rctl(m_x - la_width / 2, bkg.GetUp(), m_x + la_width / 2, m_y + SHeight);
        pDC->SetStretchBltMode(HALFTONE);//ÑÕÉ«ÓÅ»¯
        if (LTimer < LLasting / 20) {
            if (img_s1->IsNull() || !LoadingS1) {
                pDC->Ellipse(m_x - SWidth / 2, m_y - SHeight / 2, m_x + SWidth / 2, m_y + SHeight);
            }
            else {
                img_s1->Draw(pDC->GetSafeHdc(), img_rcts);
            }
        }
        else if (LTimer < LLasting * 2 / 20) {
            if (img_s2->IsNull() || !LoadingS2) {
                pDC->Ellipse(m_x - SWidth / 2, m_y - SHeight / 2, m_x + SWidth / 2, m_y + SHeight);
            }
            else {
                img_s2->Draw(pDC->GetSafeHdc(), img_rcts);
            }
        }
        else if (LTimer < LLasting * 3 / 20) {
            if (img_s3->IsNull() || !LoadingS3) {
                pDC->Ellipse(m_x - SWidth / 2, m_y - SHeight / 2, m_x + SWidth / 2, m_y + SHeight);
            }
            else {
                img_s3->Draw(pDC->GetSafeHdc(), img_rcts);
            }
        }
        else if (LTimer < LLasting * 4 / 20) {
            if (img_s4->IsNull() || !LoadingS4) {
                pDC->Ellipse(m_x - SWidth / 2, m_y - SHeight / 2, m_x + SWidth / 2, m_y + SHeight);
            }
            else {
                img_s4->Draw(pDC->GetSafeHdc(), img_rcts);
            }
        }
        else if (LTimer < LLasting * 5 / 20) {
            if (img_s5->IsNull() || !LoadingS5) {
                pDC->Ellipse(m_x - SWidth / 2, m_y - SHeight / 2, m_x + SWidth / 2, m_y + SHeight);
            }
            else {
                img_s5->Draw(pDC->GetSafeHdc(), img_rcts);
            }
        }
        else if (LTimer < LLasting * 6 / 20) {
            if (img_s6->IsNull() || !LoadingS6) {
                pDC->Ellipse(m_x - SWidth / 2, m_y - SHeight / 2, m_x + SWidth / 2, m_y + SHeight);
            }
            else {
                img_s6->Draw(pDC->GetSafeHdc(), img_rcts);
            }
        }
        else if (LTimer < LLasting * 7 / 20) {
            if (img_s7->IsNull() || !LoadingS7) {
                pDC->Ellipse(m_x - SWidth / 2, m_y - SHeight / 2, m_x + SWidth / 2, m_y + SHeight);
            }
            else {
                img_s7->Draw(pDC->GetSafeHdc(), img_rcts);
            }
        }
        else if(LTimer<LLasting*9/20){}
        else if (LTimer < LLasting * 10 / 20) {
            if (img_f1->IsNull() || !LoadingF1) {
                pDC->Ellipse(m_x - FWidth / 2, m_y - FHeight / 2, m_x + FWidth / 2, m_y + FHeight);
            }
            else {
                img_f1->Draw(pDC->GetSafeHdc(), img_rctf);
            }
        }
        else if (LTimer < LLasting * 11 / 20) {
            if (img_f2->IsNull() || !LoadingF1) {
                pDC->Ellipse(m_x - FWidth / 2, m_y - FHeight / 2, m_x + FWidth / 2, m_y + FHeight);
            }
            else {
                img_f2->Draw(pDC->GetSafeHdc(), img_rctf);
            }
        }
        else if (LTimer < LLasting * 12 / 20) {
            if (img_f3->IsNull() || !LoadingF1) {
                pDC->Ellipse(m_x - FWidth / 2, m_y - FHeight / 2, m_x + FWidth / 2, m_y + FHeight);
            }
            else {
                img_f3->Draw(pDC->GetSafeHdc(), img_rctf);
            }
        }
        else if (LTimer < LLasting * 13 / 20) {
            if (img_f4->IsNull() || !LoadingF1) {
                pDC->Ellipse(m_x - FWidth / 2, m_y - FHeight / 2, m_x + FWidth / 2, m_y + FHeight);
            }
            else {
                img_f4->Draw(pDC->GetSafeHdc(), img_rctf);
            }
        }
        else if (LTimer < LLasting * 16 / 20) {
            if (img_l1->IsNull() || !LoadingF1) {
                pDC->Ellipse(m_x - la_width / 2, bkg.GetUp(), m_x + la_width / 2, m_y + SHeight);
            }
            else {
                img_l1->Draw(pDC->GetSafeHdc(), img_rctl);
            }
        }
        else if (LTimer < LLasting * 17 / 20) {
            if (img_l2->IsNull() || !LoadingF1) {
                pDC->Ellipse(m_x - la_width / 2, bkg.GetUp(), m_x + la_width / 2, m_y + SHeight);
            }
            else {
                img_l2->Draw(pDC->GetSafeHdc(), img_rctl);
            }
        }
        else if (LTimer < LLasting * 18 / 20) {
        if (img_l3->IsNull() || !LoadingF1) {
            pDC->Ellipse(m_x - la_width / 2, bkg.GetUp(), m_x + la_width / 2, m_y + SHeight);
        }
        else {
            img_l3->Draw(pDC->GetSafeHdc(), img_rctl);
        }
        }
        else if (LTimer < LLasting * 19 / 20) {
        if (img_l4->IsNull() || !LoadingF1) {
            pDC->Ellipse(m_x - la_width / 2, bkg.GetUp(), m_x + la_width / 2, m_y + SHeight);
        }
        else {
            img_l4->Draw(pDC->GetSafeHdc(), img_rctl);
        }
        }
        else if (LTimer < LLasting * 20 / 20) {
        if (img_l5->IsNull() || !LoadingF1) {
            pDC->Ellipse(m_x - la_width / 2, bkg.GetUp(), m_x + la_width / 2, m_y + SHeight);
        }
        else {
            img_l5->Draw(pDC->GetSafeHdc(), img_rctl);
        }
        }
    }
    void SetLaserWidth(int width) {
        la_width = width;
    }
    int GetLaserWidth() {
        return la_width;
    }
    void SetLaserTimer(int timer) {
        LTimer = timer;
    }
    int GetLaserTimer() {
        return LTimer;
    }
    void SetLaserLasting(int lasting) {
        LLasting = lasting;
    }
    int GetLaserLasting() {
        return LLasting;
    }
    void SetPlayerPos(int x, int y) {
        Player_x = x;
        Player_y = y;
    }
    void UpdateTimer() {
        LTimer++;
    }
    void SetDam(int damage) {
        m_Damage = damage;
    }
    int GetDam() {
        return m_Damage;
    }
    int GetEffectiveTime() {
        return EffectiveTime;
    }
    bool Collide(Objects& obj) {
        bool LColl = false;
        int x, y;
        obj.GetPos(x, y);
        /*double dis = sqrt((m_x - x) * (m_x - x) + (m_y - y) * (m_y - y));
        double sizeDis = m_nR / 2 + obj.GetSize() / 2;
        bColl = dis - sizeDis > 0 ? false : true;*/
        double Xdis = abs(m_x - x);
        LColl = Xdis - la_width > 0 ? false : true;
        return LColl;
    }
protected:
    PlayBKG bkg;
    int Player_x, Player_y;
protected:
    CImage* img_s1 = new CImage;
    CImage* img_s2 = new CImage;
    CImage* img_s3 = new CImage;
    CImage* img_s4 = new CImage;
    CImage* img_s5 = new CImage;
    CImage* img_s6 = new CImage;
    CImage* img_s7 = new CImage;

    CImage* img_f1 = new CImage;
    CImage* img_f2 = new CImage;
    CImage* img_f3 = new CImage;
    CImage* img_f4 = new CImage;

    CImage* img_l1 = new CImage;
    CImage* img_l2 = new CImage;
    CImage* img_l3 = new CImage;
    CImage* img_l4 = new CImage;
    CImage* img_l5 = new CImage;
protected:
    bool LoadingS1 = false;
    bool LoadingS2 = false;
    bool LoadingS3 = false;
    bool LoadingS4 = false;
    bool LoadingS5 = false;
    bool LoadingS6 = false;
    bool LoadingS7 = false;

    bool LoadingF1 = false;
    bool LoadingF2 = false;
    bool LoadingF3 = false;
    bool LoadingF4 = false;

    bool LoadingL1 = false;
    bool LoadingL2 = false;
    bool LoadingL3 = false;
    bool LoadingL4 = false;
    bool LoadingL5 = false;

    int LTimer = 0;
    int LLasting = 100;

    int SWidth = 50;
    int SHeight = 30;
    int FWidth = 50;
    int FHeight = 50;

    int la_width = 30;
    int EffectiveTime = LLasting * 15 / 20;
    int m_Damage = 5;
};

