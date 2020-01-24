#include <iostream>

typedef int T;
using namespace std;

template <class type> struct List;
template <class type> struct Listnode{
    friend struct List<type>;
    Listnode<type> * next;
    type value;
};

template <class type> struct List{
    List(){tail = head = new Listnode<type>();}
    bool add(type x);
    bool remove(type x);
    bool find(type x);
    void PrintList();
    Listnode<type> * head;
    Listnode<type> * tail;
};

template <class type> bool List<type>::add(type x){
    Listnode<type> * t;
    t = new Listnode<type>();
    tail->next = t;
    tail = t;
    t->next = NULL;
    t->value = x;
    return 1;
}

template <class type> bool List<type>::remove(type x){
    Listnode<type> * t, * p;
    t = head;
    if (t->value == x){
        p = t;
        head = t->next;
        delete p;
        return 1;
    }
    while(t->next->next != NULL){
        if (t->next->value == x){
            p = t->next;
            t->next = t->next->next;
            delete p;
            return 1;
        }
        else{
            t = t->next;
        }
    }
    if (t->next == tail && t->next->value == x){
        p = tail;
        tail = t;
        tail->next = NULL;
        delete p;
        return 1;
    }
    return 0;
}

template <class type> bool List<type>::find(type x){
    Listnode<type> * t;
    t = head;
    while(t->next->next != NULL){
        if (t->next->value == x){
            return 1;
        }
        else{
            t = t->next;
        }
    }
    if (t->next == tail && t->next->value == x){
        return 1;
    }
    return 0;
}

template <class type> void List<type>::PrintList(){
    Listnode<type> * temp;
    temp = head->next;
    while(temp != NULL){
        cout << temp->value << ' ';
        temp = temp->next;
    }
}

int main()
{
    cout << "please input:" << endl;
    List<T> temp;
    string s;
    int x;
    while (cin >> s){
        if (s == "add"){
            cin >> x;
            if (temp.add(x) == 1)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        if (s == "remove"){
            cin >> x;
            if (temp.remove(x) == 1)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        if (s == "find"){
            cin >> x;
            if (temp.find(x) == 1)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        if (s == "printList"){
            temp.PrintList();
            cout << ' ' << endl;
        }
    }
    return 0;
}
