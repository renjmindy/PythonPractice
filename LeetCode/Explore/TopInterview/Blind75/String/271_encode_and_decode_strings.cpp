// ...

class Codec {

public:
  
  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    string ans;
    for (auto &str : strs) {
      ans += str.size();
      ans += str;
    }
    return ans;
  }
  
  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> ans;
    unsigned i = 0;
    while (i < s.size()) {
      uint8_t count = s[i];
      i++;
      ans.emplace_back();
      while (count > 0) {
        ans.back() += s[i];
        i++;
        count--;
      }
    }
    return ans;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

class Codec {
public:
    char delimeter = '-';
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded;
        
        for (string x: strs){
            encoded += to_string(x.size()) + delimeter + x;
        }
        return encoded;
        
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        
        int i = 0;
        while (i < s.size()){
            int delimeterIdx = s.find(delimeter, i);
            int stringSize = stoi(s.substr(i, delimeterIdx - i));  
            ans.push_back(s.substr(delimeterIdx + 1, stringSize));
            
            i = delimeterIdx + stringSize + 1;
                          
        }
        
        return ans;
    }
};
