#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

void move_disks(int, int, int, int);

/**	Solving the Towers of Hanoi problem using recusive functions.
 *	
 * @param argc: The number of command-line arguements.
 * @param argv: The vector containing command-line arguements.  
 */
int main(int argc, char* argv[]) {
	// Error checking for number of arguments.
	if (argc == 1) {
		std::cout << "Missing arguement.\n";
		std::cout << "Usage: hanoi number-of-Disks.\n";
		exit(1);
	}
	
	// Iterative loop to determine if there are only numeric digits.
	for (int i = 0; argv[1][i] != '\0'; i++)
		if (!isdigit(argv[1][i])) {
			std::cout << "Arguement must be a number.\n";
			std::cout << "Usage: hanoi number-of-Disks.\n";
			exit(1);
		}

	// Numeric string to integer.
	int num_disks = std::stoi(argv[1]);
	
	// Initial call to move_disks method.
	move_disks(num_disks, 1, 2, 3);
	
	return 0;
}

/**	Move disks from each peg.
 *
 * @param num_disks: The number of disks.
 * @param src_peg: The starting position of the disks. 
 * @param dest_peg: The intended position from the starting peg.
 * @param temp_peg: The peg used to hold a disk temporarily. 
 */
void move_disks(int num_disks, int src_peg, int dest_peg, int temp_peg) {
	// Base case.
	if (num_disks >= 1) {
		// 1. Move num_disks - 1 disks from src_peg to temp_peg, using dest_peg to hold.
		move_disks(num_disks - 1, src_peg, dest_peg, temp_peg);
		
		// 2. Move last disk (disk # numDisk) from src_peg to dest_peg.
		std::cout << num_disks << " " << src_peg << " -> " << dest_peg << std::endl;
		
		// 3. Move the num_disks -1 Disks from temp_peg to dest_peg, using src_peg as a temporary holding peg.
		move_disks(num_disks - 1, temp_peg, src_peg, dest_peg);
	}
}
