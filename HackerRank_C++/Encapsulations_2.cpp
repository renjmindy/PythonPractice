#include <iostream>
#include <vector>
using namespace std;

//add class definitions below this line

class Words {
  public:
    Words(vector<string>& n){
      list_of_words = n;
    }
  
    string GetString(int i) {
      if (i >= list_of_words.size()) {
        return "No string exists at this index.";
      }
      else {
        return list_of_words.at(i);
      }
    }
  
    void SetString(string s, int i) {
      if (i >= list_of_words.size()) {
        cout << "No string exists at this index." << endl;
      }
      else {
        list_of_words.at(i) = s;
      }
    }
  
    void CoutStrings() {
       vector<int> vowel_sizes;
       int size;
       for (auto a : list_of_words) {
         size = CountVowels(a, a.length());
         vowel_sizes.push_back(size);
       }
       for (int i = 0; i < vowel_sizes.size(); i++) {
         if (i == vowel_sizes.size()-1) {
           cout << vowel_sizes.at(i) << endl;
         }
         else {
           cout << vowel_sizes.at(i) << ',';
         }
       }
     }
  
  private:
    vector<string> list_of_words;
  
    bool IsVowel(char ch) {
      ch = toupper(ch);
      return (ch=='A' || ch=='E' || ch=='I' ||
              ch=='O' || ch=='U');
    }

    int CountVowels(string str, int n) {
      if (n == 1) {
        return IsVowel(str[n-1]);
      }
      else {
        return CountVowels(str, n-1) + IsVowel(str[n-1]);
      }
    }
};

//add class definitions above this line


int main() {
  
  //add code below this line
  
  vector<string> list = {"house", "cake", "pancake"};
  Words words(list);
  //Words vowels(list);
  //vowels.CoutStrings();
  cout << words.GetString(0) << endl;
  words.SetString("mouse", 0);
  cout << words.GetString(0) << endl;

  //add code above this line
  
  return 0;
  
}
