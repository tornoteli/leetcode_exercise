#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        stringstream str(s);
        string buffer;
        string newS;
        //clean up the string
        while (str >> buffer) {
            for (int i = 0; i< buffer.size(); i++) {
                if (isalnum(buffer[i])) {
                    newS += tolower(buffer[i]);
                }
            }
        }
        //test if is palindrome
        for (int i = 0; i < newS.size()/2; i++) {
            if (newS[i] != newS[newS.size()-1-i]) return false;
        }
        return true;
    }
};

//inplace treatment by others
// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int i = 0, j = s.size() - 1;
        
//         while (i < j) {
//             if (!isalnum(s[i]))
//                 i++;
//             else if (!isalnum(s[j]))
//                 j--;
//             else if (tolower(s[i++]) != tolower(s[j--]))
//                 return false;
//         }
        
//         return true;
//     }
// };