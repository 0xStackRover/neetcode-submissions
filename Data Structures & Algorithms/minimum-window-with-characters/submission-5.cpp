class Solution {
   public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }

        vector<int> charCount(128, 0);
        for (char ch : t) {
            charCount[ch]++;
        }

        int targetCharsRemaining = t.length();
        int minWindow[2] = {0, INT_MAX};
        int startIndex = 0;

        for (int endIndex = 0; endIndex < s.length(); endIndex++) {
            char ch = s[endIndex];

            // STRIVER LOGIC: If the count is positive, we still needed this character
            if (charCount[ch] > 0) {
                targetCharsRemaining--;
            }

            charCount[ch]--;

            // When targetCharsRemaining hits 0, our window is fully valid
            while (targetCharsRemaining == 0) {
                // Record the minimum window found so far
                if (endIndex - startIndex < minWindow[1] - minWindow[0]) {
                    minWindow[0] = startIndex;
                    minWindow[1] = endIndex;
                }

                char charAtStart = s[startIndex];

                // Give the leftmost character back to our count as we shrink
                charCount[charAtStart]++;

                // STRIVER LOGIC: If giving it back made it positive, we just
                // removed a character we actually needed! The window breaks.
                if (charCount[charAtStart] > 0) {
                    targetCharsRemaining++;
                }

                startIndex++;
            }
        }

        return minWindow[1] == INT_MAX ? ""
                                       : s.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);
    }
};