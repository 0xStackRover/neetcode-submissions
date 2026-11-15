class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        vector<int> answer;
        answer.reserve(nums.size());

        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);

        int pref = 1, suf = 1;
        for (int i = 0; i < nums.size(); i++) {
            pref *= nums[i];
            suf *= nums[nums.size() - 1 - i]; 
            
            prefix[i] = pref;
            suffix[nums.size() - 1 - i] = suf;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                answer.push_back(suffix[1]); 
            } else if (i == nums.size() - 1) {
                answer.push_back(prefix[i - 1]); 
            } else {
                answer.push_back(prefix[i - 1] * suffix[i + 1]);
            }
        }

        return answer;
    }
};