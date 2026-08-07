class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> c1(26,0);
        for(int i = 0; i<s.size(); i++){
            c1[tolower(s[i])-'a']++;
        }
        vector<int> c2(26,0);
        for(int i = 0; i<t.size(); i++){
            c2[tolower(t[i])-'a']++;
        }
        for(int i = 0; i<26; i++){
            if(c1[i]!=c2[i]) return false;
        }
        return true;
    }
};
