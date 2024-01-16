#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int m = haystack.size();
        int n = needle.size();
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i <= m - n; i++) {
            int j;
            for (j = 0; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        return -1;
    }
};
