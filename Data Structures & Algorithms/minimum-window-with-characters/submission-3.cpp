class Solution {
   public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) {
            return "";
        }

        int minLen = INT_MAX;
        int startIndex = -1;
        int left = 0, right = 0;

        array<int, 128> freq = {0};

        for (const char& ch : t) {
            freq[ch - 'A']++;
        }

        int totalCount = 0;
        while (right < s.size()) {
            const int charRight = s[right] - 'A';
            if (freq[charRight] > 0) {
                totalCount++;
            }
            freq[charRight]--;

            while (totalCount == t.size()) {
                if (right - left + 1 < minLen) {
                    startIndex = left;
                    minLen = right - left + 1;
                }
                
                freq[s[left] - 'A']++;
                const int ch = s[left] - 'A';
                if (freq[ch] > 0) {
                    totalCount--;
                }

                left++;
            }
            right++;
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};
