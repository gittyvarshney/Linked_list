#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
//very simple implementation to remove the between remove_duplicates
//from sorted list only think to note there is to free(unused_node)

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

void remove_duplicates(linkedList*& head)
{
  if(head == NULL)
  {
    cout << "nothing to remove \n";
    return;
  }

  linkedList* next_store = NULL;
  linkedList* curr = head;
  while(curr->next != NULL)
  {
    if(curr->data == curr->next->data)
    {
      next_store = curr->next;
      curr->next = curr->next->next;
      free(next_store);
    }
    else
    {
      curr = curr->next;
    }
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
    //implementation of undirected graph
    linkedList* head = NULL;
    insert_node(head,11);
    insert_node(head,11);
    insert_node(head,11);
    insert_node(head,13);
    insert_node(head,20);
    print_linkedList(head);
    remove_duplicates(head);
    print_linkedList(head);

}
