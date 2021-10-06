#include <iostream>
#include <vector>
using namespace std;

int adjacentElementsProduct(vector<int> inputArray) {
    int ans = -999999;
    for (int i = 0; i < inputArray.size()-1; i++) {
        if (ans < inputArray[i] * inputArray[i+1]) {
            ans = inputArray[i] * inputArray[i+1];
        }
    }
    return ans;
}

def adjacentElementsProduct(inputArray):

    maxList = []
    
    for i in range(0, len(inputArray)-1, 1):
        maxList.append(inputArray[i]*inputArray[i+1])
        
    return max(maxList)
