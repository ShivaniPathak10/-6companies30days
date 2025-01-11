class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> lis(n,1);
        vector<int> prev_idx(n,-1);
        int max{}, index{};
        for(int i{};i<n;++i)
        {
            for(int j{i-1};j>=0;--j)
            {
                if(lis[j]+1 >lis[i] && nums[i]%nums[j]==0)
                {
                    lis[i]=lis[j]+1;
                    prev_idx[i]=j;
                }
            }
        }

        for(int i{};i<n;++i)
        {
            if(max<lis[i])
            {
                max=lis[i];
                index=i;
            }
        }

        vector<int>divi_subset{};
        while(index!=-1)
        {
            divi_subset.push_back(nums[index]);
            index=prev_idx[index];
        }
        return divi_subset;
    }
};