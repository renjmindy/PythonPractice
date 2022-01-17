#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'unboundedKnapsack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

int unboundedKnapsack(int k, vector<int> arr) {
    vector<int> dp(k+1);
    dp[0] = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = arr.at(i); j < k + 1; j++) {
            dp[j] = max(dp[j], arr.at(i) + dp[j - arr.at(i)]);
        }
    }
    return dp.back();
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        vector<int> ar(n);
        
        for(int j = 0; j < n; j++) {
            int input;
            cin >> input;
            ar[j] = input;
        }
        
        cout << unboundedKnapsack(k,ar) << endl;

    }
    return 0;
}

/*int main()
{   
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
        
    }

    int result = unboundedKnapsack(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}*/

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
