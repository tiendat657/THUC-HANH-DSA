-- BAI GIAI ---

int findLHS(vector<int>& nums) {
    unordered_map<int, int> mp;
    
    for (int x : nums) {
        mp[x]++;
    }
    
    int maxLength = 0;
    for (const auto &[no, fr] : mp) {
        if (mp.find(no + 1) != mp.end()) { // tim thay so lon hon 1 don vi (tinh chat cua map: tang dan)
            maxLength = max(maxLength, fr + mp[no + 1]);
        }
    }
    
    return maxLength;
}
