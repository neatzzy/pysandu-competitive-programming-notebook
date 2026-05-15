// Knapsack problem implementation
// Time complexity: O(n*w)
// Space complexity: O(n*w)

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