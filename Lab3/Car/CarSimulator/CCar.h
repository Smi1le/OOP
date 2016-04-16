#pragma once
#include <vector>
#include <string>

using scope = std::vector<std::pair<int, int>>;

class CCar
{
public:
	CCar();

	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	bool IsTurnedOn() const;
	int GetSpeed() const;
	int GetGear() const;
	int GetStatus()const;
private:
	enum State { MOVE_BACK, MOVE_FORWARD, STAND };

	State UpdateStatus()const;
	bool m_isEngine;
	bool m_moveBack;
	int m_speed;
	int m_gear;
	scope m_restrictions;
};