#include <iostream>
#include <limits.h>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode *insertionSortList(ListNode *head);

int main(){
	
	return 0;
}
ListNode *insertionSortList(ListNode *head) {
	ListNode *newhead=new ListNode(INT_MIN);
	if(!head)
		return NULL;
		
	ListNode *cur=newhead;
	for(ListNode *p=head->next,*prep=head;p!=NULL;prep=p,p=p->next)
	{
		for(cur=newhead;cur->next!=p;cur=cur->next)
		{
			if(cur->next->val>p->val)
			{
				prep->next=p->next;
				p->next=cur->next;
				cur->next=p;
				p=prep;
				break;
			}	
		}
	}
	ListNode res=newhead->next;
	delete newhead;  
	return res;
}
