class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        vector<int> sizes;
        string r = "";
        for(string s: strs){
            sizes.push_back(s.size());
        }
        for(int s: sizes){
            r+= to_string(s) + ',';
        }
        r+='#';
        for(string s: strs){
            r+=s;
        }
        return r;
    }

    vector<string> decode(string s) {
        if(s=="") return {};
        vector<int> sizes;
        vector<string> res;
        int i = 0;
        while(s[i]!='#'){
            string curr = "";
            while(s[i]!=','){
                curr += s[i];
                i++;
            }
            sizes.push_back(stoi(curr));
            i++;
        }
        i++;
        for(int size: sizes){
            res.push_back(s.substr(i,size));
            i+=size;
        }
        return res;
    }
};
