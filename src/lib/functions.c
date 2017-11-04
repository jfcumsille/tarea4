#include <stdlib.h>
#include <stdio.h>
<<<<<<< HEAD
#include <stddef.h>
#include <locale.h>
=======
>>>>>>> master
#include "functions.h"

Piece* initPiece(int id, int color, int row, int col){
    Piece* p = (Piece *)malloc(sizeof(Piece));
    p->id = id;
    p->color = color;
    p->row = row;
    p->col = col;
    return p;
}


Board* initBoard(){
    Board *b = malloc(sizeof(Board));
    Piece* bT1 = initPiece(3, 1, 0, 0);
    Piece* bH1 = initPiece(5, 1, 0, 1);
    Piece* bA1 = initPiece(4, 1, 0, 2);
    Piece* bQ = initPiece(2, 1, 0, 3);
    Piece* bK = initPiece(1, 1, 0, 4);
    Piece* bA2 = initPiece(4, 1, 0, 5);
    Piece* bH2 = initPiece(5, 1, 0, 6);
    Piece* bT2 = initPiece(3, 1, 0, 7);
    b->table[0][0] = bT1;
    b->table[0][1] = bH1;
    b->table[0][2] = bA1;
    b->table[0][3] = bQ;
    b->table[0][4] = bK;
    b->table[0][5] = bA2;
    b->table[0][6] = bH2;
    b->table[0][7] = bT2;

    Piece* wT1 = initPiece(3, 0, 7, 0);
    Piece* wH1 = initPiece(5, 0, 7, 1);
    Piece* wA1 = initPiece(4, 0, 7, 2);
    Piece* wQ = initPiece(2, 0, 7, 3);
    Piece* wK = initPiece(1, 0, 7, 4);
    Piece* wA2 = initPiece(4, 0, 7, 5);
    Piece* wH2 = initPiece(5, 0, 7, 6);
    Piece* wT2 = initPiece(3, 0, 7, 7);
    b->table[7][0] = wT1;
    b->table[7][1] = wH1;
    b->table[7][2] = wA1;
    b->table[7][3] = wQ;
    b->table[7][4] = wK;
    b->table[7][5] = wA2;
    b->table[7][6] = wH2;
    b->table[7][7] = wT2;

    for(int i=0;i<8;i++){
        Piece* bP = initPiece(6, 1, 1, i);
        Piece* wP = initPiece(6, 0, 6, i);
        b->table[1][i] = bP;
        b->table[6][i] = wP;
    }
    for(int i=2;i<6;i++){
        for(int j=0;j<8;j++){
            b->table[i][j] = 0;
        }
    }
    return b;
}

wchar_t toASCII(Piece* piece){
    wchar_t ascii;
    if (piece->color == 0){

        if(piece->id == 1) ascii = L'\x256A';
        else if(piece->id == 2) ascii = L'\x256B';
        else if(piece->id == 3) ascii = L'\x256C';
        else if(piece->id == 4) ascii = L'\x256D';
        else if(piece->id == 5) ascii = L'\x256E';
        else ascii = L'\x256F';
    }
    else{
        if(piece->id == 1) ascii = L'\x2564';
        else if(piece->id == 2) ascii = L'\x2565';
        else if(piece->id == 3) ascii = L'\x2566';
        else if(piece->id == 4) ascii = L'\x2567';
        else if(piece->id == 5) ascii = L'\x2568';
        else ascii = L'\x2569';
    }
    return ascii;
}


void print_table(Board* tablero){
    setlocale(LC_ALL, "en_US.UTF-8");
    printf("\n\t  ________________________________\n");
    for(int i=0;i<8;i++){
        printf("\n");
        printf("\t |");
        for(int j=0;j<8;j++){
            if(!tablero->table[i][j]) printf("   |");
            else {
                wchar_t cell = toASCII(tablero->table[i][j]);
                printf(" %lc |", cell);
            }
        }
        printf("\n");
    }
    printf("\t ---------------------------------\n");
}
