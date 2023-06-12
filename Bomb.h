#pragma once
#include "Objects.h"
class Bomb :
    public Objects
{
public:
    Bomb() {
        SetSpeed(5);
        SetSize(40);
        //SetImgDir("\\images\\bomb.png");
        SetImgSize(40, 40);
        LoadmyImage(m_img, "\\images\\bomb\\bomb_1.png", LoadingImg);
        LoadmyImage(m_img2, "\\images\\bomb\\bomb_2.png", LoadingImgBomb2);
        LoadmyImage(m_img3, "\\images\\bomb\\bomb_3.png", LoadingImgBomb3);
        LoadmyImage(m_img_boom1, "\\images\\boom1.png", LoadingImgB1);
        LoadmyImage(m_img_boom2, "\\images\\boom2.png", LoadingImgB2);
        LoadmyImage(m_img_boom3, "\\images\\boom3.png", LoadingImgB3);
        LoadmyImage(m_img_boom4, "\\images\\boom4.png", LoadingImgB4);
        LoadmyImage(m_img_boom5, "\\images\\boom5.png", LoadingImgB5);
        LoadmyImage(m_img_boom6, "\\images\\boom6.png", LoadingImgB6);
        SetRange(150);
        SetLasting(50);
        SetBoom(false);
        //SetTiming(false);
    };
    ~Bomb() {};
public:
    virtual void IsBoom() {
        Boom = true;
        //Timing = true;
        Timer = 0;
    }
    virtual void IsNotBoom() {
        Boom = false;
        Timer = 0;
        //Timing = false;
    }
    virtual void SetDam(int Damage) {
        m_Damage = Damage;
    }
    virtual int GetDam() {
        return m_Damage;
    }
    virtual void UpdatePos(int nDir) {
        if (nDir == 1) {//1是上，玩家打的
            SetPos(m_x, m_y - m_nSpeed);
        }
        else if (nDir == 2) {//2是下，敌人打的
            SetPos(m_x, m_y + m_nSpeed);
        }
    }
    virtual void SetRange(int range) {
        m_boom_range = range;
    }
    virtual int GetRange() {
        return m_boom_range;
    }
    virtual void SetTimer(int timer) {
        Timer = timer;
    }
    virtual int GetTimer() {
        return Timer;
    }
    virtual void UpdateTimer() {
        Timer++;
    }
    virtual void UpdateBTimer() {
        BTimer++;
    }
    //virtual bool GetTiming() {
    //    return Timing;
    //}
    //virtual void SetTiming(bool timing) {
    //    Timing = timing;
    //}
    virtual bool GetBoom() {
        return Boom;
    }
    virtual void SetBoom(bool boom) {
        Boom = boom;
    }
    virtual void SetLasting(int lasting) {
        Lasting = lasting;
    }
    virtual int GetLasting() {
        return Lasting;
    }
    virtual void SetBombLasting(int lasting) {
        BLasting = lasting;
    }
    virtual int GetBombLasting() {
        return BLasting;
    }
    virtual int GetBTimer() {
        return BTimer;
    }
    virtual void SetBTimer(int btimer) {
        BTimer = btimer;
    }
    void Show(CDC* pDC) {
        if (!Boom) {
            if (BTimer < BLasting/3) {
                if (m_img3->IsNull() || !LoadingImgBomb3) {
                    pDC->Ellipse(m_x - m_nR, m_y - m_nR, m_x + m_nR, m_y + m_nR);
                }
                else {
                    pDC->SetStretchBltMode(HALFTONE);//颜色优化
                    CRect img_rcttt(m_x - m_imgWidth / 2, m_y - m_imgHeight / 2,
                        m_x + m_imgWidth / 2, m_y + m_imgHeight);
                    m_img3->Draw(pDC->GetSafeHdc(), img_rcttt);
                }
            }
            else if(BTimer<BLasting*2/3) {
                if (m_img2->IsNull() || !LoadingImgBomb2) {
                    pDC->Ellipse(m_x - m_nR, m_y - m_nR, m_x + m_nR, m_y + m_nR);
                }
                else {
                    pDC->SetStretchBltMode(HALFTONE);//颜色优化
                    CRect img_rctt(m_x - m_imgWidth / 2, m_y - m_imgHeight / 2,
                        m_x + m_imgWidth / 2, m_y + m_imgHeight);
                    m_img2->Draw(pDC->GetSafeHdc(), img_rctt);
                }
            }
            else {
                if (m_img->IsNull() || !LoadingImg) {
                    pDC->Ellipse(m_x - m_nR, m_y - m_nR, m_x + m_nR, m_y + m_nR);
                }
                else {
                    pDC->SetStretchBltMode(HALFTONE);//颜色优化
                    CRect img_rct(m_x - m_imgWidth / 2, m_y - m_imgHeight / 2,
                        m_x + m_imgWidth / 2, m_y + m_imgHeight);
                    m_img->Draw(pDC->GetSafeHdc(), img_rct);
                }
            }
        }
        else if (Boom) {
            if (Timer < Lasting / 6) {
                if (m_img_boom1->IsNull() || !LoadingImgB1) {
                    pDC->Ellipse(m_x - m_nR, m_y - m_nR, m_x + m_nR, m_y + m_nR);
                }
                else {
                    pDC->SetStretchBltMode(HALFTONE);//颜色优化
                    CRect img_rct1(m_x - m_boom_range / 2, m_y - m_boom_range / 2,
                        m_x + m_boom_range / 2, m_y + m_boom_range / 2);
                    m_img_boom1->Draw(pDC->GetSafeHdc(), img_rct1);
                }
            }
            else if (Timer < Lasting * 2 / 6) {
                if (m_img_boom2->IsNull() || !LoadingImgB2) {
                    pDC->Ellipse(m_x - m_nR, m_y - m_nR, m_x + m_nR, m_y + m_nR);
                }
                else {
                    pDC->SetStretchBltMode(HALFTONE);//颜色优化
                    CRect img_rct2(m_x - m_boom_range / 2, m_y - m_boom_range / 2,
                        m_x + m_boom_range / 2, m_y + m_boom_range / 2);
                    m_img_boom2->Draw(pDC->GetSafeHdc(), img_rct2);
                }
            }
            else if (Timer < Lasting / 2) {
                if (m_img_boom3->IsNull() || !LoadingImgB3) {
                    pDC->Ellipse(m_x - m_nR, m_y - m_nR, m_x + m_nR, m_y + m_nR);
                }
                else {
                    pDC->SetStretchBltMode(HALFTONE);//颜色优化
                    CRect img_rct3(m_x - m_boom_range / 2, m_y - m_boom_range / 2,
                        m_x + m_boom_range / 2, m_y + m_boom_range / 2);
                    m_img_boom3->Draw(pDC->GetSafeHdc(), img_rct3);
                }
            }
            else if (Timer < Lasting * 2 / 3) {
                if (m_img_boom4->IsNull() || !LoadingImgB4) {
                    pDC->Ellipse(m_x - m_nR, m_y - m_nR, m_x + m_nR, m_y + m_nR);
                }
                else {
                    pDC->SetStretchBltMode(HALFTONE);//颜色优化
                    CRect img_rct4(m_x - m_boom_range / 2, m_y - m_boom_range / 2,
                        m_x + m_boom_range / 2, m_y + m_boom_range / 2);
                    m_img_boom4->Draw(pDC->GetSafeHdc(), img_rct4);
                }
            }
            else if (Timer < Lasting * 5 / 6) {
                if (m_img_boom5->IsNull() || !LoadingImgB5) {
                    pDC->Ellipse(m_x - m_nR, m_y - m_nR, m_x + m_nR, m_y + m_nR);
                }
                else {
                    pDC->SetStretchBltMode(HALFTONE);//颜色优化
                    CRect img_rct5(m_x - m_boom_range / 2, m_y - m_boom_range / 2,
                        m_x + m_boom_range / 2, m_y + m_boom_range / 2);
                    m_img_boom5->Draw(pDC->GetSafeHdc(), img_rct5);
                }
            }
            else {
                if (m_img_boom6->IsNull() || !LoadingImgB6) {
                    pDC->Ellipse(m_x - m_nR, m_y - m_nR, m_x + m_nR, m_y + m_nR);
                }
                else {
                    pDC->SetStretchBltMode(HALFTONE);//颜色优化
                    CRect img_rct6(m_x - m_boom_range / 2, m_y - m_boom_range / 2,
                        m_x + m_boom_range / 2, m_y + m_boom_range / 2);
                    m_img_boom6->Draw(pDC->GetSafeHdc(), img_rct6);
                }
            }
        }
    }
protected:
    int m_Damage = 1;
    int m_boom_range;
    bool Boom;
    int Timer=0;
    int BTimer=0;
    int Lasting=50;
    int BLasting=30;
    //bool Timing;
    CImage* m_img2 = new CImage;
    bool LoadingImgBomb2 = false;
    CImage* m_img3 = new CImage;
    bool LoadingImgBomb3 = false;
    CImage* m_img_boom1 = new CImage;
    bool LoadingImgB1 = false;
    CImage* m_img_boom2 = new CImage;
    bool LoadingImgB2 = false;
    CImage* m_img_boom3 = new CImage;
    bool LoadingImgB3 = false;
    CImage* m_img_boom4 = new CImage;
    bool LoadingImgB4 = false;
    CImage* m_img_boom5 = new CImage;
    bool LoadingImgB5 = false;
    CImage* m_img_boom6 = new CImage;
    bool LoadingImgB6 = false;

};

