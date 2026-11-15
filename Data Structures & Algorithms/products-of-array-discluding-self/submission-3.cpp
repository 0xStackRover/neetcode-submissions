class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        vector<int> answer;
        answer.reserve(nums.size());

        int pref = 1;
        for (int i = 0; i < nums.size(); i++) {
            answer.push_back(pref);
            pref *= nums[i];
        }

        int suffix = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};