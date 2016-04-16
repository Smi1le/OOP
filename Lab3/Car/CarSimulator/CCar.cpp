#include "stdafx.h"
#include "CCar.h"
#include <iostream>
#include <iterator>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>

using namespace std;

CCar::CCar()
	: m_speed(0)
	, m_gear(0)
	, m_isEngine(false)
	, m_moveBack(false)
	, m_restrictions({ { 0, 20 },
						{ INT_MIN, INT_MAX },
						{ 0, 30 },
						{ 20, 50 },
						{ 30, 60 },
						{ 40, 90 },
						{ 50, 150 } })
{}

bool CCar::IsTurnedOn() const
{
	if (!m_isEngine)
	{
		return false;
	}
	return true;
}

bool CCar::TurnOffEngine()
{
	if (m_isEngine && m_speed == 0 && m_gear == 0)
	{
		m_isEngine = false;
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


CCar::State CCar::UpdateStatus()const
{
	if (m_speed == 0)
	{
		return State::STAND;
	}
	if (m_speed != 0)
	{
		if (m_moveBack)
		{
			return State::MOVE_BACK;
		}
		else
		{
			return State::MOVE_FORWARD;
		}
	}
}

int CCar::GetStatus() const
{
	auto state = UpdateStatus();
	if (state == MOVE_BACK)
	{
		return -1;
	}
	else if (state == MOVE_FORWARD)
	{
		return 1;
	}
	return 0;
}

#pragma message TODO: Refactor me!
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

#pragma message !!
	auto fn = [this](int speed, int gear) {
		return speed >= m_restrictions[gear + 1].first && speed <= m_restrictions[gear + 1].second;
	};

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

int CCar::GetSpeed() const
{
	return m_speed;
}

int CCar::GetGear() const
{
	return m_gear;
}