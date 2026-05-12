#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
         int count = 0;
        
        vector<int> col(n, 0);
        vector<int> diag1(2 * n, 0);
        vector<int> diag2(2 * n, 0);
        
        solve(0, n, col, diag1, diag2, count);
        
        return count;
    }
      void solve(int row, int n, vector<int>& col, vector<int>& diag1, vector<int>& diag2,    int& count) {
        if (row == n) {
            count++;
            return;
        }
        
        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row + c] || diag2[row - c + n])
                continue;
            
            col[c] = diag1[row + c] = diag2[row - c + n] = 1;
            
            solve(row + 1, n, col, diag1, diag2, count);
            
            col[c] = diag1[row + c] = diag2[row - c + n] = 0;
        }
    }
};