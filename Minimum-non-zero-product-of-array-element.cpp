#define mod 1000000007
typedef long long ll;

class Solution {
public:
    ll power(ll a, ll b)
    {
        ll res=1;
        while(b)
        {
            if(b%2==1)
            { res=(res%mod * a%mod)%mod;
            }
            a=(a%mod * a%mod)%mod;
            b=b/2;
        }
        return res;
    }

    int minNonZeroProduct(int p) {
        ll mx=(1ll<<p)-1;
        ll base =(mx-1+mod)%mod;
        ll exponent=mx/2;
        return (power(base,exponent)%mod *(mx%mod))%mod;
    }
};