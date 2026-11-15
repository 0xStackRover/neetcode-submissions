class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        int currSize = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());

        int setSize = st.size();
        return !(currSize == setSize);
    }
};