#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) {
    bool found_odd = false, changed = true;
    int n = 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }
    for (auto &m : mp) {
        if (m.second % 2 > 0) {
            found_odd = true;
            break;
        }   
    }
    if (!found_odd) {
        return "Empty String";
    }
    while (changed && s.size() > 0) {
        changed = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == s[i + 1]) {
                changed = true;
                s = s.substr(0, i) + s.substr(i + 2, s.size());
                break;
            }
        }
    }
    return s.size() > 0 ? s : "Empty String";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
