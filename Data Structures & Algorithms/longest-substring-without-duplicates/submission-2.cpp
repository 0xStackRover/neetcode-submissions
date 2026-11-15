class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;
        vector<int> mp(128, -1);
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];
            if (mp[ch] != -1) {
                left = max(mp[ch] + 1, left);
            }

            mp[ch] = right;
            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};
