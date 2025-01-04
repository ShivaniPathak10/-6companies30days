class Solution {
public:
    unordered_map<int, int> allPalSubseq; 

    bool isPal(string str){
        int i = 0 , j = str.size()-1; 
        while(i<=j){
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void generateAllPalindromicSeq(string s){
        int sz = s.size();
        int allseqcnt = (1 << sz) - 1;

        for(int i = 1 ; i <= allseqcnt ; ++i){
            string str = "";
            for(int j = 0 ; j < sz ; ++j){
                if((i & (1 << j)))
                    str.push_back(s[j]);
            }
            if(isPal(str)){
                allPalSubseq[i] = str.size();
            }
        }
    }

    int maxProduct(string s) {

        int result = -1;
        generateAllPalindromicSeq(s);

        for(auto each : allPalSubseq){
            for(auto each1: allPalSubseq){
                if( (each.first & each1.first) == 0){
                    int prod = each.second * each1.second;
                    result = max(result, prod);
                }
            }
        }

        return result;
    }
};