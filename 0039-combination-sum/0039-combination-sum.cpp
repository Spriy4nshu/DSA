class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        helper(candidates, 0, target, path, result);
        return result;
    }
    
private:
    void helper(vector<int>& candidates, int pivot, int target, vector<int>& path, vector<vector<int>>& result) {
        // base cases
        if (pivot == candidates.size() || target < 0) return;
        if (target == 0) {
            result.push_back(path);
            return;
        }
        
        // logic
        for(int i = pivot; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            helper(candidates, i, target - candidates[i], path, result);
            path.pop_back();
        }
    }
};