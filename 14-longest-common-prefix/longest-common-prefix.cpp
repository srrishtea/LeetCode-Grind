class Solution {
    int n;
public:
    string longestCommonPrefix(vector<string>& strs) {
        n=strs.size();
        sort(strs.begin(),strs.end());
        string s1=strs[0];
        string s2=strs[n-1];

        int n1=s1.length(), n2=s2.length();
        int i=0;
        string ans="";

        while(i<n1 && i<n2) {
            if(s1[i]!=s2[i]) break;
            if(s1[i]==s2[i]) ans+=s1[i];
            i++;
        }

        return ans;

        
        
    }
};