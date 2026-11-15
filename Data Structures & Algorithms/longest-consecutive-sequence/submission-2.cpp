class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        const int NUMS_SIZE = nums.size();
        if (NUMS_SIZE <= 1) {
            return NUMS_SIZE;
        }

        unordered_set<int> numSet(nums.begin(), nums.end());

        int answer = 1;

        for (const auto num : numSet) {
            if (numSet.count(num - 1) == 0) {
                int currNum = num + 1;
                int longest = 1;

                while (numSet.count(currNum) > 0) {
                    longest++;
                    currNum++;
                }
                answer = max(answer, longest);
            }
        }

        return answer;
    }
};
