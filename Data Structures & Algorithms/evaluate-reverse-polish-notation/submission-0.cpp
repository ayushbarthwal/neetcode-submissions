class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i<tokens.size(); i++){
            string ch = tokens[i];
            if(ch=="+" || ch=="-" || ch=="/" || ch=="*"){
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                int v;
                if(ch=="+"){
                    v = n2 + n1;
                }
                else if(ch=="-"){
                    v = n2-n1;
                }
                else if (ch=="*"){
                    v = n2*n1;
                }
                else{
                    v = n2/n1;
                }
                st.push(v);
            }
            else{
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};
