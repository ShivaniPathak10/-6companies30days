 static int nCr(int n, int r) {
        if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
        long long ans = 1;
        for(int i = 1; i <= r; i++) {
            ans *= n - r + i;
            ans /= i;
        }
        return ans;
    }

    int waysToReachStair(int k) {
        if(k==0 || k==4) return 2;
        if(k==1 || k==2) return 4;
        int x = ceil(log2(k));
        int ways = 0;
        while (true) {
            int y = pow(2, x) - k;
            if (y >= (x + 2)) break;
            ways += nCr(x + 1, y);
            ++x;
        }
        return ways;
    }
};