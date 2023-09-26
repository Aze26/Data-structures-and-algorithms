#include<iostream>
#include"link_queue.h"
using std::cout;
using std::endl;
LinkQueue::LinkQueue()
{
    m_size=0;
    m_head=m_tail=nullptr;
}
LinkQueue::~LinkQueue()
{
    LinkNode *ptr=m_head;
    while (m_head!=nullptr)
    {
        m_head=m_head->next;
        delete ptr;
        ptr=m_head;
    }
    m_head=m_tail=nullptr;
}
void LinkQueue::LinkPush(int val)
{
    if (m_size==0)
    {
        m_head=m_tail=new LinkNode(val);
    }
    else
    {
        LinkNode *ptr=new LinkNode(val);
        ptr->next=m_head;
        m_head=ptr;
    }
    ++m_size;
}
void LinkQueue::LinkPop()
{
    if (m_size==0)
    {
        return;
    }
    else
    {
        LinkNode *ptr=m_head;
        m_head=m_head->next;
        delete ptr;
    }
    --m_size;
}
void LinkQueue::LinkInject(int val)
{
    if (m_size=0)
    {
        m_head=m_tail=new LinkNode(val);
    }
    else
    {
        LinkNode *ptr=new LinkNode(val);
        m_tail->next=ptr;
        m_tail=ptr;
    }
    ++m_size;
}
void LinkQueue::LinkEject()
{
    if (m_size==0)
    {
        return;
    }
    else
    {
        LinkNode *ptr=m_head;
        while (ptr->next!=m_tail)
        {
            ptr=ptr->next;
        }
        ptr->next=nullptr;
        delete m_tail;
        m_tail=ptr;
    }
    --m_size;
}
std::ostream & operator<<(std::ostream &os,LinkQueue &lq)
{
    LinkNode *ptr=lq.m_head;
    while (ptr!=nullptr)
    {
        os<<ptr->val<<endl;
        ptr=ptr->next;
    }
    return os;
}
int main()
{
    LinkQueue l1=LinkQueue();
    l1.LinkPush(3);
    l1.LinkPush(2);
    l1.LinkPush(1);
    cout<<l1;
    cout<<"-------------------\n";
    l1.LinkEject();
    cout<<l1;
    system("pause");
    return 0;
}