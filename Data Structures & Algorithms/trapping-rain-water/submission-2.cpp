class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int answer = 0;
        const int sz = height.size();
        vector<int> pref(sz, 0), suff(sz, 0);

        int left = height[0], right = height[sz - 1];
        for (int i = 0; i < sz; i++) {
            left = max(left, height[i]);
            right = max(right, height[sz - i - 1]);

            pref[i] = left;
            suff[sz - i - 1] = right;
        }

        for (int i = 0; i < sz; i++) {
            int currWater = min(pref[i], suff[i]) - height[i];
            answer += currWater;
        }

        return answer;
    }
};
