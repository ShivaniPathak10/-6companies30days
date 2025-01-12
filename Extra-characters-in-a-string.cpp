class Solution {

    //return junk size
    int dp(int index,const string &s, vector<string>& dictionary,vector<int> &memo){

        if(index == s.size()) return 0;
        if(memo[index]!=-1) return memo[index];

        //from index to try all possible
        int result = s.size()-index;
        for(const auto &x:dictionary){
            
            if(int pos = s.find(x,index);pos!=string::npos){
                result = min(result, pos-index + dp(pos+x.size(),s,dictionary,memo));
            }
        }
        return memo[index] = result;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {

        int n = s.size();

        //memo[i]:start at s[i], extra char.

        vector<int> memo(n,-1);
        
        return dp(0,s,dictionary,memo);
    }
};