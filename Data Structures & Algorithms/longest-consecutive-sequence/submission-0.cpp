class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num(nums.begin(),nums.end());
        int m = 0;
        for(int n: num){
            if(num.find(n-1)==num.end()){
                int l = 1;
                while(num.find(n+l)!=num.end()){
                    l++;
                }
                m = max(m,l);
            }
        }
        return m;
    }

};
