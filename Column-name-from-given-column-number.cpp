class Solution {
public:
    string convertToTitle(int columnNumber) {
        int temp = columnNumber;
        string ans="";
        while(temp> 0)
        {
            temp--;
            int dig = temp%26;
            char c= 'A'+dig;
            ans= c+ans;
            temp= temp/26;
        }
        return ans;
    }
};