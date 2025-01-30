class Solution {
public:

static vector<string> ssplit(string s){
	int n=s.length();string k="";vector<string> v;
	for(int i=0;i<n;i++){
		if(s[i]!=','&& i!=n-1){
			k+=s[i];
		}
		else{if(s[i]!=',')k+=s[i];v.push_back(k);k="";
		}
		
	}return v;
}
    bool isValidSerialization(string s) {int c=0;
    vector<string >v=ssplit(s);
        for(int i=v.size()-1;i>-1;i--){
            if(v[i].compare("#")&&c<2)return false;
            
            if(!v[i].compare("#"))c++;
            else{
                c--;
            }
        }return c==1;
    }
};