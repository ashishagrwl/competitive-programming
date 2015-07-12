#include <bits/stdc++.h>
using namespace std;

struct treeNode {
    int index;
    treeNode* left;
    treeNode* right;
};

void inorder(const treeNode* root, vector<int>& vk, int level=1) {
    if (!root)
        return;
    bool invert = false;
    for(auto&& i : vk) {
        if (!(level%i))
            invert = !invert;

    }
    if (invert) {
        inorder(root->right, vk, level+1);
        cout << root->index << " ";
        inorder(root->left, vk, level+1);
    } else {
        inorder(root->left, vk, level+1);
        cout << root->index << " ";
        inorder(root->right, vk, level+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    treeNode *head = new treeNode;
    head->index = 1;
    head->left = head->right = NULL;
    queue<treeNode*> qu;
    qu.push(head);
    int count = 0;
    cin >> count;
    while (count--) {
        int index1 = 0, index2=0;
        cin >> index1 >> index2;
        treeNode* temp = qu.front();
        if (-1 != index1) {
            temp->left = new treeNode;
            temp->left->index = index1;
            temp->left->left = temp->left->right = NULL;
            qu.push(temp->left);
        }
        if (-1 != index2) {
            temp->right = new treeNode;
            temp->right->index = index2;
            temp->right->left = temp->right->right = NULL;
            qu.push(temp->right);
        }
        qu.pop();
    }
    while (!qu.empty())
        qu.pop();
    //inorder(head);
    int t=0;
    cin >> t;
    vector<int> _vk;
    _vk.reserve(t);
    while (t--) {
        int k=0;
        cin >> k;
        _vk.push_back(k);
        //// level order
        // int level=1, curr_lvl_count=1, next_lvl_count=0;
        // qu.push(head);
        // vector<int> level_nodes;
        // while (!qu.empty()) {
        //     treeNode* temp = qu.front();
        //     if (temp->left) {
        //         qu.push(temp->left);
        //         next_lvl_count++;
        //     }
        //     if (temp->right) {
        //         qu.push(temp->right);
        //         next_lvl_count++;
        //     }
        //     level_nodes.push_back(temp->index);
        //     qu.pop();
        //     curr_lvl_count--;
        //     if (!curr_lvl_count) {
        //         curr_lvl_count = next_lvl_count;
        //         next_lvl_count = 0;
        //         if (!(level%k)) {
        //             for (std::vector<int>::reverse_iterator ri = level_nodes.rbegin(); ri != level_nodes.rend(); ++ri) {
        //                 cout << *ri << " ";
        //             }
        //         } else {
        //             for (auto&& i: level_nodes) {
        //                 cout << i << " ";
        //             }
        //         }
        //         //cout << '\n';
        //         level_nodes.clear();
        //         level++;
        //     }
        // }
        inorder(head, _vk);
        cout << '\n';
    }
    cout << flush;
    return 0;
}