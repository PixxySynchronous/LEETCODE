#include <iostream>
using namespace std;

int main() {
    int n = -5;  // We're printing the 32-bit binary representation of -5

    // Loop from the 31st bit (MSB) to the 0th bit (LSB)
    for (int i = 31; i >= 0; i--) {
        // (n >> i) shifts the i-th bit to the rightmost position (LSB)
        // & 1 isolates the least significant bit (LSB)
        // So ((n >> i) & 1) gives the bit at position i
        cout << ((n >> i) & 1);
    }

    return 1;  // Return non-zero to indicate program completed (usually return 0 is used for success)
}
// This program prints the binary representation of an integer in 32 bits.I couldn't come up with this idea. I feel the need to revise the basics proeperly.