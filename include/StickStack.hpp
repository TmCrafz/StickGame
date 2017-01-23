#pragma once

/*
 * The StickStack is a class which represents two Stacks of Sticks.
 */

class StickStack
{
private:
	// Maximal amount of sticks on a stack
	const int m_StackHeight;
	// The actual amount of stacks on the left and right Stack
	int m_leftStack;
	int m_rightStack;

public:

	explicit StickStack(int stackHeight);
	
	void removeFromLeft();
	void removeFromRight();
	void removeFromBoth();

	void printStack() const;
};

