class Solution {
    int n,m;
public:
    bool rotateString(string s, string goal) {
        n=s.length();
        m=goal.length();

        if(n!=m) return false;

        string doubles=s+s;
        return doubles.find(goal)<doubles.length();

        
        
    }
};