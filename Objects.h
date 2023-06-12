#pragma once
#include <string>
#include "PlayBKG.h"
#include <vector>
typedef CImage* pCImage;
class Objects
{
public://初始化
	Objects() { 
		FindBorder(bkg.GetLeft(), bkg.GetUp(), bkg.GetRight(), bkg.GetDown()); 
		LoadmyImage(m_img_heart, "\\images\\heart.png", LoadingHeart);
	};
	~Objects() {};

public://基本功能
	virtual void SetPos(int x, int y) {
		m_x = x;
		m_y = y;
	}
	virtual void GetPos(int& x, int& y) {
		x = m_x;
		y = m_y;
	}
	virtual int GetX() {
		return m_x;
	}
	virtual int GetY() {
		return m_y;
	}
	virtual void SetSpeed(int nSpeed) {
		m_nSpeed = nSpeed;
	}
	virtual int GetSpeed() {
		return m_nSpeed;
	}
	virtual void SetSize(int nR) {
		m_nR = nR;
	}
	virtual int GetSize() {
		return m_nR;
	}
	/*virtual void SetImgDir(std::string Dir) {
		strPlus = Dir.c_str();
	};*/
	virtual void SetImgSize(int width, int height) {
		m_imgWidth = width;
		m_imgHeight = height;
	}
	virtual bool OutofPlace() {
		if ((m_x <= m_LeftBorder || m_x >= m_RightBorder || m_y <= m_UpBorder || m_y >= m_DownBorder))
			return true;
		else return false;
	}
	virtual void FindBorder(int left, int up, int right, int down) {
		m_LeftBorder = left;
		m_UpBorder = up;
		m_RightBorder = right;
		m_DownBorder = down;
	}
	virtual bool Collide(Objects& obj) {
		bool bColl = false;
		int x, y;
		obj.GetPos(x, y);
		double dis = sqrt((m_x - x) * (m_x - x) + (m_y - y) * (m_y - y));
		double sizeDis = m_nR / 2 + obj.GetSize() / 2;
		bColl = dis - sizeDis > 0 ? false : true;
		return bColl;
	}
	virtual void SetExists(bool nExi) {
		exists = nExi;
	}
	virtual bool GetExists() {
		return exists;
	}
public://进阶功能
	virtual void Show(CDC* pDC);
	virtual void LoadmyImage(pCImage& m_img, std::string strPlus, bool& LoadingImg);
	virtual void UpdatePos(int nDir);
public:
	virtual void ShowHP(CDC* pDC) {
		//health.Format(L"%d", m_Health);
		//pDC->TextOutW(GetX() + GetSize() + 10, GetY(), health);
		int t = 0;
		int h = 0;
		for (int i = 0; i < m_Health; i++) {
			ShowHeart(pDC, GetX() + GetSize() + 10 + t, GetY() + h, m_heartSize);
			if ((i+1) % 10 == 0) {
				t = 0;
				h += 10;
			}
			else t += 10;
		}
	}
	virtual void SetHP(int HP) {
		m_Health = HP;
	}
	virtual int GetHP() {
		return m_Health;
	}
	virtual void SetAutoInt(int Auto) {
		a_AutoAttackInterval = Auto;
	}
	virtual int GetAutoInt() {
		return a_AutoAttackInterval;
	}
	virtual void ShowHeart(CDC* pDC,int x,int y, int R) {
		if (m_img_heart->IsNull() || !LoadingHeart) {
			pDC->Ellipse(x - R, y - R, x + R, y + R);
		}
		else {
			pDC->SetStretchBltMode(HALFTONE);//颜色优化
			CRect img_rct_heart(x - R / 2, y - R / 2,
				x + R / 2, y + R / 2);
			m_img_heart->Draw(pDC->GetSafeHdc(), img_rct_heart);
		}
	}
	virtual void SetIniHP(int IniHP) {
		Initial_HP = IniHP;
	}
	virtual int GetIniHP() {
		return Initial_HP;
	}
	virtual void SetRate(int rate) {
		CreateRate = rate;
	}
	virtual int GetRate() {
		return CreateRate;
	}

protected://基础参数
	int Initial_HP;
	int MOVE_LEFT = 0;
	int MOVE_RIGHT = 1;
	int MOVE_UP = 2;
	int MOVE_DOWN = 3;
	PlayBKG bkg;
	bool exists = true;
	int m_LeftBorder, m_UpBorder, m_RightBorder, m_DownBorder;
	double m_x, m_y;//坐标
	int m_nSpeed;//速度（每秒走多远）
	int m_nR;//碰撞半径
	CImage* m_img;
	int m_imgWidth = 10, m_imgHeight = 10;
	bool LoadingImg = false;
	CString strPlus = _T("");
protected:
	int a_AutoAttackInterval;
	int m_Health;
	CString health;
	CImage* m_img_heart;
	bool LoadingHeart = false;
	int m_heartSize = 10;
	int CreateRate;
};