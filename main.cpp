#include <iostream>
#include "include/Game.hpp"
#include "include/StickStack.hpp"
#include "include/AI.hpp"

int main()
{
	AI ai{ 10 };
	ai.printTable();
	Game game{ 10 };
	game.run();
}
