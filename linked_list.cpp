#include<iostream>
#include"linked_list.h"
using namespace std;
DoublyLinkedList::DoublyLinkedList()
{
    m_size=0;
    m_head=nullptr;
    m_tail=nullptr;
}
DoublyLinkedList::~DoublyLinkedList()
{
    ListNode *ptr=m_head;
    while (m_head!=nullptr)
    {
        m_head=m_head->next;
        delete ptr;
        ptr=m_head;
    }
    m_head=m_tail=nullptr;
}
void DoublyLinkedList::insertFront(int val)
{
    if (m_size==0)
    {
        m_head=m_tail=new ListNode(val);
    }
    else
    {
        ListNode *ptr=new ListNode(val);
        ptr->next=m_head;
        m_head->prev=ptr;
        m_head=ptr;
    }
    ++m_size;
}
void DoublyLinkedList::insertBack(int val)
{
    if (m_size==0)
        m_head=m_tail=new ListNode(val);
    else
    {
        ListNode *ptr=new ListNode(val);
        m_tail->next=ptr;
        ptr->prev=m_tail;
        m_tail=ptr;
    }
    ++m_size;
}
void DoublyLinkedList::insertNode(int pos,int val)
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
        ListNode *ptr1,*ptr2;
        ptr1=m_head;
        for (int i = 0; i < pos-1; i++) 
        {
            ptr1=ptr1->next;
        }
        ptr2=new ListNode(val);
        ptr2->next=ptr1->next;
        ptr1->next->prev=ptr2;
        ptr1->next=ptr2;
        ptr2->prev=ptr1;
    }
}
void DoublyLinkedList::deleteNode(int pos)
{
    if (pos<0||pos>m_size-1)
        return;
    ListNode *ptr1,*ptr2;
    if (pos==0)         //删除链表的头节点
    {
        ptr1=m_head;
        if (m_size==1)
        {
            m_head=m_tail=nullptr;
        }
        else
        {
            m_head=m_head->next;
            m_head->prev=nullptr;
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
        else
        {
            ptr2->next->prev=ptr1;
        }
        delete ptr2;
    }
    --m_size;
}
void DoublyLinkedList::updateNode(int pos,int val)
{
    if (pos<0||pos>m_size-1)
        return;
    ListNode *ptr=m_head;
    for (int i = 0; i < pos-1; i++)
    {
        ptr=ptr->next;
    }
    ptr->val=val;
}
int main()
{

    system("pause");
}