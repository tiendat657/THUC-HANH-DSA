      --- DE BAI ---
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
Constraints:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

      --- BAI GIAI: Sort + Binary Search --- 

vector<int> twoSum(vector<int>& nums, int target) {
    int n = (int)nums.size(); // dat n de de code de nhin hon
    
    vector<pair<int, int>> valueWithIndex; // khoi tao 1 vector luu chi so va vi tri de sau khi sap xep, ta khong bi mat vi tri ban dau cua chung
    for (int i = 0; i < n; i++) {
        valueWithIndex.push_back({nums[i], i});
    }
    
    // ta khong can viet comparator vi sap xep second khong lam anh huong den ket qua bai toan
    sort(valueWithIndex.begin(), valueWithIndex.end());
    
    for (int i = 0; i < n; i++) {
        int needed = target - valueWithIndex[i].first;
        
        int l = i + 1, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2; // tranh tran kieu du lieu int

            if (valueWithIndex[m].first == needed) {
                // su dung initialization list de tra ve vi tri ban dau cua phan tu do
                return {valueWithIndex[i].second, valueWithIndex[m].second};
            } else if (valueWithIndex[m].first > needed) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
    }
    return {-1, -1}; // vi de bai dam bao se co 1 cap gia tri tra ve, nen dong nay chi de compiler khong bao loi thieu ket qua tra ve
}



            --- BAI GIAI: Unordered_map (Hash_map) --- 

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> valWithIndex;
    
    for (int i = 0; i < (int)nums.size(); i++) {
        int needed = target - nums[i];
        if (valWithIndex.find(needed) != valWithIndex.end()) {
            return { valWithIndex[needed], i};
        }
        valWithIndex[nums[i]] = i;
    }
    
    return {-1, -1};
}
