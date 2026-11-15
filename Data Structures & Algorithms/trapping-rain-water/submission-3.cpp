class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int answer = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = height[left], rightMax = height[right];

        while (left < right) {
            if (height[left] < height[right]) {
                left++;
                leftMax = max(leftMax, height[left]);
                answer += leftMax - height[left];
            } else {
                right--;
                rightMax = max(rightMax, height[right]);
                answer += rightMax - height[right];
            }
        }

        return answer;
    }
};
