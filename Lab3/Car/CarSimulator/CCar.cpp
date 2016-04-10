#include "stdafx.h"
#include "CCar.h"
#include <iostream>
#include <iterator>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>

using namespace std;

bool CCar::IsTurnedOn()
{
	if (!m_isEngine)
	{
		return false;
	}
	return true;
}

bool CCar::TurnOffEngine()
{
	if (!m_isEngine)
	{
		return false;
	}
	if (m_speed == 0 && m_gear == 0)
	{
		return true;
	}
	return false;
}

bool CCar::TurnOnEngine()
{
	if (!m_isEngine)
	{
		m_isEngine = true;
		m_gear = 0;
		m_speed = 0;
		return true;
	}
	return false;
}


void CCar::UpdateStatus()
{
	if (m_speed == 0)
	{
		m_state = STAND;
	}
	if (m_speed != 0)
	{
		if (m_moveBack)
		{
			m_state = MOVE_BACK;
		}
		else
		{
			m_state = MOVE_FORWARD;
		}
	}
}

int CCar::GetStatus()
{
	UpdateStatus();
	if (m_state == MOVE_BACK)
	{
		return -1;
	}
	else if (m_state == MOVE_FORWARD)
	{
		return 1;
	}
	return 0;
}


bool CCar::SetGear(int gear)
{
	if (gear < -1 || gear > 5)
	{
		return false;
	}
	if (!m_isEngine && gear != 0)
	{
		return false;
	}
	if (m_gear == 0 && m_speed == 0)
	{
		m_moveBack = false;
	}
	if (gear == -1 && !m_moveBack && (m_gear == 0 || m_gear == 1 )&& m_speed == 0)
	{
		m_moveBack = true;
		m_gear = gear;
		return true;
	}
	if (m_gear == -1 && gear == 1 && m_moveBack && m_speed == 0)
	{
		m_moveBack = false;
		m_gear = gear;
		return true;
	}
	if (m_gear == -1 && gear == 0)
	{
		m_gear = gear;
		return true;
	}
	if (gear == 0)
	{
		m_gear = gear;
		return true;
	}

	if (gear > 0 && (m_speed >= m_restrictions[gear + 1].first && m_speed <= m_restrictions[gear + 1].second) && !m_moveBack)
	{
		m_gear = gear;
		return true;
	}
	return false;
}

bool CCar::SetSpeed(int speed)
{
	if (!m_isEngine && speed == 0)
	{
		return true;
	}
	if (m_isEngine)
	{
		if (m_gear == 0) // Случай когда машина стоит на нейтралке
		{
			if (speed > m_speed)
			{
				cout << "----------------------" << endl;
				return false;
			}
			m_speed = speed;
			return true;
		}
		else if (speed >= m_restrictions[m_gear + 1].first && speed <= m_restrictions[m_gear + 1].second)
		{
			m_speed = speed;
			return true;
		}
	}
	return false;
}

int CCar::GetSpeed()
{
	return m_speed;
}

int CCar::GetGear()
{
	return m_gear;
}