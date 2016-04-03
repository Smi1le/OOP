#pragma once
#include <vector>
#include <string>

using scope = std::vector<std::pair<int, int>>;

class CCar
{
public:
	CCar() = default;
	~CCar() = default;
	bool SetCommand();
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	bool IsTurnedOn();
	int GetSpeed();
	int GetGear();

private:
	void Info();
	void GetState();
	enum { MOVE_BACK, MOVE_FORWARD, STAND} m_state;
	bool m_isEngine = false;
	bool m_moveBack = false;
	int m_speed = 0;
	int m_gear = 0;
	scope m_restrictions = { {0, 20},
							 {INT_MIN, INT_MAX},
							 {0, 30},
							 {20, 50},
							 {30, 60},
							 {40, 90},
							 {50, 150} };
};