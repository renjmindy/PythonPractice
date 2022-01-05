#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'happyLadybugs' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING b as parameter.
 */

string happyLadybugs(string b) {
    if (b.empty()) {
        return "YES";
    }
    int count = 0;
    set<char> a;
    unordered_map<char, int> cp;
    unordered_map<char, int> mp;
    for (int i = 0; i < b.size(); i++) {
        if (b[i] != '_') {
            a.insert(b[i]);
            mp[b[i]]++;
            cp[b[i]] += i;
            count++;
        }
    }
    if (count == b.size() && a.size() > 1) {
        if (a.size() % 2 == 0 && a.size() == (b.size() / 2)) {
            for (auto &c : cp) {
                if (c.second % 2 == 0) {
                    return "NO";
                }
            }
        }
        else {
            return "NO";
        }
    }
    for (auto &m : mp) {
        if (m.second == 1 && m.first != '_') {
            return "NO";
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
