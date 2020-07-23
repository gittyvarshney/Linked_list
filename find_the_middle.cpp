#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
//very simple implementation to find middle element in one go
//for even number the middle is the farthest

class linkedList
{
public:
  int data;
  linkedList* next;
};

void insert_node(linkedList*& head,int d)
{
  linkedList* temp = head;
  linkedList* ptr = new linkedList();
  ptr->data = d;
  ptr->next = NULL;
  if(temp != NULL)
  {
    while(temp->next !=NULL)
    {
      temp = temp->next;
    }
    temp->next = ptr;
  }
  else
  {
    head = ptr;
  }
}

void print_linkedList(linkedList*& head)
{
  linkedList* temp = head;
  while(temp!= NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << "\n";
}

void find_middle(linkedList*& head)
{
  if(head == NULL)
  {
    cout << "nothing to remove \n";
    return;
  }

  linkedList* slow = head;
  linkedList* fast = head;
  while(fast != NULL && fast->next!= NULL) //for shortest middle in case of
  {//even numbers add another terminator fast->next->next != NULL
    slow = slow->next;
    fast = fast->next->next;
  }
  cout << "middle element is: " << slow->data;
}

int main()
{
	 /*
    #ifndef ONLINE_JUDGE
      freopen("D:\\Project Sunrise\\input.txt", "r", stdin);
      freopen("D:\\Project Sunrise\\output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    */
    //implementation of undirected graph
    linkedList* head = NULL;
    insert_node(head,1);
    insert_node(head,2);
    insert_node(head,3);
    insert_node(head,4);
    insert_node(head,5);
    insert_node(head,6);
    print_linkedList(head);
    find_middle(head);

}
