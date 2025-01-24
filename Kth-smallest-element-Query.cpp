
class Solution {
public:
    const static bool cmp(pair<string,int> &a, pair<string,int>&b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int n = queries[i][1];
            int k = nums[0].size() - n;
            vector<pair<string,int>> arr;
            for( int j=0;j<nums.size();j++){
                string str = nums[j].substr(k,nums[j].size()-k);
                arr.push_back({str,j});
            } 
            sort(arr.begin(),arr.end(),cmp);
            int x = queries[i][0]-1;
            int ind = arr[x].second;
            ans.push_back(ind);
        }
        return ans;
    }
};