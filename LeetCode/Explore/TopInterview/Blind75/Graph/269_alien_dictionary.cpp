// DFS

// Complexity Analysis
// Time complexity : O(C)O(C).
// Building the adjacency list has a time complexity of O(C)O(C) for the same reason as in Approach 1.
// Again, like in Approach 1, we traverse every "edge", but this time we're using depth-first-search.
// Space complexity : O(1)O(1) or O(U + \min(U^2, N))O(U+min(U2,N)).
// Like in Approach 1, we build an adjacency list. Even though this one is a reversed adjacency list, it still contains the same number of relations.

class Solution {
  
private:
  // False == visited. True == visited && in current explore path.
  unordered_map<char, bool> mpStatus;
  unordered_map<char, unordered_set<char> > mpTable;
  string ans;
  
  // Return true if no cycles detected.
  bool dfs(char c) {
    
    // If `c` already exits in status table, that means it has already been added to output string.
    if (mpStatus.count(c)) {
      return mpStatus[c]; // If this node was grey (true), a cycle was detected.
    }
    
    // Set c's status to True, for it's in the current explore path!
    mpStatus[c] = true;
    
    // Explore c's successors
    for (auto &i : mpTable[c]) {
      if (dfs(i)) {
        return true; // a cycle found
      }
    }
    
    // re-set c's status false after its being visited and explored in current path already
    mpStatus[c] = false;
    ans += c;
    return false;
  }
  
public:
  string alienOrder(vector<string>& words) {
    
    // Step 0: Put all unique letters into table as keys.
    // add all chars in table
    for (auto &word : words) {
      for (auto &c : word) {
        mpTable[c] = {};
      }
    }
    
    // Step 1: Find all edges and add reverse edges to table.
    // populate table
    for (int i = 0; i < words.size() - 1; i++) {
      string curr = words[i];
      string next = words[i + 1];
      
      // Find the first non match and insert the corresponding relation.
      int j = 0;
      for (j = 0; j < min(curr.size(), next.size()); j++) {
        // Find the first mismatch char
        if (curr[j] != next[j]) {
          mpTable[curr[j]].insert(next[j]);
          break;
        }
      }
      
      // Check that next is not a prefix of curr.
      // Handle the corner case: ["abc", "ab"]
      if (j == min(curr.size(), next.size()) && curr.size() > next.size()) {
        return "";
      }
      
    }
      
    // Step 2: DFS to build up the output list.
    for (auto &c : mpTable) {
      if (dfs(c.first)) {
        return "";
      }
    }
      
    if (ans.size() < mpTable.size()) {
      return "";
    }
    
    // Reverse the ouput string
    reverse(ans.begin(), ans.end());
    
    return ans;
  }
};
