#include <vector>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i = 1 ; i < rows ; i++)
        {
            for(int j = 1 ; j < cols ; j++)
            {
                if(matrix[i][j] != matrix[i-1][j-1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

// for(i = 0 ; i < m ; i++)
// {
//     for(j = 0; j < n ; j++)
//     {
//         if(M[i][j] != M[i+1][j+1])
//         return false;
//     }
// }
// return true;