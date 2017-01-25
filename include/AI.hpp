#pragma once
#include <vector>
/*
 * Not really an AI, but I dont have a better name and this class can play agains
 * human players later (but only the stick game)
 */

class AI
{
private:
	int m_stackSize;
	// Store which game moves lead to win and which to lose
	// The size of the vectors are the stack size + 1
	const std::vector<std::vector<bool>> m_moveTable;

public:
	explicit AI(int stackSize);

	void printTable() const;

private:

	std::vector<std::vector<bool>> calcMoveTable(int stackSize) const;

};
