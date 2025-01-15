class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long int bigAst=mass;
     sort(asteroids.begin(),asteroids.end());
       for(int i=0;i<asteroids.size();i++)
       {
           if(bigAst>=asteroids[asteroids.size()-1])
           {
               return true;
           }
           else if(bigAst>=asteroids[i]) {
               bigAst+=asteroids[i];
           } else {
               return false;
           }
       } 
       return true;
    }
};