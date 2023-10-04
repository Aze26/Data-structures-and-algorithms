#include<iostream>
#include"BinaryTree.h"
using std::cout;
using std::endl;
using std::to_string;
BinaryTree::BinaryTree()
{
    m_root=nullptr;
}
BinaryTree::~BinaryTree()
{
    Clear();
}
void BinaryTree::Clear()
{
    DeleteTree(m_root);
}
void BinaryTree::InsertNode(const int &val)
{
    if (m_root==nullptr)
    {
        m_root=new TreeNode(val);
    }
    else
    {
        TreeNode *ptr=findNode(val);
        if (val<ptr->val)
        {
            ptr->left=new TreeNode(val);
        }
        else if (val>ptr->val)
        {
            ptr->right=new TreeNode(val);
        }
    }
}
void BinaryTree::DeleteNode(const int &val)
{
    if (m_root==nullptr)
    {
        return;
    }
    TreeNode *par,*cur;
    par=nullptr;
    cur=m_root;
    while (cur!=nullptr)
    {
        if (cur->val<val)
        {
            par=cur;
            cur=cur->right;
        }
        else if (cur->val>val)
        {
            par=cur;
            cur=cur->left;
        }
        else
        {
            break;
        }
    }
    if (cur==nullptr)
    {
        return;
    }
    if (cur->left!=nullptr)
    {
        ShiftLeft(cur);
    }
    if (cur->right!=nullptr)
    {
        ShiftRight(cur);
    }
    if (par==nullptr)
    {
        delete cur;
        m_root=nullptr;
    }
    else if (cur==par->left)
    {
        delete cur;
        par->left=nullptr;
    }
    else
    {
        delete cur;
        par->right=nullptr;
    }
}
void BinaryTree::DeleteTree(TreeNode *&root)
{
    if (root==nullptr)
    {
        return;
    }
    DeleteTree(root->left);
    DeleteTree(root->right);
    delete root;
    root=nullptr;
}
void BinaryTree::UpdateNode(const int &old_val,const int &new_val)
{
    DeleteNode(old_val);
    InsertNode(new_val);
}
void BinaryTree::ShiftLeft(TreeNode *root)
{
    TreeNode *par,*cur;
    par=root;
    cur=root->left;
    while (cur->right!=nullptr)
    {
        par=cur;
        cur=cur->right;
    }
    root->val=cur->val;
    if (cur->left!=nullptr)
    {
        ShiftLeft(cur);
    }
    if (cur->right!=nullptr)
    {
        ShiftRight(cur);
    }
    if (cur->val<par->val)
    {
        delete par->left;
        par->left=nullptr;
    }
    else
    {
        delete par->right;
        par->right=nullptr;
    }
}
void BinaryTree::ShiftRight(TreeNode *root)
{
    TreeNode *par,*cur;
    par=root;
    cur=cur->right;
    while (cur->left!=nullptr)
    {
        par=cur;
        cur=cur->left;
    }
    root->val=cur->val;
    if (cur->left!=nullptr)
    {
        ShiftLeft(cur);
    }
    if (cur->right!=nullptr)
    {
        ShiftRight(cur);
    }
    if (cur->val<par->val)
    {
        delete cur;
        par->left=nullptr;
    }
    else
    {
        delete cur;
        par->right=nullptr;
    }
}
bool BinaryTree::Contains(const int &val)
{
    TreeNode *ptr=findNode(val);
    if (ptr!=nullptr)
    {
        if (ptr->val==val)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
void BinaryTree::preorderRecursive(const TreeNode *root,string &result)
{
    //result.push_back('{');
    if (root==nullptr)
    {
        result.push_back('#');
    }
    else
    {
        result.append(to_string(root->val));
        preorderRecursive(root->left,result);
        preorderRecursive(root->right,result);
    }
    //result.push_back('}');
}
string BinaryTree::preorderTraversal()
{
    string result;
    preorderRecursive(m_root,result);
    return result;
}
void BinaryTree::postorderRecursive(const TreeNode *root,string &result)
{
    if (root==nullptr)
    {
        result.push_back('#');
    }
    else
    {
        result.append(to_string(root->val));
        postorderRecursive(root->left,result);
        postorderRecursive(root->right,result);
    }
}
string BinaryTree::postorderTraversal()
{
    string result;
    postorderRecursive(m_root,result);
    return result;
}
int main()
{
    BinaryTree b1=BinaryTree();
    b1.InsertNode(1);
    b1.InsertNode(2);
    b1.InsertNode(3);
    b1.DeleteNode(3);
    b1.InsertNode(4);
    b1.InsertNode(5);
    b1.UpdateNode(5,6);
    cout<<b1.preorderTraversal()<<endl;
    //cout<<b1.Contains(1);
    cout<<b1.postorderTraversal();
    system("pause");
    return 0;
}