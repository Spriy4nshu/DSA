// //DP Approach: variable

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int a1 = nums[0];
        int a2 = max(a1, nums[1]);
        for(int i = 2; i < nums.size(); i++){
            int temp = a1;
            a1 = a2;
            a2 = max(nums[i] + temp, a2);
            // if(nums[i] + a1 > a2){
            //     int temp = a1;
            //     a1 = a2;
            //     a2 = nums[i] + temp;
            // }
            // else{
            //     a1 = a2;
            // }
        }
        return max(a1, a2);
    }
};

// DP Approach: 1D array

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         if(nums.size() == 1) return nums[0];
//         vector<int> robbings;
//         robbings.push_back(nums[0]);
//         robbings.push_back(max(nums[1], nums[0]));
//         for(int i = 2; i < nums.size(); i++){
//             if(nums[i] + robbings[i - 2] > robbings[i - 1]){
//                 robbings.push_back(nums[i] + robbings[i - 2]);
//             }
//             else{
//                 robbings.push_back(robbings[i - 1]);
//             }
//         }
//         return robbings[nums.size() - 1];
//     }
// };


// Exhaustive Approach:

// class Solution {
// public:
//     int helper(vector<int>& nums, int idx, int robbings){
//         //base
//         if(nums.size() == 1) return nums[0];
//         if(idx >= nums.size()) return robbings;
        
//         //logic
//         //choose
//         int case1 = helper(nums, idx + 2, robbings + nums[idx]);

//         //not choose
//         int case2 = helper(nums, idx + 1, robbings);

//         return max(case1, case2);
//     }
//     int rob(vector<int>& nums) {
//         return helper(nums, 0, 0);
//     }
// };