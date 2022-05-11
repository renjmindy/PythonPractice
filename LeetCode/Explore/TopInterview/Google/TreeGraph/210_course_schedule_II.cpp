class Solution {
  
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      unordered_map<int, vector<int> > mp;
      vector<int> inDegree(numCourses, 0);
      queue<int> q;
      vector<int> ans;
      
      for (auto &p : prerequisites) {
        mp[p[1]].push_back(p[0]);
        inDegree[p[0]]++;
      }
      
      for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
          q.push(i);
        }
      }
      while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto &child : mp[node]) {
          inDegree[child]--;
          if (inDegree[child] == 0) {
            q.push(child);
          }
        }
      }
      return ans.size() != numCourses ? vector<int> (0, 0) : ans;
    }
};
