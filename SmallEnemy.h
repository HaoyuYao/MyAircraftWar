#pragma once
#include "Objects.h"
class SmallEnemy :
    public Objects
{
public:
    SmallEnemy() {
        SetSpeed(2);
        SetSize(20);
        SetHP(1);
        SetDam(1);
        //SetImgDir("\\images\\small_enemy.png");
        LoadmyImage(m_img, "\\images\\enemy\\small_enemy.png",LoadingImg);
        //LoadmyImage(m_img, "\\images\\lt.jpg", LoadingImg);
        SetImgSize(m_nR + 10, m_nR + 12);
        SetRate(600);
    };
    ~SmallEnemy() {};
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
protected:
    //int e_CreateRate;
    int e_Damage;
    int e_AttackInterval;
};

