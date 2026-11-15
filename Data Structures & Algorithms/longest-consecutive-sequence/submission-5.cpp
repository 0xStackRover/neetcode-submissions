class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        unordered_set<int> st(nums.begin(), nums.end());
        int answer = 1;

        for (const int num : st) {
            if (!st.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (st.count(currentNum + 1)) {
                    currentNum++;
                    currentStreak++;
                }

                answer = max(answer, currentStreak);
            }
        }

        return answer;
    }
};