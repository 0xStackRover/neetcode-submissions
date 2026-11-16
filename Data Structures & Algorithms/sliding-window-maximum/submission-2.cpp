class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return {};

        vector<int> answer;
        priority_queue<pair<int, int>> max_heap;

        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            max_heap.push({nums[right], right});

            if (right - left + 1 == k) {
                while (max_heap.top().second < left) {
                    max_heap.pop();
                }

                answer.push_back(max_heap.top().first);
                left++;
            }
        }

        return answer;
    }
};