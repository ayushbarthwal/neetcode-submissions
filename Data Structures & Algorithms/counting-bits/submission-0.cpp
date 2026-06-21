class Solution {
public:
    int count(int n){
        int res = 0;
        while(n!=0){
            if(n) res++;
            n = n&(n-1);
        }
        return res;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i = 0; i<=n; i++){
            ans[i] = count(i);
        }
        return ans;
    }
};
