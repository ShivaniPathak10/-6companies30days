class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph(n,vector<int>(n,INT_MAX));
        for(int i = 0; i < n; i++) graph[i][i] = 0;
        for(int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]][edges[i][1]] = edges[i][2];
            graph[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        // this triple nested loop is floyd warshall algorithm
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX) {
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                    }
                }
            }
        }
        int minIndex = -1, minValue = INT_MAX;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(i!=j && graph[i][j]<=distanceThreshold) count++;
            }
            if(count<=minValue) {
                minIndex = i;
                minValue = count;
            }
        }
        return minIndex;
    }
};