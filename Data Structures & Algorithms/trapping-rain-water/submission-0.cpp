class Solution {
   public:
    int trap(vector<int>& height) {
        int trappedWater = 0;
        vector<int> leftMax(height.size(), 0);
        vector<int> rightMax(height.size(), 0);

        int leftmaxi = 0;
        int righmaxi = 0;
        for (int i = 0; i < height.size(); i++) {
            leftmaxi = max(leftmaxi, height[i]);
            leftMax[i] = leftmaxi;

            int rightIdx = height.size() - i - 1;
            righmaxi = max(righmaxi, height[rightIdx]);
            rightMax[rightIdx] = righmaxi;
        }

        for (int i = 0; i < height.size(); i++) {
            int left = leftMax[i];
            int right = rightMax[i];

            int ele = height[i];
            if (ele < left && ele < right) {
                trappedWater += min(left, right) - ele;
            }
        }

        return trappedWater;
    }
};
