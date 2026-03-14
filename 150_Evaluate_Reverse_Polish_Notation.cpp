#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(const string& t : tokens){
            if(t == "+" || t == "-" || t == "*" || t == "/"){

                int right = stk.top();
                stk.pop();
                int left = stk.top();
                stk.pop();
                int result = 0;

                if(t == "+")
                    result = left + right;
                else if(t == "-")
                    result = left - right;
                else if(t == "*")
                    result = left * right;
                else if(t == "/")
                    result = left / right;

                stk.push(result);
            }
            else
            {
                stk.push(stoi(t));
            }
        }
        return stk.top();
    }
};