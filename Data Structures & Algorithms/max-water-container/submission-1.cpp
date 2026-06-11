class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int longest = 0;
        while(i<j){
            int a = j-i;
            int s;
            if(height[i]<height[j]){
                s=height[i]*a;
                i++;
            }
            else{
                s=height[j]*a;
                j--;
            }
            longest = max(longest,s);
        }
        return longest;
    }
};
