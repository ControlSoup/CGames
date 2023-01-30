#ifdef _MACROS_H
#define _MACROS_H
#include "../general_macros.h"
#endif

#ifdef _STDLIO_H
#define _STDLIO_H
#include <stdio.h>
#endif


#define cord2move(i,j) (i * 3 + j)

typdef enum{
    Empty = 0,
    X     = 1,
    O     = 2
} player;


typedef struct{
    u_int turns;
    char[9] board_elements;
} tictactoe;


void null_board(tictactoe board){
    tictactoe.turns = 0;
    tictactoe.board_elements = {0,0,0,
                                0,0,0,
                                0,0,0};
}

int check_win(tictactoe board){
    u_int i;

    //Check Diagnol win
    for(i = 0; i < 3; i++){
        // Check horizontal win
        if (board.board_elements[cord2move(i,0)] == 
            board.board_elements[cord2move(i,1)] == 
            board.board_elements[cord2move(i,2)])
            return 1;
            break;
        // Check vertical win
        if (board.board_elements[cord2move(0,i)] == 
            board.board_elements[cord2move(1,i)] == 
            board.board_elements[cord2move(2,i)])
            return 1;
            break;
    }

    if (board.board_elements[cord2move(0,0)] == 
        board.board_elements[cord2move(1,1)] == 
        board.board_elements[cord2move(2,2)])
        return 1;

    else if (board.board_elements[cord2move(0,2)] == 
             board.board_elements[cord2move(1,1)] == 
             board.board_elements[cord2move(2,0)])
             return 1;

    else return 0;
}

int is_valid_move(tictactoe board, u_int move){
    if (board.elements[move] == Empty) return 1;
    else return 0;
}

void update_turn(tictactoe board, u_int x_cord, u_int y_cord, player user){

    u_int move = cord2move(x_cord,y_cord);

    // Check if the move is valid
    if (!is_valid_move(board,move)){
        print("Not a valid move\n");
        break;
    }

    board.turns += 1;

    if (user == X)      board.elements[move] = user;
    else if (user == Y) board.elements[move] = user;
}

