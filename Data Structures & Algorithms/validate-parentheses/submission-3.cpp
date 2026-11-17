class Solution {
   public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) {
            return false;
        }

        stack<char> st;

        for (const char ch : s) {
            if (ch == '[' || ch == '{' || ch == '(') {
                st.push(ch);
                continue;
            }

            // basically stack is empty and you recieved a closing bracket
            if (st.empty()) {
                return false;
            }

            const char top = st.top();
            if (ch == ']' && top == '[') {
                st.pop();
            } else if (ch == '}' && top == '{') {
                st.pop();
            } else if (ch == ')' && top == '(') {
                st.pop();
            } else {
                return false;
            }
        }

        return st.empty();
    }
};
