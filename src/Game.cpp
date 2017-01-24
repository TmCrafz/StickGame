#include "../include/Game.hpp"
#include <iostream>

Game::Game(int stackHeight)
: m_stickStack{ stackHeight }
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
		render();
		readInput();
		update();
		m_round++;
	}

}

void Game::readInput()
{
	std::cin >> m_inputBuffer;
	std::cout << std::endl;
}

void Game::update()
{
	switch(m_inputBuffer)
	{
		case 'l' : m_stickStack.removeFromLeft(); break;
		case 'r' : m_stickStack.removeFromRight(); break;
		case 'b' : m_stickStack.removeFromBoth(); break;
		default: m_isRunning = false;
	}
}

void Game::render()
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
	std::cout << "[l] Remove from left [r] remove from right [b] Remove from both" << std::endl;
}
