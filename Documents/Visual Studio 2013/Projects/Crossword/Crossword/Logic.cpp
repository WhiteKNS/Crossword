#include "Logic.h"

Logic::Logic()
{
	matrix = new int*[LINES];

	for (int i = 0; i < LINES; ++i)
	{
		matrix[i] = new int[COLUMNS];
	}

	
	counter = 0;

	
}



string Logic::Input(){                                      // User input answer!
	cout << "Input your answer!" << endl;
	cin >> checkword;
	for (unsigned int i = 0; i < checkword.size(); i++){
		if ((checkword.at(i) >= char(65)) && (checkword.at(i) <= char(90))) checkword.at(i) += 32;    // check registers! If user input answer or some symbol in Upper register,the program automatically will change it to lower register;
	}
	return checkword;
}

void Logic::gotoXY(int column, int line)   // Set Cursor position;
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
		);

}

void Logic::InitialHorizontal(string word, int line1, int column1){
	int i, j;
	int k = word.size();
	for (i = line1, j = 0; i <(line1 + k); i++, j++){
		CharField[i][column1] = word.at(j);
	}
}

void Logic::InitialVertical(string word, int line1, int column1){
	int i, j;
	int k = word.size();
	for (i = column1, j = 0; i < (column1 + k); i++, j++){
		CharField[line1][i] = word.at(j);
	}
}

Logic::~Logic()
{
	for (int i = 0; i < LINES; ++i)
		delete[] matrix[i];

	delete[] matrix;
//delete matrix
}

void Logic::Print(){  
	int line2, column2;// Print console
	line2 = 2; column2 = 35;
	gotoXY(column2, line2);
	for (int i = 0; i < LINES; i++, cout<<"\n", line2++, gotoXY(column2, line2)){
		for (int j = 0; j < COLUMNS; j++){
			cout << CharField[i][j] << " ";
		}
	}

}

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


bool Logic::InitLevel(int level)
{
		DataBase *base = DataBase::getInstance();
	base->setVector();
	base->setWords();
	base->setQuestions();
	base->setArrows();
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
	 /*
	 for (unsigned int i = 0; i < LINES; ++i)
	 {
		 for (unsigned int j = 0; j < COLUMNS; ++j)
		 {
			 cout<<matrix[i][j];
		 }
	 }
	 cout << "\n" << endl;*/
	words = base->getWords(level);
	/*
	for (auto i = words.begin(); i != words.end(); ++i)
		std::cout << *i << ' ';

	cout << "\n" << endl;
	*/
	questions = base->getQuestions(level); //0 - number of level;
	/*
	for (auto i = questions.begin(); i != questions.end(); ++i)
		std::cout << *i << ' ';

	cout << "\n" << endl;
	*/
	arrows = base->getArrows(level);
	/*
	for (auto i = arrows.begin(); i != arrows.end(); ++i)
		std::cout << *i << ' ';
		*/
	for (int i = 0; i < LINES; i++){
		for (int j = 0; j < COLUMNS; j++){
			for (int l = 2; l < 9; l++){                          // Paint Field;
				if (1 == matrix[i][j]) CharField[i][j] = char(96);
				if (!matrix[i][j]) CharField[i][j] = char(32);
				if (l == matrix[i][j]) CharField[i][j] = char(l + 47);
			}
		}
	}
	return false;
}

void Logic::Game()
{
	//PrintMatrix();
	//PrintChar();
	Print();
	for (unsigned int i = 0; i < words.size(); i++){
		Flag.push_back(0);
	}

	cout << "\n\n" << endl;
	gotoXY(0, 13);
	for (unsigned int i = 0; i < words.size(); i++){
		if (!Flag[i]) { cout <<i+1<<" "<< questions.at(i) << "   "  << endl; }  // print questions;
	}
	if (words.size() == counter) { cout << "                                        You win!" << endl; return; }

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
	if (Number<1 || Number>words.size())
	{
		cerr << "Wrong data! Try again!" << endl;
		Game();
	}
	else
	{
		int index = Number - 1;
		Input();
		if (checkword == words.at(index))
		{
			Flag[index] = 1;
			counter++;
			if (arrows.at(index) == 0)
			{
				for (int i = 0; i < LINES; ++i)
				{
					for (int j = 0; j < COLUMNS; ++j)
					{
						if (matrix[i][j] == (index + 2))
						{
							InitialHorizontal(words.at(index), i, j);
							system("cls");
							Print();
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
							InitialVertical(words.at(index), i, j);
							system("cls");
							Print();
							break;
						}
					}
				}
			}

			else { cout << "Wrong!!!" << endl; Sleep(500); system("cls"); Print(); }

		}

	}
}