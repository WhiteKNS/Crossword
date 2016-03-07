#include "Painter.h"


Painter::Painter(int **matrix,unsigned int words_size) //constructor
{
	for (int i = 0; i < LINES; i++){
		for (int j = 0; j < COLUMNS; j++){
			for (unsigned int l = 2; l < 2 + words_size; l++){                          // Paint Field;
				if (1 == matrix[i][j]) CharField[i][j] = char(96);
				if (!matrix[i][j]) CharField[i][j] = " ";
				if (l == matrix[i][j]) CharField[i][j] = to_string(l - 1);
			}
		}
	}
}

void Painter::PaintHorizontal(string word, int line1, int column1){
	int i, j;
	int k = word.size();
	for (i = line1, j = 0; i <(line1 + k); i++, j++){
		CharField[i][column1] = word.at(j);
	}
}

void Painter::PaintVertical(string word, int line1, int column1){
	int i, j;
	int k = word.size();
	for (i = column1, j = 0; i < (column1 + k); i++, j++){
		CharField[line1][i] = word.at(j);
	}
}

void Painter::Print(){
	int line2, column2;// Print console
	line2 = 2; column2 = 35;
	gotoXY(column2, line2);
	for (int i = 0; i < LINES; i++, cout << "\n", line2++, gotoXY(column2, line2)){
		for (int j = 0; j < COLUMNS; j++){
			cout << CharField[i][j] << " ";
		}
	}

}

void Painter::gotoXY(int column, int line)   // Set Cursor position;
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
		);

}