/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
private:
  int ptr;
  char buf4[4];
  bool valid[4];

  /*
    returns true if successfully able to serve next char
    char served is saved in "ch" variable
  */
  bool serve_char(char &ch) {
    if (ptr > 3 || !valid[ptr]) {
      // if ptr > 3 || it is not pointing to valid location
      // need to attempt read4 from file
      int read_chars = read4(buf4);
      if (read_chars == 0) {
        // if no more chars could be read, return false
        // since no more chars to serve
        return false;
      }
      else {
        // if could read some chars, set ptr = 0
        // and set valid bits for newly read chars
        for (int i = 0; i < read_chars; ++i) {
          valid[i] = true;
        }
        ptr = 0;
      }
    }
    
    // make pointer invalid to indicate this info is stale
    valid[ptr] = false;
    // copy character into output buffer "ch"
    ch = buf4[ptr++];
    // return true because we could serve an additional character
    return true;
  }
  
public:
  Solution () {
    // ptr points to unread char to serve next
    ptr = 0;
    // valid[i] is true if buf4[i] has valid, unread info
    for (int i = 0; i < 4; ++i) {
      valid[i] = false;
    }
  }
  
  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return    The number of actual characters read
   */
  int read(char *buf, int n) {
    // counts number of chars read
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
      char ch;
      
      // attempt adding one char at a time to buf
      if (!serve_char(ch)) {
        // if could not read more, exit from loop
        break;
      }
      // could get ch, so copy to buf
      // incremement count
      buf[i] = ch;
      ++count;
    }
    
    return count;
  }
};
