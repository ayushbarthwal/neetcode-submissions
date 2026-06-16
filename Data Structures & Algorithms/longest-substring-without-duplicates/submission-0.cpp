class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int l = 0, r = 0;
        int m = 0;
        while(r<s.length()){
            while(mp[s[r]]){
                mp[s[l]]--;
                l++;
            }
            mp[s[r]]++;
            r++;
            m = max(m,r-l);
        }
        return m;
    }
};
