// problem code that caused me a late night headache

#include "helpers.h"

double solution(double b_units, bool debug_flag) {
    uint16_t pre_a = getBfromA(b_units);

    // Serialize A
    std::string buffer;
    buffer += static_cast<char>((pre_a & 0xFF00) >> 8);
    buffer += static_cast<char>(pre_a & 0x00FF);

    if (debug_flag) {
        std::cout << "--- Serialize ---" << std::endl;
        std::cout << std::hex << ((pre_a & 0xFF00) >> 8) << std::endl;
        std::cout << std::hex << (pre_a & 0x00FF) << std::endl; 
    }

    // ---- do some stuff ----

    // Deserialize A
    const int HIGH_BYTE_INDEX = 0;
    const int LOW_BYTE_INDEX = 1;

    if (debug_flag) {
        std::cout << "--- Deserialize ---" << std::endl;
        std::cout << "High : " << std::hex << (uint16_t) ((0xFF & buffer[HIGH_BYTE_INDEX]) << 8) << std::endl;
        std::cout << "Low : " << std::hex << (uint16_t) (0xFF & buffer[LOW_BYTE_INDEX]) << std::endl;
        uint16_t tmp_a = ((0xFF & buffer[HIGH_BYTE_INDEX]) << 8) | (0xFF & buffer[LOW_BYTE_INDEX]);
        std::cout << "Sum : " << std::hex << (uint16_t) tmp_a << " (BINGO NO OVERFLOW!)" << std::endl;
    }

    uint16_t post_a = buffer[HIGH_BYTE_INDEX];
    post_a = ((post_a & 0x00FF) << 8);
    post_a |= (buffer[LOW_BYTE_INDEX] & 0x00FF);
    
    const double final_b_units = getAfromB(post_a);
    std::cout << "--- Conversion Results ---" << std::endl;
    PRINT_DOUBLE(b_units);
    PRINT_DOUBLE(final_b_units);

}

int main() {
    // B to A to B conversion test

    // Example shows +1 unit error
    double b_units = 210; // in B is 32,905 in A
 
    // Example that doesn't show 1 unit error
    // double b_units = 20;
    double final_b_units = solution(b_units, true);
}