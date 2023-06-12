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
        case 1://1�������ƶ�
            SetPos(m_x, m_y - m_nSpeed);
            break;
        case 2://2�������ƶ�
            SetPos(m_x, m_y + m_nSpeed);
            break;
        case 3://3�������ƶ�
            SetPos(m_x - m_nSpeed, m_y);
            break;
        case 4://4�������ƶ�
            SetPos(m_x + m_nSpeed, m_y);
        default:
            break;
        }
    }
protected:
    int Heal;
};

