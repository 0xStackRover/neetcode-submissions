class Solution {
   public:
    int characterReplacement(string s, int k) {
        if (s.empty()) {
            return 0;
        }

        int answer = 0, changes = 0, left = 0, right = 0;
        vector<int> freq(26, 0);

        while (right < s.size()) {
            const char ch = s[right] - 'A';
            freq[ch]++;
            changes = max(changes, freq[ch]);

            if ((right - left + 1 - changes) > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            answer = max(answer, right - left + 1);
            right++;
        }

        return answer;
    }
};
