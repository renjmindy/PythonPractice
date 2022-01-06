#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

bool alternating(string& s) {
    if (s.size() < 2) {
        return 0;
    }
    if (s[0] == s[1]) return 0;
    for (int i = 2; i < s.size(); i++) {
        if (i & 1 && i % 2 > 0) { // odd
            if (s[i] != s[1]) {
                return 0;
            }
        }
        else { // even
            if (s[i] != s[0]) {
                return 0;
            }   
        }
    }
    return 1;
}

int alternate(string s) {
    int ans = -1;
    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            if (i == j) {
                continue;
            }
            string t;
            for (int k = 0; k < s.size(); k++) {
                if (s[k] == i || s[k] == j) {
                    t += s[k];
                }
            }
            //cout << t << endl;
            if (alternating(t)) {
                //cout << t << " " << t.size() << " " << ans << endl;
                if ((int)t.size() > ans) {
                    //cout << t << endl;
                    ans = (int)t.size(); 
                }
            }
        }
    }
    return ans > 0 ? ans : 0;
}

/*int alternate(string s) {
    set<char> ss;
    vector<char> a, b, c;
    vector<int> d;
    for (int i = 0; i < s.size(); i++) {
        ss.insert(s[i]);
    }
    for (auto &i : ss) {
        //cout << i << " ";
        c.push_back(i);
    }
    
    for (int i = 0; i < c.size() - 1; i++) {   
        for (int j = i + 1; j < c.size(); j++) {
            for (int k = 0; k < s.size(); k++) {
                if (s[k] != c[i] && s[k] != c[j]) {
                    a.push_back(s[k]);
                }
            }
            b = a;
            reverse(a.begin(), a.end());
            for (auto &k : b) {
                cout << k << " ";
            }
            cout << "\n";
            for (auto &m : a) {
                cout << m << " ";
            }
            cout << "\n----\n";
            if (a == b) {
                cout << "here\n";
                d.push_back(a.size());
            }
            a.clear();
        }
    }
    return d.size() > 0 ? *max_element(d.begin(), d.end()) : 0;
}*/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

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
