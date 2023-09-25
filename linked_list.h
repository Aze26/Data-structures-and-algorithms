#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
struct ListNode
{
    int val;
    ListNode *prev;
    ListNode *next;
    ListNode(int _val=0):val(_val),next(nullptr),prev(nullptr){};
};
class DoublyLinkedList
{
private:
    int m_size;
    ListNode *m_head;
    ListNode *m_tail;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertFront(int val);
    void insertBack (int val);
    void insertNode (int pos,int val);
    void deleteNode (int pos);
    void updateNode (int pos,int val);
    ListNode *findNode(int val)
    {
        ListNode *ptr=m_head;
        while (ptr!=nullptr)
        {
            if (ptr->val==val)
            {
                return ptr;
            }
            ptr=ptr->next;
        }
        return nullptr;
    }
};
#endif