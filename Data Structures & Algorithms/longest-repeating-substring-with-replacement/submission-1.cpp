class Solution {
   public:
    int characterReplacement(string s, int k) {
        int answer = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> mp;
            int maxFreq = 0;
            for (int j = i; j < s.size(); j++) {
                char ch = s[j];
                mp[ch]++;
                maxFreq = max(maxFreq, mp[ch]);

                // basically calculated if its possible to convert all elements
                if ((j - i + 1 - maxFreq) <= k) {
                    answer = max(answer, j - i + 1);
                }
            }
        }
        return answer;
    }
};
