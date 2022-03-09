class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<string> sp;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] != '.') {
          string s1 = "row" + to_string(i) + to_string(board[i][j] - '0');
          string s2 = "col" + to_string(j) + to_string(board[i][j] - '0');
          string s3 = "box" + to_string(i / 3 * 3 + j / 3) + to_string(board[i][j] - '0');
          if (sp.count(s1) || sp.count(s2) || sp.count(s3)) {
            return false;
          }
          sp.insert(s1);
          sp.insert(s2);
          sp.insert(s3);
        }
      }
    }
    return true;
  }
};
