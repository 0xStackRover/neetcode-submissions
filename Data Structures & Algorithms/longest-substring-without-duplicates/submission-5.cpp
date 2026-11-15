class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;
        vector<int> freq(128, -1);

        int left = 0, right = 0;
        while (left < s.size() && right < s.size()) {
            char ch = s[right];
            if (freq[ch] != -1) {
                left = max(left, freq[ch] + 1);
            }
            freq[ch] = right;
            answer = max(right - left + 1, answer);
            right++;
        }
        return answer;
    }
};
