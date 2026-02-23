#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0;   // current count of consecutive 1s
    int maxCount = 0; // maximum count found so far

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            count++;                      // increase count
            maxCount = max(maxCount, count);
        } else {
            count = 0;                    // reset if 0 is found
        }
    }
    return maxCount;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << "Maximum Consecutive Ones: "
         << findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
