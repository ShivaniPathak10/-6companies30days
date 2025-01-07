//applying bfs on all the rottens oraranges simultaneosly 

class Solution {
public:
    long long int count=0;

    void bfs(queue<pair<int,int>>q,vector<vector<int>>& grid,int n, int m)
    {
        while(!q.empty())
        {
            int k = q.size();

            //flag is for , only count when a rrotteen orange is rottening other orange , 
            // it is possible oraneg in queu but it is not rottening any other 
            int flag=0;
            while(k--)
            {
                pair<int,int>pp=q.front();
                int i = pp.first;
                int j = pp.second;
                q.pop();

                if(i-1>=0 && grid[i-1][j]==1)
                {
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                    flag++;
                }
                if(i+1<n && grid[i+1][j]==1)
                {
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                    flag++;
                }
                if(j-1>=0 && grid[i][j-1]==1)
                {
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                    flag++;
                }
                if(j+1<m && grid[i][j+1]==1)
                {
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                    flag++;
                }
            }
            if(flag)
            {
                count++;
            }
        }

    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //quque for storing all rotten oranges 
        queue<pair<int,int>>q;

        //storing roten orages in queueu
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    pair<int,int>p={i,j};
                    q.push(p);
                }
            }
        }

        //applying bfs on all rotten oranges in one go 
        bfs(q,grid,n,m);

        //if at last some fresh orange is left (unreacheable)
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }

        return count;
    }
};