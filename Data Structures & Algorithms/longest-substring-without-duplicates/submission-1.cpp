class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;
        unordered_map<char, int> mp;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            if (mp.find(s[right]) != mp.end()) {
                left = max(mp[s[right]] + 1, left);
            }

            mp[s[right]] = right;
            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};
