#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target, int start, vector<int>& temp) {
        if(target == 0) {
            result.push_back(temp);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {
            // Skip duplicates
            if(i > start && candidates[i] == candidates[i - 1]) continue;

            // If element exceeds target, stop further exploration
            if(candidates[i] > target) break;

            temp.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, temp);
            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        backtrack(candidates, target, 0, temp);
        return result;
    }
};
