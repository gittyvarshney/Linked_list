#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
//Given a singly linked list and a number k, write a function to
//find the (n/k)-th element, where n is the number of elements in the list.
//We need to consider ceil value in case of decimals.
//The Implemenatation is very simple you know it.

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

void find_modular(linkedList*& head, int k)
{
  if(head == NULL && k <=0)
  {
    cout << "Null or k less than zero \n";
    return;
  }

  int i=1;
  linkedList* curr = head; //since by default 1st element comes as it says ceil
  for(linkedList* temp = head->next; temp!= NULL; temp=temp->next)
  {//Starts with the second node of list
    if(i%k == 0)
    {
      curr = curr->next;
    }
    i++;
  }
  cout << "The Node is: " << curr->data;

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
    //first linked list
    insert_node(head,1);
    insert_node(head,2);
    insert_node(head,3);
    insert_node(head,4);
    insert_node(head,5);
    insert_node(head,6);
    print_linkedList(head);
    find_modular(head,2);
}
