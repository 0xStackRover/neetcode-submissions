class Solution {
   public:
    string encode(vector<string>& strs) {
        string response = "";
        for (const string& str : strs) {
            int sz = str.size();
            response += to_string(sz);
            response += "#";
            response += str;
        }
        return response;
    }

    vector<string> decode(string s) {
        // cout << "s : " << s << "\n";
        vector<string> resp;
        int i = 0;
        while (i < s.size()) {
            string num = "";
            while (s[i] != '#') {
                num += s[i];
                i++;
            }

            int n = stoi(num);
            resp.push_back(s.substr(i + 1, n));
            i += n + 1;
        }

        return resp;
    }
};