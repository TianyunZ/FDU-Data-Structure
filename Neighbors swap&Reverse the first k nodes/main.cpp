#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
		int n;
		ListNode* next;
};
ListNode* reverse1(ListNode* first, ListNode* last)
{
	ListNode* head = last;
	while (first != last)
	{
		ListNode* tmp = first->next;
		first->next = head;
		head = first;
		first = tmp;
	}
	return head;
}
int size(ListNode *head)
{
	ListNode *p = head;
	int count = 0;
	while (p)
	{
		p = p->next;
		count++;
	}
	return count;
}
ListNode* reverse(ListNode* head, int k) {
	ListNode* head_out = NULL;
	ListNode *p_flag = NULL;
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;
	int count = size(head);
	if (k>count)
	{
		return head;
	}
	int m = (count) / k;
	int i = 1;
	ListNode *pre = head;
	ListNode*p1;
	ListNode*q;
	while (i <= m)
	{
		q = head;
		int flag = 1;
		while (flag <= k)
		{
			head = head->next;
			flag++;
		}
		p1 = head;
		if (i == 1)
		{
			head_out = reverse1(q, head);
			p_flag = head_out;
		}
		else
		{
			int flag2 = 1;
			while (flag2<k)
			{
				p_flag = p_flag->next;
				flag2++;
			}
			p_flag->next = reverse1(q, head);
			p_flag = p_flag->next;
		}//帮助p遍历到下一次的头，保存当前的位置
		head = p1;
		i++;
	}
	return head_out;

}
int main()
{
	int k;
	cout << "请输入K" << endl;
	cin >> k;
	ListNode *head, *p;
	cout << "输入数据" << endl;
	head = new ListNode();
	cin >> head->n;
	head->next = NULL;
	p = head;
	while (cin)
	{
		p->next = new ListNode();
		cin >> p->next->n;
		p->next->next = NULL;
		p = p->next;
	}
	ListNode *p_output = reverse(head, k);
 	while (p_output->next!=NULL)
	{
		cout << p_output->n<<" ";
		p_output = p_output->next;
	}
//	system("pause");
	return 0;
}
