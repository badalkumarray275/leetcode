class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        vector<vector<int>>res;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<m;i++)
        {
            vector<int>v;
            for(int j=0;j<n;j++)
            {
                v.push_back(matrix[j][i]);
            }
            res.push_back(v);
        }
        return res;
    }
};