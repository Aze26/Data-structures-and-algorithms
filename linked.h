#ifndef LINKED_H_
#define LINKED_H_
#include<iostream>
struct LinkNode
{
    int val;
    LinkNode *prev;
    LinkNode *next;
    LinkNode(int _val):val(_val),prev(nullptr),next(nullptr){}
};
class DoublyLink
{
private:
    int m_size;
    LinkNode *m_head;
    LinkNode *m_tail;
public:
    DoublyLink();
    ~DoublyLink();
    void insertFront(int val);
    void insertBack(int val);
    void insertNode(int pos,int val);
    void deleteNode(int pos);
    void updateNode(int pos,int val);
    friend std::ostream & operator<<(std::ostream &os,DoublyLink &dk);
};
#endif