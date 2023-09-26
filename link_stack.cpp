#include<iostream>
#include"link_stack.h"
using std::cout;
using std::endl;
LinkStack::LinkStack()
{
    m_size=0;
    m_head=m_tail=nullptr;
}
LinkStack::~LinkStack()
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
bool LinkStack::isempty()
{
    return m_size==0;
}
void LinkStack::push(int val)
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
    m_size++;
}
void LinkStack::pop()
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
int LinkStack::top()
{
    return m_head->val;
}
int LinkStack::size()
{
    return m_size;
}
std::ostream & operator<<(std::ostream &os,LinkStack &ls)
{
    LinkNode *ptr=ls.m_head;
    while (ptr!=nullptr)
    {
        os<<ptr->val<<endl;
        ptr=ptr->next;
    }
    return os;
}
int main()
{
    LinkStack l1=LinkStack();
    l1.push(1);
    l1.push(2);
    l1.push(3);
    cout<<l1<<endl;
    cout<<l1.size()<<endl;
    l1.pop ();
    cout<<"------------------\n";
    cout<<l1<<endl;
    cout<<l1.size();
    system("pause");
    return 0;
}