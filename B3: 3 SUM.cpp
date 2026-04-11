class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    
    // ky thuat 2 con tro yeu cau sap xep mang
    sort(nums.begin(), nums.end());

    int n = (int)nums.size();
    // co dinh i, dung 2 con tro de tim kiem
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) break; // neu 1 so da > 0, cac so sau no (lon hon no) chac chan se > 0 nen break de return luon
        
        if (i > 0 && nums[i] == nums[i - 1]) continue; // bo qua phan tu trung lap nhau
        int l = i + 1, r = n - 1;
        
        while (l < r) { // yeu cau l != r
            // target = 0
            int needed = - nums[i]; // S = a[i] + a[l] + a[r] -> ...
            int curSum = nums[l] + nums[r]; // tao 1 bien tong hien tai de so sanh
            
            if (curSum == needed) { // neu dung yeu cau -> them vao vector
                res.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1]) l++; // bo qua phan tu trung lap nhau
                while (l < r && nums[r] == nums[r - 1]) r--; // bo qua phan tu trung lap nhau
                // sau khi loai bo, can dich them 1 o de sang so moi
                l++; r--;
            } else if (curSum > needed) {
                r--; // giam r de curSum be lai -> tim
            } else {
                l++; // tang l de tong curSum lon hon -> tim
            }
        }

    }
    return res;
}
};
