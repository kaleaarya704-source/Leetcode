#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;

        for (const auto e : s) {
            if (e != '#')
                s1.push(e);
            else if (!s1.empty())
                s1.pop();
        }

        for (const auto e : t) {
            if (e != '#')
                s2.push(e);
            else if (!s2.empty())
                s2.pop();
        }

        string ans1, ans2;

        while (!s1.empty()) {
            ans1 += s1.top();
            s1.pop();
        }

        while (!s2.empty()) {
            ans2 += s2.top();
            s2.pop();
        }

        return ans1 == ans2;
    }
};