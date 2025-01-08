class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        sort(contact.begin(), contact.end());
        contact.erase(unique(contact.begin(), contact.end()), contact.end());
        vector<vector<string>> result;
        string prefix ="";
        
        for(char c:s)
        {
            prefix+=c;
            vector<string> matches;
            for(string& entry:contact)
            {
                if(entry.find(entry==0))
                {
                    matches.push_back(entry);
                }
            }
            if(matches.empty())
            {
                result.push_back({"0"});
            }
            else {
                result.push_back(matches);
            }
        }
        return result;
    }
};