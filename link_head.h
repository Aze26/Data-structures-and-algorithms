#ifndef LINK_HEAD_H_
#define LINK_HEAD_H_
#include<iostream>
struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode(int _val):val(_val),next(nullptr){}
};
class HeadLink
{
private:
    int m_size;
    LinkNode *m_head;
public:
    HeadLink();
    ~HeadLink();
    int LinkSize();
    int FrontVal();
    bool ExitNode(int val);
    void InsertNode(int val);
    void DeleteNode(int val);
    friend std::ostream &operator<<(std::ostream &os,HeadLink &hl);
};
#endif