#include <iostream>
#include <string>

#include "Pong.hpp"

int main()
{
	//std::srand(static_cast<unsigned>time(NULL));

	Pong pongy;
	while (pongy.whilstRunning())
	{
		pongy.update();
		pongy.render();
	}
	return 0;

}