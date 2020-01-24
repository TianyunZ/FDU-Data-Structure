#include <iostream>

using namespace std;

template <class type> class stack{
public:
    type * stk;
    int top = -1;
    int MAXN = 64;
    char name;
    stack(){
        stk = new type[MAXN];
    }
    ~stack(){delete []stk;}
    int push(type x){
        if (top >= MAXN -1)
            return 1;
        stk[++top] = x;
        return 0;
    }
    int pop(){
        if (top == -1)
            return 1;
        top--;
        return 0;
    }
    type getTop(){
        if (top == -1)
            return NULL;
        return stk[top];
    }
    int isEmpty() const{
        return top == -1;
    }
    int isFull() const{
        return top == MAXN -1;
    }
};

void creat(stack<int> s[], int n){
    s[0].name = 'A';
    s[0].MAXN = s[1].MAXN = s[2].MAXN = n;
    for (int i = 0; i < n; i ++){
        s[0].push(n - i);
    }
    if (n % 2 == 0){
        s[1].name = 'B';
        s[2].name = 'C';
    }
    else{
        s[1].name = 'C';
        s[2].name = 'B';
    }
}

long pow(int x, int y){
    long s = x;
    for (; y > 1; y --){
        s = s*x;
    }
    return s;
}

int hanoi(stack<int> s[], long max){
    int i = 0;
    int k = 0;
    while (k < max){
        s[(i+1)%3].push(s[i%3].getTop());
        cout << "move disk " << s[i%3].getTop() << " from " << s[i%3].name << " to " << s[(i+1)%3].name << endl;
        s[i%3].pop();
        k ++;
        if (k == max){
            break;
        }
        if (s[(i+2)%3].isEmpty() || !s[i%3].isEmpty() &&s [i%3].getTop() < s[(i+2)%3].getTop()){
            s[(i+2)%3].push(s[i%3].getTop());
            k ++;
            cout << "move disk " << s[i%3].getTop() << " from " << s[i%3].name << " to " << s[(i+2)%3].name << endl;
            s[i%3].pop();

        }
        else{
            s[(i)%3].push(s[(i+2)%3].getTop());
            k ++;
            cout << "move disk " << s[(i+2)%3].getTop() << " from " << s[(i+2)%3].name << " to " << s[(i)%3].name << endl;
            s[(i+2)%3].pop();
        }
        i ++;
    }
    return 0;
}

int main()
{
    cout << "please input the size of hanoi:" << endl;
    int n;
    cin >> n;
    stack<int> s[3];
    long max = pow(2, n) - 1;
    creat(s, n);
    hanoi(s, max);
    return 0;
}
