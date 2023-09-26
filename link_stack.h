#ifndef LINK_STACK_H_
#define LINK_STACK_H_
#include<iostream>
struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode(int _val):val(_val),next(nullptr){}
};
class LinkStack
{
private:
    int m_size;
    LinkNode *m_head;
    LinkNode *m_tail;
public:
    LinkStack();
    ~LinkStack();
    //bool isfull();
    bool isempty();
    void pop();
    void push(int val);
    int  top();
    int  size();
    friend std::ostream & operator<<(std::ostream &os,LinkStack &ls);
};
#endif