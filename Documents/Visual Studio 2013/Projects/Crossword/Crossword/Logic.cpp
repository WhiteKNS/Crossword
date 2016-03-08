#include "Logic.h"

Logic::Logic() : counter(0), base(DataBase::getInstance())
{
	matrix = new int*[LINES];

	for (int i = 0; i < LINES; ++i)
	{
		matrix[i] = new int[COLUMNS];
	}

	base->setGame();
}


const int Logic::getLevels()
{
	return base->getNumberOfLevels();
}

string Logic::Input(){                                      // User input answer!
	cout << "Input your answer!" << endl;
	cin >> checkword;
	transform(checkword.begin(), checkword.end(), checkword.begin(), tolower);
	return checkword;
}


Logic::~Logic()
{
	for (int i = 0; i < LINES; ++i)
		delete[] matrix[i];

	delete[] matrix;
}

bool Logic::InitLevel(int level)
{
	 field = base->getCrossword(level);

	 int k = 0;

	 for (unsigned int i = 0; i < LINES; ++i)
	 {
		 for (unsigned int j = 0; j < COLUMNS; ++j)
		 {
			 matrix[i][j] = field.at(k);
			 ++k;
		 }
	 }
	
	words = base->getWords(level);

	questions = base->getQuestions(level); //0 - number of level;
	
	arrows = base->getArrows(level);
	
	painter = new Painter(matrix, words.size());
	
	Flag.clear();

	for (unsigned int i = 0; i < words.size(); i++)
		Flag.push_back(false);

	return false;
}

bool Logic::Game()
{
	painter->Print();

	cout << "\n\n" << endl;
	painter->gotoXY(0, 13);
	for (unsigned int i = 0; i < words.size(); i++)
	{
		if (!Flag[i]) { cout <<i+1<<" "<< questions.at(i) << "   "  << endl; }  // print questions;
	}
	if (words.size() == counter) { cout << "                                        You win!" << endl; Sleep(3000); system("cls"); counter = 0; return true; }

	unsigned int Number;
	cout << "\nInput NUMBER of question!" << endl;
	cin >> Number;
	if (cin.fail()){                                                              // check data type;
		cerr << "Wrong data type! Try again! Input INT data!" << endl;
		cin.clear();
		cin.sync();
		Sleep(1000);
		system("cls");
		Game();
	}
	if (Number<1 || Number>words.size()||Flag[Number-1])
	{
		cerr << "Wrong data! Try again!" << endl;
		Sleep(500); system("cls");
		Game();
	}
	else
	{
		int index = Number - 1;
		Input();
		if (checkword == words.at(index))
		{
			Flag[index] = true;
			counter++;
			if (arrows.at(index) == 0)
			{
				for (int i = 0; i < LINES; ++i)
				{
					for (int j = 0; j < COLUMNS; ++j)
					{
						if (matrix[i][j] == (index + 2))
						{
							painter->PaintHorizontal(words.at(index), i, j);
							system("cls");
							painter->Print();
							break;
						}
					}
				}
			}
			else if (arrows.at(index) == 1)
			{
				for (int i = 0; i < LINES; ++i)
				{
					for (int j = 0; j < COLUMNS; ++j)
					{
						if (matrix[i][j] == (index + 2))
						{
							painter->PaintVertical(words.at(index), i, j);
							system("cls");
							painter->Print();
							break;
						}
					}
				}
			}
		}
		else { cout << "Wrong!!!" << endl; Sleep(500); system("cls"); painter->Print(); }
	}
	return false;
}

/*
void Logic::PrintChar()
{
for (int i = 0; i < LINES; i++, cout << "\n"){
for (int j = 0; j < COLUMNS; j++){
cout << CharField[i][j];
}
}
}


void Logic::PrintMatrix()
{
for (int i = 0; i < LINES; i++, cout<<"\n")
{
for (int j = 0; j < COLUMNS; j++)
cout << matrix[i][j];
}
}

for (auto i = Flag.begin(); i != Flag.end(); i++)
cout << *i << " ";

*/