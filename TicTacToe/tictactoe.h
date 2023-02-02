#define cord2move(i,j) (i * 3 + j)

typedef enum{
    Empty = 0,
    X     = 1,
    O     = 2
} player;


typedef struct{
    bool is_user_turn;
    char turns;
    char board_elements[9];
} tictactoe;


void null_board(tictactoe board){
    board.turns = 0;
    char i;

    for (i = 0; i < 9; i++){
        board.board_elements[i] = 0;
    }
}

int check_win(tictactoe board){
    char i;

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

int is_valid_move(tictactoe board, char move){
    if (board.board_elements[move] == Empty) return 1;
    else return 0;
}

void update_turn(tictactoe board, char x_cord, char y_cord, player user){

    char move = cord2move(x_cord,y_cord);

    // Check if the move is valid
    if (!is_valid_move(board,move)){
        printf("Not a valid move\n");
    }
    else{
        board.turns += 1;

        if (user == X)      board.board_elements[move] = user;
        else if (user == O) board.board_elements[move] = user;
    }
}

