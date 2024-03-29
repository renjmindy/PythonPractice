#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'separateNumbers' function below.
 *
 * The function accepts STRING s as parameter.
 */

void separateNumbers(string s) {
    bool passed = false;
    long long int ans = 0;
    if (s[0] == '0') {
        string t = "0";
        long long int n = 1;
        while (n < s.size()) {
            t += to_string(n);
            n += 1;
        }
        if (t == s) {
            passed = true;
        }
    }
    else {
        for (int i = 1; i <= (s.size()/2); i++) {
            ans *= 10;
            ans += (s[i - 1] - '0');
            long long int n = ans + 1;
            string t = s.substr(0, i);
            while (t.size() < s.size()) {
                t += to_string(n);
                n += 1;
            }
            if (s == t) {
                passed = true;
                break;
            }
        }  
    }
    if (passed && s.size() > 1) {
        cout << "YES " + to_string(ans) << endl; 
    }
    else {
        cout << "NO" << endl;
    }
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

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
