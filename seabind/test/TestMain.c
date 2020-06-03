/*
 * callmaxofthree.c
 *
 * A small program that illustrates how to call the maxofthree function we wrote in
 * assembly language.
 */

#include <stdio.h>
#include <inttypes.h>
#include "../src/Assembly.h"

int main() {
    printf("%ld\n", plusone(4));
    return 0;
}
