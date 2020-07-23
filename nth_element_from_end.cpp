#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
//nth element from last is designed by me to execute in one go
//not taking any responsibility if any error arises
//It is based on the concept of two pointers one increment once &
//Other incremented twice

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

void nth_from_end(linkedList*& head,int n)
{
  if(head == NULL)
  {
    return;
  }
  int index;
  linkedList* ptr =  head; //taking two pointers one increment by one
  linkedList* ptr_d = head;//another increment by double
  int k=1;
  while(ptr_d->next != NULL && ptr_d->next->next != NULL && k!=n)
  {
    ptr = ptr->next;
    ptr_d = ptr_d->next->next;
    k++;
    //if found k==n loops breaks and
  }
  index=k;
  while(ptr_d->next!= NULL)//let the ptr_d pointer reach the end by incrementing
  {//both pointers by one;
    index++;
    ptr = ptr->next;
    ptr_d = ptr_d->next;
  }
  if(k<n) //if n is still greater than k them we have to do some logic
  {//if 4th element from front is 3rd element from last what is 5th element from last then
    ptr = head;
    for(int i=1;i<index-(n-k);i++)
    {
      ptr = ptr->next;
    }
  }
  cout << n << "th from end is: " << ptr->data << "\n";
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
    print_linkedList(head);
    nth_from_end(head,5);
    print_linkedList(head);

}
