class Solution {
public:
    int x,y;
    int i=0,j=0;
    
    Solution(int m, int n) {
        x=m;
        y=n;
    }
    
    vector<int> flip() {
        vector<int>v = {i,j};
        if(j==y-1)i=(i+1)%x;
        j=(j+1)%y;
        return v;
    }
    
    void reset() {
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */