#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
//same as reverse_linked list only extra is head->next = curr;

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

void k_reverse_linkedList(linkedList*& head,int k)
{
  linkedList* curr = head;
  linkedList* prev = NULL;
  linkedList* next = NULL;

  while(curr!= NULL && k--) //the only change is that we have extra and condition
  {//for k and..
    next = curr->next;
    curr->next = prev;

    prev = curr;
    curr = next;
  }
  head->next = curr; //head next should point to the curr left out
  head= prev; // new head becomes previous

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
    insert_node(head,3);
    insert_node(head,4);
    insert_node(head,5);
    insert_node(head,6);
    print_linkedList(head);
    k_reverse_linkedList(head,3);
    print_linkedList(head);

}
