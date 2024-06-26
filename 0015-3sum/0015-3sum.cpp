class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int n1 = nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                vector<int> triplet = {n1};
                if(nums[l] + nums[r] + n1 == 0){
                    triplet.push_back(nums[l]);
                    triplet.push_back(nums[r]);
                    result.push_back(triplet);
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l - 1]) l++;
                    while(l < r && nums[r] == nums[r + 1]) r--;
                }
                if(nums[l] + nums[r] + n1 < 0){
                    l++;
                }
                if(nums[l] + nums[r] + n1 > 0){
                    r--;
                }
                
            }
        }
        return result;
    }
};