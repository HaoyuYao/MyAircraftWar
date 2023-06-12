#pragma once
#include "Objects.h"
#include "Shell.h"
#include "PlayBKG.h"
#include "Bomb.h"
#include "Laser.h"
class Player :
    public Objects
{
public:
    Player() {
        FindBorder(bkg.GetLeft(), bkg.GetUp(), bkg.GetRight(), bkg.GetDown());
        SetPos((m_RightBorder + m_LeftBorder) / 2, m_DownBorder);
        SetSpeed(10);
        SetSize(80);
        SetHP(10);
        SetIniHP(10);
        SetAutoInt(100);
        SetShellSpeed(20);
        SetShellDam(1);
        SetBombDam(3);
        SetLaserDam(9);
        SetImgSize(70, 80);
        LoadmyImage(m_img, "\\images\\player.png",LoadingImg);
        LoadmyImage(m_p1, "\\images\\player\\player1.png", L1);
        LoadmyImage(m_p2, "\\images\\player\\player2.png", L2);
        LoadmyImage(m_p3, "\\images\\player\\player3.png", L3);
        LoadmyImage(m_p4, "\\images\\player\\player4.png", L4);
        LoadmyImage(m_p5, "\\images\\player\\player5.png", L5);
        LoadmyImage(m_p6, "\\images\\player\\player6.png", L6);
        LoadmyImage(m_p7, "\\images\\player\\player7.png", L7);
        LoadmyImage(m_p8, "\\images\\player\\player8.png", L8);
        LoadmyImage(m_p9, "\\images\\player\\player9.png", L9);
        LoadmyImage(m_p10, "\\images\\player\\player10.png", L10);
    };
    ~Player() {};
public:
    void Show(CDC* pDC) {
        CRect img_rct(m_x - m_imgWidth / 2, m_y - m_imgHeight / 2, m_x + m_imgWidth / 2, m_y + m_imgHeight);
        pDC->SetStretchBltMode(HALFTONE);//ÑÕÉ«ÓÅ»¯
        if (m_p1->IsNull() ||m_p2->IsNull()||m_p3->IsNull()||m_p4->IsNull()||m_p5->IsNull()||
            m_p6->IsNull()||m_p7->IsNull() ||m_p8->IsNull()||m_p9->IsNull()||m_p10->IsNull()||
            !L1||!L2||!L3||!L4||!L5||!L6||!L7||!L8||!L9||!L10) {
            pDC->Ellipse(m_x - m_nR, m_y - m_nR, m_x + m_nR, m_y + m_nR);
        }
        else {
            if (PTimer < PLasting / 10)
                m_p1->Draw(pDC->GetSafeHdc(), img_rct);
            else if (PTimer < PLasting * 2 / 10)
                m_p2->Draw(pDC->GetSafeHdc(), img_rct);
            else if (PTimer < PLasting * 3 / 10)
                m_p3->Draw(pDC->GetSafeHdc(), img_rct);
            else if (PTimer < PLasting * 4 / 10)
                m_p4->Draw(pDC->GetSafeHdc(), img_rct);
            else if (PTimer < PLasting * 5 / 10)
                m_p5->Draw(pDC->GetSafeHdc(), img_rct);
            else if (PTimer < PLasting * 6 / 10)
                m_p6->Draw(pDC->GetSafeHdc(), img_rct);
            else if (PTimer < PLasting * 7 / 10)
                m_p7->Draw(pDC->GetSafeHdc(), img_rct);
            else if (PTimer < PLasting * 8 / 10)
                m_p8->Draw(pDC->GetSafeHdc(), img_rct);
            else if (PTimer < PLasting * 9 / 10)
                m_p9->Draw(pDC->GetSafeHdc(), img_rct);
            else
                m_p10->Draw(pDC->GetSafeHdc(), img_rct);
        }
        if (PTimer >= PLasting)PTimer = 0;
        UpdatePTimer();
    }
    virtual void SetPTimer(int timer) {
        PTimer = timer;
    }
    virtual void UpdatePTimer() {
        PTimer++;
    }
    virtual int GetPTimer() {
        return PTimer;
    }
    virtual void FireBomb() {
        m_Bomb.SetPos(m_x, m_y);
        m_vecBomb.push_back(m_Bomb);
    }
    virtual void FireShell() {
        m_Shell.SetPos(m_x, m_y);
        m_vecShell.push_back(m_Shell);
    }
    virtual void FireLaser() {
        m_Laser.SetPlayerPos(m_x, m_y);
        m_Laser.SetPos(m_x, m_y - m_nR);
        m_vecLaser.push_back(m_Laser);
    }
    virtual void BombMove(int nDir) {
        for (auto& m_Bomb : m_vecBomb)
            if (!m_Bomb.GetBoom())
                m_Bomb.UpdatePos(nDir);
    }
    virtual void ShellMove(int nDir) {
        for (auto& m_Shell : m_vecShell)
            m_Shell.UpdatePos(nDir);
    }
    virtual void LaserMove() {
        for (auto& m_Laser : m_vecLaser) {
            m_Laser.SetPos(m_x, m_y);
        }
    }
    virtual bool BombHitTarget(Objects& obj) {
        bool bHit = false;
        for (auto& co_Bomb : m_vecBomb) {
            if (co_Bomb.GetTimer() < 1) {
                if (!m_Bomb.GetBoom()) {//Ã»ÓÐ±¬Õ¨²Å¼ì²âÅö×²
                    if (co_Bomb.Collide(obj)) {
                        //co_Bomb.SetExists(false);
                        bHit = true;
                        co_Bomb.IsBoom();
                    }
                }
            }
        }
        return bHit;
    }
    virtual bool BombEffected(Objects& obj) {
        bool bEfc = false;
        for (auto& co_Bomb : m_vecBomb) {
            if (co_Bomb.GetTimer() <= 1) {
                if (co_Bomb.GetBoom()) {//±¬Õ¨²Å¼ì²â±¬Õ¨²¨¼°
                    if (sqrt((obj.GetX() - co_Bomb.GetX()) * (obj.GetX() - co_Bomb.GetX()) + (obj.GetY() - co_Bomb.GetY()) * (obj.GetY() - co_Bomb.GetY())) <= co_Bomb.GetRange()) {
                        bEfc = true;
                    }
                }
            }
        }
        return bEfc;
    }
    virtual bool HitTarget(Objects& obj) {
        bool sHit = false;
        for (auto& co_Shell : m_vecShell) {
            if (co_Shell.Collide(obj)) {
                co_Shell.SetExists(false);
                sHit = true;
            }
        }
        return sHit;
    }
    virtual bool LaserHitTarget(Objects& obj) {
        bool LHit = false;
        for (auto& co_Laser : m_vecLaser) {
            if (co_Laser.GetLaserTimer() >= co_Laser.GetEffectiveTime()) {
                if (co_Laser.Collide(obj)) {
                    LHit = true;
                }
            }
        }
        return LHit;
    }
    virtual int GetBombDam() {
        return m_Bomb.GetDam();
    }
    virtual int GetShellDam() {
        return m_Shell.GetDam();
    }
    virtual int GetLaserDam() {
        return m_Laser.GetDam();
    }
    virtual void UpdateBomb() {
        int i = 0;
        for (auto& m_Bomb : m_vecBomb) {
            if (!m_Bomb.GetExists())
                m_vecBomb.erase(m_vecBomb.begin() + i);
            else
                i++;
        }
    }
    virtual void UpdateShell() {
        int i = 0;
        for (auto& m_Shell : m_vecShell) {
            if (!m_Shell.GetExists())
                m_vecShell.erase(m_vecShell.begin() + i);
            else
                i++;
        }
    }
    virtual void ShowLaser(CDC* pDC) {
        for (auto& m_Laser : m_vecLaser) {
            m_Laser.Show(pDC, m_UpBorder);
            m_Laser.UpdateTimer();
            if (m_Laser.GetLaserTimer() >= m_Laser.GetLaserLasting()) {
                m_Laser.SetExists(false);
            }
        }
        UpdateLaser();
    }
    virtual void UpdateLaser() {
        int i = 0;
        for (auto& m_Laser : m_vecLaser) {
            if (!m_Laser.GetExists())
                m_vecLaser.erase(m_vecLaser.begin() + i);
            else
                i++;
        }
    }
    virtual void ShowBomb(CDC* pDC) {
        for (auto& m_Bomb : m_vecBomb) {
            m_Bomb.Show(pDC);
            if (m_Bomb.OutofPlace())
                m_Bomb.SetExists(false);
            if (m_Bomb.GetBoom()) {
                m_Bomb.UpdateTimer();
            }
            else {
                m_Bomb.UpdateBTimer();
            }
            if (m_Bomb.GetTimer() >= m_Bomb.GetLasting()) {
                m_Bomb.SetExists(false);
            }
            if (m_Bomb.GetBTimer() >= m_Bomb.GetBombLasting()) {
                m_Bomb.SetBTimer(0);
            }
        }
        UpdateBomb();
    }
    virtual void ShowShell(CDC* pDC) {
        for (auto& m_Shell : m_vecShell) {
            m_Shell.Show(pDC,PLAYER);
            if (m_Shell.OutofPlace())
                m_Shell.SetExists(false);
        }
        UpdateShell();
    }
    virtual void SetBombSpeed(int speed) {
        m_Bomb.SetSpeed(speed);
    }
    virtual void SetShellSpeed(int speed) {
        m_Shell.SetSpeed(speed);
    }
    virtual void SetBombDam(int damage) {
        m_Bomb.SetDam(damage);
    }
    virtual void SetShellDam(int damage) {
        m_Shell.SetDam(damage);
    }
    virtual void SetLaserDam(int damage) {
        m_Laser.SetDam(damage);
    }
    virtual void ClearBomb() {
        m_vecBomb.clear();
    }
    virtual void ClearShell() {
        m_vecShell.clear();
    }
    virtual void ClearLaser() {
        m_vecLaser.clear();
    }
    virtual void ShowHP(CDC* pDC) {
        //health.Format(L"%d", m_Health);
        //pDC->TextOutW(GetX() + GetSize() + 10, GetY(), health);
        //int t = 0;
        //int h = 0;
        int m = 0;
        for (int i = 0; i < m_Health; i++) {
            //ShowHeart(pDC, GetX() + GetSize() + 10 + t, GetY() + h, m_heartSize);
            ShowHeart(pDC, m_LeftBorder + 30 + m, m_DownBorder - 40, m_heartSize+30);
            //if ((i + 1) % 10 == 0) {
            //    t = 0;
            //    h += 10;
            //}
            //else t += 10;
            m += 40;
        }
    }
public:
    void UpdatePos(double dDir, int x, int y);
protected:
    Shell m_Shell;
    std::vector<Shell> m_vecShell;
    Bomb m_Bomb;
    std::vector<Bomb> m_vecBomb;
    Laser m_Laser;
    std::vector<Laser> m_vecLaser;
protected:
    CImage* m_p1 = new CImage;
    CImage* m_p2 = new CImage;
    CImage* m_p3 = new CImage;
    CImage* m_p4 = new CImage;
    CImage* m_p5 = new CImage;
    CImage* m_p6 = new CImage;
    CImage* m_p7 = new CImage;
    CImage* m_p8 = new CImage;
    CImage* m_p9 = new CImage;
    CImage* m_p10 = new CImage;
    bool L1 = false;
    bool L2 = false;
    bool L3 = false;
    bool L4 = false;
    bool L5 = false;
    bool L6 = false;
    bool L7 = false;
    bool L8 = false;
    bool L9 = false;
    bool L10 = false;
    int PTimer = 0;
    int PLasting = 100;
};

