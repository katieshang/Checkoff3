/* FUNCTION-INLINING EXAMPLE
 *
 * Open terminal in the folder containing this file.
 *
 * Compile:
 *   gcc -O2 function_inlining.c -o function_inlining
 *
 * Run:
 *   ./function_inlining
 */

#include <stdio.h>

static inline unsigned square(unsigned x) { return x * x; }

int main(void) {
    unsigned result = square(5);
    printf("Result: %u\n", result);

    return 0;
}
