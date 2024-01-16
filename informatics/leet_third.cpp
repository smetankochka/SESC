#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            int start = 0, end = n - 1;
            while (start < end) {
                std::swap(matrix[i][start], matrix[i][end]);
                start++;
                end--;
            }
        }
    }
};
