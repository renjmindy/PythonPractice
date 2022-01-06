#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int marsExploration(string s) {
    int len = s.size(), ans = 0;
    string t = "SOS";
    for (int i = 1; i < (int)(len/3); i++) {
        t += "SOS";
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            ans += 1;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
