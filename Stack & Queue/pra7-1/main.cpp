#include <iostream>
#define N 20
using namespace std;

template<class type> struct stack{
private:
    type * stk;
    int max;
    int top = -1;
public:
    stack(){
        max = N;
        stk = new type[max];
    }
    ~stack(){delete []stk;}
    int push(type x){
        if (top >= N-1)
            return 1;
        top ++;
        stk[top] = x;
        return 0;
    }
    int pop(){
        top --;
        return 0;
    }
    type getTop(){
        return stk[top];
    }
    int isEmpty(){
        if(top == -1)
            return 1;
        return 0;
    }
};

template<class type> struct queue{
private:
    stack<type> s1, s2;
public:
    queue(){
        stack<type> s1;
        stack<type> s2;
    }
    int add(type x){
        s1.push(x);
        return 1;
    }
    int poll(){
        int k;
        if(s1.isEmpty())
            return 0;
        while(!s1.isEmpty()){
            s2.push(s1.getTop());
            s1.pop();
        }
        k = s2.getTop();
        s2.pop();
        while(!s2.isEmpty()){
            s1.push(s2.getTop());
            s2.pop();
        }
        return k;
    }
    int peek(){
        if (s1.isEmpty())
            return 1;
        return 0;
    }
    void printQueue(){
        while(!s1.isEmpty()){
            s2.push(s1.getTop());
            s1.pop();
        }
        while(!s2.isEmpty()){
            cout << s2.getTop() << ' ';
            s1.push(s2.getTop());
            s2.pop();
        }
    }
};

int main()
{
    cout << "please input:" << endl;
    string s;
    int x;
    queue<int> q;
    while(cin >> s){
        if(s == "add"){
            cin >> x;
            if(q.add(x))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        if(s == "poll"){
            if(q.poll())
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        if(s == "peek"){
            if(q.peek())
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        if(s == "printQueue"){
            q.printQueue();
        }
    }
    return 0;
}
