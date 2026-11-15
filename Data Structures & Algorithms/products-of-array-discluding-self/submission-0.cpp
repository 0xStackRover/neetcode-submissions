class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size(), 0);
        vector<int> suf(nums.size(), 0);

        int left = 1, right = 1;
        for (int i = 0; i < nums.size(); i++) {
            left *= nums[i];
            right *= nums[nums.size() - i - 1];
            pre[i] = left;
            suf[nums.size() - i - 1] = right;
        }

        vector<int> answer(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int computed = 1;
            if (i - 1 >= 0) {
                computed *= pre[i - 1];
            }
            if (i + 1 < nums.size()) {
                computed *= suf[i + 1];
            }
            answer[i] = computed;
        }
        return answer;
    }
};