// DP Approach: 1D Array:

class Solution {
    public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1);
        for(int i = 1; i <= amount; i++){
            dp[i] = 999999;
        }
        for(int coin: coins){
            for(int i = 0; i <= amount; i++){
                if(coin <= i){
                    dp[i] = min(dp[i], (dp[i - coin] + 1));
                }
            }
        }
        if(dp[amount] == 999999) return -1;
        return dp[amount];
    }
};

// DP Approach: 2D Array:

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));
//         for(int i = 1; i <= amount; i++){
//             dp[0][i] = 999999;
//         }
//         for(int i = 1; i <= coins.size(); i++){
//             for(int j = 0; j <= amount; j++){
//                 if(coins[i - 1] > j){
//                     dp[i][j] = dp[i - 1][j];
//                 }
//                 else{
//                     dp[i][j] = min(dp[i - 1][j], (dp[i][j - coins[i - 1]] + 1));
//                 }
//             }
//         }
//         if(dp[coins.size()][amount] == 999999) return -1;
//         return dp[coins.size()][amount];
//     }
// };

// Exhaustive Approach:

// class Solution {
// public:
//     int helper(vector<int>& coins, int idx, int coinsUsed, int amount){
//         //base
//         if(amount == 0) return coinsUsed;
//         if(idx >= coins.size() || amount < 0) return -1;
//         //logic
//         //choose
//         int case1 = helper(coins, idx, coinsUsed + 1, amount - coins[idx]);

//         //don't choose
//         int case2 = helper(coins, idx + 1, coinsUsed, amount);

//         if(case1 == -1) return case2;
//         if(case2 == -1) return case1;
//         return min(case1, case2);
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         return helper(coins, 0, 0, amount);
//     }
// };