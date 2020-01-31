#include <iostream>
using namespace std;
#include <stack>
#include <vector>
#include <fstream>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
istream& read_num(istream &in, vector<int>& num)
{//读取文件入一个vector
	if (in)
	{
		int x;
		while (in >> x) num.push_back(x);
	}
	return in;
}
bool insert(TreeNode* &tree,int x)//这个tree要传引用进去
{
	if (tree == NULL)
	{
		tree = new TreeNode(x);
		return true;

	}
	else
		if (x < tree->val)
		{
			insert(tree->left, x);
		}
		else if (x > tree->val)
		{
			insert(tree->right, x);
		}
		else return false;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() == 0 || inorder.size() == 0)
		return NULL;
	TreeNode* root = new TreeNode(preorder[0]);
	int pos = 0;
	while (inorder[pos] != preorder[0])
	{
		pos++;
	}
	vector<int> q;
	vector<int> p;
	int i = 0, j = 1;
	while (i<pos)
	{
		q.push_back(inorder[i]);
		i++;
	}
	while (j <= pos)
	{
		p.push_back(preorder[j]);
		j++;
	}
	root->left = buildTree(p, q);
	vector<int> p1;
	vector<int> p2;
	int m = pos + 1, n = pos + 1;
	while (m<preorder.size())
	{
		p1.push_back(preorder[m]);
		m++;
	}
	while (n<inorder.size())
	{
		p2.push_back(inorder[n]);
		n++;
	}
	root->right = buildTree(p1, p2);
	return root;
}
//算法
TreeNode* removex(TreeNode* t, int x)
{
	TreeNode *p = t;
	stack<TreeNode*> st;
	do {
		while (p)
		{
			st.push(p);
			p = p->left;
		}
		if (st.empty() == 0)
		{
			p = st.top();
			st.pop();
			if (p->right&&p->right->val >= x)
			{
				if (p != t)
				{
					TreeNode* temp = p->right;
					p->right = temp->left;
					delete temp;
				}
				else {
					t = p->left;
					return t;
				}

			}
			else if (!p->left&&!p->right&&p->val >= x)
			{
				t->right=NULL;
				return t;
			}
			else p = p->right;
		}
	} while (p || st.empty() == 0);
	return t;
 }

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> ans;
	if (root == NULL)
	{
		return ans;
	}
	if (root->left != NULL)
	{
		vector<int> temp1;
		temp1 = inorderTraversal(root->left);
		for (int i = 0; i<temp1.size(); i++)
		{
			ans.push_back(temp1[i]);
		}
	}
	ans.push_back(root->val);
	if (root->right != NULL)
	{
		vector<int> temp2;
		temp2 = inorderTraversal(root->right);
		for (int i = 0; i<temp2.size(); i++)
		{
			ans.push_back(temp2[i]);
		}

	}
	return ans;
}
int main()
{
	vector<int> pre, in, num;
	int x;
	//重定向
	ofstream log("C:\\Users\\zty\\Documents\\数据结构\\pra11-1\\output.txt");
	streambuf* oldbuf = cout.rdbuf(log.rdbuf());
	ifstream file;
	file.open("C:\\Users\\zty\\Documents\\数据结构\\pra11-1\\input.txt");
	if (!file.is_open())
	{
		cout << "error open";
		exit(1);
	}

	read_num(file, num);
	for (int i = 1; i <=num.size() / 2; i++)
	{
		pre.push_back(num[i]);
	}
	for (int i = num.size()/2+1; i < num.size(); i++)
	{
		in.push_back(num[i]);
	}
	x = num[0];
	TreeNode* t;
	t=buildTree(pre, in);
	TreeNode*p=removex(t,x);
	vector<int> ans = inorderTraversal(p);
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	system("pause");
	return 0;
}

/*#include <iostream>
#include <fstream>

using namespace std;

struct BinNode{
    int data;
    BinNode * lchild;
    BinNode * rchild;
};

void CreateTree(BinNode * &t, int sfron[], int smid[], int size){
    BinNode * p;
    p = new BinNode();
    p->data = sfron[0];
    p->lchild = NULL;
    p->rchild = NULL;
    t = p;
    int i = 0;
    while(smid[i] != t->data){
        i++;
    }
    if (size == 1){
        return;
    }
    if(i != 0)
        CreateTree(t->lchild, &sfron[1], &smid[0], i);

    if(i+1 < size)
        CreateTree(t->rchild, &sfron[i+1], &smid[i+1], size-1-i);
}

BinNode * DeleteTree(BinNode * t, int x){
    BinNode * r = t;
    while(r->data >= x){
        r = r->lchild;
    }
    while(t!=NULL){

        if(t->rchild->data >= x){
            t->rchild = NULL;
        }
        else{
            t = t->rchild;
        }
    }
}

void BehPrintTree(BinNode * t){
    if(t != NULL){
        BehPrintTree(t->lchild);
        BehPrintTree(t->rchild);
        cout << t->data << ' ';
        //OutPut << t->data << ' ';
    }
}

void MidPrintTree(BinNode * t){
    if(t != NULL){
        MidPrintTree(t->lchild);
        cout << t->data << ' ';
        //OutPut << t->data << ' ';
        MidPrintTree(t->rchild);
    }
}

int main()
{
    cout << "Please input the length and two string of numbers:" << endl;
    int k, size;
    cin >> k >> size;
    BinNode * root;
    int sfron[k], smid[k];
    for(int i = 0; i <size ;i ++){
        cin >> sfron[i];
    }
    for (int i = 0; i < size ;i ++){
        cin >> smid[i];
    }
    CreateTree(root, &sfron[0], &smid[0], size);
    DeleteTree(root, k);
    BehPrintTree(root);
    cout << ' ' << endl;
    MidPrintTree(root);
    cout << ' ' << endl;
    //ofstream OutPut("input.txt");

    //OutPut.close();
    return 0;
}
*/
/*
13 9
8 3 1 6 4 7 10 14 13
1 3 4 6 7 8 10 13 14
*/
