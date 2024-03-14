// C++ recursive function to
// solve tower of hanoi puzzle
#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod,
                  char aux_rod)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk%d from rod%c  to rod%c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
// Driver code
int main()
{
    int N = 4;
    // A, B and C are names of rods
    towerOfHanoi(N, 'A', 'C', 'B'); // A is source , B is intermediate and C is destination
    return 0;
}
