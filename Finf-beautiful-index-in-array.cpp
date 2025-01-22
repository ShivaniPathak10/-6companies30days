class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int lenS = s.length(), lenA = a.length(), lenB = b.length();
        vector<int> ans;
        int i = 0;
        for (int j = 0; j <= lenS - lenB; ++j) {
            string subB = s.substr(j, lenB);
            if (subB != b) {
                continue;
            }

            for (; i <= lenS - lenA; i++) {
                string subA = s.substr(i, lenA);
                if (subA != a) {
                    continue;
                }
                if (abs(i - j) <= k) {
                    ans.push_back(i);
                }
                else {
                    if (i > j) {
                        break;
                    }
                }
            }
        }

        return ans;
    }
};