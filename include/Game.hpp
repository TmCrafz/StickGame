#pragma once
#include "../include/AI.hpp"
#include "../include/StickStack.hpp"

class Game
{
private:
	StickStack m_stickStack;
	AI m_ai;
	char m_inputBuffer;
	bool m_isRunning;
	int m_round;
public:
	explicit Game(int stackHeight);
	
	void run();
private:
	// Read from player which is its next move
	void readNextMoveInput();
	void update();

	bool isGameSuccessful() const;
};
