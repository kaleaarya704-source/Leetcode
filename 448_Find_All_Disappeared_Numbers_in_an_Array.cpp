//With hash table
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>result;

        unordered_map<int , int>um;

        for(int i = 0 ; i < n ; i++)
        {
            um[nums[i]]++;
        }

        for(int i = 1 ; i <= n ; i++)
        {
            if(um.find(i) == um.end())
            {
                result.push_back(i);
            }
        }
        return result;
    }
};


//With array
// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
        
//         int sz = nums.size();
//         vector<int> ans;
        
//         // Create array B containing numbers 1 to n
//         vector<int> B;
//         for(int i = 1; i <= sz; i++) {
//             B.push_back(i);
//         }
        
//         // Check which numbers from B are missing in nums
//         for(int i = 0; i < sz; i++) {
//             bool flag = false;
            
//             for(int j = 0; j < sz; j++) {
//                 if(B[i] == nums[j]) {
//                     flag = true;
//                     break;
//                 }
//             }
            
//             if(flag == false) {
//                 ans.push_back(B[i]);
//             }
//         }
        
//         return ans;
//     }
// };


// //With set
// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
        
//         int n = nums.size();
//         vector<int> result;
        
//         set<int> st;
        
//         // Insert elements into set
//         for(int i = 0; i < n; i++) {
//             st.insert(nums[i]);
//         }
        
//         // Check from 1 to n
//         for(int i = 1; i <= n; i++) {
//             if(st.find(i) == st.end()) {
//                 result.push_back(i);
//             }
//         }
        
//         return result;
//     }
// };
