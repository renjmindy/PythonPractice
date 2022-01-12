#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */
 
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, abs(a % b));
    }
} 

int lcm(int a, int b) {
    return (a * b) / gcd(a, b); 
}

int getTotalX(vector<int> a, vector<int> b) {
    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        bool founda = false;
        bool foundb = false;
        for (int j = 0; j < a.size(); j++) {
            if (i % a.at(j)) {
                founda = true;
                break;
            } 
        }
        for (int j = 0; j < b.size(); j++) {
            if (b.at(j) % i) {
                foundb = true;
                break;
            } 
        }
        if (!founda && !foundb) {
            ans += 1;
        }
    }
    return ans;
}

/*int getTotalX(vector<int> a, vector<int> b) {
    int ans = 0;
    vector<int> ap, bp;
    for (int i = 1; i <= 100; i++) {
        ap.clear();
        bp.clear();
        for (int j = 0; j < a.size(); j++) {
            if (i % a.at(j)) {
                ap.push_back(0);
            }
            else {
                ap.push_back(1);
            }
        }
        for (int j = 0; j < b.size(); j++) {
            if (b.at(j) % i) {
                bp.push_back(0);
            }
            else {
                bp.push_back(1);
            }
        }
        if (accumulate(ap.begin(), ap.end(), 0) == a.size() &&
            accumulate(bp.begin(), bp.end(), 0) == b.size()) {
            ans += 1;
        }
    }
    return ans;
}*/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    int total = getTotalX(arr, brr);

    fout << total << "\n";

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
