class Solution {
public:
    bool check(string s,string word)
    {
        int n=s.size();
        if (s.size()!=word.size()) return false;
        int i;
        for (i=0;i<s.size();i++) 
        {
            if (s[i]!=word[i] &&  s[i]!=' ')
            {
                break;
            }
        }
        if (i==n)
        return true;
         reverse(s.begin(),s.end());
         for (i=0;i<s.size();i++) 
        {
            if (s[i]!=word[i] &&  s[i]!=' ')
            {
                break;
            }
        }
         if (i==n)
        return true;
        return false;
    }
    bool placeWordInCrossword(vector<vector<char>>& board, string word) 
    {
        int n=board.size();
        int m=board[0].size();
        for (int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (board[i][j]=='#') continue;
                string str="";
                while(j<m && board[i][j]!='#') str+=board[i][j++];
                if (check(str,word)) return true;
            }
        }
        for (int j=0;j<m;j++)
        {
            for (int i=0;i<n;i++)
            {
                if (board[i][j]=='#') continue;
                string str="";
                while(i<n && board[i][j]!='#') str+=board[i++][j];
               if (check(str,word)) return true;

            }
        }
        return false;
    }
};