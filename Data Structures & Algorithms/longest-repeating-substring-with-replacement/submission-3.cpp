class Solution {
   public:
    int characterReplacement(string s, int k) {
        int answer = 0;
        array<int, 26> mp = {0};
        int left = 0, right = 0, maxFreq = 0;

        while (right < s.size()) {
            int ch = s[right] - 'A';
            mp[ch]++;
            maxFreq = max(maxFreq, mp[ch]);

            if ((right - left + 1) - maxFreq > k) {
                mp[s[left] - 'A']--;
                left++;
            }

            answer = max(answer, right - left + 1);
            right++;
        }

        return answer;
    }
};
