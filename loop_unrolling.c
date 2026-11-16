/* LOOP-UNROLLING EXAMPLE
 *
 * Open terminal in the folder containing this file.
 *
 * Compile:
 *   gcc -O0 loop_unrolling.c -o loop_unrolling
 *
 * Run:
 *   ./loop_unrolling
 */

#include <stdio.h>

int main(void) {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int normal_sum = 0;
    int unrolled_sum = 0;

    /* One element per iteration. */
    for (int i = 0; i < 8; i++) {
        normal_sum += a[i];
    }

    /* Two elements per iteration. */
    for (int i = 0; i < 8; i += 2) {
        unrolled_sum += a[i];
        unrolled_sum += a[i + 1];
    }

    printf("Normal sum: %d\n", normal_sum);
    printf("Unrolled sum: %d\n", unrolled_sum);

    return 0;
}
