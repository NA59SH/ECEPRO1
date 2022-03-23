/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: nsherazi
 *
 * Created on 24 March 2022, 01:18
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 5

void readAr(FILE *in, int a[][SIZE]){
    char c[SIZE*2];
    int row=0,col=0;
    if (in == NULL){
        printf("Could not open file");
        return;
    }
    while(fscanf(in, "%s", c) == 1){
        // process buffer
        a[row%SIZE][col%SIZE] = atoi(c);
        if(col%SIZE==(SIZE-1)){
            row++;
        }
        col++;
    }
    if (feof(in)){
        // hit end of file
        fclose(in);
    }
    return;
};

void getParity(int a[][SIZE]){
    int colp = 0, rowp = 0;
    int rp[SIZE], cp[SIZE];
    for(int row=0;row<SIZE;row++){
        rowp=0;
        for(int col=0;col<SIZE;col++){
            rowp += a[row][col];
        }
        rp[row] = rowp%2;
    }

    for(int col=0;col<SIZE;col++){
        colp=0;
        for(int row=0;row<SIZE;row++){
            colp += a[row][col];
        }
        cp[col] = colp%2;
    }

    // print
    printf("Parity Array:\n");
    for(int row=0;row<SIZE;row++){
        for(int col=0;col<SIZE;col++){
            printf("%d ", a[row][col]);
        }
        printf("\n");
    }
    printf("Horizontal Parity: ");
    for(int i=0;i<SIZE;i++){
        printf("%d ", rp[i]);
    }
    printf("\nVertical Parity: ");
    for(int i=0;i<SIZE;i++){
        printf("%d ", cp[i]);
    }
    printf("\n");
}

int main(void){
    FILE *fptr;
    int a[SIZE][SIZE];
    fptr = fopen("array.txt","r");
    readAr(fptr, a);
    getParity(a);
}