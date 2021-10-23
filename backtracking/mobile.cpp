#include <bits/stdc++.h>
using namespace std;

map<char, string> m = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

int ilove(int n){

        vector<int>ans;
        for(int i=0;i<n;i++){
        ans.push_back(i);
        }
        return ans[0];

}
vector<string> result;
void helper(string str, int i, string current){
    if(i==str.size()){
        result.push_back(current);
        return;
    }
    string letters = m[str[i]];
    for(int j=0; j<letters.size(); j++){
        helper(str, i+1, current+letters[i]);
    }
}
vector<strinletterCombinations(string digits) {
        if(digits.size() != 0){
            
        }
    }
// C++ Iterative program to add two linked lists
#include <bits/stdc++.h>
using namespace std;

// A linked List Node
class Node
{
	public:
	int data;
	Node* next;
};

// to push a new node to linked list
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node[(sizeof(Node))];

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

// to add two new numbers
Node* addTwoNumList(Node* l1, Node* l2) {
	stack<int> s1,s2;
	while(l1!=NULL){
		s1.push(l1->data);
		l1=l1->next;
	}
	while(l2!=NULL){
		s2.push(l2->data);
		l2=l2->next;
	}
	int carry=0;
	Node* result=NULL;
	while(s1.empty()==false || s2.empty()==false){
		int a=0,b=0;
		if(s1.empty()==false){
			a=s1.top();s1.pop();
		}
		if(s2.empty()==false){
			b=s2.top();s2.pop();
		}
		int total=a+b+carry;
		Node* temp=new Node();
		temp->data=total%10;
		carry=total/10;
		if(result==NULL){
			result=temp;
		}else{
			temp->next=result;
			result=temp;
		}
	}
	if(carry!=0){
		Node* temp=new Node();
		temp->data=carry;
		temp->next=result;
		result=temp;
	}
	return result;
}

// to print a linked list
void printList(Node *node)
{
	while (node != NULL)
	{
		cout<<node->data<<" ";
		node = node->next;
	}
	cout<<endl;
}

// Driver Code
int main()
{
	Node *head1 = NULL, *head2 = NULL;

	int arr1[] = {5, 6, 7};
	int arr2[] = {1, 8};

	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);

	// Create first list as 5->6->7
	int i;
	for (i = size1-1; i >= 0; --i)
		push(&head1, arr1[i]);

	// Create second list as 1->8
	for (i = size2-1; i >= 0; --i)
		push(&head2, arr2[i]);
	
	Node* result=addTwoNumList(head1, head2);
	printList(result);

	return 0;
}


int* getCharCountArray(char* str)
{
    int* count = (int*)calloc(sizeof(int), NO_OF_CHARS);
    int i;
    for (i = 0; *(str + i); i++)
        count[*(str + i)]++;
    return count;
}

