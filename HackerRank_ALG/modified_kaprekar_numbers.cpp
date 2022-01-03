#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */
 
int getMedian(long n) {
    vector<long> ans;
    while (n >= 1) {
        ans.push_back(n % 10);
        n /= 10;
    }
    if (ans.size() % 2 == 0) {
        return ans.size() / 2;
    }
    else {
        return (ans.size() / 2) + 1;
    }
} 
 
long getDigitSum(long n) {
    vector<long> ans;
    int m = pow(10, getMedian(n));
    while (n >= 1) {
        ans.push_back(n % m);
        n /= m;
    }
    return (long)accumulate(ans.begin(), ans.end(), 0);
}

void kaprekarNumbers(int p, int q) {
    vector<long> ans;
    for (int i = p; i <= q; i++) {
        //cout << i << " " << (long)i*i << endl;
        if (getDigitSum((long)i*i) == i) {
            ans.push_back(i);
        }
    }
    if (ans.size() > 0) {
        for (auto &a : ans) {    
            cout << a << " ";
        }
    }
    else {
        cout << "INVALID RANGE";
    }
}

int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

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
