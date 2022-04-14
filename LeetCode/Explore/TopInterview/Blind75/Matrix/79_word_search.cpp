private:
  bool dfs(int i, int j, int pre, string &word, vector<int> &dx, vector<int> &dy, vector<vector<char> > &board) {
    if (pre == word.size()) {
      return true;
    }
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[pre]) {
      return false;
    }
    char c = board[i][j];
    board[i][j] = '#';
    bool tf = false;
    for (int k = 0; k < 4; k++) {
      tf = dfs(i + dx[k], j + dy[k], pre + 1, word, dx, dy, board);
      if (tf) {
        board[i][j] = c;
        return tf;
      }
    }
    board[i][j] = c;
    return tf;
  }
  
public:
    bool exist(vector<vector<char>>& board, string word) {
      vector<int> dx = {0, 0, 1, -1};
      vector<int> dy = {1, -1, 0, 0};
      for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
          if (board[i][j] == word[0]) {
            if (dfs(i, j, 0, word, dx, dy, board)) {
              return true;
            }
          }
        }
      }
      return false;
    }
};
