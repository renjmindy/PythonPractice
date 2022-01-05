#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'strangeCounter' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER t as parameter.
 */

long long strangeCounter(long long t) {
    long long t0 = 3, ts = 3, cycle = 1;
    while (ts < t) {
        t0 *= 2;
        ts += t0;
        cycle += 1;
    }
    return ts - t + 1;
}

/*long long strangeCounter(long long t) {
    long long t0 = 3, ts = 3, cycle = 1;
    while (ts < t) {
        t0 *= 2;
        ts += t0;
        cycle += 1;
    }
    long long ans = 0;
    for (long long i = ts; i >= t; i--) {
        ans += 1;
    }
    return ans;
}
*/
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    long t = stol(ltrim(rtrim(t_temp)));

    long result = strangeCounter(t);

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
