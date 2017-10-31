#include <stdlib.h>
#include <stdio.h>
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
    Board *b = (Board *) malloc(sizeof(Board));
    Piece* table[8][8];
    Piece* bT1 = initPiece(3, 1, 0, 0);
    Piece* bH1 = initPiece(5, 1, 0, 1);
    Piece* bA1 = initPiece(4, 1, 0, 2);
    Piece* bQ = initPiece(2, 1, 0, 3);
    Piece* bK = initPiece(1, 1, 0, 4);
    Piece* bA2 = initPiece(4, 1, 0, 5);
    Piece* bH2 = initPiece(5, 1, 0, 6);
    Piece* bT2 = initPiece(3, 1, 0, 7);
    table[0][0] = bT1;
    table[0][1] = bH1;
    table[0][2] = bA1;
    table[0][3] = bQ;
    table[0][4] = bK;
    table[0][5] = bA2;
    table[0][6] = bH2;
    table[0][7] = bT2;

    Piece* wT1 = initPiece(3, 0, 7, 0);
    Piece* wH1 = initPiece(5, 0, 7, 1);
    Piece* wA1 = initPiece(4, 0, 7, 2);
    Piece* wQ = initPiece(2, 0, 7, 3);
    Piece* wK = initPiece(1, 0, 7, 4);
    Piece* wA2 = initPiece(4, 0, 7, 5);
    Piece* wH2 = initPiece(5, 0, 7, 6);
    Piece* wT2 = initPiece(3, 0, 7, 7);
    table[7][0] = wT1;
    table[7][1] = wH1;
    table[7][2] = wA1;
    table[7][3] = wQ;
    table[7][4] = wK;
    table[7][5] = wA2;
    table[7][6] = wH2;
    table[7][7] = wT2;

    for(int i=0;i<8;i++){
        Piece* bP = initPiece(6, 1, 1, i);
        Piece* wP = initPiece(6, 0, 6, i);
        table[1][i] = bP;
        table[6][i] = wP;
    }
    for(int i=2;i<6;i++){
        for(int j=0;j<8;j++){
            table[i][j] = 0;
        }
    }
}

wchar_t toASCII(Piece* piece){
    wchar_t ascii;
    if (piece->color == 0){
        if(piece->id == 1) ascii = L'\u256A';
        else if(piece->id == 2) ascii = L'\u256B';
        else if(piece->id == 3) ascii = L'\u256C';
        else if(piece->id == 4) ascii = L'\u256D';
        else if(piece->id == 5) ascii = L'\u256E';
        else ascii = L'\u256F';
    }
    else{
        if(piece->id == 1) ascii = L'\u2564';
        else if(piece->id == 2) ascii = L'\u2565';
        else if(piece->id == 3) ascii = L'\u2566';
        else if(piece->id == 4) ascii = L'\u2567';
        else if(piece->id == 5) ascii = L'\u2568';
        else ascii = L'\u2569';
    }
    return ascii;
}

void print_table(Board *tablero){
  for(int i=0;i<<8;i++){
    for(int j=0;j<8;j++){
      wprintf(L"%c", tablero->table[i][j]);
    }
    printf("\n");
  }
}
