class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rowSets;
        unordered_map<int, unordered_set<char>> colSets;
        unordered_map<int, unordered_set<char>> boxSets;

        const int BOARD_SIZE = 9;
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                const char ch = board[row][col];
                if (ch == '.') {
                    continue;
                }

                int boxIndex = (row / 3) * 3 + (col / 3);

                if (rowSets[row].count(ch) > 0 || colSets[col].count(ch) > 0 ||
                    boxSets[boxIndex].count(ch) > 0) {
                    return false;
                }

                rowSets[row].insert(ch);
                colSets[col].insert(ch);
                boxSets[boxIndex].insert(ch);
            }
        }

        return true;
    }
};