class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        
        unordered_set<string> st;
        
        for(auto startWord:startWords)
        {
            sort(startWord.begin(),startWord.end());
            st.insert(startWord);
        }
        int count=0;
        
        for(auto targetWord:targetWords)
        {
            for(int i=0;i<targetWord.size();i++)
            {
            
                string toSearch=targetWord.substr(0,i)+targetWord.substr(i+1);
                
                sort(toSearch.begin(),toSearch.end());
                
                if(st.find(toSearch)!=st.end())
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};