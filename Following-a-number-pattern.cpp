public:
    string printMinNumberForPattern(string s){
        // code here
        int n= s.size();
        string result;
        stack<int> st;
        for(int i=0;i<=n;i++)
        {
            st.push(i+1);
            if(i== n || s[i]=='I')
            {
                while(!st.empty())
                {
                    result+= to_string(st.top());
                    st.pop();
                }
            }
        }
        return result;
    }
};