class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        
        sort(nums.begin(), nums.end());

        int answer = 1;
        int longest = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }

            if (abs(nums[i] - nums[i - 1]) == 1) {
                longest++;
                answer = max(longest, answer);
            } else {
                longest = 1;
            }
        }
        return max(answer, longest);
    }
};