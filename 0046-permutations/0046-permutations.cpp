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

class Solution {
private:
    vector<vector<int>> res;
    void helper(vector<int>& nums, vector<bool>& exist, vector<int>& path) {
        // base case
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        // logic
        for (int i = 0; i < nums.size(); i++) {
            // skip if number is already used
            if (exist[i]) continue;
            
            // action
            exist[i] = true;
            path.push_back(nums[i]);
            
            // recurse
            helper(nums, exist, path);
            
            // backtrack
            path.pop_back();
            exist[i] = false;
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<int> path;
        vector<bool> exist(nums.size(), false);  // initialize with false
        helper(nums, exist, path);
        return res;
    }
};