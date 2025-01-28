class Solution 
{
public:
    long long inverse(int a,int p)
    {
        if(a==1)
        {
            return 1;
        }

        return (p-p/a)*inverse(p%a,p)%p;
    }

    int numberOfWays(int start, int end, int k) 
    {
        int dist,p;
        dist=end-start;
        p=1000000007;

        if(dist>k || (k-dist)%2==1)
        {
            return 0;
        }

        long long ans;
        ans=1;

        int x=k;
        int y=(k-dist)/2;

        for(int i=1;i<=y;i++)
        {
            ans=ans*(x-i+1)%p;
            ans=ans*inverse(i,p)%p;
        }

        return ans;
    }
};