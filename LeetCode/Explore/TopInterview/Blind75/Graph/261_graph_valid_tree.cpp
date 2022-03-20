// Advanced Graph Theory + Union Find

// Complexity Analysis
// Let EE be the number of edges, and NN be the number of nodes.
// α(N)α(N) is the Inverse Ackermann Function.
// Time Complexity : O(N \cdot α(N))O(N⋅α(N)).
// When E ≠ N - 1E​=N−1, we simply return false. Therefore, the worst case is when E = N - 1E=N−1. 
// Because EE is proportional to NN, we'll say E = NE=N to simplify the analysis.
// We are putting each of the NN edges into the UnionFind data structure, using the union(...) method. 
// The union(...) method itself has no loops or recursion, so the entire cost of calling it is dependent on the cost of the find(...) method that it calls.
// find(...)'s cost is dependent on how far the node it was searching for is from the root. Using the naïve implementation of union find, this depth could be NN. 
// If this was the case for all of the calls, we'd have a final cost of O(N^2)O(N2).
// However, remember those optimizations we did? Those keep the tree depths very shallow. It turns out that find(...) amortizes to O(α(N))O(α(N)), where α is the 
// Inverse Ackermann Function. The incredible thing about this function is that it grows so slowly that NN will never go higher than 44 in the universe as we know 
// it! So while in "practice" it is effectively O(1)O(1), in "theory" it is not.
// Actually proving this upper bound on the depth is a very advanced proof, which I'd certainly hope you'd never need to do in an interview! If you're interested 
// though, I recommend looking in a good algorithm's text book or paper.
// Anyway, this gives us a total of N \cdot O(α(N)) = O(N \cdot α(N))N⋅O(α(N))=O(N⋅α(N)).
// Space Complexity : O(N)O(N).
// The UnionFind data structure requires O(N)O(N) space to the store the arrays it uses.

class DSU {
  
private:
  vector<int> parents;
  
public:
  
  // For efficiency, we aren't using makeset, but instead initialising
  // all the sets at the same time in the constructor.
  DSU(int n) {
    parents.resize(n);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }
  }
  
  // The find method, without any optimizations. It traces up the parent
  // links until it finds the root node for A, and returns that root.
  int find(int x) {
    while (parents[x] != x) {
      x = parents[x];
    }
    return x;
  }
  
  // The union method, without any optimizations. It returns True if a
  // merge happened, False if otherwise.
  bool unionFind(int x, int y) {
    
    // Find the roots for A and B.
    // Check if A and B are already in the same set.
    if (find(x) == find(y)) {
      return false;
    }
    
    // Merge the sets containing A and B.
    parents[find(x)] = find(y);
    return true;
  }
};

class Solution {
  
public:
  bool validTree(int n, vector<vector<int>>& edges) {
    // connected graph and no cycles is called tree.
    // from edges use disjoiny union to find cycle
    // for no cylces we need n-1 edges.
    
    // Condition 1: The graph must contain n - 1 edges.
    if (edges.size() != n - 1) {
      return false;
    }
    
    // Condition 2: The graph must contain a single connected component.
    // Create a new UnionFind object with n nodes. 
    DSU *dsu = new DSU(n);
    
    // Add each edge. Check if a merge happened, because if it 
    // didn't, there must be a cycle.
    for (auto &edge : edges) {
      if (!dsu->unionFind(edge[0], edge[1])) {
        return false;
      }
    }
    return true;
  }
};
