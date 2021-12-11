#include <iostream>
#define N 8

bool place_queens(int[][N], int);
bool is_safe(int[][N], int, int);
void print_solution(int[][N]);

/** Solving the Eight Queens problem by recursion and iteration. 
 *
 * @param board: The size of the 2D-array.
 */
int main() {
	int board[N][N] = {{0}};

	if (place_queens(board, 0))
		print_solution(board);

	else
		std::cout << "Error - no solution found. " << std::endl;

	return 0;
}

/** Place the queen onto the board.
 * 
 * @param board: The size of the 2D-array.
 * @param row: X-coordinate changed upon recursive call.
 * @param col: Y-coordinate changed upon recursive call.
 * @returns: True to signify successful placement.
 */
bool place_queens(int board[N][N], int row) {
	// Base case #1: All queens have been placed successfully.
	if (row >= N)
		return true;

	for (int col = 0; col < N; col++) {
		// Check current space (verical and diagonal).
		if (is_safe(board, row, col)) {
			board[row][col] = 1;
		
            // Recursive call for the next queen.
            if (place_queens(board, row + 1))
				// Base case #2: All queens in rows below have been placed.
                return true;
			
			// Remove the queen.
            else
                board[row][col] = 0;
        }
	}

	// Base case #3: We were not able to place a queen anywhere in this row.
	return false;
}

/** Checks if current queen is not occupying the same vertical or diagonal spaces. 
 * 
 * @param board: The size of the 2D-array.
 * @param row: X-coordinate changed upon recursive call.
 * @param col: Y-coordinate changed upon recursive call.
 * @return: If false, a safe position could not be found.
 */
bool is_safe(int board[N][N], int row, int col) {
	int i, j;

	// Check the rows above this column.
	for (i = row - 1; i >= 0; i--)
		if (board[i][col] == 1)
			return false;
	
	// Check the left diagonal above this row.
	for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
		if (board[i][j] == 1)
			return false;

	// Check the right diagonal above this row.
	for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
		if (board[i][j] == 1)
			return false;

	return true;
}

/** Print the board.   
 * 	
 * @param board: The size of the 2D-array.
 */
void print_solution(int board[N][N]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			std::cout << board[i][j] << " ";

			if (j == (N - 1))
				std::cout << std::endl;
		}
}
