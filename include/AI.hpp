#pragma once
#include <vector>
/*
 * Not really an AI, but I dont have a better name and this class can play agains
 * human players later (but only the stick game)
 */

class AI
{

public:
	class MoveTable
	{
	private:
		const int m_Rows;
		const int m_Columns;
		std::vector<std::vector<bool>> m_table;
	public:
		MoveTable(int rows, int columns);
		
		int getRowCnt() const;
		int getColumnCnt() const;

		bool getValue(int row, int column) const;
		void setValue(int row, int column, bool value);

		void print() const;
	};
	
	// The possible game moves
	enum class GameMove
	{
		LEFT,
		RIGHT,
		BOTH
	};

private:
	int m_stackHeight;
	// Store which game moves lead to win and which to lose
	// The size of the rows and columns are the stack size + 1
	// so we can store the cases when a stack is empty
	MoveTable m_moveTable;
public:
	explicit AI(int stackHeight);
	
	// Return the move which the AI wants do next
	GameMove getNextGameMove(int leftStackCnt, int rightStackCnt) const;

	void printTable() const;

private:

	void calcMoveTable();

};
