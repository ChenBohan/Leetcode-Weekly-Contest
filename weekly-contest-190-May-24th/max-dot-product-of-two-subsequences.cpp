class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int sz1=nums1.size(),sz2=nums2.size();
        vector<vector<int>> dp(sz1+1,vector<int>(sz2+1,-1e8));
        for(int i=1; i<=sz1; i++){
            for(int j=1; j<=sz2; j++){
                //1.1 不选择前面的
                dp[i][j] = nums1[i-1] * nums2[j-1];
                //1.2 也选择前面的
                dp[i][j] = max(dp[i][j], nums1[i-1] * nums2[j-1] + dp[i-1][j-1]);
                //2 选择nums1[i],不选择nums2[j]
                dp[i][j]= max(dp[i][j], dp[i][j-1]);
                //3 不选择nums1[i],选择nums2[j]
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                //4 nums1[i],nums2[j]都不选择
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
            }
        }
        return dp[sz1][sz2];
    }
};
