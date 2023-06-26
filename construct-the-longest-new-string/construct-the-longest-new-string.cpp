class Solution {
public:
    int longestString(int x, int y, int z) {
        
        int res =0;
        int AAstart =0;
        int BBstart =0;
        int x1 =x,y1 =y;
        while(x1>0 && y1>0)
        {
            AAstart +=  2;
            BBstart += 2;
            x1--;
            y1--;
            
        }
        if(x1>0)
        {
            AAstart++;
            
        }
        if(y1>0)
        {
            BBstart++;
        }
        
        res = max(AAstart,BBstart);
        res  += z;
        return  2*res; 
    }
};