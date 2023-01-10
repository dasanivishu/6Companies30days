// Ques1:You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
//intitution :just push numbers into stack and when operator come pop two numbers a,b
//and perform operations on b and a and push result in stack ,final result in stack
//will be the result
class Solution {
public:
    string operate(string a,string b,string c)
    {
        int x=stoi(a);
        int y=stoi(b);
        int ans;
        if(c=="+")
          ans=x+y;
        else if(c=="-")
         ans=x-y;
        else if(c=="*")
        ans=x*y;
        else
        ans=x/y;
      string result=to_string(ans);
    return result; 
    }
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<string>st;
        for(int i=0;i<n;i++)
        {
            string s=tokens[i];
            if(s=="*"||s=="+"||s=="-"||s=="/")
            {
                string a=st.top();
                st.pop();
                string b=st.top();
                st.pop();
                string result=operate(b,a,s);
                st.push(result);
            }
            else
            st.push(tokens[i]);
        }
        string ans= st.top();
        return stoi(ans);
        
    }
};
