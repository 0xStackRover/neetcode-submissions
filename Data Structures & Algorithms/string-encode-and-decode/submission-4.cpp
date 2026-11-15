class Solution {
   public:
    string encode(vector<string>& strs) {
        string response;
        for (const string& str : strs) {
            response += to_string(str.size()) + "@" + str;
        }

        return response;
    }

    vector<string> decode(const string& s) {
        vector<string> answer;
        int i = 0;
        while (i < s.size()) {
            int len = 0;
            while (s[i] != '@') {
                len = len * 10 + (s[i] - '0');
                i++;
            }

            answer.push_back(s.substr(i + 1, len));
            i += len + 1;
        }
        return answer;
    }
};
