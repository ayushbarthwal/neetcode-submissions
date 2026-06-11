class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num(nums.begin(), nums.end());
        int longest = 0;
        for (int n : num) {
            if (!num.count(n - 1)) {
                int length = 1;
                while (num.find(n + length) != num.end()) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
