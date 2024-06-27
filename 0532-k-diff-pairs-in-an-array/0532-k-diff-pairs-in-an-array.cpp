class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size() <= 1) return 0;
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = 1;
        int count = 0;
        while(r < nums.size()){
            if(r == l){
                r++;
                continue;
            }
            if(nums[r] - nums[l] == k){
                count++;
                l++;
                r++;
                while(r < nums.size() && nums[r] == nums[r - 1]) r++;
                while(l < nums.size() && nums[l] == nums[l - 1]) l++;
            }
            else if(nums[r] - nums[l] < k){
                r++;
            }
            else{
                l++;
            }
        }
        return count;
    }
};