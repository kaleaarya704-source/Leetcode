#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        unordered_map<int, int> um;   
        vector<int> ans(n + 1);
        
        um[0] = 0;
        ans[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            um[i] = um[i / 2] + (i % 2);
            ans[i] = um[i];
        }
        
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> ans(n + 1);
        
//         for (int i = 1; i <= n; i++) {
//             ans[i] = ans[i >> 1] + (i & 1);
//         }
        
//         return ans;
//     }
// };