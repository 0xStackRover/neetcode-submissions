class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> row, col, box;

        const int BOARD_SIZE = 9;

        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                const char ch = board[i][j];

                if (ch == '.') {
                    continue;
                }

                int boxIdx = (i / 3) * 3 + (j / 3);

                // check before inserting
                if (row[i].count(ch) > 0 || col[j].count(ch) > 0 || box[boxIdx].count(ch) > 0) {
                    return false;
                }

                row[i].insert(ch);
                col[j].insert(ch);
                box[boxIdx].insert(ch);
            }
        }

        return true;
    }
};
