#include <stdio.h>
#include <stdlib.h>

const int ROWS = 20;
const int COLS = 10;

int tetro_o[2][2] = {
	{1, 1},
	{1, 1}
};

int * copyBoard(int board[ROWS][COLS]);
void nullBoard(int *board[ROWS][COLS]);

void drawBoard(int *board);

int calcRows(int tetro[][]);
int calcCols(int tetro[][]);

int xPos = 1;
int yPos = 1;



int main(){

	int gameboard[ROWS][COLS];

	int *cb;
	int *tetro = &tetro_o;

	while(running){

		system("clear");

		cb = copyBoard(gameboard);

		for(i = 0; i < calcRows(*tetro); i++){
			for(j = 0; j < calcCols(*tetro); j++){
				*(cb + (j + yPos) + (i + xPos) * COLS) += *tetro[i][j];
			}
		}

		drawBoard();


	return 0;
}


int * copyBoard(int board[ROWS][COLS]){

	int sol[ROWS][COLS];

	for(i = 0; i < ROWS; i++){
		for(j = 0; j < COLS; j++){
			sol[i][j] = board[i][j];
		}
	}

	return sol;
}

void nullBoard(int *board[ROWS][COLS]){
	
}

void drawBoard(int *board){
	for(i = 0; i < COLS; i++){
		printf("-");
	}
	printf("\n");
	for(i = 0; i < ROWS; i++){
		for(j = 0; j < COLS; j++){
			if(*(board + j + i * COLS) == 0){
				printf(" ");
			}else{
				printf("%c", (char) 254);
			}
		}
		printf("\n");
	}
}

int calcRows(int tetro[][]){
	return sizeof(tetro) / sizeof(tetro[0]);
}

int calcCols(int tetro[][]){
	return sizeof(tetro[0]) / sizeof(tetro[0][0]);
}
