struct Node {
    char val;
    int weight, size;
    Node *left, *right;
    int toinvert;
    Node(char c) : val(c), weight(rand()), size(1), left(NULL), right(NULL), toinvert(0) {}
} *root;
inline int size(Node *treap) {
    return treap ? treap->size : 0;
}
void push(Node *treap) {
    if(treap == NULL) return;
    if(treap->toinvert == 0) return;
    Node *temp = treap->left;
    treap->left = treap->right;
    treap->right = temp;
    treap->toinvert = 0;
    if(treap->left != NULL) treap->left->toinvert ^= 1;
    if(treap->right != NULL) treap->right->toinvert ^= 1;
}
void split(Node *treap, Node *&left, Node *&right, int val) {
    if (!treap) {
        left = right = NULL; return;
    }
    push(treap);
    if (size(treap->left) < val) {
        split(treap->right, treap->right, right, val - size(treap->left) - 1);
        left = treap;
    } else {
        split(treap->left, left, treap->left, val);
        right = treap;
    }
    treap->size = 1 + size(treap->left) + size(treap->right);
}
void merge(Node *&treap, Node *left, Node *right) {
    if (left == NULL) 
        treap = right; return;
    if (right == NULL) 
        treap = left; return;
    push(left); push(right);
    if (left->weight < right->weight) {
        merge(left->right, left->right, right); treap = left;
    } else {
        merge(right->left, left, right->left); treap = right;
    }
    treap->size = 1 + size(treap->left) + size(treap->right);
}
void solve() { //USAGE: 
    //get integers n,q and string s
    for(auto c: s) merge(root, root, new Node(c));
    while(q--) {
        int l, r; cin >> l >> r;
        Node *a, *b;
        split(root, a, b, l - 1);
        Node *c, *d;
        split(b, c, d, r - l + 1);
        c->toinvert ^= 1;
        merge(root, a, c);
        merge(root, root, d);
    }
    cout << root << nl;
}