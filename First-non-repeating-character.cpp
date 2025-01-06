class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp,ind;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            ind[s[i]]=i;
        }
        char fir='\0';
        for(int i=0;i<s.length();i++){
            if(mp[s[i]]==1){
                fir=s[i];
                break;
            }
        }
        auto it=ind.find(fir);
        if(it!=ind.end()){
            return it->second;
        }
        return -1;
    }
};