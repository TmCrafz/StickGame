#include "../include/Game.hpp"
#include <iostream>
#include <string>

Game::Game(int stackHeight)
: m_stickStack{ stackHeight }
, m_ai{ stackHeight }
, m_inputBuffer{ '\0' }
, m_isRunning{ false }
, m_round{ 0 }
{

}

void Game::run()
{
	m_isRunning = true;
	m_round = 0;
	while (m_isRunning)
	{
		update();
		m_round++;
	}

}

void Game::readNextMoveInput()
{
	std::string validChars{ "" };
	std::string inputText{ "" };
	if (!m_stickStack.isLeftEmpty())
	{
		inputText += "[l] Remove from left ";
		validChars += "l";
	}
	if (!m_stickStack.isRightEmpty())
	{
		inputText += "[r] remove from right ";
		validChars += "r";
	}
	if (!m_stickStack.isLeftEmpty() && !m_stickStack.isRightEmpty())
	{
		inputText += "[b] Remove from both";
		validChars += "b";
	}
	bool success{ false };
	do
	{
		std::cout << inputText << std::endl;
		std::cin >> m_inputBuffer;
		success = validChars.find(m_inputBuffer) != std::string::npos;
	} while(!success);
} 

void Game::update()
{
	m_stickStack.printStack();
	if (m_round % 2 == 0)
	{
		std::cout << "Player One" << std::endl;
	}
	else
	{
		std::cout << "Player Two" << std::endl;
	}
	if (m_round % 2 == 0)
	{
		readNextMoveInput();
		switch(m_inputBuffer)
		{
			case 'l': m_stickStack.removeFromLeft(); break;
			case 'r': m_stickStack.removeFromRight(); break;
			case 'b': m_stickStack.removeFromBoth(); break;
			default: m_isRunning = false;
		}
	}
	// AI
	else
	{
		AI::GameMove move{ m_ai.getNextGameMove(m_stickStack.getLeftStickCount(), m_stickStack.getRightStickCount()) };
		switch(move)
		{
			case AI::GameMove::LEFT: m_stickStack.removeFromLeft(); break;
			case AI::GameMove::RIGHT: m_stickStack.removeFromRight(); break;
			case AI::GameMove::BOTH: m_stickStack.removeFromBoth(); break;
		}
	}
	if (isGameSuccessful())
	{

		if (m_round % 2 == 0)
		{
			std::cout << "Player one wins" << std::endl;
		}
		else
		{
			std::cout << "Player two wins" << std::endl;
		}
		m_isRunning = false;
	}
}

bool Game::isGameSuccessful() const
{
	return m_stickStack.isEmpty();
}
