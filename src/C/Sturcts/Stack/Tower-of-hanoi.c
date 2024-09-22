#include <stdio.h>

// Function to perform the Tower of Hanoi
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    // Base case: If there's only 1 disk, move it directly
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    // Recursive case:
    // Step 1: Move n-1 disks from the 'from_rod' to 'aux_rod' using 'to_rod' as auxiliary
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // Step 2: Move the nth (largest) disk from 'from_rod' to 'to_rod'
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);

    // Step 3: Move the n-1 disks from 'aux_rod' to 'to_rod' using 'from_rod' as auxiliary
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;  // Number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Call the towerOfHanoi function
    towerOfHanoi(n, 'A', 'C', 'B');  // A is the source, C is the destination, B is the auxiliary

    return 0;
}
