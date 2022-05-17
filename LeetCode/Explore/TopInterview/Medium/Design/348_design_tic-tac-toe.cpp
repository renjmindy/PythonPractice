class TicTacToe {
  
private:
  vector<int> rows, cols;
  int lDiag, rDiag, n;
  
public:
    TicTacToe(int size) {
      n = size;
      for (int i = 0; i < size; i++) {
        rows.push_back(0); //no symbol yet
        cols.push_back(0); //no symbol yet
      }
      lDiag = 0, rDiag = 0;
      //0 - no symbol yet
      //+1 for player 1's entries
      //-1 for player 2's entries
    }
    
    int move(int row, int col, int player) {
      if (player == 1) {
        rows[row]++;
        cols[col]++;
        if (row == col) {
          lDiag++;
        }
        if (row + col == n - 1) {
          rDiag++;
        }
        if (rows[row] == n || cols[col] == n || lDiag == n || rDiag == n) {
          return 1;
        }
      }
      else {
        rows[row]--;
        cols[col]--;
        if (row == col) {
          lDiag--;
        }
        if (row + col == n - 1) {
          rDiag--;
        }
        if (rows[row] == -n || cols[col] == -n || lDiag == -n || rDiag == -n) {
          return 2;
        }
      }
      return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
