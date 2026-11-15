class Solution {
   public:
    string encode(vector<string>& strs) {
        string encoded;

        for (const string& str : strs) {
            encoded += to_string(str.size());
            encoded += '#';
            encoded += str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        int n = s.size();

        while (i < n) {
            int len = 0;

            while (s[i] != '#') {
                len = len * 10 + (s[i] - '0');
                i++;
            }

            i++;  // skip '#'

            result.push_back(s.substr(i, len));

            i += len;
        }

        return result;
    }
};