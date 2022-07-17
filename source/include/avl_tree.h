#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include "node.h"
#include <algorithm>

class AVLTree {
    private:
        Node *root;

        Node* right_rotation(Node *pt) {
            return pt;
        }

        Node* left_rotation(Node *pt) {
            return pt;
        }

    public:
        

        AVLTree() {
            root = nullptr;
        }

        AVLTree(int x) {
            root = new Node(x);
        }

        Node* search(Node *pt, int x) {
            if(pt == nullptr) 
                return nullptr;
            else if(x == pt->key) 
                return pt;
            else if(x > pt->key)
                return search(pt->left, x);
            else if(x < pt->key)
                return search(pt->right, x);
        }
 
        Node* insert(int x, Node *pt) {
            if(pt == nullptr) { // no nodes
                root = new Node(x);
                return root;
            }
            
            if(x < pt->key)
                pt->left = insert(x, pt->left);
            else
                pt->right = insert(x, pt->right);

            pt->update_height();
            pt->update_balance();

            if(pt->balance > 1) { // unbalanced to the left
                Node *leftchild = pt->left;
                if(leftchild->left->height > leftchild->right->height) // newly inserted key is in the left subtree of the left child, so height(leftchild->left) > height(leftchild->right)
                    return right_rotation(pt);
                else {
                    leftchild = left_rotation(pt->left); // its not, so double rotation
                    return right_rotation(pt);
                }
            }
            else if(pt->balance < -1) { // unbalanced to the right
               Node *rightchild = pt->right;
               if(rightchild->right->height > rightchild->left->height) // newly key in right subtre of right child, so height(rightchild->right) > height(rightchild->left) 
                   return left_rotation(pt);
               else {
                   rightchild = right_rotation(pt);
                   return left_rotation(pt);
               }
            }

            return pt;
        }

        Node* remove(int x, Node *pt) {
            if (pt == nullptr)
                return nullptr;
        }
};

#endif
