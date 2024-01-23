class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    vector<int> result;
    unordered_set<int> numSet;
    int duplicate, missing;

    for (int num : nums) {
        if (numSet.count(num)) {
            duplicate = num;
        }
        numSet.insert(num);
    }

    for (int i = 1; i <= nums.size(); i++) {
        if (!numSet.count(i)) {
            missing = i;
            break;
        }
    }

    result.push_back(duplicate);
    result.push_back(missing);

    return result;
    }
};
