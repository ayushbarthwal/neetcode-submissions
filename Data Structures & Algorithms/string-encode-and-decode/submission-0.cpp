class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string a;
        for(string s: strs){
            a += to_string(s.size()) + ',';
        }
        a+='#';
        for(string s:strs){
            a+=s;
        }
        return a;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        int i = 0;
        int j = 0;
        vector<int> sizes;
        while(s[i]!='#'){
            while(s[j]!=','){
                j++;
            }
            sizes.push_back(stoi(s.substr(i,j-i)));
            j++;
            i = j;
        }
        i++;
        vector<string> ans;
        for(int len: sizes){
            ans.push_back(s.substr(i,len));
            i+=len;
        }
        return ans;
    }
};
