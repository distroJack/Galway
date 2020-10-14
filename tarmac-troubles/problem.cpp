// problem code that caused me a late night headache

#include "helpers.h"

double bad_solution(double b_units, bool debug_flag) {
    uint16_t pre_a = getBfromA(b_units);
    
    // Serialize A
    std::string buffer;
    buffer += static_cast<char>(pre_a / 0x100);
    buffer += static_cast<char>(pre_a & 0x00FF);

    if (debug_flag) {
        std::cout << "--- Serialize ---" << std::endl;
        std::cout << std::hex << (pre_a / 0x100) << std::endl;
        std::cout << std::hex << (pre_a & 0x00FF) << std::endl;
    }

    // ---- do some stuff ----

    // Deserialize A
    const int HIGH_BYTE_INDEX = 0;
    const int LOW_BYTE_INDEX = 1;

    if (debug_flag) {
        std::cout << "--- Deserialize ---" << std::endl;
        printf("High : 0x%02x\n", buffer[HIGH_BYTE_INDEX]);
        printf("Low : 0x%02x\n", buffer[LOW_BYTE_INDEX]); // Low byte sign extension overflows us
        uint16_t tmp_a = buffer[HIGH_BYTE_INDEX] * 0x100 + buffer[LOW_BYTE_INDEX];
        std::cout << "Sum : " << std::hex << (uint16_t) tmp_a << " (BINGO OVERFLOW!)" << std::endl;
    }

    uint16_t post_a = buffer[HIGH_BYTE_INDEX] * 0x100;
    post_a += buffer[LOW_BYTE_INDEX];
    
    const double final_b_units = getAfromB(post_a);
    std::cout << "--- Conversion Results ---" << std::endl;
    PRINT_DOUBLE(b_units);
    PRINT_DOUBLE(final_b_units);

}

int main() {
    // B to A to B conversion test

    // Example shows +1 unit error
    double b_units = 210;
 
    // Example that doesn't show 1 unit error
    // double b_units = 20;
    double final_b_units = bad_solution(b_units, true);
}