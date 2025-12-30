#include <stdio.h>

void towersOfHanoi(int n, char source, char destination, char auxiliary) {

    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    towersOfHanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towersOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {

	/// HW 2: Hanoi


    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);
    printf("\n--- Solution Steps ---\n");
    towersOfHanoi(numDisks, 'A', 'C', 'B');


/*
				Enter the number of disks: 3

				--- Solution Steps ---
				Move disk 1 from A to C
				Move disk 2 from A to B
				Move disk 1 from C to B
				Move disk 3 from A to C
				Move disk 1 from B to A
				Move disk 2 from B to C
				Move disk 1 from A to C
*/

// The time complexity of this algorithm is O(2^n),
// meaning that the number of operations increases exponentially as the number of disks increases.

    return 0;
}