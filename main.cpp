#include <iostream>
#include "include/StickStack.hpp"

int main()
{
	StickStack stickStack{ 10 };
	stickStack.printStack();
	bool isRunning{ true };
	while(isRunning)
	{
		std::cout << "[l] Remove from left [r] remove from right [b] Remove from both" << std::endl;
		char input{ ' ' };
		std::cin >> input;
		std::cout << std::endl;
		switch(input)
		{
			case 'l' : stickStack.removeFromLeft(); break;
			case 'r' : stickStack.removeFromRight(); break;
			case 'b' : stickStack.removeFromBoth(); break;
			default: isRunning = false;
		}
		stickStack.printStack();
	}
}
