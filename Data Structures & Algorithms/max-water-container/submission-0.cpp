class Solution {
public:
    int maxArea(vector<int>& heights) {
        int m = 0;
        int l = 0, r = heights.size()-1;
        while(l<r){
            int a = (heights[l]>heights[r]) ? heights[r]:heights[l];
            int s = r-l;
            m = max(m,a*s);
            if(heights[l]>heights[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return m;
    }
};
