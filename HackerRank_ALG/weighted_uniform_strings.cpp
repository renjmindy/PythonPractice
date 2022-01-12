#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'weightedUniformStrings' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY queries
 */

vector<string> weightedUniformStrings(string s, vector<int> queries) {
    vector<string> ans;
    vector<bool> v(10*1000*1000);
    int c = 0, count[26];
    memset(count, 0, sizeof(count));
    set<int> sp;
    char pre = '1', cur = '1';
    for (int i = 0; i < s.size(); i++) {
        //count[s[i]-'a']++;
        pre = cur;
        cur = s[i];
        if (cur != pre) {
            c = 1;
        }
        else {
            c++;
        }
        v[(s[i] - 'a' + 1)*c] = true;
    }
    /*for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                v[(i+1)*(j+1)] = true;
                //if (!sp.count((j+1)*(i+1))) {
                //    sp.insert((j+1)*(i+1));
                //}
            }
        }
    }*/
    for (int i = 0; i < queries.size(); i++) {
        if (v[queries[i]]) {
            ans.push_back("Yes");
        }
        else {
            ans.push_back("No");
        }
        /*if (sp.count(queries.at(i))) {
            ans.push_back("Yes");
        }
        else {
            ans.push_back("No");
        }*/
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
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
