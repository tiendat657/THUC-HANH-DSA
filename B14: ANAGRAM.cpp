C1: Sort
void swap(char &a, char &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(string &a, int low, int high) {
    int i = low - 1;
    int j = high + 1;
    
    int pivot = a[low];
    while (true) {
        do {
            i++;
        } while (a[i] < pivot);
        
        do {
            j--;
        } while (a[j] > pivot);
        
        if (i >= j) return j;
        
        swap(a[i], a[j]);
    }
}

void quickSort(string &a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        
        quickSort(a, low, pi);
        quickSort(a, pi + 1, high);
    }
}
    bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    
    quickSort(s, 0, (int)s.length() - 1);
    quickSort(t, 0, (int)t.length() - 1);
    
    return s == t;
}

C2: Mang_cong_don

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    
    int n = (int)s.length();
    
    vector<int> alphabet(26, 0);
    for (int i = 0; i < n; i++) {
        alphabet[s[i] - 'a']++;
        alphabet[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (alphabet[i] != 0) return false;
    }
    
    return true;
}
