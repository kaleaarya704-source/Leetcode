#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if(m *  n != r * c)
            return mat;

        vector<vector<int>> M2(r , vector<int>(c));

        int a = 0 , b = 0;

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                M2[a][b] = mat[i][j];
                b++;

                if(b == c)
                {
                    a++;
                    b = 0;
                }
            }
        }
        return M2;
    }
};

// a = 0 , b = 0
// for(i = 0 ; i < m ; i++)
// {
//     for(j = 0 ; j < n ; j ++)
//     {
//         M2[a][b] = M1[i][j];
//         b++;
//         if(b == c)
//         {
//             a++;
//             b = 0;
//         }
//     }
// }