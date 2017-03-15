#include <iostream>
#include <stdio.h>

using namespace std;

typedef int valueType;

struct ListNode {
    valueType val;
    ListNode* prev;
    ListNode* next;

    ListNode(valueType val,ListNode* prev = 0,ListNode* next = 0)
        : val(val), prev(prev),next(next) {}
};

class LinkedList
{
    private:
        ListNode* header;
        ListNode* tail;
    public:
        LinkedList();
        void print_list();
        void move(LinkedList x);
        void append(valueType x);
};

LinkedList::LinkedList()
{
    header = new ListNode(0);
    tail = new ListNode(0);
    header->next = tail;
    tail->prev = header;
}

void LinkedList::append(valueType x)
{
    ListNode* n = new ListNode(x,tail->prev,tail);
    tail->prev->next = n;
    tail->prev = n;
}

void LinkedList::print_list()
{
    ListNode* print = header->next;
    while(print != tail)
    {
        printf("%d\n",print->val);
        print = print->next;
    }
}

void LinkedList::move(LinkedList t)
{
    if(header->next == tail)
    {
        return;
    }
    header->next->prev = t.tail->prev;
    t.tail->prev->next = header->next;
    t.tail->prev = tail->prev;
    tail->prev->next = t.tail;
    header->next = tail;
    tail->prev = header;
}

int main()
{
    int n;
    LinkedList lot[100001];
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        char op;
        int val1,val2;
        cin >> op >> val1 >> val2;
        if(op == 'N')
        {
            lot[val2].append(val1);
        }
        else if(op == 'M')
        {
            lot[val1].move(lot[val2]);
        }
    }
    for(int i = 1;i <= n;i++)
    {
        lot[i].print_list();
    }
    return 0;
}