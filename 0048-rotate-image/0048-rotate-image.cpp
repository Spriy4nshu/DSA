class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // take transpose of the matrix
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < m; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < n; i++){
            int j = 0;
            int k = matrix[0].size() - 1;
            while(j < k){
                swap(matrix[i][j], matrix[i][k]);
                j++;
                k--;
            }
        }
    }
};