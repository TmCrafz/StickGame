#include "../include/StickStack.hpp"
#include <iostream>

StickStack::StickStack(int stackHeight)
: m_StackHeight{ stackHeight }
, m_leftStack{ stackHeight }
, m_rightStack{ stackHeight }
{
	
}

int StickStack::getLeftStickCount() const
{
	return m_leftStack;
}

int StickStack::getRightStickCount() const
{
	return m_rightStack;
}

void StickStack::removeFromLeft()
{
	m_leftStack = m_leftStack <= 1 ? 0 : m_leftStack - 1; 
}

void StickStack::removeFromRight()
{
	m_rightStack = m_rightStack <= 1 ? 0 : m_rightStack - 1; 
}

void StickStack::removeFromBoth()
{
	removeFromLeft();
	removeFromRight();
}


bool StickStack::isLeftEmpty() const
{
	return m_leftStack < 1;
}

bool StickStack::isRightEmpty() const
{
	return m_rightStack < 1;
}

bool StickStack::isEmpty() const
{
	return isLeftEmpty() && isRightEmpty();
}

void StickStack::printStack() const
{
	for (int i{ m_StackHeight }; i > 0; i--)
	{
		// If the stack - i is smaller then 0, the stack size 
		// is smaller then i, so no stack is drawn
		char left{ m_leftStack - i < 0 ? ' ' : '-' };
		char right{ m_rightStack - i < 0 ? ' ' : '-'  };
		std::cout << "   " << left << "  " << right << std::endl;
	}
}
