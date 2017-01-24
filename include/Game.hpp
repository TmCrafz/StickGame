#pragma once
#include "../include/StickStack.hpp"

class Game
{
private:
	StickStack m_stickStack;
	char m_inputBuffer;
	bool m_isRunning;
	int m_round;
public:
	explicit Game(int stackHeight);
	
	void run();
private:
	void readInput();
	void update();
	void render();
};
