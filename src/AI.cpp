#include "../include/AI.hpp"
#include <cassert>
#include <iostream>

AI::MoveTable::MoveTable(int rows, int columns)
: m_Rows{ rows }
, m_Columns{ columns }
{
	// Fill table with default values
	for (int row{ 0 }; row < m_Rows; row++)
	{
		std::vector<bool> m_rowEntries;
		for (int column{ 0 }; column < m_Columns; column++)
		{
			m_rowEntries.push_back(false);
		}
		m_table.push_back(m_rowEntries);
	}
}

int AI::MoveTable::getRowCnt() const
{
	return m_Rows;
}

int AI::MoveTable::getColumnCnt() const
{
	return m_Columns;
}

bool AI::MoveTable::getValue(int row, int column) const
{
	return m_table.at(row).at(column);
}

void AI::MoveTable::setValue(int row, int column, bool value)
{
	m_table.at(row).at(column) = value;
}

void AI::MoveTable::print() const
{
	for (const std::vector<bool> &rowMoves : m_table)
	{
		for (bool winMove : rowMoves)
		{
			char c{ winMove ? '+' : 'o' };
			std::cout << c; 
		}
		std::cout << std::endl;
	}
}

AI::AI(int stackSize)
: m_stackSize{ stackSize }
, m_moveTable{ stackSize + 1, stackSize + 1 }
{
	calcMoveTable();
}

void AI::printTable() const
{
	m_moveTable.print();
}

void AI::calcMoveTable()
{
	// The moveTable have row and column cnt from 0 to m_stackSize.
	// In the Stack Game the player, which pull the takes the last stick wins.
	// There are 3 possible moves: 
	//    -take one stick of the left stack
	//    -take one stick of the right stack
	//    -take one stock of both stacks
	// So a player can win when there are only oe stick on every stack or
	// When one stack is empty and the remaining stack have only one stick.
	// A stack is now represented as a tuple of remaining sticks on stack: (leftStack, rightStack)
	// So its clear that there is a winning chance when there have the following cases: (1, 0), (0, 1), (1, 1)
	// That are the entries we start with. We fill them into the table and then check if we can get from the other empty entries
	// to this winning entries. Then we can later select the move which lead to a win move (when possible)
	
}
