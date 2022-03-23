/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: nsherazi
 *
 * Created on 24 March 2022, 01:28
 */

#include <stdio.h>
#include <stdlib.h>

char matrix[3][3]; /* the tic tac toe matrix */

char checkBoard(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void printBoard(void);

int main(void)
{
char done;

printf("This is the game of Tic Tac Toe.\n");
printf("You will be playing against the computer.\n");

done = ' ';
init_matrix();

do {
printBoard();
get_player_move();
done = checkBoard(); /* see winner */
if(done!= ' ') break; /* winner!*/
get_computer_move();
done = checkBoard(); /* see if winner */
} while(done== ' ');

   printBoard(); /* show final positions */
if(done=='X') printf("\n\nYou won!\n");
else printf("\n\nComputer Won!\n");
  

return 0;
}

/* Initialize the matrix. */
void init_matrix(void)
{
int i, j;

for(i=0; i<3; i++)
for(j=0; j<3; j++) matrix[i][j] = ' ';
}

/* Get a player's move. */
void get_player_move(void)
{
int x, y;

printf("Enter X,Y coordinates for your move: ");
scanf("%d%*c%d", &x, &y);

x--; y--;

if(matrix[x][y]!= ' '){
printf("Invalid move, try again.\n");
get_player_move();
}
else matrix[x][y] = 'X';
}

/* Get a move from the computer. */
void get_computer_move(void)
{
int i, j;
for(i=0; i<3; i++){
for(j=0; j<3; j++)
if(matrix[i][j]==' ') break;
if(matrix[i][j]==' ') break;
}

if(i*j==9) {
printf("draw\n");
exit(0);
}
else
matrix[i][j] = 'O';
}

/* Display the matrix on the screen. */
void printBoard(void)
{
int t;

for(t=0; t<3; t++) {
printf(" %c | %c | %c ",matrix[t][0],
matrix[t][1], matrix [t][2]);
if(t!=2) printf("\n---|---|---\n");
}
printf("\n");
}

/* See if there is a winner. */
char checkBoard(void)
{
int i;

for(i=0; i<3; i++) /* checkBoard rows */
if(matrix[i][0]==matrix[i][1] &&
matrix[i][0]==matrix[i][2]) return matrix[i][0];

for(i=0; i<3; i++) /* checkBoard columns */
if(matrix[0][i]==matrix[1][i] &&
matrix[0][i]==matrix[2][i]) return matrix[0][i];

/* test diagonals */
if(matrix[0][0]==matrix[1][1] &&
matrix[1][1]==matrix[2][2])
return matrix[0][0];

if(matrix[0][2]==matrix[1][1] &&
matrix[1][1]==matrix[2][0])
return matrix[0][2];

return ' ';
}