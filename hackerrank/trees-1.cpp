#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

// void insertNode(node** root, int value);
// bool lookupInTree(const node* root, int value);
// void inorder(const node* root);
// void preorder(const node* root);
// void postorder(const node* root);
// void deleteTree(node* root);

// implementation of insert, lookup, print and delete ops on a simple binary
// search tree with string as key/value.

// void insertNode(node** root, int value) {
//     int ret = 0;
//     if (!*root) {
//         node* temp = (node*)malloc(sizeof(node));
//         temp->data = value;
//         temp->left = temp->right = NULL;
//         *root = temp;
//         return;
//     }
//     // if the entry exists in the tree, do not add and return
//     if ((*root)->data == value)
//         return;
//     if ((*root)->data < value)
//         insertNode(&((*root)->right), value);
//     else
//         insertNode(&((*root)->left), value);
//     return;
// }

// https://www.hackerrank.com/challenges/binary-search-tree-insertion
node* insert(node* root, int value) {
    if (!root) {
        node* temp = (node*)malloc(sizeof(node));
        temp->data = value;
        temp->left = temp->right = NULL;
        root = temp;
        return root;
    }
    if (root->data == value)
        return root;
    if (root->data < value) {
        if (!root->right) {
            node* temp = (node*)malloc(sizeof(node));
            temp->data = value;
            temp->left = temp->right = NULL;
            root->right = temp;
            return root;
        }
        insert (root->right, value);
    }
    else {
        if (!root->left) {
            node* temp = (node*)malloc(sizeof(node));
            temp->data = value;
            temp->left = temp->right = NULL;
            root->left = temp;
            return root;
        }
        insert (root->left, value);
    }
    return root;
}

// https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree
int height(const node* root) {
    if (!root)
        return 0;
    int right = height(root->right);
    int left = height(root->left);
    if (right > left)
        left = right;
    return (1 + left);
}

node* lookupInTree(node* root, int value) {
    if (root->data == value)
        return root;
    else if (root->data > value) {
        if (!(root->left))
            return false;
        else
            return lookupInTree(root->left, value);
    }
    else {
        if (!(root->right))
            return false;
        else
            return lookupInTree(root->right, value);
    }
}

void inorder(const node* root) {
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void deleteTree(node* root) {
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
    root = NULL;
}

void preorder(node *root) {
    if (!root)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root) {
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

//https://www.hackerrank.com/challenges/tree-level-order-traversal
void LevelOrder(node *root) {
    if (!root)
        return;
    int nCurrLevel = 1, nNextLevel = 0;
    std::queue<node*> elements;
    elements.push(root);
    while (!elements.empty()) {
        printf("%d ", (elements.front())->data);
        if (elements.front()->left) {
            elements.push(elements.front()->left);
            ++nNextLevel;
        }
        if (elements.front()->right) {
            elements.push(elements.front()->right);
            ++nNextLevel;
        }
        elements.pop();
        --nCurrLevel;
        if (!nCurrLevel) {
            nCurrLevel = nNextLevel;
            nNextLevel = 0;
        }
    }
}

void levelOrderm(node *root, bool maintainLevels = false) {
    if (!root)
        return;
    int nCurrLevel = 1, nNextLevel = 0;
    std::queue<node*> elements;
    elements.push(root);
    while (!elements.empty()) {
        printf("%d ", (elements.front())->data);
        if (elements.front()->left) {
            elements.push(elements.front()->left);
            ++nNextLevel;
        }
        if (elements.front()->right) {
            elements.push(elements.front()->right);
            ++nNextLevel;
        }
        elements.pop();
        --nCurrLevel;
        if (!nCurrLevel) {
            if (maintainLevels)
                printf("\n");
            nCurrLevel = nNextLevel;
            nNextLevel = 0;
        }
    }
}

// https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor
bool buildPath(node* root, int value, stack<node*>& path) {
    if (!root)
        return false;
    path.push(root);
    if (root->data == value)
        return true;
    if (!(buildPath(root->left, value, path) || buildPath(root->right, value, path))) {
        path.pop();
        return false;
    } else {
        return true;
    }
}

node * lca(node * root, int v1,int v2) {
    stack<node*> st1, st2;
    buildPath (root, v1, st1);
    buildPath (root, v2, st2);
    int size1 = st1.size();
    int size2 = st2.size();
    if (size1>size2) {
        for (int i = 0; i < (size1-size2); ++i) {
            st1.pop();
        }
    }
    else {
        for (int i = 0; i < (size2-size1); ++i) {
            st2.pop();
        }
    }
    while (st1.top() != st2.top()) {
        st1.pop();
        st2.pop();
    }
    // while (!st1.empty()) {
    //     cout << st1.top()->data << " ";
    //     st1.pop();
    // }
    // cout << '\n';
    // while (!st2.empty()) {
    //     cout << st2.top()->data << " ";
    //     st2.pop();
    // }
    // cout << '\n';
    return st1.top();
}

// https://www.hackerrank.com/challenges/tree-top-view
void top_view(node * root) {

}

int main() {
    node* _root = NULL;
    int input = 0;
    while (true) {
        scanf("%d", &input);
        if (-1 == input)
            break;
        _root = insert(_root, input);
    }
    lca(_root, 45, 55);
    cout << height(_root);
    deleteTree(_root);
    return 0;
}