#include <vector>

using namespace std;

class Solution {
public:
        int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Place elements in correct positions
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 2: Find first missing positive
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // Step 3: If all positions are correct
        return n + 1;
    }
};