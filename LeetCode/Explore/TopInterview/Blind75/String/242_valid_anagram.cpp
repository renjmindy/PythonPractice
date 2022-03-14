// sorting 

// Complexity analysis
// Time complexity : O(n \log n)O(nlogn). Assume that nn is the length of ss, sorting costs O(n \log n)O(nlogn) and comparing two strings costs O(n)O(n). 
// Sorting time dominates and the overall time complexity is O(n \log n)O(nlogn).
// Space complexity : O(1)O(1). Space depends on the sorting implementation which, usually, costs O(1)O(1) auxiliary space if heapsort is used. 
// Note that in Java, toCharArray() makes a copy of the string so it costs O(n)O(n) extra space, but we ignore this for complexity analysis because:
// It is a language dependent detail.
// It depends on how the function is designed. For example, the function parameter types can be changed to char[].

class Solution {
public:
  bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
  }
  
// one pass hash table

// Complexity analysis
// Time complexity : O(n)O(n). Time complexity is O(n)O(n) because accessing the counter table is a constant time operation.
// Space complexity : O(1)O(1). Although we do use extra space, the space complexity is O(1)O(1) because the table's size stays constant no matter how large nn is.

class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> mps, mpt;
    for (auto &c : s) {
      mps[c]++;
    }
    for (auto &c : t) {
      mpt[c]++;
    }
    for (auto &m : mps) {
      if (mpt[m.first] != m.second) {
        return false;
      }
    }
    return mps.size() == mpt.size();
  }
};
