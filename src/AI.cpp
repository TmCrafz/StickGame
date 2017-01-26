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

AI::AI(int stackHeight)
: m_stackHeight{ stackHeight }
, m_moveTable{ stackHeight + 1, stackHeight + 1 }
{
	calcMoveTable();
}


AI::GameMove AI::getNextGameMove(int leftStackCnt, int rightStackCnt) const
{
	if (m_moveTable.getValue(leftStackCnt, rightStackCnt) == true)
	{
					
	}
	// This move result in a game state in which we can win, even of the other player do all right
	if (rightStackCnt > 0 && m_moveTable.getValue(leftStackCnt, rightStackCnt - 1) == false)
	{
		return GameMove::RIGHT;
	}
	if (leftStackCnt > 0 && m_moveTable.getValue(leftStackCnt - 1, rightStackCnt) == false)
	{
		return GameMove::LEFT;
	}			
	if (leftStackCnt > 0 && rightStackCnt > 0 && m_moveTable.getValue(leftStackCnt - 1, rightStackCnt - 1) == false)
	{
		return GameMove::BOTH;
	}

	// No clever move possible do anything
	// Implement random choice later
	if (rightStackCnt > 0)
	{
		return GameMove::RIGHT;
	}
	if (leftStackCnt > 0)
	{
		return GameMove::LEFT;
	}
	// Should never get reached
	return GameMove::BOTH;
}

void AI::printTable() const
{
	m_moveTable.print();
}


/**
 * The moveTable have row and column cnt from 0 to m_stackSize.
 * In the Stack Game the player, which pull the takes the last stick wins.
 * There are 3 possible moves: 
 *    -take one stick of the left stack
 *    -take one stick of the right stack
 *    -take one stick of both stacks
 * So a player can win when there are only one stick on every stack or
 * when one stack is empty and the remaining stack have only one stick.
 * A stack is now represented as a tuple of remaining sticks on stack: (leftStack, rightStack)
 * We start with setting the (0, 0) entry to false.
 * Now we check if we can reach this entry from the surrounding fields by making one of the three moves mentioned above.
 * If this is the case we have a win chance from the field where we have test it. We check this for every entry and get
 * a moveTable which says us from which position we have a possibility to win.
 */
void AI::calcMoveTable()
{
	for (int row{ 0 }; row < m_moveTable.getRowCnt(); row++)
	{
		for (int column{ 0 }; column < m_moveTable.getColumnCnt(); column++)
		{
			// The first entry have to be false so the surrounding entries can determine that there can win
			// (There is a win possibility when there is a move which leads to an entry where is no win possibility, 
			// so a entry which is false)
			if (row == 0 && column == 0)
			{
				m_moveTable.setValue(0, 0, false);
			}
			
			// Determine if there is a win chance from this position, when we take a stick of the right stack
			if (column > 0 && m_moveTable.getValue(row, column - 1) == false)
			{
				m_moveTable.setValue(row, column, true);
				continue;
			}
			// Determine if there is a win chance from this position, when we take a stick of the left stack
			if (row > 0 && m_moveTable.getValue(row - 1, column) == false)
			{
				m_moveTable.setValue(row, column, true);
				continue;
			}			
			// Determine if there is a win chance from this position, when we take a stick of both stacks
			if (row > 0 && column > 0 && m_moveTable.getValue(row - 1, column - 1) == false)
			{
				m_moveTable.setValue(row, column, true);
				continue;
			}			
		}
	}
}
