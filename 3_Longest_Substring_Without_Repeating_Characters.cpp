#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
    int left = 0, maxLength = 0;

    for (int right = 0; right < s.length(); right++) {
        if (mp.find(s[right]) != mp.end() && mp[s[right]] >= left) {
            left = mp[s[right]] + 1;
        }
        mp[s[right]] = right;
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;

    }
};


// using array 
// int lengthOfLongestSubstring(string s) {
//     vector<int> index(256, -1);
//     int left = 0, maxLength = 0;

//     for (int right = 0; right < s.length(); right++) {
//         if (index[s[right]] >= left) {
//             left = index[s[right]] + 1;
//         }
//         index[s[right]] = right;
//         maxLength = max(maxLength, right - left + 1);
//     }

//     return maxLength;
// }