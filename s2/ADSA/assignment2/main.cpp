#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class AVLTree
{
    private:

    struct Node
    {
        int val;
        Node *left;
        Node *right;
        int height;
    };

    Node* root;

    void inOrder(Node *node) 
    {   
        if (node != NULL) {
            inOrder(node->left);
            cout << node->val << " ";
            inOrder(node->right);
        }
    }

    void preOrder(Node *node) 
    {   
        if (node != NULL) {
            cout << node->val << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void postOrder(Node *node) 
    {   
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->val << " ";
        }
    }

    Node* singleLeftR(Node* &node) 
    {
        Node* temp = node->right;
        node->right = temp->left; 
        temp->left = node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        temp->height = 1 + max(getHeight(temp->right), node->height);
        return temp;
    }

    Node* singleRightR(Node* &node) 
    {
        Node* temp = node->left;
        node->left = temp->right; 
        temp->right = node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        temp->height = 1 + max(getHeight(temp->left), node->height);
        return temp;
    }

    Node* doubleLeftRightR(Node* &node)
    {
        node->left = singleLeftR(node->left);
        return singleRightR(node);
    }

    Node* doubleRightLeftR(Node* &node)
    {
        node->right = singleRightR(node->right);
        return singleLeftR(node);
    }

    Node* rebalance(Node* node) 
    {
        if (getBalance(node) > 1) {
            if (getBalance(node->left) < 0) {
                node = doubleLeftRightR(node);
            } else {
                node = singleRightR(node);
            }
        } else if (getBalance(node) < -1) {
            if (getBalance(node->right) > 0) {
                node = doubleRightLeftR(node);
            } else {
                node = singleLeftR(node);
            }
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        return node;
    }

    Node* insert(Node *node, int key) 
    {
        if (node == NULL) {
            node = new Node();
            node->height = 1;
            node->val = key;
            node->left = NULL;
            node->right = NULL;
            return node;
        } 
        
        if (key < node->val) {
            node->left = insert(node->left, key);
        } else if (key > node->val) {
            node->right = insert(node->right, key);
        } else return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        node = rebalance(node);

        return node;
    }

    Node* findMax(Node* node)
    {
        if (node == NULL) {
            return node;
        } else if (node->right == NULL) {
            return node;
        } else {
            return findMax(node->right);
        }
    }

    Node* remove(Node *node, int key)
    {
        if (node == NULL) return node;

        Node* temp;

        if (key < node->val) {
            node->left = remove(node->left, key);
        } else if (key > node->val) {
            node->right = remove(node->right, key);
        
        } else if (node->left && node->right) {
            temp = findMax(node->left);
            node->val = temp->val;
            node->left = remove(node->left, node->val);
            
        } else {
            temp = node;
            if (node->left == NULL) {
                node = node->right;
            } else {
                node = node->left;
            }
            delete temp;
        } 

        if (node == NULL) return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        node = rebalance(node);

        return node;
    }

    public:
    AVLTree() 
    {
        root = NULL;
    }

    int getHeight(Node *node)
    {
        if (node == NULL) return 0;
        return node->height;
    }

    int getBalance(Node *node) 
    {
        if (node == NULL) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    void treeTraversal(string order) 
    {
        if (root == NULL) {
            cout << "EMPTY" << endl;
            return;
        }

        if (order == "PRE") preOrder(root);
        else if (order == "IN") inOrder(root);
        else postOrder(root);

        cout << endl;
    }

    void insert(int val)
    {
        root = insert(root, val);
    }

    void remove(int val)
    {
        root = remove(root, val);
    }
    
};

vector<string> getMoves(string s)
{
    vector<string> moves;

    stringstream ss(s);
    string m;
    
    while (ss >> m) {
        moves.push_back(m);
    }
    
    return moves;
}

int main()
{
    string s;
    getline(cin, s);

    vector<string> moves = getMoves(s);

    AVLTree *root = new AVLTree();

    for (int i = 0; i < moves.size()-1; i++) {
        int val = stoi(moves[i].substr(1, moves[i].length()-1));

        if (moves[i][0] == 'A') {
            root->insert(val);
        } else {
            root->remove(val);
        }
    }

    root->treeTraversal(moves[moves.size()-1]);
}