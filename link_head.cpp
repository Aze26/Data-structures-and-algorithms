#include<iostream>
#include"link_head.h"
using std::cout;
using std::endl;
HeadLink::HeadLink()
{
    m_size=0;
    m_head=nullptr;
}
HeadLink::~HeadLink()
{
    LinkNode *ptr=m_head;
    while (m_head!=nullptr)
    {
        m_head=m_head->next;
        delete ptr;
        ptr=m_head;
    }
    m_head=nullptr;
}
int HeadLink::LinkSize()
{
    return m_size;
}
int HeadLink::FrontVal()
{
    return m_head->val;
}
bool HeadLink::ExitNode(int val)
{
    LinkNode *ptr=m_head;
    while (ptr!=nullptr)
    {
        if (ptr->val==val)
        {
            return true;
        }
        else
        {
            ptr=ptr->next;
        }
    }
    return false;
}
void HeadLink::InsertNode(int val)
{
    if (!ExitNode(val))
    {
        if (m_size==0)
        {
            m_head=new LinkNode(val);
            m_head->next=nullptr;
        }
        else
        {
            LinkNode *ptr=m_head;
            while (ptr->next!=nullptr)
            {
                ptr=ptr->next;
            }
            ptr->next=new LinkNode(val);
        }
        m_size++;
    }
}
void HeadLink::DeleteNode(int val)
{
    if (ExitNode(val))
    {
        if (m_head->val == val)
        {
            LinkNode *temp = m_head;
            m_head = m_head->next;
            delete temp;
        }
        else
        {
            LinkNode *prev = m_head;
            LinkNode *curr = m_head->next;
            while (curr != nullptr)
            {
                if (curr->val == val)
                {
                    prev->next = curr->next;
                    delete curr;
                    break;
                }
                else
                {
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
        m_size--;
    }
}
std::ostream & operator<<(std::ostream &os,HeadLink &hl)
{
    LinkNode *ptr=hl.m_head;
    while (ptr!=nullptr)
    {
        os<<ptr->val<<endl;
        ptr=ptr->next;
    }
    return os;
}
int main()
{
    HeadLink h1=HeadLink();
    h1.InsertNode(4);
    h1.InsertNode(3);
    h1.InsertNode(2);
    h1.InsertNode(1);
    h1.DeleteNode(4);
    cout<<h1.FrontVal()<<endl;
    cout<<h1.ExitNode(1);
    system("pause");
    return 0;
}