#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include<string>
using std::string;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
};
class BinaryTree
{
private:
    TreeNode *m_root;
public:
    BinaryTree();
    ~BinaryTree();
    void Clear();
    void InsertNode(const int &val);
    void DeleteNode(const int &val);
    void UpdateNode(const int &old_val,const int &new_val);
    bool Contains(const int &val);
    void DeleteTree(TreeNode *&root);
    void ShiftLeft(TreeNode *root);
    void ShiftRight(TreeNode *root);
    TreeNode *findNode(const int &val)
    {
        TreeNode *ptr;
        ptr=m_root;
        while (ptr!=nullptr)
        {
            if (val<ptr->val)
            {
                if (ptr->left!=nullptr)
                {
                    ptr=ptr->left;
                }
                else
                {
                    return ptr;
                }
            }
            else if (val>ptr->val)
            {
                if (ptr->right!=nullptr)
                {
                    ptr=ptr->right;
                }
                else
                {
                    return ptr;
                }
            }
            else
            {
                return ptr;
            }
        }
        return ptr;
    }
    void preorderRecursive (const TreeNode *root,string &result);
    void postorderRecursive(const TreeNode *root,string &result);
    string preorderTraversal ();
    string postorderTraversal();
};
#endif