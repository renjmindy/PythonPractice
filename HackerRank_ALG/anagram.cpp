#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int anagram(string s) {
    if (s.size() & 1) {
        return -1;
    }
    else {
        int count[26];
        for(int i = 0; i < 26;i++){
            count[i] = 0;
        }
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(i < s.size() / 2) {
                count[s[i] - 'a']++;
            } else {
                count[s[i] - 'a'] = max((count[s[i] - 'a'] - 1), 0);
            }
        }
        for(int i = 0; i < 26;i++){
            ans += abs(count[i]);
        }
        return ans;
    }
 
    /*string a = s.substr(0, s.size()/2);
    string b = s.substr((s.size() / 2), s.size() - 1);
    vector<char> av(a.begin(), a.end());
    vector<char> bv(b.begin(), b.end()); 
    for (char &ca : av) {
        cout << ca << " ";
    }
    cout << "\n";
    for (char &cb : bv) {
        cout << cb << " ";
    }
    cout << "\n";
    for (char &c : av) {
        auto it = find(bv.begin(), bv.end(), c);
        if (it == bv.end()) {
            cout << c << " ";
            ans += 1;
        }    
        else {
            //cout << "\n";
            //b = b.substr(0, it - bv.begin()) + b.substr(it - bv.begin() + 1);
            //cout << b << endl;
            //vector<char> bv(b.begin(), b.end()); 
            for (char &c : bv) {
                cout << "\t" << c << " ";
            }
            cout << "\n";
            count += 1;
        }
    }
    return (s.size()/2) - count;*/
}

/*int anagram(string s) {
    set<int> sp, ap, bp;
    int ans = 0, res = 0, count[26], counta[26], countb[26];
    memset(count, 0, sizeof(count));
    memset(counta, 0, sizeof(counta));
    memset(countb, 0, sizeof(countb));
    //for (int i = 0; i< s.size(); i++) {
    //    if (!sp.count(s[i])) {
    //        count[s[i] - 'a']++;
    //        sp.insert(s[i]);    
    //    }
    //}
    //for (int i = 0; i < 26; i++) {
    //    if (count[i] > 0) {
    //        res += 1;
    //    }
    //}
    //if (res == s.size() && s.size() & 1) {
    //    return -1;
    //}
    if (s.size() & 1) {
        for (int i = 0; i < s.size() / 2; i++) {
            counta[s[i] - 'a']++;
            if (!ap.count(s[i])) {
                ap.insert(s[i]);
            }
        }
        for (int i = (s.size() / 2) + 1; i < s.size(); i++) {
            countb[s[i] - 'a']++;
            if (!bp.count(s[i])) {
                bp.insert(s[i]);
            }
        }
        for (int i = 0; i < 26; i++) {
            if (counta[i] > 0) {
                res += 1;
            }
            if (countb[i] > 0) {
                res += 1;
            }
        }
    }
    else {
        for (int i = 0; i < s.size() / 2; i++) {
            counta[s[i] - 'a']++;
            if (!ap.count(s[i])) {
                ap.insert(s[i]);
            }
        }
        for (int i = s.size() / 2; i < s.size(); i++) {
            countb[s[i] - 'a']++;
            if (!bp.count(s[i])) {
                bp.insert(s[i]);
            }
        }
    }
    if (res > 0 && res == s.size() - 1 && s.size() & 1) {
        return -1;
    }
    if (ap == bp) {
        return 0;
    }
    else {
        for (int i = 0; i < 26; i++) {
            if (counta[i] != countb[i]) {
                ans += (abs(counta[i] - countb[i]));
            }
        }
    }
    return ans/2;
}*/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

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
