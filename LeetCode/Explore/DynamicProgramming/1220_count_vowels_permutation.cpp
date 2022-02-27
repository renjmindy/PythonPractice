class Solution {
public:
  int countVowelPermutation(int n) {
    long ans = 0L;
    vector<long> aPC(n, 0), ePC(n, 0), iPC(n, 0), oPC(n, 0), uPC(n, 0);
    aPC[0] = 1L;
    ePC[0] = 1L;
    iPC[0] = 1L;
    oPC[0] = 1L;
    uPC[0] = 1L;
    int MOD = 1000000007;
    for (int i = 1; i < n; i++) {
      aPC[i] = (ePC[i - 1] + iPC[i - 1] + uPC[i - 1]) % MOD;
      ePC[i] = (aPC[i - 1] + iPC[i - 1]) % MOD;
      iPC[i] = (ePC[i - 1] + oPC[i - 1]) % MOD;
      oPC[i] = (iPC[i - 1]) % MOD;
      uPC[i] = (iPC[i - 1] + oPC[i - 1]) % MOD;
    }
    ans = (aPC[n - 1] + ePC[n - 1] + iPC[n - 1] + oPC[n - 1] + uPC[n - 1]) % MOD;
    return (int)ans;
  }
};
