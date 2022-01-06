#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int countD = 0, countLow = 0, countUp = 0, countS = 0, ans = 0;
    string special_characters = "!@#$%^&*()-+";
    for (int i = 0; i < n; i++) {
        if (isdigit(password[i])) {
            countD += 1;
        }
        if (islower(password[i])) {
            countLow += 1;
        }
        if (isupper(password[i])) {
            countUp += 1;
        }
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' ||
        password[i] == '$' || password[i] == '%' || password[i] == '^' ||
        password[i] == '&' || password[i] == '*' || password[i] == '(' ||
        password[i] == ')' || password[i] == '-' || password[i] == '+') {
            countS += 1;
        }
    }
    if (countD == 0) {
        ans += 1;
    }
    if (countLow == 0) {
        ans += 1;
    }
    if (countUp == 0) {
        ans += 1;
    }
    if (countS == 0) {
        ans += 1;
    }
    if (password.size() + ans < 6) {
        ans += (6 - password.size() - ans);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

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
