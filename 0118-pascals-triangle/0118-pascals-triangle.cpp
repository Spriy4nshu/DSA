class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i = 0; i < numRows; i++){
            vector<int> row;
            for(int j = 0; j <= i; j++){
                if(j > 0 && j < i){
                    int l = result[i - 1][j - 1];
                    int r = result[i - 1][j];
                    row.push_back(l + r);
                }
                else row.push_back(1);
            }
            result.push_back(row);
        }

        return result;
    }
};