class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int size=arr.size();
        int ans=0;
        for(int start=0,end=0;start+2<size;start=end)
        {
            end= start+1;
            if(arr[start]<arr[end])
            {
                while(end+1< size && arr[end]<arr[end+1])
                {
                    end++;
                }

           
                if(end+1<size && arr[end]>arr[end+1])
                {
                    while(end+1<size && arr[end]>arr[end+1])
                    {
                        ++end;
                    }
                    ans = max(ans,end-start+1);
                }
                else
                {
                    ++end;
                }
            }
        }
        return ans;
    }
};