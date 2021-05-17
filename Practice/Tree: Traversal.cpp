//preorder transversal (VLR)
void preOrder(Node *root) {
    if(!root) return;
    std::cout << root->data << ' ';
    preOrder(root->left);
    preOrder(root->right);
}

//inorder transversal (LVR)
void inOrder(Node *root) {
    if(!root) return;
    inOrder(root->left);
    std::cout << root->data << ' ';
    inOrder(root->right);
}

//postorder transversal (LRV)
void postOrder(Node *root) {
    if(!root) return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->data << ' ';
}

//level-order transversal
void levelOrder(Node * root) {
    queue<Node*> q;
    q.emplace(root);
    
    while(!q.empty()){
        Node* ptr = q.front();
         q.pop();
            
        if(!ptr) continue;
        cout << ptr->data << ' ';
        if(ptr->left) q.emplace(ptr->left);
        if(ptr->right) q.emplace(ptr->right);
    }
}
