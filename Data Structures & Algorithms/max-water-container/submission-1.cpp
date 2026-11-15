class Solution {
   public:
    int maxArea(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }

        int answer = 0;
        int left = 0, right = heights.size() - 1;

        while (left < right) {
            int currWater = (right - left) * min(heights[left], heights[right]);
            answer = max(answer, currWater);

            if (heights[left] > heights[right]) {
                right--;
            } else {
                left++;
            }
        }
        return answer;
    }
};
