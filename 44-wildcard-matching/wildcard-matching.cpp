class Solution {

    bool f(int i,int j,string &s, string &p,vector<vector<int>>& dp)
    {
        if(i==0 && j==0) return true;
        if(i==0 && j>0) return false;

        if(j==0 && i>0) 
        {
            for(int x=1;x<=i;x++)
            {
                if(s[i-1] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] !=-1) return dp[i][j];

        if(s[i-1] == p[j-1] || s[i-1] == '?') return dp[i][j] =  f(i-1,j-1,s,p,dp);
        
        if(s[i-1] == '*') return dp[i][j] = f(i-1,j,s,p,dp) | f(i,j-1,s,p,dp);

        return  dp[i][j] = false;
    }
public:
bool isAllStars(string & S1, int i) {


  for (int j = 1; j <= i; j++) {
    if (S1[j - 1] != '*')
      return false;
  }
  return true;
}

    bool isMatch(string S2, string S1) {
        
         int n = S1.size();
  int m = S2.size();

  vector < bool > prev(m + 1, false);
  vector < bool > cur(m + 1, false);

  prev[0] = true;

  for (int i = 1; i <= n; i++) {
    cur[0] = isAllStars(S1, i);
    for (int j = 1; j <= m; j++) {

      if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
        cur[j] = prev[j - 1];

      else {
        if (S1[i - 1] == '*')
          cur[j] = prev[j] || cur[j - 1];

        else cur[j] = false;
      }
    }
    prev = cur;
  }

  return prev[m];
    }
};