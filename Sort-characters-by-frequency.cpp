class Solution {
public:
    string frequencySort(string s) {
       if(s.size()==0 || s.size()==1) return s;

       priority_queue<pair<int, char>> pq;
       string result="";
       vector<int> map(126,0);
       for(int i=0;i<s.size();i++)
       {
           map[s[i]]++;
       } 
       for(int j=0;j<126;j++)
       {
           if(map[j]!=0)
           {   char c=j;
               pq.push({map[j],c});
           }
       }
       while(!pq.empty())
       {
           auto i=pq.top();
           pq.pop();
           int j=i.first;
           char c=i.second;
           while(j--)
           {
               result.push_back(c);
           }
       }
       return result;
    }
};