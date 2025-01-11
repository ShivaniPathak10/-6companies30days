class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
      priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
      int n=nums.size();
      for(int i=0;i<n;i++)
      {
          pq.push({nums[i],i});
      }

      priority_queue<int, vector<int>,greater<int>> p;
      int i=0;
      while(i<k)
      {
          p.push(pq.top().second);
          pq.pop();
          i++;
      }
      vector<int> ans;
      while(!p.empty())
      {
          ans.push_back(nums[p.top()]);
          p.pop();
      }
      return ans;

    }
};