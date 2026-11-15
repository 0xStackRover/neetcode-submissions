class Solution {
   public:
    string minWindow(string s, string t) {
        if (s == t) {
            return s;
        }
        string answer = "";
        int tot = 0;
        unordered_map<char, int> freq;
        for (const char& ch : t) {
            freq[ch]++;
            tot++;
        }

        for (int i = 0; i < s.size(); i++) {
            char currentChar = s[i];
            if (freq.find(currentChar) == freq.end()) {
                continue;
            }

            unordered_map<char, int> freq2(freq);
            int right = i;
            int curr = 0;
            while (right < s.size()) {
                if (curr > tot) {
                    break;
                }

                char ch = s[right];
                if (freq2.find(ch) != freq2.end() && freq2[ch] != 0) {
                    freq2[ch]--;
                    curr++;
                }

                right++;
                if (curr == tot) {
                    if (answer != "") {
                        int siz = answer.size();
                        string substr = s.substr(i, right - i);

                        if (substr.size() < siz) {
                            answer = substr;
                        }
                    } else {
                        answer = s.substr(i, right - i);
                    }
                    break;
                }
            }
        }
        return answer;
    }
};
