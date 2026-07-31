class Solution {
public:
    int maxArea(vector<int>& heights) {
        int m = 0;
        int l = 0, r = heights.size()-1;
        while(l<r){
            int s = (r-l)*(min(heights[l],heights[r]));
            m = max(m,s);
            if(heights[l]<heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return m;
    }
};
