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
	int level = 0;

	logic->InitLevel(level++);
	cout << "Level "<< level << endl;
	while (level<= logic->getLevels())
	{
		if (logic->Game())
		{
			cout << "Level " << 1 + level << endl;
			if (level >= logic->getLevels()) break;
				logic->InitLevel(level++);
		}
	}

	cout << " The End!!! " << endl;

	delete logic;
	return 0;
}