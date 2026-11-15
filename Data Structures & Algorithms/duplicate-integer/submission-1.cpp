class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        unordered_set<int> st(nums.begin(), nums.end());
        return !(nums.size() == st.size());
    }
};