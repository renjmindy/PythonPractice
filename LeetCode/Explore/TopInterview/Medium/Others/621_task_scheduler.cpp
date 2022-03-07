class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> frequencies(26);
    for (auto &task : tasks) {
      frequencies[task - 'A']++;
    }
    sort(frequencies.begin(), frequencies.end());
    int fMax = frequencies[25];
    int idle_time = (fMax - 1) * n;
    for (int i = frequencies.size() - 2; i >= 0 && idle_time > 0; i--) {
      idle_time -= min(fMax - 1, frequencies[i]);
    }
    idle_time = max(0, idle_time);
    return idle_time + tasks.size();
  }
};
