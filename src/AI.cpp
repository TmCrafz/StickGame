#include "../include/AI.hpp"
#include <iostream>

AI::AI(int stackSize)
: m_stackSize{ stackSize }
, m_moveTable{ calcMoveTable(stackSize) }
{

}

void AI::printTable() const
{
	for (const std::vector<bool> &rowMoves : m_moveTable)
	{
		for (bool winMove : rowMoves)
		{
			char c{ winMove ? '+' : 'o' };
			std::cout << c; 
		}
		std::cout << std::endl;
	}
}

std::vector<std::vector<bool>> AI::calcMoveTable(int stackSize) const
{
	std::vector<std::vector<bool>> moveTable; 
	
	for (int i{ 0 }; i <= stackSize; i++)
	{
		std::vector<bool> moveRow;
		for (int j{ 0 }; j <= stackSize; j++)
		{
			moveRow.push_back(true);
		}
		moveTable.push_back(moveRow);
	}
	return moveTable;
}
