class Solution {
public:
    int countCollisions(string directions) {
        int ans =0;
        int collision=0;
        int right =0;
        int left =0;
        int stationary =0;
        for(int a =0;a<directions.size();a++)
        {
        if(directions[a]=='R')
        {
            right++;
        }
        if(directions[a]=='S')
        {
          ans+=right;
          stationary=1;
          right=0;
        }
        if(directions[a]=='L')
        {
            if(right>0)
            {
               ans = ans+right+1;
               right=0;
               collision=1;
            }
            else if(stationary==1)
            {
                ans++;
                collision=1;
            }
            else if(collision==1)
            {
                ans++;
            }
        }

        }
        return ans;
    }
};