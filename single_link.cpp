#include<iostream>
#include"single_link.h"
using std::cout;
using std::endl;
SingleLink::SingleLink()
{
    m_size=0;
    m_head=m_tail=nullptr;
}
SingleLink::~SingleLink()
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
void SingleLink::insertFront(int val)
{
    if (m_size==0)
    {
        m_head=m_tail= new LinkNode(val);
    }
    else
    {
        LinkNode *ptr=new LinkNode(val);
        ptr->next=m_head;
        m_head=ptr;
    }
    ++m_size;
}
void SingleLink::insertBack(int val)
{
    if (m_size==0)
    {
        m_head=m_tail=new LinkNode(val);
    }
    else
    {
        LinkNode *ptr=new LinkNode(val);
        m_tail->next=ptr;
        ptr->next=nullptr;
        m_tail=ptr;
    }
    ++m_size;
}
void SingleLink::insertNode(int pos,int val)
{
    if (pos<=0)
    {
        insertFront(val);
    }
    else if (pos>=m_size-1)
    {
        insertBack(val);
    }
    else
    {
        LinkNode *ptr1,*ptr2;
        ptr1=m_head;
        for (int i = 0; i < pos-1; i++)
        {
            ptr1=ptr1->next;
        }
        ptr2= new LinkNode(val);
        ptr2->next=ptr1->next;
        ptr1->next=ptr2;
    }
    ++m_size;
}
void SingleLink::deleteNode(int pos)
{
    if (pos<0||pos>m_size-1)
    {
        return;
    }
    LinkNode *ptr1,*ptr2;
    if (pos==0)
    {
        ptr1=m_head;
        if (m_size==1)
        {
            m_head=m_tail=nullptr;
        }
        else
        {
            m_head=m_head->next;
        }
        delete ptr1;
    }
    else
    {
        ptr1=m_head;
        for (int i = 0; i < pos-1; i++)
        {
            ptr1=ptr1->next;
        }
        ptr2=ptr1->next;
        ptr1->next=ptr2->next;
        if (ptr2->next==nullptr)
        {
            m_tail=ptr1;
        }
        delete ptr2;
    }
    --m_size;
}
void SingleLink::updateNode(int pos,int val)
{
    if (pos<0||pos>m_size-1)
    {
        return;
    }
    LinkNode *ptr=m_head;
    for (int i = 0; i < pos; i++)
    {
        ptr=ptr->next;
    }
    ptr->val=val;
}
std::ostream & operator<<(std::ostream &os,SingleLink &sk)
{
    LinkNode *ptr=sk.m_head;
    while (ptr!=nullptr)
    {
        os<<ptr->val<<endl;
        ptr=ptr->next;
    }
    return os;
}
int main()
{
    SingleLink s1=SingleLink();
    cout<<s1;
    cout<<"\n---------------------\n";
    s1.insertFront(1);
    s1.insertNode(0,2);
    s1.insertNode(0,3);
    s1.updateNode(0,4);
    s1.deleteNode(0);
    cout<<s1;
    system("pause");
    return 0;
}