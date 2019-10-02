


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "IrmaMoves.h"

char **createMapBoard(void) {
    char **board = malloc(sizeof(char *)* 8);
    for (int i = 0; i < 8; i++) {
        board[i] = malloc(sizeof(char) * 8);
    }

    strncpy(board[0], "FF      ", 8);
    strncpy(board[1], " F      ", 8);
    strncpy(board[2], " FF     ", 8);
    strncpy(board[3], "  F     ", 8);
    strncpy(board[4], "  K     ", 8);
    strncpy(board[5], "C  B    ", 8);
    strncpy(board[6], " CC D   ", 8);
    strncpy(board[7], "  C  DD ", 8);
    return board;
};


int charToNum(char x) { // Function created to easily convert letter to number for the board
    switch(x) {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
        default:
            return 0;
    }
}


void printMapBoard (char **board) {
    printf("========\n");
    for (int i=0;i<8;i++){
        printf("%.8s", board[i]);
        printf("\n");
    }
    printf("========\n");
};

char **destroyMapBoard(char **board) {
    for (int i = 0; i < 8; i++) {
        free(board[i]);
    };
    free(board);
    return NULL;
};

char **predictIrmaChange(char *str, Move *irmaMove) {
    char **board = createMapBoard();
    //printMapBoard(board);
    parseNotationString(str, irmaMove);
    board[irmaMove->from_loc.row][charToNum(irmaMove->from_loc.col)] = 'I';
    printMapBoard(board);
    /// Updating Irma
    irmaMove->current_loc.col = irmaMove->from_loc.col;
    irmaMove->current_loc.row = irmaMove->from_loc.row;
    // Moving horizontal and checking for land/ocean
    if (charToNum(irmaMove->from_loc.col) > charToNum(irmaMove->to_loc.col)) { // Moving left
        for(int i = 0; i < (charToNum(irmaMove->from_loc.col) - charToNum(irmaMove->to_loc.col)); i++) {
            if (isalpha(board[irmaMove->current_loc.row][charToNum(irmaMove->current_loc.col)-1])) { // Land
                irmaMove->irma.ws -= 15;
                irmaMove->irma.wg -= 10;
                irmaMove->current_loc.col -= 1;
            } else { // Ocean
                irmaMove->irma.ws += 10;
                irmaMove->irma.wg += 5;
                irmaMove->current_loc.col -= 1;
            }
        }
    } else if(charToNum(irmaMove->from_loc.col) < charToNum(irmaMove->to_loc.col)) { // Moving right
        for(int i = 0; i < (charToNum(irmaMove->to_loc.col) - charToNum(irmaMove->from_loc.col)); i++) {
            if (isalpha(board[irmaMove->current_loc.row][charToNum(irmaMove->current_loc.col)+1])) {
                irmaMove->irma.ws -= 15;
                irmaMove->irma.wg -= 10;
                irmaMove->current_loc.col += 1;
            } else {
                irmaMove->irma.ws += 10;
                irmaMove->irma.wg += 5;
                irmaMove->current_loc.col += 1;
            }
        }
    }
    // Moving vertical and checking for land/ocean
    if (irmaMove->from_loc.row > irmaMove->to_loc.row) { // Moving up
        for (int i = 0; i < (irmaMove->from_loc.row - irmaMove->to_loc.row); i++) {
            if (isalpha(board[irmaMove->current_loc.row-1][charToNum(irmaMove->current_loc.col)])) {
                irmaMove->irma.ws -= 2;
                irmaMove->irma.wg -= 1;
                irmaMove->current_loc.row -= 1;
            } else {
                irmaMove->irma.ws += 6;
                irmaMove->irma.wg += 3;
                irmaMove->current_loc.row -= 1;
            }
        }
    } else if (irmaMove->from_loc.row < irmaMove->to_loc.row) { // Moving down
        for (int i = 0; i < (irmaMove->to_loc.row - irmaMove->from_loc.row); i++) {
            if (isalpha(board[irmaMove->current_loc.row+1][charToNum(irmaMove->current_loc.col)])) {
                irmaMove->irma.ws -= 2;
                irmaMove->irma.wg -= 1;
                irmaMove->current_loc.row += 1;
            } else {
                irmaMove->irma.ws += 6;
                irmaMove->irma.wg += 3;
                irmaMove->current_loc.row += 1;
            }
        }
    }
    board[irmaMove->from_loc.row][charToNum(irmaMove->from_loc.col)] = ' '; // Return the old character
    board[irmaMove->current_loc.row][charToNum(irmaMove->current_loc.col)] = 'I';
    printMapBoard(board);
    return board;
};

void parseNotationString(char *str, Move *Irma) {
    sscanf(str, "%c%d %d %d %c%d", &Irma->from_loc.col, &Irma->from_loc.row, &Irma->irma.ws, &Irma->irma.wg, &Irma->to_loc.col, &Irma->to_loc.row);
    Irma->current_loc.col = 'x';
    Irma->current_loc.row = -1;
};

double difficultyRating(void) {
    return 4;
}

double hoursSpent(void) {
    return 10;
}


void failwhale(void)
{
	printf("fail whale :(\n");
	exit(0);
}

int main(void)
{
	// Create a map board.
	char **board = createMapBoard();

	// Check that some of lands and ocean squares are in the correct positions.
	if (board[0][1] != 'F')
		failwhale();
	if (board[4][2] != 'K')
		failwhale();
	if (board[5][3] != 'B')
		failwhale();
	if (board[2][0] != ' ')
		failwhale();

	printMapBoard(board);

	printf("Hooray!\n");

	return 0;
}
