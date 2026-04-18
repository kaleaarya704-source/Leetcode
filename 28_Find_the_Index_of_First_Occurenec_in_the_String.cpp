#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
          int n = haystack.size();
        int m = needle.size();

        // Edge case
        if (m == 0) return 0;

        for (int i = 0; i <= n - m; i++) {
            int j = 0;

            // Compare substring
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            // If full match found
            if (j == m) {
                return i;
            }
        }

        return -1;
    }
};