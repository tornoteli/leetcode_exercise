// Valid Anagram
#include <iostream> 
#include <string>
#include <unordered_map> 
using namespace std; 

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> mapS;
        //insert S into hashmap
        for (int i = 0; i < s.size(); i++) {
            mapS[s[i]]++;
        }
        //find if t is in hashmap
        for (int i = 0; i < t.size(); i++) {
            unordered_map<char, int>::iterator found = mapS.find(t[i]);
            if (found == mapS.end()) return false;
            found->second --;
            if (found->second == 0) {
                mapS.erase(found);
            }
        }
        return true;
    }
};

//better solution from others
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.length() != t.length()) return false;
//         int n = s.length();
//         int counts[26] = {0};
//         for (int i = 0; i < n; i++) { 
//             counts[s[i] - 'a']++;
//             counts[t[i] - 'a']--;
//         }
//         for (int i = 0; i < 26; i++)
//             if (counts[i]) return false;
//         return true;
//     }
// };
