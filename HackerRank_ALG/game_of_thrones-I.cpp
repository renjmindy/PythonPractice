#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string gameOfThrones(string s) {
    int count[26], ans = 0;
    memset(count, 0, sizeof(count));
    if (s.size() & 1) {
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] & 1) {
                ans += 1;
            }
        }
        return ans == 1 ? "YES" : "NO";
    }
    else {
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] & 1) {
                ans += 1;
            }
        }
        return ans == 0 ? "YES" : "NO";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
