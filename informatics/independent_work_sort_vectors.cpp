#include <iostream>
#include <vector>

std::vector<int> mergeSortedVectors(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    std::vector<int> mergedVec;
    int i = 0, j = 0;
    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] < vec2[j]) {
            mergedVec.push_back(vec1[i]);
            i++;
        } else {
            mergedVec.push_back(vec2[j]);
            j++;
        }
    }
    while (i < vec1.size()) {
        mergedVec.push_back(vec1[i]);
        i++;
    }
    while (j < vec2.size()) {
        mergedVec.push_back(vec2[j]);
        j++;
    }
    return mergedVec;
}

std::vector<int> mergeSortedArrays(const std::vector<std::vector<int>>& arrays) {
    if (arrays.empty()) {
        return {};
    }
    std::vector<int> merged = arrays[0];
    for (int i = 1; i < arrays.size(); i++) {
        merged = mergeSortedVectors(merged, arrays[i]);
    }
    return merged;
}

int main() {
    int k;
    std::cin >> k;
    std::vector<std::vector<int>> arrays(k);
    for (int i = 0; i < k; ++i) {
        int len;
        std::cin >> len;
        arrays[i].resize(len);
        for (int j = 0; j < len; ++j) {
            std::cin >> arrays[i][j];
        }
    }
    std::vector<int> merged = mergeSortedArrays(arrays);
    for (int val : merged) {
        std::cout << val << " ";
    }
    return 0;
}
