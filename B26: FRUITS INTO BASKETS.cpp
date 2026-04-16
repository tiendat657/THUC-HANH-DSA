int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n = (int)fruits.size();
    int unplaced = 0; // so luong trai cay chua co gio
        
    for (int i = 0; i < n; i++) {
        bool placed = false; // mac dinh la chua co ro
        
        for (int j = 0; j < n; j++) {
            if (baskets[j] != 0 && fruits[i] <= baskets[j]) {
                placed = true; // da tim ra
                baskets[j] = 0; // danh dau ve 0 -> danh dau gio nay da co trai cay
                break; // tim duoc thi thoat luon vi 1 loai chi can 1 gio
            }
        }
        
        if (!placed) unplaced++;
    }
    
    return unplaced;
}
