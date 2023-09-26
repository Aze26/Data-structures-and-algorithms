#ifndef LINK_QUEUE_H_
#define LINK_QUEUE_H_
#include<iostream>
struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode(int _val):val(_val),next(nullptr){}
};
class LinkQueue
{
private:
    int m_size;
    LinkNode *m_head;
    LinkNode *m_tail;    
public:
    LinkQueue();
    ~LinkQueue();
    void LinkPush(int val);     //val插入前端
    void LinkPop ();            //删除前端
    void LinkInject(int val);   //val插入尾端
    void LinkEject();           //删除尾端
    friend std::ostream & operator<<(std::ostream &os,LinkQueue &lq);
};
#endif