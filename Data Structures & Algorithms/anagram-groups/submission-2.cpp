class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) {
            return {};
        }

        unordered_map<string, vector<string>> mp;
        for (const auto& it : strs) {
            string key(26, 0);
            for (const char ch : it) {
                key[ch - 'a']++;
            }
            mp[key].push_back(it);
        }

        vector<vector<string>> answer;
        for (const auto& itr : mp) {
            answer.push_back(itr.second);
        }
        return answer;
    }
};
