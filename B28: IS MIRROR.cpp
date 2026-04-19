bool isMirror(TreeNode* nleft, TreeNode* nright) {
    if (nleft == nullptr && nright == nullptr) return true;
    if (nleft == nullptr || nright == nullptr || nleft->val != nright->val) return false;
  
    return isMirror(nleft->left, nright->right) && isMirror(nleft->right, nright->left);
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
  
    return isMirror(root->left, root->right);
}
