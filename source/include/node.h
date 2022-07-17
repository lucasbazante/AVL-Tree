#ifndef _NODE_H_
#define _NODE_H_

#include <algorithm>

class Node {
    public:
        int key;
        Node *left;
        Node *right;
        int height = 1;
        int balance = 0;

        Node(int k = 0, Node *l = nullptr, Node *r = nullptr) {
            key = k;
            Node *left = l;
            Node *right = r;
        }

        void update_height() {
            int lh = left == nullptr ? 0 : left->height;
            int rh = right == nullptr ? 0 : right->height;
            height = 1 + std::max(lh, rh);
        }

        void update_balance() {
            int lh = left == nullptr ? 0 : left->height;
            int rh = right == nullptr ? 0 : right->height;
            balance = lh - rh;
        }
};

#endif
