#include <wchar.h>

typedef struct coords Coords;

struct piece{
    int id;
    int color; // 0: Blanca, 1: Negro
    int row;
    int col;
};
typedef struct piece Piece;

struct board{
    Piece* table[8][8];
};
typedef struct board Board;


Piece *initPiece(int id, int color, int row, int col);
Board *initBoard();
void print_table(Board *tablero);
wchar_t toASCII(Piece *piece);
