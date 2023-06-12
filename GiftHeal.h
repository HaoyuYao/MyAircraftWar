#pragma once
#include "Objects.h"
class GiftHeal :
    public Objects
{
public:
    GiftHeal() {
        LoadmyImage(m_img, "\\images\\gifts\\heal.png", LoadingImg);
        SetSpeed(1);
        SetSize(25);
        SetHeal(5);
        SetImgSize(45, 25);
        SetRate(8000);
    }
    ~GiftHeal() {};
public:
    void SetHeal(int heal) {
        Heal = heal;
    }
    int GetHeal() {
        return Heal;
    }
    virtual void UpdatePos(int nDir) {
        switch (nDir) {
        case 1://1是向上移动
            SetPos(m_x, m_y - m_nSpeed);
            break;
        case 2://2是向下移动
            SetPos(m_x, m_y + m_nSpeed);
            break;
        case 3://3是向左移动
            SetPos(m_x - m_nSpeed, m_y);
            break;
        case 4://4是向右移动
            SetPos(m_x + m_nSpeed, m_y);
        default:
            break;
        }
    }
protected:
    int Heal;
};

