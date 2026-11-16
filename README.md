# Checkoff3
## Introduction

Compiler optimizations improve the machine instructions generated from source code while preserving the program's defined behavior. The original C file usually stays unchanged, but the compiled program can do less unnecessary work and run faster.

This project explores how compilation choices affect performance and why a seemingly simpler operation does not always lead to faster execution.

## What I Explored

- **Optimization levels:** I compared an array-summing program compiled with GCC using `-O0`, `-O1`, `-O2`, and `-O3`.
- **Loop unrolling:** I compared a loop that processes one element per iteration with a manually unrolled version that processes two.
- **Function inlining:** I explored how replacing a function call with the function's operations can reduce call overhead and enable further simplification.
- **Tradeoffs:** I investigated why optimizations can increase code size, complicate debugging, or provide little performance benefit.

## Most Interesting Discoveries

### Optimization made a large difference in the array-sum experiment

The experiment summed an array of one million unsigned integers 100 times per timing sample. The recorded CPU times were:

| Optimization level | Recorded CPU time |
| --- | ---: |
| `-O0` | 213.11 ms |
| `-O1` | 29.58 ms |
| `-O2` | 9.09 ms |
| `-O3` | 8.58 ms |

The recorded `-O3` run was about 25 times faster than `-O0`, but its time was only 5.6% lower than `-O2`. This showed that increasing the optimization level does not always produce a large additional improvement. These results apply to this experiment; other programs and machines may behave differently.

### Fewer loop iterations do not mean fewer additions

In the loop-unrolling example, both versions added eight elements. The original loop used eight iterations, while the unrolled loop used four. Unrolling can reduce loop checks and index updates, but it increases code size and does not guarantee faster execution.

### Inlining can enable more than one optimization

A call such as `square(5)` can be replaced with `5 * 5` through inlining, then simplified to `25` through constant folding. Small, frequently called functions can benefit, but expanding a function at many call sites can make the program larger. The `inline` keyword does not guarantee inlining.

## Reflection and Takeaway

The most surprising discovery was that reducing apparent work, such as loop iterations or function calls, does not automatically improve execution time. I would like to learn more about how compilers decide when unrolling and inlining are worthwhile and how those decisions vary across processors.

**Key takeaway: Measure performance instead of assuming an optimization will help.**
