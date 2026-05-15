// Knapsack problem implementation using dynamic programming
// Time complexity: O(n*w), where n is the number of items and w is the maximum weight
// Space complexity: O(n*w) for the dp table

int knapsack(int w, vector<ii>& items){
    int n = items.size();
    vector<vi> dp(n+1, vi(w+1, 0));

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= w ; j++){
            if(items[i-1].first > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-items[i-1].first] + items[i-1].second);
        }
    }

    return dp[n][w];
}