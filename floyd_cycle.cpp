#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
//Detect cycle through floyd algorithm which is no coincidence
//two pointer p and q increment p ones and increment q twice
//to find starting of loop increment the meet node and head node

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


void create_cycle(linkedList*& head,int at)
{
  linkedList* temp = head;
  linkedList* prev = NULL;
  linkedList* loop_at = NULL;
  while(temp!= NULL)
  {
    if(temp->data == at) //creates loop at 3rd node
    {
      loop_at = temp;
    }
    prev = temp;
    temp = temp->next;
  }
    prev->next = loop_at;
}

void floyd_find_start_node(linkedList* head,linkedList* p)
{ //finds the starting node of loop when cycle is founded
  //though floyd algorithm (no coincidence)
  while(head!= p)
  {
    head = head->next;
    p = p->next;
  }
  cout << "Starting node of loop is: " << head->data << "\n";
}

void detect_cycle(linkedList*& head)
{// increment p once
 // increment q twice it is quaranteed is cycle is there it
 // is busted
  linkedList* p = head;
  linkedList* q = head;

  while(p!= NULL && q!= NULL && q->next != NULL)
  {
    p = p->next;
    q = q->next->next;
    if(p == q)
    {
      cout << "cycle detected \n";
      floyd_find_start_node(head,p);
      return;
    }
  }
  cout << "There is no Cycle \n";
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
    insert_node(head,7);
    print_linkedList(head);
    create_cycle(head,4);
    detect_cycle(head);

}
