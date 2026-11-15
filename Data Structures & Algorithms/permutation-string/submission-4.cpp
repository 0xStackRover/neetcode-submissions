class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }

        vector<int> freq(26, 0);
        for (const char ch : s1) {
            freq[ch - 'a']++;
        }

        int s1Size = s1.size();

        for (int i = 0; i <= s2.size() - s1Size; i++) {
            int idx = s2[i] - 'a';
            if (freq[idx] == 0) {
                continue;
            }

            bool isMatch = true;
            vector<int> innerFreq(26, 0);
            for (int j = i; j < s1.size() + i; j++) {
                int idx = s2[j] - 'a';
                innerFreq[idx]++;

                if (innerFreq[idx] > freq[idx]) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) {
                return true;
            }
        }

        return false;
    }
};
