#pragma once
#include "Objects.h"
#include "Shell.h"
class MiddleEnemy :
    public Objects
{
public:
    MiddleEnemy() {
        SetSpeed(1);
        SetSize(25);
        SetHP(20);
        SetDam(3);
        //SetImgDir("\\images\\middle_enemy.png");
        SetRate(10000);
        SetShellSpeed(5);
        SetInt(1200);
        SetImgSize(50, 60);
        LoadmyImage(m_img, "\\images\\enemy\\middle_enemy.png",LoadingImg);
        //LoadmyImage(m_img, "\\images\\kunkun.png", LoadingImg);
    };
    ~MiddleEnemy() {};
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
        m_Shell.SetPos(m_x, m_y);
        m_vecShell.push_back(m_Shell);
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
        return m_Shell.GetDam();
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
            m_Shell.Show(pDC,ENEMY);
            if (m_Shell.OutofPlace())
                m_Shell.SetExists(false);
        }
        UpdateShell();
    }
    virtual void SetShellSpeed(int speed) {
        m_Shell.SetSpeed(speed);
    }
    virtual void SetShellDam(int damage) {
        m_Shell.SetDam(damage);
    }
    virtual void ClearShell() {
        m_vecShell.clear();
    }
protected:
    Shell m_Shell;
    std::vector<Shell> m_vecShell;
    //int e_CreateRate;
    int e_Damage;
    int e_AttackInterval;
};

