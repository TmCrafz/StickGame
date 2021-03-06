#pragma once

/*
 * The StickStack class represents two stacks of sticks
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
	
	int getLeftStickCount() const;
	int getRightStickCount() const;

	void removeFromLeft();
	void removeFromRight();
	void removeFromBoth();
	
	bool isLeftEmpty() const;
	bool isRightEmpty() const;
	bool isEmpty() const;

	void printStack() const;
};

