#include <iostream>
#include <algorithm>
using namespace std;

bool checkPalindrome(string inputString) {
    string vinputString = inputString;
    reverse(vinputString.begin(), vinputString.end());
    return vinputString == inputString;
}

def checkPalindrome(inputString):
    
    sList = list(inputString)
    vList = sList[::-1]

    if sList == vList:
        return True
    else:
        return False
