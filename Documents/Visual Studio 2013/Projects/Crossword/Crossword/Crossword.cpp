#include <iostream>
#include <string>
#include "DB.h"
#include "Logic.h"

using namespace std;

int main()

{
	system("color F0");
	system("mode con cols=100 lines=50");
	Logic *logic = new Logic();
	logic->InitLevel(0);
	while (1)
	logic->Game();
	return 0;
}