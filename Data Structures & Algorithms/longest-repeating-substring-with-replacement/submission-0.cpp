class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> cs(s.begin(),s.end());
        int m = 0;
        for(char c: cs){
            int count = 0, l = 0, r = 0;
            while(r<s.length()){
                if(s[r]==c) count++;
                while(((r-l+1)-count)>k){
                    if(s[l]==c) count--;
                    l++;
                }
                m = max(m,r-l+1);
                r++;
            }
        }
        return m;
    }
};
