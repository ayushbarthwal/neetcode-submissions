class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ml = 0, mr = 0;
        int w = 0;
        while(l<=r){
            if(height[l]<height[r]){
                if(height[l]>ml) ml=height[l];
                else w+=ml-height[l];
                l++;
            }
            else{
                if(height[r]>mr) mr=height[r];
                else w+=mr-height[r];
                r--;
            }
        }
        return w;
    }
};
