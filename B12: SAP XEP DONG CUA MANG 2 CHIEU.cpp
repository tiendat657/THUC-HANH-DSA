      --- BAI GIAI ---

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <climits>
#define MAX 1000005
#define endl "\n"
typedef long long ll;
using namespace std;


void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &a, int low, int high) {
    int pivot = a[high];
    
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(vector<int> &a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}
int main(void) {
    int n, m, k; cin >> n >> m >> k;
    
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    quickSort(a[k - 1], 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
