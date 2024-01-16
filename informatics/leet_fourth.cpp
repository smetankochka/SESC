#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) {
            return {};
        }
        
        std::vector<std::string> result;
        std::vector<std::string> phoneMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        generateCombinations(digits, phoneMap, "", 0, result);
        
        return result;
    }

private:
    void generateCombinations(const std::string& digits, const std::vector<std::string>& phoneMap, std::string current, int index, std::vector<std::string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        std::string letters = phoneMap[digits[index] - '0'];
        for (char letter : letters) {
            generateCombinations(digits, phoneMap, current + letter, index + 1, result);
        }
    }
};
