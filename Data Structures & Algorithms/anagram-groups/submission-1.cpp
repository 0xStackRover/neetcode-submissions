class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) {
            return {};
        }

        unordered_map<string, vector<string>> mp;
        for (auto it : strs) {
            string copied = it;
            sort(copied.begin(), copied.end());
            mp[copied].push_back(it);
        }

        vector<vector<string>> answer;
        for (const auto& itr : mp) {
            answer.push_back(itr.second);
        }
        return answer;
    }
};
