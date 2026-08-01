class Solution {
public:
    int check(vector<int>& piles, int h, int n){
        long long t = 0;
        for(int i = 0; i<piles.size(); i++){
            t+=((piles[i]+n-1)/n);
        }
        if(t>h) return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int m = 0;
        for(int i = 0; i<piles.size(); i++){
            m = max(m,piles[i]);
        }
        int low = 1, high = m;
        while(low<=high){
            int mid = (low+high)/2;
            if(check(piles,h,mid)){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
