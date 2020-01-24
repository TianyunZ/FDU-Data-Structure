//递归
#include <iostream>

using namespace std;

void GenPairCore(char* brackets, int bracketCount, int leftBrackets, int rightBrackets){
    //没有剩余的括号，此时输出一个组合
	if(leftBrackets==0 && rightBrackets==0){
		cout << brackets << ',' ;
	}
	else {
		//有剩余的左括号
		if (leftBrackets>0){
			brackets[bracketCount] = '(';
			GenPairCore(brackets, bracketCount+1, leftBrackets-1, rightBrackets);
		}
		//剩余的右括号数大于左括号数，说明栈中有未匹配的左括号，此时右括号可进栈
		if (rightBrackets>leftBrackets){
			brackets[bracketCount] = ')';
			GenPairCore(brackets, bracketCount+1, leftBrackets, rightBrackets-1);
		}
	}
}
//输出n对括号的所有正确组合
void GenPair(int n){
	pairCount = 0;
	char* brackets = new char[n*2+1];
	brackets[n*2] = '\0';
	GenPairCore(brackets, 0, n, n);
	delete[] brackets;
}

int main(){
    int n;
    cout << "please input n:" << endl;
    cin >> n;
    cout << '[';
    GenPair(n);
    cout << ']';
    return 0;
}
