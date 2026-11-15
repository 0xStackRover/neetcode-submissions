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
        sort(s1.begin(), s1.end());

        for (int i = 0; i <= s2.size() - s1Size; i++) {
            int idx = s2[i] - 'a';
            if (freq[idx] == 0) {
                continue;
            }

            string temp = s2.substr(i, s1Size);
            cout << s2[i] << " temp: " << temp << endl;
            sort(temp.begin(), temp.end());
            if (s1 == temp) {
                return true;
            }
        }

        return false;
    }
};
