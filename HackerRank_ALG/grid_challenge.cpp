#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gridChallenge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY grid as parameter.
 */

/*bool cmp(string a, string b) {
    for(int i = 0; i < a.size(); i++)
        if(a[i] < b[i])
            return true;
    return false;
}
string gridChallenge(vector<string> grid) {
    for(auto &s : grid)
        sort(s.begin(), s.end());
    if(is_sorted(grid.begin(), grid.end(), cmp))
        return "YES";
    else
        return "NO";
}*/

string gridChallenge(vector<string> grid) {
    for(auto &s : grid) {
        sort(s.begin(), s.end());
    }
    vector<char> a, b;
    vector<int> ans;
    for (int i = 0; i < grid[0].size(); i++) {
        a.clear();
        b.clear();
        for (int j = 0; j < grid.size(); j++) {
            //cout << grid[j][i] << endl;
            a.push_back(grid[j][i]);
        }
        b = a;
        sort(a.begin(), a.end());
        if (a == b) {
            ans.push_back(1);
        }
        else {
            ans.push_back(0);
        }
    }
    int sum = accumulate(ans.begin(), ans.end(), 0);
    return sum == grid[0].size() ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid[i] = grid_item;
        }

        string result = gridChallenge(grid);

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
