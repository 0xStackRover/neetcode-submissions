class MinStack {
   public:
    MinStack() {}

    void push(int val) {
        if (m_stack.empty()) {
            m_stack.push_back({val, val});
        } else {
            int m_min = min(val, m_stack.back().first);
            m_stack.push_back({m_min, val});
        }
    }

    void pop() { m_stack.pop_back(); }

    int top() { return m_stack.back().second; }

    int getMin() { return m_stack.back().first; }

   private:
    vector<pair<int, int>> m_stack;
};
