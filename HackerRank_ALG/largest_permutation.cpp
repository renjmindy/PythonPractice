#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'largestPermutation' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

vector<int> largestPermutation(int k, vector<int> arr) {
    int j = 0, temp = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != (arr.size() - i) && k > 0) {
            j = i + 1;
            while (arr[j] != (arr.size() - i)) {
                j++;
            }
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            k--;
        }
    }
    return arr;
}

/*bool comp(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

vector<int> largestPermutation(int k, vector<int> arr) {
    int j = 0, n = arr.size();
    vector<pair<int, int> > b;
    for (int i = 0; i < n; i++) {
        b.push_back(make_pair(i, arr.at(i)));
    }
    sort(b.begin(), b.end(), comp);
    while (k > 0) {
        auto itr = find(arr.begin(), arr.end(), b[j].second);
        int idx = itr - arr.begin();
        int temp = arr[j];
        //cout << idx << " " << temp << endl;
        arr[j] = arr[idx];
        arr[idx] = temp;
        k -= 1;
        j += 1;
    }
    return arr;
}*/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    vector<int> result = largestPermutation(k, arr);

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
