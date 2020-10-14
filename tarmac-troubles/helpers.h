// uint16-double-cast helper consts/funcs

#ifndef UINT16_DOUBLE_CAST_HELPER_H_
#define UINT16_DOUBLE_CAST_HELPER_H_
#include <stdio.h>
#include <iostream>
#include <inttypes.h>
#include <string>

using namespace std;
#define PRINT_DOUBLE(x) std::cout << #x << " : " << x << std::endl;

// Dummy constants used to keep me out of trouble
const double A_TO_B_CONVERSION = 0.0063821f;
const double B_TO_A_CONVERSION = 1 / A_TO_B_CONVERSION;

double getAfromB(const uint16_t b_units) {
    return b_units * A_TO_B_CONVERSION;
}

uint16_t getBfromA(const double a_units) {
    return static_cast<uint16_t> (a_units * B_TO_A_CONVERSION);
}

#endif // UINT16_DOUBLE_CAST_HELPER_H_