int findFirstGreaterOrEqual(vector<int> &tails, int x) {
    int l = 0, r = (int)tails.size() - 1;
    int res = -1;
    
    while (l <= r) {
        int m = l + (r - l) / 2;
        
        if (tails[m] >= x) {
            res = m; // luu lai vi tri tiem nang
            r = m - 1; // tim tiep ben trai xem co phan tu nao tot hon khong
        } else {
            l = m + 1;
        }
    }
    return res;
}
int lengthOfLIS(vector<int>& nums) {
    int n = (int)nums.size();
    vector<int> tails;
    
    for (int i = 0; i < n; i++) {
        int pos = findFirstGreaterOrEqual(tails, nums[i]);
        if (pos == -1) { // khong co bat ki phan tu nao trong tails >= x -> x co the keo dai day con hien tai
            tails.push_back(nums[i]);
        } else {
            tails[pos] = nums[i];
        }
    }
    return (int)tails.size();
}
