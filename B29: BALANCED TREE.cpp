int checkHeight(TreeNode* node) {
    if (node == nullptr) return 0;
    
    int l = checkHeight(node->left);
    if (l == -1) return -1;
    
    int r = checkHeight(node->right);
    if (r == -1) return -1;
    
    if (abs(l - r) > 1) return -1;
    
    return 1 + max(l, r);
}

bool isBalanced(TreeNode* root) {
    return (checkHeight(root) == -1) ? false : true;
}
