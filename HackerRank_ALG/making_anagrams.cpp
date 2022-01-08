#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makingAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int makingAnagrams(string s1, string s2) {
    int ans = 0, count[26];
    memset(count, 0, sizeof(count));
    set<int> s1p;
    for (int i = 0; i < s1.size(); i++) {
        count[s1[i] - 'a']++;
        if (!s1p.count(s1[i])) {
            s1p.insert(s1[i]);
        }
    }
    for (int i = 0; i < s2.size(); i++) {
        if (!s1p.count(s2[i])) {
            //cout << s2[i] << " ";
            ans += 1;
        } 
        else {
            if (count[s2[i] - 'a'] > 0) {
                count[s2[i] - 'a'] -= 1;
            }
            else {
                ans += 1;
            }
         }
    }
    for (int i = 0; i < 26; i++) {
        ans += count[i];
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
