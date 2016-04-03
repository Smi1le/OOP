#include "stdafx.h"
#include "CCar.h"
#include <iostream>
#include <iterator>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>



using namespace std;

bool CCar::SetCommand()
{
	cout << "Please enter command\n";
	string command;
	vector<string> instructions;
	getline(cin, command);
	boost::split(instructions, command, boost::is_any_of(" "));
	if (instructions[0] == "")
	{
		std::cout << "GoodBay " << endl;
		return false;
	}
	if (instructions[0] == "Info")
	{
		this->Info();
	}
	else if (instructions[0] == "EngineOn")
	{
		this->TurnOnEngine();
	}
	else if (instructions[0] == "EngineOff")
	{
		this->TurnOffEngine();
	}
	else if (instructions[0] == "SetGear")
	{
		this->SetGear(atoi(instructions[1].c_str()));
	}
	else if (instructions[0] == "SetSpeed")
	{
		this->SetSpeed(atoi(instructions[1].c_str()));
	}
	else
	{
		std::cout << "Entered an incorrect command" << std::endl;
	}
	return true;
}

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
	cout << "To turn off the engine reduce your speed to 0 and switch the transmission in neutral" << endl;
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


void CCar::GetState()
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

bool CCar::SetGear(int gear)
{
	if (gear < -1 || gear > 5)
	{
		cout << "Wrong transmission was specified" << endl;
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
	std::cout << "It is impossible to enable the transfer of.\n";
	return false;
}

bool CCar::SetSpeed(int speed)
{
	if (!m_isEngine && speed != 0)
	{
		cout << "Engine is off." << endl;
		return false;
	}
	else if (m_gear == 0) // Случай когда машина стоит на нейтралке
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
	cout << "You can not put that kind of speed in this transmission" << endl;
	return false;
}

void CCar::Info()
{
	if (m_isEngine)
	{
		cout << "Engine is turn on.\n";
	}
	cout << "Car has the " << m_speed << " speed\n";
	cout << "Car has the " << m_gear << " gear\n";
	this->GetState();
	switch (m_state)
	{
	case MOVE_BACK:
		cout << "Car moves backwards.\n";
		break;
	case MOVE_FORWARD:
		cout << "Car moves forward.\n";
		break;
	case STAND:
		cout << "The car is stationary.\n";
		break;
	}
}

int CCar::GetSpeed()
{
	return m_speed;
}

int CCar::GetGear()
{
	return m_gear;
}