class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, m = INT_MAX, a = 0;
        map<int,int> ws, wt;
        for(char ch: t){
            wt[ch]++;
        }
        int have = 0, need = wt.size();

        while(r<s.length()){
            char ch = s[r];
            ws[ch]++;
            if(wt[ch] && wt[ch]==ws[ch]) have++;
            while(need==have){
                if((r-l+1)<m){
                    m = r-l+1;
                    a = l;
                }
                ch = s[l];
                ws[ch]--;
                if(wt[ch] && ws[ch]<wt[ch]) have--;
                l++;
            }
            r++;
        }

        if(m==INT_MAX) return "";
        return s.substr(a,m);
    }
};
