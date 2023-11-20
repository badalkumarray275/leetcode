class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        

           int ans;
           int count =0;
           int lastp =0,lastg =0,lastm =0;

           for(int i=0;i<garbage.size();i++)
           {
               for(auto c:garbage[i])
               {
                   count++;
                   if(c=='M') lastm =i;
                   else if(c=='P') lastp =i;
                   else lastg =i;
               }
           }

           for(int i=1;i<travel.size();i++)
           {
               travel[i] += travel[i-1];
           }

           ans = count;

           if(lastp>0) ans += travel[lastp-1];
           if(lastg>0) ans += travel[lastg-1];
           if(lastm>0) ans += travel[lastm-1];


           return ans;
    }
};