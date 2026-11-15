class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) {
            return {};
        }

        unordered_map<string, vector<string>> mp;
        for (const auto& it : strs) {
            string key(26, 0);
            for (char ch : it) {
                key[ch - 'a']++;
            }
            mp[key].push_back(it);
        }

        vector<vector<string>> answer;
        answer.reserve(mp.size());

        for (auto& itr : mp) {
            answer.push_back(std::move(itr.second));
        }

        return answer;
    }
};