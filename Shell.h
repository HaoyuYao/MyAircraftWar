#pragma once
#include "Objects.h"
const int PLAYER = 1;
const int ENEMY = 2;
class Shell :
    public Objects
{
public:
    Shell() {
        SetSpeed(20);
        SetSize(20);
        //SetImgDir("\\images\\shell_player.png");
        LoadmyImage(m_img, "\\images\\shell_player.png",LoadingImg);
        LoadmyImage(m_img2, "\\images\\shell_enemy.png", LoadingImg2);
        //SetImgDir("\\images\\")
        SetImgSize(20, 40);//宽，高
    };
    ~Shell() {};
public:
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
    CImage* GetShellImg1() {
        return m_img;
    }
    CImage* GetShellImg2() {
        return m_img2;
    }
    void Show(CDC* pDC, int PorE) {
        if (PorE == PLAYER) {
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
        else if (PorE == ENEMY) {
            if (m_img2->IsNull() || !LoadingImg) {
                pDC->Ellipse(m_x - m_nR, m_y - m_nR, m_x + m_nR, m_y + m_nR);
            }
            else {
                pDC->SetStretchBltMode(HALFTONE);//颜色优化
                CRect img_rct2(m_x - m_imgWidth / 2, m_y - m_imgHeight / 2,
                    m_x + m_imgWidth / 2, m_y + m_imgHeight);
                m_img2->Draw(pDC->GetSafeHdc(), img_rct2);
            }
        }
    }
protected:
    int m_Damage = 1;
    CImage* m_img2;
    bool LoadingImg2;
};

