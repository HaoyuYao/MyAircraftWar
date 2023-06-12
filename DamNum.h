#pragma once
class DamNum
{
public:
	void SetX(int x) {
		m_x = x;
	}
	int GetX() {
		return m_x;
	}
	void SetY(int y) {
		m_y = y;
	}
	int GetY() {
		return m_y;
	}
	void SetTimer(int timer) {
		Timer = timer;
	}
	int GetTimer() {
		return Timer;
	}
	void UpdateTimer() {
		Timer++;
	}
	void SetNum(int num) {
		m_num = num;
	}
	int GetNum() {
		return m_num;
	}
public:
	int m_x;
	int m_y;
	int Timer = 0;
	int m_num;
};

