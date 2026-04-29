class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";
        for(int i = 0; i<s.length(); i++){
            if(isalnum(s[i])){
                a+=tolower(s[i]);
            }
        }
        int f = 0, l = a.length()-1;
        while(f<l){
            if(a[f]==a[l]){
                f++;
                l--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
