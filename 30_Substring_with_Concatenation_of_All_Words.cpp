#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
         vector<int> result;
        
        if (s.empty() || words.empty()) return result;
        
        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        
        unordered_map<string, int> wordMap;
        
        // Store frequency of each word
        for (string word : words) {
            wordMap[word]++;
        }
        
        // Try all possible starting points within wordLen
        for (int i = 0; i < wordLen; i++) {
            unordered_map<string, int> windowMap;
            int left = i, count = 0;
            
            // Move window in steps of wordLen
            for (int j = i; j + wordLen <= s.size(); j += wordLen) {
                string word = s.substr(j, wordLen);
                
                if (wordMap.count(word)) {
                    windowMap[word]++;
                    count++;
                    
                    // If more than needed, shrink window
                    while (windowMap[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowMap[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                    
                    // If all words matched
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // Reset window
                    windowMap.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }
        
        return result;
    }
};