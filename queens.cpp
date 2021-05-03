/*
	queens.cpp
	Date Written: 1/28
	Created by: Kyin Edwards
*/

#include <iostream>

#define N 8

bool place_queens(int[][N], int);
bool is_safe(int[][N], int, int);
void print_solution(int[][N]);

/*
	Solving the Eight Queens problem by calling a 
	recursive and iterative loop. 
	
	@param board the size of the 2D-array. 
*/
int main() {
	int board[N][N] = { {0} };

	// Call the recursive function place_queens() and pass it the 2D-array along with 0 to place a queen in row 0.


	if (place_queens(board, 0))
		print_solution(board);

	else
		std::cout << "Error - no solution found. " << std::endl;

	return 0;
}

/*
	place_queens() function will place queens by iteration.  
	
	@param board the size of the 2D-array.
	
	@param row used to change the position upon recursive call.
	
	@param col used to iterate through the columns of the array. 
	
	@return true to signify successful placement. 
*/
bool place_queens(int board[N][N], int row) {
	// Base case #1 - All queens have been placed successfully.
	if (row >= N)
		return true;

	for (int col = 0; col < N; col++) {
		// If the space is free of queens both vertically and diagonally
		if (is_safe(board, row, col)) {
			// Place queen at board[row][col].
			board[row][col] = 1;
		
            // Recursive call for the next queen.
            if (place_queens(board, row + 1))
				// Base case #2 - All queens in rows below have been successfully placed.
                return true;
			
			// Statement removes the queen by setting board[][N] equal to 0.
            else
                board[row][col] = 0;
        }
	}

	// Base case #3 - We were not able to place a queen anywhere in this row.
	return false;
}

/*
	Used to check if the placed queen is not occupying a space that is in the same position vertically, upper left diagonal and upper right diagonal.  
	
	@param board the size of the 2D-array.
	
	@param row to move through the rows of the array. 
	
	@param col to move through the rows of the array or remain in the same index. 
	
	@return if returning false, one of the three conditions were met.  
*/
bool is_safe(int board[N][N], int row, int col) {
	int i, j;
	
	// Check the rows above this column. col stays the same, row varies from row - 1 down to 0.
	for (i = row - 1; i >= 0; i--)
		// check vertical
		if (board[i][col] == 1)
			return false;
	
	// Check the left diagonal above this row. col varies from col - 1 down to 0, row varies from row - 1 down to 0.
	for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
		if (board[i][j] == 1)
			return false;

	// Check the right diagonal above this row. col varies from col + 1 up to 7, row varies from row - 1 down to 0.
	for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
		if (board[i][j] == 1)
			return false;

	return true;
}

/*
	Print the board.   
	
	@param board the size of the 2D-array.
*/
void print_solution(int board[N][N]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			std::cout << board[i][j] << " ";

			if (j == (N - 1))
				std::cout << std::endl;
		}
}