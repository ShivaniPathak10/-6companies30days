class Solution {
public:
    int mp[100001] = {};
    long long maximumSubarraySum(const vector<int>& v, const int& k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        long long sum = 0, ret = 0;
        const int n = size(v);
        int ex = 0;
        for (int i = 0; i < k; i++) sum += v[i], ex += !(++mp[v[i]] - 2);
        for (int i = k; i < n; i++) ret = (!ex && sum > ret) ? sum : ret, ex += !(++mp[v[i]] - 2), ex -= !(--mp[v[i - k]] - 1), sum += v[i] - v[i - k];
        return (!ex && sum > ret) ? sum : ret;
    }
};