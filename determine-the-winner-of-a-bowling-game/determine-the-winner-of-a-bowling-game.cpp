class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        
        
        int  n = player1.size();
        int score1 =0,score2=0;
        
        if(n>=1)
        {
            score1 += player1[0];
            score2 += player2[0];
            
        }
        if(n>=2)
        {
            if(player1[0]==10)
            {
                score1 += 2*player1[1];
                
            }
            else
            {
               score1 += player1[1];
            }
            if(player2[0]==10)
            {
                score2 += 2*player2[1];
            }
            else
            {
               score2 += player2[1];
            }
            
        }
        for(int i=2;i<n;i++)
        {
            if(player1[i-1]==10 || player1[i-2]==10)
            {
                score1 += 2*player1[i];
                
            }
            else
            {
                  score1 += player1[i];
            }
            if(player2[i-1]==10 || player2[i-2]==10 )
            {
                  score2 += 2*player2[i];
            }
            else
            {
                 score2 += player2[i];
            }
        }
        if(score1>score2)
        {
            return 1;
        }
        else  if(score2>score1)
        {
            return 2;
        }
        else
        {
            return 0;
        }
        
    }
};