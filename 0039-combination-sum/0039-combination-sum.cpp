// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> result;
//         vector<int> path;
//         helper(candidates, 0, target, path, result);
//         return result;
//     }
    
// private:
//     void helper(vector<int>& candidates, int idx, int target, vector<int> path, vector<vector<int>>& result) {
//         // base cases
//         if (idx >= candidates.size() || target < 0) return;
//         if (target == 0) {
//             result.push_back(path);
//             return;
//         }
        
//         // logic
//         // dont choose
//         helper(candidates, idx + 1, target, path, result);

//         // choose
//         //action
//         path.push_back(candidates[idx]);
//         // recurse
//         helper(candidates, idx, target - candidates[idx], path, result);
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> result;
//         vector<int> path;
//         helper(candidates, 0, target, path, result);
//         return result;
//     }
    
// private:
//     void helper(vector<int>& candidates, int idx, int target, vector<int>& path, vector<vector<int>>& result) {
//         // base cases
//         if (idx >= candidates.size() || target < 0) return;
//         if (target == 0) {
//             result.push_back(path);
//             return;
//         }
        
//         // logic
//         // dont choose
//         helper(candidates, idx + 1, target, path, result);

//         // choose
//         //action
//         path.push_back(candidates[idx]);
//         // recurse
//         helper(candidates, idx, target - candidates[idx], path, result);
//         // backtrack
//         path.pop_back();
//     }
// };

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        helper(candidates, 0, target, path, result);
        return result;
    }
    
private:
    void helper(vector<int>& candidates, int pivot, int target, vector<int> path, vector<vector<int>>& result) {
        // base cases
        if (target < 0) return;
        if (target == 0) {
            result.push_back(path);
            return;
        }
        
        // logic
        for(int i = pivot; i < candidates.size(); i++){
            vector<int> li = path;
            //action
            li.push_back(candidates[i]);
            // recurse
            helper(candidates, i, target - candidates[i], li, result);
        }
    }
};

// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> result;
//         vector<int> path;
//         helper(candidates, 0, target, path, result);
//         return result;
//     }
    
// private:
//     void helper(vector<int>& candidates, int pivot, int target, vector<int>& path, vector<vector<int>>& result) {
//         // base cases
//         if (target < 0) return;
//         if (target == 0) {
//             result.push_back(path);
//             return;
//         }
        
//         // logic
//         for(int i = pivot; i < candidates.size(); i++){
//             // action
//             path.push_back(candidates[i]);
//             // recurse 
//             helper(candidates, i, target - candidates[i], path, result);
//             // backtrack
//             path.pop_back();
//         }
//     }
// };