#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

void timeConversion(string s) {
    
    int hr, mn, sec;
    hr = (s[0]-'0')*10 + (s[1]-'0');
    mn = (s[3]-'0')*10 + (s[4]-'0');
    sec = (s[6]-'0')*10 + (s[7]-'0');
    if (s[8] == 'A' && hr == 12) {
        hr=00; 
     }
     else if (s[8] == 'P') {
         if (hr == 12) {
             hr = 12;
         }
         else {
             hr += 12;     
         }
     }
     
    /*int hour, minute, second;
    char c1, c2;
    scanf("%d:%d:%d%c%c", &hour, &minute, &second, &c1, &c2);
    // printf("%d\n%d\n%d\n%c\n%c", hour, minute, second, c1, c2);
    hour = hour % 12;
    if (c1 == 'P'){
        hour += 12;
    }*/  
     
   printf("%02d:%02d:%02d\n",hr, mn, sec);
   return; 
}

int main()
{

    string s;
    getline(cin, s);

    timeConversion(s);

    return 0;
}
