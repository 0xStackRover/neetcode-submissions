class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        array<int, 26> freq = {0};
        for (const char& str : s1) {
            freq[str - 'a']++;
        }

        for (int i = 0; i < s2.size(); i++) {
            array<int, 26> freq2 = {0};

            for (int j = i; j < s2.size(); j++) {
                int idx = s2[j] - 'a';
                freq2[idx]++;

                if (freq2[idx] > freq[idx]) {
                    break;
                }

                if (j - i + 1 == s1.size()) {
                    return true;
                }
            }
        }

        return false;
    }
};
