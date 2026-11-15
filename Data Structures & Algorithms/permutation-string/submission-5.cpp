class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }

        vector<int> freq(26, 0);
        vector<int> freqSub(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            freq[s1[i] - 'a']++;
            freqSub[s2[i] - 'a']++;
        }

        if (freq == freqSub) {
            return true;
        }

        for (int i = s1.size(); i < s2.size(); i++) {
            freqSub[s2[i] - 'a']++;
            freqSub[s2[i - s1.size()] - 'a']--;
            if (freq == freqSub) {
                return true;
            }
        }

        return false;
    }
};
