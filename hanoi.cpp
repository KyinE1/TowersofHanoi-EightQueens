/*
	hanoi.cpp
	Date Written: 1/28
	Created by: Kyin Edwards
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

void move_disks(int, int, int, int);

/*
	Solving the Towers of Hanoi problem using recusive functions.
	
	@param argc number of command-line arguements.
	
	@param argv command-line arguements.  
*/
int main(int argc, char* argv[]) {
	int num_disks;
	
	if (argc == 1) {
		std::cout << "Missing arguement " << std::endl;
		std::cout << "Usage: hanoi number-of-Disks " << std::endl;
		exit(1);
	}
	
	// Iterative loop to determine if there are only numeric digits.
	for (int i = 0; argv[1][i] != '\0'; i++)
		if (!isdigit(argv[1][i])) {
			std::cout << "Arguement must be a number " << std::endl;
			std::cout << "Usage: hanoi number-of-Disks " << std::endl;
			exit(1);
		}

	// For numeric string to integer.
	num_disks = std::stoi(argv[1]);
	
	// Initial call to move_disks().
	// num_disks from peg 1 to peg 2 while using the temporary holding peg (3).
	move_disks(num_disks, 1, 2, 3);
	
	return 0;
}

/*
	Move Disks from starting peg to the next peg using the last peg as a temporary hold. 

	@param num_disks how many Disks available to move.
	
	@param src_peg the starting position of the Disks. 
	
	@param dest_peg the intended position from the starting peg.
	
	@param temp_peg the peg used to hold Disks temporarily. 
*/
void move_disks(int num_disks, int src_peg, int dest_peg, int temp_peg) {
	if (num_disks >= 1) {
		// 1. Move num_disks - 1 Disks from src_peg to temp_peg, using dest_peg to hold.
		move_disks(num_disks - 1, src_peg, dest_peg, temp_peg);
		
		// 2. Move last disk (disk # numDisk) from src_peg to dest_peg.
		std::cout << num_disks << " " << src_peg << " -> " << dest_peg << std::endl;
		
		// 3. Move the num_disks -1 Disks from temp_peg to dest_peg, using src_peg as a temporary holding peg.
		move_disks(num_disks - 1, temp_peg, src_peg, dest_peg);
	}
}