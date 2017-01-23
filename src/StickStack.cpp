#include "../include/StickStack.hpp"
#include <iostream>

StickStack::StickStack(int stackHeight)
: m_StackHeight{ stackHeight }
, m_leftStack{ stackHeight }
, m_rightStack{ stackHeight }
{
	
}

void StickStack::removeFromLeft()
{
	m_leftStack--;
}

void StickStack::removeFromRight()
{
	m_rightStack--;
}

void StickStack::removeFromBoth()
{
	removeFromLeft();
	removeFromRight();
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
