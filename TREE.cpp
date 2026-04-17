#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <unordered_set>
#include <stack>
#define MAX 1000005
#define endl "\n"
typedef long long ll;
using namespace std;

// khai bao cau truc cay nhi phan
struct Node {
    int data;
    Node* left;
    Node* right;
};


// duyet trai - goc - phai (in-order) bang de quy
void inorder(Node* node, vector<int> &res) {
    if (node == nullptr) return;

    inorder(node->left, res);
    res.push_back(node->data);
    inorder(node->right, res);
}

// ket hop ham duyet de tra ve vector luu du lieu tu cay nhi phan
vector<int> traversal(Node* root) {
    vector<int> res;
    if (root == nullptr) return res;
    inorder(root, res);
    
    return res;
}

// duyet trai - goc - phai (in-order) bang stack
vector<int> inorderStack(Node * root) {
    if (root == nullptr) return {};
    
    vector<int> res; // vector luu ket qua
    stack<Node*> s; // tao stack de luu cac node da di qua
    
    s.push(root);
    
    while (!s.empty()) {
        Node* curr = s.top();
        res.push_back(curr->data);
        s.pop();
        
        if (curr->left) s.push(curr->left); // cho left vao truoc de duyet qua left sau
        if (curr->right) s.push(curr->right); // cho right vao sau de lay right ra truoc
    }
    // sau buoc nay, ta da co res theo thu tu goc - phai - trai
    // -> reverse de dao nguoc lai thanh: trai - phai - goc (post)
    reverse(res.begin(), res.end());
    
    return res;
}

vector<int> postoerder(Node* root) {
    if (root == nullptr) return {};
    
    vector<int> res; // vector luu ket qua
    stack<Node*> s; // tao stack de luu cac node da di qua
    
    Node* curr = root;
    
    while (curr != nullptr || !s.empty()) {
        while (curr != nullptr) { // di het ben trai
            s.push(curr);
            curr = curr->left;
        }
        while (curr != nullptr) { // sau khi di het ben trai, di het ben phai
            s.push(curr);
            curr = curr->right;
        }
        // sau khi di het, quay luu bang cach lay tung node trong stack ra
        
        curr = s.top();
        res.push_back(curr->data);
        s.pop();
    }
    
    return res;
}

int main(void) {
    
    
    return 0;
}
