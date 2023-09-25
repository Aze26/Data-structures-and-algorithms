#include<iostream>
#include"linked.h"
using std::cout;
using std::endl;
DoublyLink::DoublyLink()
{
    m_size=0;
    m_head=m_tail=nullptr;
}
DoublyLink::~DoublyLink()
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
void DoublyLink::insertFront(int val)
{
    if (m_size==0)
    {
        m_head=m_tail=new LinkNode(val);
    }
    else
    {
        LinkNode *ptr=new LinkNode(val);
        ptr->next=m_head;
        m_head->prev=ptr;
        ptr->prev=nullptr;
        m_head=ptr;
    }
    ++m_size;
}
void DoublyLink::insertBack(int val)
{
    if (m_size==0)
    {
        m_head=m_tail=new LinkNode(val);
    }
    else
    {
        LinkNode *ptr=new LinkNode(val);
        m_tail->next=ptr;
        ptr->prev=m_tail;
        ptr->next=nullptr;
        m_tail=ptr;
    }
    ++m_size;
}
void DoublyLink::insertNode(int pos,int val)
{
    if (pos<=0)
    {
        insertFront(val);
    }
    else if (pos>=m_size)
    {
        insertBack(val);
    }
    else
    {
        LinkNode *ptr1=m_head;
        LinkNode *ptr2=new LinkNode(val);
        for (int i = 0; i < pos-1; i++)
        {
            ptr1=ptr1->next;
        }
        //ptr2->next=ptr1->next;
        ptr1->next->prev=ptr2;
        ptr2->next=ptr1->next;
        ptr2->prev=ptr1;
        ptr1->next=ptr2;
    }
    ++m_size;
}
void DoublyLink::deleteNode(int pos)
{
    if (pos<0||pos>m_size-1)
    {
        return;
    }
    else
    {
        if (pos==0)
        {
            if (m_size==1)
            {
                m_head=m_tail=nullptr;
            }
            else
            {
                LinkNode *ptr=m_head;
                m_head=m_head->next;
                delete ptr;
            }
        }
        else
        {
            LinkNode *ptr1=m_head;
            LinkNode *ptr2;
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
    }
    --m_size;
}
void DoublyLink::updateNode(int pos,int val)
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
std::ostream & operator<<(std::ostream &os,DoublyLink &dk)
{
    LinkNode *ptr=dk.m_head;
    while (ptr!=nullptr)
    {
        os<<ptr->val<<endl;
        ptr=ptr->next;
    }
    return os;
}
int main()
{
    DoublyLink d1=DoublyLink();
    d1.insertFront(1);
    d1.insertBack (3);
    cout<<d1<<endl;
    cout<<"\n--------------------\n";
    d1.insertNode(1,2);
    cout<<d1;
    d1.insertBack(5);
    cout<<"\n--------------------\n";
    cout<<d1;
    d1.updateNode(3,4);
    cout<<"\n--------------------\n";
    cout<<d1<<endl;
    d1.insertNode(4,5);
    cout<<d1<<endl;
    d1.deleteNode(4);
    cout<<d1;
    system("pause");
    return 0;
}