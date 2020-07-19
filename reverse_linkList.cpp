#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

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

void reverse_linkedList(linkedList*& head)
{
  linkedList* curr = head;
  linkedList* prev = NULL;
  linkedList* next = NULL;

  while(curr != NULL)
  {
    next = curr->next;
    curr->next = prev;

    prev = curr;
    curr = next;
  }
  head= prev;

}

void print_linkedList(linkedList*& head)
{
  linkedList* temp = head;
  while(temp!= NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
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
    linkedList* head = NULL;
    insert_node(head,3);
    insert_node(head,4);
    insert_node(head,5);
    insert_node(head,6);
    print_linkedList(head);
    reverse_linkedList(head);
    cout << "\n";
    print_linkedList(head);

}
