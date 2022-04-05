class Solution {
  
private:
  bool func(int i, int j, int idx, vector<vector<char> > &board, string &word, vector<int> &dx, vector<int> &dy) {
    if (idx == word.size()) {
      return true;
    }
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) {
      return false;
    }
    char c = board[i][j];
    board[i][j] = '$';
    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];
      
      bool valid = func(x, y, idx + 1, board, word, dx, dy);
      if (valid) {
        board[i][j] = c;
        return true;
      }
    }
    board[i][j] = c;
    return false;
  }
  
public:
  bool exist(vector<vector<char>>& board, string word) {
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == word[0]) {
          if (func(i, j, 0, board, word, dx, dy)) {
            return true;
          }
        }
      }
    }
    return false;
  }
};
