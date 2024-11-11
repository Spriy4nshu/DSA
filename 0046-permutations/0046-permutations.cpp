// class Solution {
// private:
//     vector<vector<int>> res;
//     void helper(vector<int>& nums, vector<bool>& exist, vector<int>& path){
//         //base
//         if(path.size() == nums.size()){
//             res.push_back(path);
//             return;
//         }

//         //logic
//         for(int i = 0; i < nums.size(); i++){
//             //action
//             path.push_back(nums[i]);
//             //recurse
//             helper(nums, i, path);
//             //backtrack
//             path.pop_back();
//         }
//     }
    
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         if(nums.size() == 0) return {};
//         vector<int> path;
//         vector<bool> exist(nums.size(), );
//         helper(nums, 0, path);
//         return res;
//     }
// };

// class Solution {
// private:
//     vector<vector<int>> res;
//     void helper(vector<int>& nums, vector<bool>& exist, vector<int>& path) {
//         // base case
//         if (path.size() == nums.size()) {
//             res.push_back(path);
//             return;
//         }

//         // logic
//         for (int i = 0; i < nums.size(); i++) {
//             // skip if number is already used
//             if (exist[i]) continue;
            
//             // action
//             exist[i] = true;
//             path.push_back(nums[i]);
            
//             // recurse
//             helper(nums, exist, path);
            
//             // backtrack
//             path.pop_back();
//             exist[i] = false;
//         }
//     }
    
    
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         if (nums.size() == 0) return {};
//         vector<int> path;
//         vector<bool> exist(nums.size(), false);  // initialize with false
//         helper(nums, exist, path);
//         return res;
//     }
// };


class Solution {
private:
    void helper(vector<int>& nums, vector<vector<int>>& res, int idx, vector<int>& path, vector<int>& visited){
        // base
        if(idx > nums.size()) return;
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        // for loop based recursion
        for(int i = 0; i < nums.size(); i++){
            if(visited[i]) continue;
            // action
            path.push_back(nums[i]);
            visited[i] = 1;
            //recurse
            helper(nums, res, i, path, visited);
            //backtrack
            path.pop_back();
            visited[i] = 0;
        }
    }
    
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<int> visited(nums.size(), 0);
        helper(nums, res, 0, path, visited);
        return res;
    }
};