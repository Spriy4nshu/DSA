class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;  // Pointer for 0s
        int m = 0;  // Pointer for current element
        int h = nums.size() - 1;  // Pointer for 2s

        while(m <= h){
            if(nums[m] == 2){
                // Swap nums[m] and nums[h]
                swap(nums[m], nums[h]);
                h--;  // Move h left
            }
            else if(nums[m] == 0){
                // Swap nums[m] and nums[l]
                swap(nums[m], nums[l]);
                m++;  // Move m right
                l++;  // Move l right
            }
            else{
                // If the element is 1, just move m right
                m++;
            }
        }
    }
};