#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
         int i = 0, j = 0;
        int star = -1, match = 0;

        while (i < s.size()) {
            // Case 1: Characters match or '?'
            if (j < p.size() && (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            }
            // Case 2: '*'
            else if (j < p.size() && p[j] == '*') {
                star = j;
                match = i;
                j++;
            }
            // Case 3: Last pattern pointer was '*', try to match more characters
            else if (star != -1) {
                j = star + 1;
                match++;
                i = match;
            }
            // Case 4: No match
            else {
                return false;
            }
        }

        // Check remaining characters in pattern
        while (j < p.size() && p[j] == '*') {
            j++;
        }

        return j == p.size();
    }
};