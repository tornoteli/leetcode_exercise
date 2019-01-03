#include <iostream>

class Solution {
public:
    int myAtoi(string str) {
        long int output = 0;
        bool isMinus = false;
        int i = 0;
        while (str[i] == ' ' && i < str.size()) {
            i++;
        }
        if (i < str.size()) {
            if (str[i] == '-') {
                isMinus = true;
                i++;
            }else if (str[i] == '+') {
                isMinus = false;
                i++;
            }    
        }
        while (isdigit(str[i]) && i < str.size() && output <= INT_MAX) {
            output = output*10 + (str[i]-48);
            // cout << "output: " << output << endl;
            i++;
        }
        if (isMinus) {
            output = - output;
            // cout << "isMinus: " << isMinus << endl;
        }
        if (output > INT_MAX) return INT_MAX;
        if (output < INT_MIN) return INT_MIN;
        return (int)output;
    }
};