class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = nums[0];
        int c = nums[0];
        for(int i = 1; i<nums.size(); i++){
            c = max(nums[i],c+nums[i]);
            m = max(m,c);
        }
        return m;
    }
};
