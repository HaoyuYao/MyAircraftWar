#include "pch.h"
#include "Player.h"

void Player::UpdatePos(double dDir, int x, int y) {
	if ((m_x <= m_LeftBorder || m_x >= m_RightBorder || m_y <= m_UpBorder || m_y >= m_DownBorder)
		&& (x <= m_LeftBorder || x >= m_RightBorder || y <= m_UpBorder || y >= m_DownBorder));
	else {
		m_x += m_nSpeed * cos(dDir);
		m_y += m_nSpeed * sin(dDir);
	}
}