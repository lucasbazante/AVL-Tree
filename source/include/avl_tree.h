#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include "node.h"
#include <iostream>
#include <algorithm>
#include <string>

class AVLTree {
    private:
        Node *root;

        struct Trunk {
            Trunk *prev;
            std::string str;

            Trunk(Trunk *prev, std::string str)
            {
                this->prev = prev;
                this->str = str;
            }
        };

        int height_of(Node *pt) {
            return pt == nullptr ? 0 : pt->height; 
        }

        Node* right_rotation(Node *pt) {
            Node *ptu = pt->left;
            pt->left = ptu->right;
            ptu->right = pt;
            
            pt->update_height();
            ptu->update_height();
            pt->update_balance();
            ptu->update_balance();

            return ptu;
        }

        Node* left_rotation(Node *pt) {
            Node *ptu = pt->right;
            pt->right = ptu->left;
            ptu->left = pt;
            
            pt->update_height();
            ptu->update_height();
            pt->update_balance();
            ptu->update_balance();

            return ptu;
        }
        
        Node* search_procedure(Node *pt, int x) {
            if(pt == nullptr) 
                return nullptr;
            else if(x == pt->key) 
                return pt;
            else if(x < pt->key)
                return search_procedure(pt->left, x);
            else if(x > pt->key)
                return search_procedure(pt->right, x);
            return nullptr;
        }

        Node* insert_procedure(int x, Node *pt) {
            if(pt == nullptr) { // no nodes
                Node *ptn = new Node(x);
                return ptn;
            }
            
            if(x < pt->key)
                pt->left = insert_procedure(x, pt->left);
            else
                pt->right = insert_procedure(x, pt->right);

            pt->update_height();
            pt->update_balance();

            if(pt->balance > 1) { // unbalanced to the left
                Node *leftchild = pt->left;
               
                if(height_of(leftchild->left) <= height_of(leftchild->right)) // need to perform double rotation
                    leftchild = left_rotation(pt->left);
                return right_rotation(pt); // we always rotate one time right
            }
            else if(pt->balance < -1) { // unbalanced to the right
               Node *rightchild = pt->right;
               
               if(height_of(rightchild->right) <= height_of(rightchild->left))
                   rightchild = right_rotation(pt);
               return left_rotation(pt);
            }

            return pt;
        } 

        Node* remove_procedure(int x, Node* pt) {
            if(pt == nullptr) // found no such key in subtrees
                return nullptr;
            
            // searching step
            if(x < pt->key)
                pt->left = remove_procedure(x, pt->left);
            else if(x > pt->key)
                pt->right = remove_procedure(x, pt->right);
            else { // found the key to remove
                if(pt->left == nullptr or pt->right == nullptr) { // none or one child
                    Node *aux = pt->left ? pt->left : pt->right;

                    if(aux == nullptr)
                        aux = pt, pt = nullptr;
                    else
                        *pt = *(pt->left ? pt->left : pt->right);

                    delete aux;
                }
                else { // has two childs, find inorder sucessor and transform in leaf removal
                    Node *sucessor = pt->right;

                    while(sucessor->left != nullptr)
                        sucessor = sucessor->left;

                    pt->key = sucessor->key; // copy to the node
                    pt->right = remove_procedure(pt->key, pt->right); // delete the sucessor
                }
            }

            if(pt == nullptr) // the tree only had that node
                return pt;

            pt->update_height();
            pt->update_balance();

            // cases of unbalancing
            if(pt->balance > 1) { // right imbalance
                if(height_of(pt->left) < height_of(pt->right)) // perform a double
                    pt->left = left_rotation(pt->left);
                return right_rotation(pt); // we always rotate one to right
            }
            else if(pt->balance < -1) {
                if(height_of(pt->right) < height_of(pt->left))
                    pt->right = right_rotation(pt->right);
                return left_rotation(pt);
            }

            return pt;
        }
    
        void show_trunks(Trunk * p) {
            if(p == nullptr)
                return;

            show_trunks(p -> prev);
            std::cout << p->str;
        }

        void print_tree(Node *pt, Trunk *prev, int is_left) {
            if(pt == nullptr)
                return;

            std::string prev_str = "    ";
            Trunk *trunk = new Trunk(prev, prev_str);
            print_tree(pt->right, trunk, 1);

            if(!prev)
                trunk->str = "———";
            else if(is_left) {
                trunk->str = ".———";
                prev_str = "   |";
            } else {
                trunk->str = "`———";
                prev->str = prev_str;
            }

            show_trunks(trunk);
            std::cout << " " << pt->key << std::endl;

            if(prev) 
                prev->str = prev_str;
            trunk -> str = "   |";

            print_tree(pt->left, trunk, 0);
        }
    
    public:
        AVLTree() {
            root = nullptr;
        }

        AVLTree(int x) {
            root = new Node(x);
        }

        Node* get_root() {
            return root;
        }

        Node* search(int x) {
            return search_procedure(root, x);
        }
 
        void insert(int x) {
            root = insert_procedure(x, root);
        }
        
        void remove(int x) {
            root = remove_procedure(x, root);
        }

        void inorder_print(Node *pt) {
            if(pt == nullptr)
                return;
            inorder_print(pt->left);
            std::cout << pt->key << " ";
            inorder_print(pt->right);
        }

        void pretty_print(Node *pt = nullptr) {
            if(pt == nullptr)
                pt = root;
            print_tree(pt, nullptr, 0);
            std::cout << std::endl;
        }
};

#endif
