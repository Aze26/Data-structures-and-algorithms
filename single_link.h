#ifndef SINGLE_LINK_H_
#define SINGLE_LINK_H_
#include<iostream>
struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode(int _val):val(_val),next(nullptr){}
};
class SingleLink
{
private:
    int m_size;
    LinkNode *m_head;
    LinkNode *m_tail;
public:
    SingleLink();
    ~SingleLink();
    void insertNode(int pos,int val);
    void insertFront(int val);
    void insertBack(int val);
    void deleteNode(int pos);
    void updateNode(int pos,int val);
    //LinkNode *findNode(int val)
    friend std::ostream & operator<<(std::ostream &os,SingleLink &sk);
};
#endif