class Solution {
public:
long gcd(long a, long b) {
    while (b != 0) {
        long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
    int minimizeSet(int d1, int d2, int unc1, int unc2) {
        // very good concept 
        // use this to understand:https://www.youtube.com/watch?v=cuNS7HcvWoQ

        long low=0,high=1e10;
        long ans=1e9;
        while(low<=high){
            long mid=low+(high-low)/2;
            long a=mid-(mid/d1);
            long b = mid-(mid/d2);
        long lcm=(long(d1)*long(d2))/(long)gcd(d1,d2);
        long c= mid-(mid/d1)-(mid/d2)+(mid/lcm);
        if(a>=unc1&&b>=unc2&&(a+b-c)>=(unc1+unc2))
           {
               ans=mid;
               high=mid-1;
           }
        else
            low=mid+1;
        }
    return ans;
    }
};