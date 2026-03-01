#include <iostream>
#include <vector>
using namespace std;class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

//Using Hash Table
// class Solution {
//     public :
//         vector<int>twoSum (vector<int>& nums , int t) {
//             unordered_map <int , int>um;
//             for(int i = 0 ; i < nums.size() ; i++){
//                 int temp = t - nums[i]; // t = temp + nums[i];

//                 if(um.find(temp) != um.end())
//                 {
//                     return {um[temp],i};
//                 }
//                 um[nums[i]] = i;
//             }
//             return{};
//         }
// };