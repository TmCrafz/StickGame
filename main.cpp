#include <iostream>
#include "include/StickStack.hpp"

int main()
{
	StickStack stickStack{ 10 };
	stickStack.removeFromLeft();
	stickStack.removeFromBoth();
	stickStack.printStack();
}
