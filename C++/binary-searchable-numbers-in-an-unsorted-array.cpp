// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int binarySearchableNumbers(vector<int>& nums) {
        static const bool count_distinct = true;
        vector<int> right(size(nums) + 1, numeric_limits<int>::max());
        for (int i = size(nums); i >= 1; --i) {
            right[i - 1] = min(right[i], nums[i - 1]);
        }
        unordered_set<int> result;
        
        int left = numeric_limits<int>::min();
        for (int i = 0; i < size(nums); ++i) {
            if (left <= nums[i] && nums[i] <= right[i + 1]) {
                result.emplace(nums[i]);
            }
            left = max(left, nums[i]);
            
        }
        if (count_distinct) {
            return size(result);
        }
        int cnt = 0;
        for (const auto& x : nums) {
            if (result.count(x)) {
                ++cnt;
            }
        }
        return cnt;
    }
};
