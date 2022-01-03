#include <bits/stdc++.h>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'beautifulTriplets' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER d
 *  2. INTEGER_ARRAY arr
 */

int beautifulTriplets(int d, vector<int> arr) {
    int ans = 0;
    unordered_map<int, int> mp;
    for (int a : arr) {
        mp[a]++;
        ans += mp[a-d]*mp[a-2*d];
    }
    
    // for (int i = 0; i < arr.size() - (2 * d - 2); i++) {
        //cout << arr[i] << " " << arr[i+d-1] << " " << arr[i+2*d-2] << endl;
        //if ((arr[i + d - 1] - arr[i] == d) && (arr[i + 2 * d - 2] - arr[i + d - 1] == d)) {
    //    vector<int>::iterator it1 = find(arr.begin(), arr.end(), arr[i]+d);
    //    vector<int>::iterator it2 = find(arr.begin(), arr.end(), arr[i]+2*d);
    //    if (it1 != arr.end() && it2 != arr.end()) {    
    //        ans += 1;
    //    }
    //}
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = beautifulTriplets(d, arr);

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
