#include <iostream>

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
        void insert_front(valueType x);
        void append(valueType x);
        void delete_node(int k);
};

LinkedList::LinkedList()
{
    header = new ListNode(0);
    tail = new ListNode(0);
    header->next = tail;
    tail->prev = header;
}

void LinkedList::insert_front(valueType x)
{
    ListNode* n = new ListNode(x,header,header->next);
    header->next->prev = n;
    header->next = n;
}

void LinkedList::append(valueType x)
{
    ListNode* n = new ListNode(x,tail->prev,tail);
    tail->prev->next = n;
    tail->prev = n;
}

void LinkedList::delete_node(int x)
{
    ListNode* del = header;
    for(int i = 0;i <= x; i++)
    {
        if(del->next == 0)
        {
            return;
        }
        del = del->next;
    }
    del = del->prev;
    del->prev->next = del->next;
    del->next->prev = del->prev;
    delete del;
}

void LinkedList::print_list()
{
    ListNode* print = header->next;
    while(print != tail)
    {
        cout << print->val << endl;
        print = print->next;
    }
}

int main()
{
    int n;
    cin >> n;
    LinkedList result;
    for(int i = 0;i < n;i++)
    {
        char op;
        int val;
        cin >> op >> val;
        if(op == 'I')
        {
            result.insert_front(val);
        }
        else if(op == 'D')
        {
            result.delete_node(val);
        }
        else if(op == 'A')
        {
            result.append(val);
        }
    }
    result.print_list();
    return 0;
}