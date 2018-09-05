#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ROWS 20
#define COLS 10

int gameboard[ROWS][COLS];
int copiedBoard[ROWS][COLS];

int tetro_o[2][2] = {
	{1, 1},
	{1, 1}
};

int * copyBoard(int board[ROWS][COLS]);
void nullBoard();

void drawBoard(int *board);
int calcRows();
int calcCols();

int xPos = 0;
int yPos = 1;

//some comment for git
char currentTetro = 'o';

int running = 1;




int main(){


	int *cb;
	int *tetro = &(tetro_o[0][0]);

	struct timespec tim, tim2;
  tim.tv_sec = 0;
  tim.tv_nsec = 500000000L;

	nullBoard();

	while(running == 1){

		system("clear");

		cb = copyBoard(gameboard);

		for(int i = 0; i < calcRows(); i++){
			for(int j = 0; j < calcCols(); j++){
				//printf("%d\n", (cb + (j + yPos) + (i + xPos) * COLS));
				int sum = *(cb + (j + yPos) + (i + xPos) * COLS) + *(tetro + j + i * calcCols());
				if((xPos + calcRows()) == ROWS){
					printf("Reached bottom\n");
					gameboard[i + xPos][j + yPos] = sum;
				}else if(sum == 2){
					printf("Reached another one");
					xPos = xPos - 1;
					gameboard[i + xPos][j + yPos] = sum;
				}
				*(cb + (j + yPos) + (i + xPos) * COLS) = sum;
			}
		}

		//running = 0;
		if(xPos < ROWS){
			xPos+= 1;
		}else{
			xPos = 1;
		}


		drawBoard(cb);

		nanosleep(&tim, &tim2);
	}
	return 0;
}


int * copyBoard(int board[ROWS][COLS]){


	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			copiedBoard[i][j] = board[i][j];
		}
	}

	return &(copiedBoard[0][0]);
}

void nullBoard(){
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			gameboard[i][j] = 0;
		}
	}
}

void drawBoard(int *board){
	for(int i = 0; i < COLS; i++){
		printf("-");
	}
	printf("\n");
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			if(*(board + j + i * COLS) == 0){
				printf(" ");
			}else if(*(board + j + i * COLS) == 1){
				printf("0");
			}else{
				printf("x");
			}
		}
		printf("\n");
	}
}

int calcRows(){
	switch(currentTetro){
		case 'o':
			return 2;
	}
}

int calcCols(){
	switch(currentTetro){
		case 'o':
			return 2;
	}
}
