class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (const int& num : nums) {
            freq[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto& itr : freq) {
            bucket[itr.second].push_back(itr.first);
        }

        vector<int> answer;
        for (int i = bucket.size() - 1; i > 0; i--) {
            for (const int& num : bucket[i]) {
                answer.push_back(num);
                if (answer.size() == k) {
                    return answer;
                }
            }
        }

        return answer;
    }
};