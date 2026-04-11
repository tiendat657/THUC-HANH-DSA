      --- BAI GIAI ---
int missingNumber(vector<int>& nums) {
    int n = (int)nums.size();
    
    ll target = 1LL * n * (n + 1) / 2;
    ll sum = 0;
    for (int x : nums) {
        sum += x;
    }
    
    return target - sum;
}
