#include "NodeBST.h"
#include <iostream>

NodeBST::NodeBST() : root(nullptr) {}

NodeBST::~NodeBST() {
    deleteSubTree(root);
}

void NodeBST::deleteSubTree(Node *node) {
    if (node != nullptr) {
        deleteSubTree(node->left);
        deleteSubTree(node->right);
        delete node;
    }
}

void NodeBST::insert(int val) {
    if (root == nullptr) {
        root = new Node(val);
    } else {
        Node *current = root;
        while (true) {
            if (val < current->val) {
                if (current->left == nullptr) {
                    current->left = new Node(val);
                    break;
                } else {
                    current = current->left;
                }
            } else if (val > current->val) {
                if (current->right == nullptr) {
                    current->right = new Node(val);
                    break;
                } else {
                    current = current->right;
                }
            } else {
                break;
            }
        }
    }
}

bool NodeBST::find(int val) const {
    Node *current = root;
    while (current != nullptr) {
        if (val == current->val) {
            return true;
        } else if (val < current->val) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

void NodeBST::print_inorder() const {
    inorder(root);
}

void NodeBST::print_preorder() const {
    preorder(root);
}

void NodeBST::print_postorder() const {
    postorder(root);
}

void NodeBST::inorder(Node *node) const {
    if (node != nullptr) {
        inorder(node->left);
        std::cout << node->val << " ";
        inorder(node->right);
    }
}

void NodeBST::preorder(Node *node) const {
    if (node != nullptr) {
        std::cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void NodeBST::postorder(Node *node) const {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        std::cout << node->val << " ";
    }
}
