// Sieve of Eratosthenes
// Make a bool array of lenght n with all entries as false
// then keep finding multiple of i which is less than n and make them true
// 3<=i<=n
// the first value which will change is i*i
// we need not to run loop till n we can do it till sqrt(n)

class Solution {
public:
  int countPrimes(int n) {
    if (n <= 2) {
      return 0;
    }
    int ans = 0;
    vector<bool> dp(n, false);
    for (int i = 2; i <= sqrt(n); i++) {
      if (!dp[i]) {
        for (int j = i*i; j < n; j+=i) {
          dp[j] = true;
        }
      }
    }
    for (int i = 2; i < n; i++) {
      if (!dp[i]) {
        ans++;
      }
    }
    return ans;
  }
};
