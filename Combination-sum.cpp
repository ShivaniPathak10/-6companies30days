class Solution {
public:

    vector<vector<int>>ans;
    void f(int i, vector<int>&candidates , vector<int>&v , int t , int k){
        int n = candidates.size();
        if(t == 0 && k==0){
            ans.push_back(v);
        }

        for(int j=i;j<n;j++){

            if(j > i && candidates[j] == candidates[j-1]){
                continue;
            }
            if(candidates[j] <= t){
            v.push_back(candidates[j]);
            f(j+1 , candidates , v , t-candidates[j] , k-1);
            v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>candidates;
        int target = n;
        for(int i=1;i<=9;i++){
            candidates.push_back(i);
        }

        vector<int>v;
        f(0 , candidates , v , target , k);
        return (ans);

    }
};