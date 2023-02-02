#include <stdio.h>
#include "../macros.h"
#include <stdbool.h>

#include "tictactoe.h"

tictactoe main_board;

int main(){
    null_board(main_board);
    main_board.board_elements[0] = X;
    main_board.board_elements[4] = O;
    print_board(main_board);
    main_board.board_elements[4] = Empty;
    print_board(main_board);
    
}

char* get_symbol(player player){
    if (player == Empty) return " ";
    if (player == X) return "X";
    if (player == O) return "O"; 
}

void print_board(tictactoe board ){
    char i,j;
    
    if (board.is_user_turn){
        printf("User's Turn:\n");
    }
    else{
        printf("User's Turn:\n");
    }

    
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            char* ptr_symbol = get_symbol(board.board_elements[cord2move(i,j)]);
            if (j == 0 || j == 1) printf(" %c |", *ptr_symbol);
            if (j == 2) printf(" %c \n", *ptr_symbol);
        }
        
        if (i != 2) printf("------------\n");
    }
    printf("\n");
    printf("\n");
}