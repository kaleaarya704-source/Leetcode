#include <vector>

using namespace std;

class Solution {
public:
    void solve(int index, vector<int>& candidates, int target, 
               vector<int>& current, vector<vector<int>>& result) {
        
        // Base case: target achieved
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Traverse from current index
        for (int i = index; i < candidates.size(); i++) {
            
            // If candidate exceeds target → stop
            if (candidates[i] > target) continue;

            // Choose the element
            current.push_back(candidates[i]);

            // Stay at same index (reuse allowed)
            solve(i, candidates, target - candidates[i], current, result);

            // Backtrack
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          vector<vector<int>> result;
        vector<int> current;

        solve(0, candidates, target, current, result);

        return result;
    }
};