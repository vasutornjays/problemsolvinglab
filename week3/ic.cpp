#include <iostream>
#include <string>

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
        void turnleft();
        void turnright();
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

void LinkedList::turnleft()
{
    if(header->next == tail)
    {
        return;
    }
    ListNode* tmp = header->next;
    tmp->next->prev = header;
    header->next = tmp->next;
    tail->prev->next = tmp;
    tmp->prev = tail->prev;
    tmp->next = tail;
    tail->prev = tmp;
}

void LinkedList::turnright()
{
    if(header->next == tail)
    {
        return;
    }
    ListNode* tmp = tail->prev;
    tmp->prev->next = tail;
    tail->prev = tmp->prev;
    tmp->next = header->next;
    header->next->prev = tmp;
    header->next = tmp;
    tmp->prev = header;
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
        string op;
        int val;
        cin >> op;
        if(op.compare("li") == 0)
        {
            cin  >> val;
            result.insert_front(val);
        }
        else if(op.compare("ri") == 0)
        {
            cin >> val;
            result.append(val);
        }
        else if(op.compare("lr") == 0)
        {
            result.turnleft();
        }
        else if(op.compare("rr") == 0)
        {
            result.turnright();
        }
    }
    result.print_list();
    return 0;
}