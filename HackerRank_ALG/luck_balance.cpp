#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'luckBalance' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. 2D_INTEGER_ARRAY contests
 */

int luckBalance(int k, vector<vector<int>> contests) {
    vector<int> ones, zeroes;
    int ans = 0;
    for (int i = 0; i < contests.size(); i++) {
        if (contests[i][1] == 1) {
            ones.push_back(contests[i][0]);
        }
        else {
            zeroes.push_back(contests[i][0]);
        }
    }
    if (ones.size() > 0) {
        sort(ones.begin(), ones.end(), greater<int>());
        if (k < ones.size()) {
            for (int i = 0; i < k; i++) {
                ans += ones.at(i);
            }
            for (int i = k; i < ones.size(); i++) {
                ans -= ones.at(i);
            }
        }
        else {
            ans += accumulate(ones.begin(), ones.end(), 0);
        }
    }
    if (zeroes.size() > 0) {
        ans += accumulate(zeroes.begin(), zeroes.end(), 0);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    vector<vector<int>> contests(n);

    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        string contests_row_temp_temp;
        getline(cin, contests_row_temp_temp);

        vector<string> contests_row_temp = split(rtrim(contests_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int contests_row_item = stoi(contests_row_temp[j]);

            contests[i][j] = contests_row_item;
        }
    }

    int result = luckBalance(k, contests);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
