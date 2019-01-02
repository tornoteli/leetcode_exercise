//Add Bold Tag in String
//20190102-1
#include <iostream>
#include <string>

//implement the mask approach/brute force time O(mn) space O(2n)
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int N = s.size();
        bool mask[N] = {false};
        //if found dict[i] in s, set those chars in mask to true
        for (int i = 0; i < dict.size(); i++) {
            int found = s.find(dict[i]);//s.find() return size_t
            while (found != string::npos) {
                for (int j = found; j < found+dict[i].size(); j++) {
                    mask[j] = true;
                }
                found = s.find(dict[i], found+1);
            }
        }
        //insert <b> and </b> to every end of trues
        string newS;
        for (int i = 0; i < N; i++) {
            if (i == 0) {
                if (mask[i]) {
                    newS.append("<b>");
                }
            }else{
                if (!mask[i-1] && mask[i]) {
                    newS.append("<b>");
                }
                if (mask[i-1] && !mask[i]) {
                    newS.append("</b>");
                } 
            }
            newS.push_back(s[i]);
            if(i == N-1 && mask[i]) {
                newS.append("</b>");
            }
        }
        return newS;
    }
};