#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maximumPerimeterTriangle' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY sticks as parameter.
 */

bool comp(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

vector<int> maximumPerimeterTriangle(vector<int> sticks) {
    int n = sticks.size();
    vector<int> ans;
    vector<pair<int, int> > v1;
    vector<pair<int, int> > v2;
    vector<pair<int, int> > v3;
    sort(sticks.begin(), sticks.end());
    for (int i = 0; i < n - 2; i++) {
        if (sticks[i] + sticks[i+1] > sticks[i+2]) {
            v1.push_back(make_pair(i, sticks[i]+sticks[i+1]+sticks[i+2]));
        }
    }
    if (v1.size() == 0) {
        ans = {-1};
    }
    else {
        sort(v1.begin(), v1.end(), comp);
        if (v1[0].second > v1[1].second) {
            ans = {sticks[v1[0].first], sticks[v1[0].first+1], sticks[v1[0].first+2]};
        }
        else {
            for (auto &i : v1) {
                if (i.second == v1[0].second) {
                    v2.push_back(make_pair(i.first, sticks[i.first+2]));
                    v3.push_back(make_pair(i.first, sticks[i.first]));
                }
            }
            sort(v2.begin(), v2.end(), comp);
            if (v2[0].second > v2[1].second) {
                ans = {sticks[v2[0].first], sticks[v2[0].first+1], sticks[v2[0].first+2]};
            }
            else {
                sort(v3.begin(), v3.end(), comp);
                if (v3[0].second > v3[1].second) {
                    ans = {sticks[v3[0].first], sticks[v3[0].first+1], sticks[v3[0].first+2]};
                }
                else if (v3[0].second == v3[1].second) {
                    ans = {sticks[v3[0].first], sticks[v3[0].first+1], sticks[v3[0].first+2]};
                }
            }
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string sticks_temp_temp;
    getline(cin, sticks_temp_temp);

    vector<string> sticks_temp = split(rtrim(sticks_temp_temp));

    vector<int> sticks(n);

    for (int i = 0; i < n; i++) {
        int sticks_item = stoi(sticks_temp[i]);

        sticks[i] = sticks_item;
    }

    vector<int> result = maximumPerimeterTriangle(sticks);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
