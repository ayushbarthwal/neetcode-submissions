class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto s: strs){
            vector<int> c(26,0);
            for(int i = 0; i<s.length(); i++){
                c[s[i]-'a']++;
            }
            string key = to_string(c[0]);
            for(int i = 1; i<26; i++){
                key+= "," + to_string(c[i]);
            }
            mp[key].push_back(s);
        }
        vector<vector<string>> res;
        for(auto p: mp){
            res.push_back(p.second);
        }
        return res;
    }
};
