#pragma once
#include "Objects.h"
#include "Shell.h"
class HugeEnemy :
    public Objects
{
public:
    HugeEnemy() {
        SetSpeed(1);
        SetSize(35);
        SetHP(60);
        SetDam(9);
        //SetImgDir("\\images\\middle_enemy.png");
        SetRate(25000);
        SetShellSpeed(3);
        SetInt(3000);
        SetImgSize(140, 160);
        //LoadmyImage(m_img, "\\images\\middle_enemy.png",LoadingImg);
        LoadmyImage(m_img, "\\images\\enemy\\huge_enemy.png", LoadingImg);
    };
    ~HugeEnemy() {};
public:
    /*virtual void SetRate(int rate) {
        e_CreateRate = rate;
    }
    virtual int GetRate() {
        return e_CreateRate;
    }*/
    virtual void SetDam(int damage) {
        e_Damage = damage;
    }
    virtual int GetDam() {
        return e_Damage;
    }
    virtual void SetInt(int interval) {
        e_AttackInterval = interval;
    }
    virtual int GetInt() {
        return e_AttackInterval;
    }
    virtual void UpdatePos() {
        SetPos(m_x, m_y + m_nSpeed);
    }
    virtual void FireShell() {
        m_ShellMid.SetPos(m_x, m_y + m_nR / 2);
        m_ShellLeft.SetPos(m_x - m_nR, m_y);
        m_ShellRight.SetPos(m_x + m_nR, m_y);
        m_vecShell.push_back(m_ShellMid);
        m_vecShell.push_back(m_ShellLeft);
        m_vecShell.push_back(m_ShellRight);
    }
    virtual void ShellMove(int nDir) {
        for (auto& m_Shell : m_vecShell)
            m_Shell.UpdatePos(nDir);
    }
    virtual bool HitTarget(Objects& obj) {
        bool bHit = false;
        for (auto& co_Shell : m_vecShell) {
            if (co_Shell.Collide(obj)) {
                co_Shell.SetExists(false);
                bHit = true;
            }
        }
        return bHit;
    }
    virtual int GetShellDam() {
        return m_ShellMid.GetDam();
    }
    virtual void UpdateShell() {
        int i = 0;
        for (auto m_Shell : m_vecShell) {
            if (!m_Shell.GetExists())
                m_vecShell.erase(m_vecShell.begin() + i);
            else
                i++;
        }
    }
    virtual void ShowShell(CDC* pDC) {
        for (auto& m_Shell : m_vecShell) {
            m_Shell.Show(pDC, ENEMY);
            if (m_Shell.OutofPlace())
                m_Shell.SetExists(false);
        }
        UpdateShell();
    }
    virtual void SetShellSpeed(int speed) {
        m_ShellMid.SetSpeed(speed);
        m_ShellLeft.SetSpeed(speed);
        m_ShellRight.SetSpeed(speed);
    }
    virtual void SetShellDam(int damage) {
        m_ShellMid.SetDam(damage);
        m_ShellLeft.SetDam(damage);
        m_ShellRight.SetDam(damage);
    }
    virtual void ClearShell() {
        m_vecShell.clear();
    }
    void SetETimer(int timer) {
        ETimer = timer;
    }
    int GetETimer() {
        return ETimer;
    }
    int GetETop() {
        return ETop;
    }
    void UpdateETimer() {
        ETimer++;
    }
protected:
    Shell m_ShellMid;
    Shell m_ShellLeft;
    Shell m_ShellRight;
    std::vector<Shell> m_vecShell;
    //int e_CreateRate;
    int e_Damage;
    int e_AttackInterval;
    int ETimer = 0;
    int ETop = 200;
};

