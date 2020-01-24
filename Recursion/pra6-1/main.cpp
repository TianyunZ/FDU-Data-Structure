//�ݹ�
#include <iostream>

using namespace std;

void GenPairCore(char* brackets, int bracketCount, int leftBrackets, int rightBrackets){
    //û��ʣ������ţ���ʱ���һ�����
	if(leftBrackets==0 && rightBrackets==0){
		cout << brackets << ',' ;
	}
	else {
		//��ʣ���������
		if (leftBrackets>0){
			brackets[bracketCount] = '(';
			GenPairCore(brackets, bracketCount+1, leftBrackets-1, rightBrackets);
		}
		//ʣ�������������������������˵��ջ����δƥ��������ţ���ʱ�����ſɽ�ջ
		if (rightBrackets>leftBrackets){
			brackets[bracketCount] = ')';
			GenPairCore(brackets, bracketCount+1, leftBrackets, rightBrackets-1);
		}
	}
}
//���n�����ŵ�������ȷ���
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
