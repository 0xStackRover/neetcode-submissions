class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const auto& str : strs) {
            string orig = str;
            sort(orig.begin(), orig.end());
            mp[orig].push_back(str);
        }

        vector<vector<string>> response;
        for (const auto itr : mp) {
            response.push_back(itr.second);
        }

        return response;
    }
};
