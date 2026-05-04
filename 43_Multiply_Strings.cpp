#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
          int n = num1.size(), m = num2.size();
        
        // Result can be at most n + m digits
        vector<int> result(n + m, 0);
        
        // Multiply each digit
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        
        // Convert result to string
        string res = "";
        for (int num : result) {
            if (!(res.empty() && num == 0)) {
                res += to_string(num);
            }
        }
        
        return res.empty() ? "0" : res;
    }
};