#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(2);
        sort(nums.begin(),nums.end());
        for(int i =0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                ans[0]=nums[i];
                break;
            }
        }
        int expected_sum = n*(n+1)/2;
        int actual_sum = 0;
        for(int i = 0 ; i<n ; i++)
        actual_sum+=nums[i];
        ans[1]=expected_sum - (actual_sum - ans[0]);
        return ans;
    }
};