class Solution {
 public:
  string truncateSentence(string s, int k) {
    size_t i(0);
    int count(0);
    for (; i < s.size(); ++i) {
      if (s[i] == ' ') ++count;
      if (count == k) break;
    }
    if (i == s.size() - 1) return s;
    return s.substr(0, i);
  }
};
