/* ARRAY-SUM OPTIMIZATION EXPERIMENT
 *
 * Requires GCC. Open a terminal in the folder containing this file.
 *
 * Compile the same program at four optimization levels:
 *   gcc -O0 simple_array_benchmark.c -o array_O0
 *   gcc -O1 simple_array_benchmark.c -o array_O1
 *   gcc -O2 simple_array_benchmark.c -o array_O2
 *   gcc -O3 simple_array_benchmark.c -o array_O3
 *
 * Run each version:
 *   ./array_O0
 *   ./array_O1
 *   ./array_O2
 *   ./array_O3
 */

#include <stdio.h>
#include <time.h>

#define N 1000000
#define REPEATS 100
#define SAMPLES 7

static unsigned a[N];

int main(void) {
    for (int i = 0; i < N; i++) {
        a[i] = i % 100;
    }

    for (int sample = 0; sample < SAMPLES; sample++) {
        unsigned long long checksum = 0;
        clock_t start = clock();

        for (int repeat = 0; repeat < REPEATS; repeat++) {
            /* Change one value so each repetition has a different input. */
            a[0] = repeat;
            unsigned sum = 0;
            for (int i = 0; i < N; i++) {
                sum += a[i];
            }
            checksum += sum;
        }

        double ms = 1000.0 * (clock() - start) / CLOCKS_PER_SEC;
        printf("Sample %d: %.2f ms, checksum %llu\n", sample + 1, ms, checksum);
    }
    return 0;
}
