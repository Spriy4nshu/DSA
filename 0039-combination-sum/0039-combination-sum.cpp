class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        helper(candidates, 0, target, path, result);
        return result;
    }
    
private:
    void helper(vector<int>& candidates, int idx, int target, vector<int>& path, vector<vector<int>>& result) {
        // base cases
        if (idx == candidates.size() || target < 0) return;
        if (target == 0) {
            result.push_back(path);
            return;
        }
        
        // logic
        // not choose current number
        helper(candidates, idx + 1, target, path, result);
        
        // choose current number
        path.push_back(candidates[idx]);
        helper(candidates, idx, target - candidates[idx], path, result);
        path.pop_back();
    }
};