#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
         // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert to long long for safety
        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);
        long long result = 0;

        // Bit manipulation
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;

            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            result += multiple;
        }

        // Apply sign
        if ((dividend < 0) ^ (divisor < 0))
            result = -result;

        return (int)result;
    }
};