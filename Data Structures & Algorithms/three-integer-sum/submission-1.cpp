class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;

        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) {
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1, right = nums.size() - 1;
            int target = -nums[i];
            while (left < right) {
                int currSum = nums[left] + nums[right];
                if (currSum == target) {
                    answer.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while (nums[left] == nums[left - 1] && left < right) {
                        left++;
                    }
                    while (nums[right] == nums[right + 1] && left < right) {
                        right--;
                    }
                } else if (currSum > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }

        return answer;
    }
};