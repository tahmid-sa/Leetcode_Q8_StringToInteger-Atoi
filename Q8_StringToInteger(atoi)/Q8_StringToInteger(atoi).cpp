#include <iostream>
#include <map>
#include <string>

using namespace std;

int myAtoi(string s) {
    bool neg = false;
    map<char, int> mapNums = { {'0', 0},  {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, 
        {'5', 5} , {'6', 6} , {'7', 7} , {'8', 8} , {'9', 9} };
    int retNum = 0;

    if (s.empty() == true) {
        return 0;
    }

    for (int i = 0; i < s.size(); i++) {
        if ((s[i] != ' ' && s[i] != '+' && s[i] != '-') && (retNum == 0 && mapNums.find(s[i]) == mapNums.end())) {
            break;
        }

        if (mapNums.find(s[i]) == mapNums.end() || (s[i] == '0' && retNum == 0)) {
            if (retNum > 0) {
                break;
            }

            if ((s[i] == '-' || s[i] == '+') && (mapNums.find(s[i + 1]) == mapNums.end())) {
                return 0;
            }

            if (s[i] == '-' && retNum == 0) {
                neg = true;
                continue;
            }

            //if (s[i] == '+' && retNum == 0) {
            //    continue;
            //}

            //if (s[i] != ' ' && retNum == 0) {
            //   break;
            //}
        }
        else if (mapNums.find(s[i]) != mapNums.end() && (s[i] != '0' || retNum != 0)) {
            auto numI = mapNums.find(s[i])->second;

            if ((neg == false && ((long)retNum * 10) + numI > pow(2, 31) - 1)) {
                return pow(2, 31) - 1;
            }

            if (neg == true && ((long)retNum * 10) + numI > pow(2, 31)) {
                return -1 * pow(2, 31);
            }

            retNum *= 10;
            retNum += numI;

            continue;
        }
    }

    if (neg == true) {
        retNum *= -1;
    }

    return retNum;
}

int main()
{
    string s = "   -   +000934";

    cout << myAtoi(s);

    return 0;
}