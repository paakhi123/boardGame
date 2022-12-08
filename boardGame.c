#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// make_move(board , column , player) updates the board following a move
// by the given player in the given column; returns false if the move
// was illegal because the column was full
// requires: 0 <= column < 7
// player is either 'X' or 'O'
bool make_move(char board[6][7], int column , char player) {
	int row=0;
    for (row = 5; row >= 0; row --) {
        if (!(board[row][column] == 'X' || board[row][column] == 'O')) {
            board[row][column] = player;
            return true;
        }
    }
return false;
}

// check_win(board) returns true if the given player has 4 connected
//   pieces on the board
bool check_win(char board[6][7], char player) {
	int i,j,m;
    for ( i = 0; i < 6; i++) {
        for (j = 0; j < 7; j++) {
            if (board[i][j] == player) {
            // Check for horizontal wins 
                bool horizontal_win = true;
                    for (m = 1; m < 4; m++) {
                        if (j+m >= 7 || board[i][j+m] != player) {
                            horizontal_win = false;
                        }
                    }
            // Check for vertical wins 
                bool vertical_win = true;
                    for (m = 1; m < 4; m++) {
                        if (i+m >= 6 || board[i+m][j] != player) {
                            vertical_win = false;
                        }
                    }
            // Check for diagonal wins 
                bool diagonal_win = true;
                    for ( m = 1; m < 4; m++) {
                        if (i+m >= 6 || j+m >= 7 || board[i+m][j+m] != player) {
                            diagonal_win = false;
                        }
                    }
            // Check for back -diagonal wins 
                bool backdiagonal_win = true;
                    for ( m = 1; m < 4; m++) {
                        if (i+m >= 6 || j-m < 0 || board[i+m][j-m] != player) {
                            backdiagonal_win = false;
                        }       
                    }
            if (horizontal_win || vertical_win || diagonal_win || backdiagonal_win) {
                return true;
                }
            }
        }
    }
return false;
}

void print_board(char board[6][7]) {
	int i,j;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 7; j++) {
            if(board[i][j] == 'X' || board[i][j] == 'O') {
                printf("%c", board[i][j]);
            } 
            else {
                printf("*");
            }
        }
    printf("\n");
    }
}

int main(void) {
	char board[6][7] = {"*******",
						"*******",
						"*******",
						"*******",
						"*******",
						"*******"};
	char player = 'X';
	int move;
	for (move = 0; move < 6*7; move++) {
		printf("Enter the column that player %c wants to play in: ", player);
		int column_value;
		int return_value = scanf("%d", &column_value);
		if (return_value < 1 || column_value < 0 || column_value >= 7) {
			break;
		}
		if (make_move(board , column_value, player)) {
			print_board(board);
			if (check_win(board , player)) {
				printf("Player %c wins!\n", player);
				break;
			}
			if (player == 'X') {
				player = 'O';
			}
			else {
				player = 'X';
			}
		} 
		else {
			printf("Try again.\n");
			move --;
		}
	}
	if (move == 6*7) {
		printf("Tie game.\n");
	}
	char test1[6][7] = {"*******",
						"*******",
						"X******",
						"X*****O",
						"X*****O",
						"X*****O"};
    assert(check_win(test1 , 'X'));
    assert(!check_win(test1 , 'O'));
    char test2[6][7] = {"*******",
						"*******",
						"****O**",
						"X**OXX*",
						"XXOXOX*",
						"XOXOOOX"};
	assert(!check_win(test2 , 'X'));
	assert(check_win(test2 , 'O'));
	char test3[6][7] = {"*******",
						"*******",
						"*******",
						"******O",
						"******O",
						"XXXXOOO"};
	assert(check_win(test3 , 'X'));
	assert(!check_win(test3 , 'O'));
	char test4[6][7] = {"*******",
						"*******",
						"***XOXO",
						"***XXOX",
						"***OOXO",
						"**OXXOX"};
	assert(check_win(test4 , 'X'));
	assert(!check_win(test4 , 'O'));
	
	
	assert(make_move(board,'O','X'));
	assert(board[5][0]=='X');
	assert(check_win);
	
	assert(make_move(board,'O','X'));
	assert(board[2][1]=='X');
	assert(check_win);
	
	assert(make_move(board,'O','X'));
	assert(board[4][3]=='X');
	assert(check_win);
	
	
}
