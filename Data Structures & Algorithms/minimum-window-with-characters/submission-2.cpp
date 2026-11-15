class Solution {
   public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) {
            return "";
        }

        int minLen = INT_MAX;
        int startIndex = -1;

        for (int i = 0; i < s.size(); i++) {
            array<int, 128> freq = {0};
            for (const char& ch : t) {
                freq[ch - 'A']++;
            }

            int count = 0;
            for (int j = i; j < s.size(); j++) {
                int ch = s[j] - 'A';
                if (freq[ch] > 0) {
                    count++;
                }

                if (count == t.size()) {
                    if (j - i + 1 < minLen) {
                        startIndex = i;
                        minLen = j - i + 1;
                        break;
                    }
                }
                freq[ch]--;
            }
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};
