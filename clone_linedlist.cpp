#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
//this algorithm is used to make a copy of a linked list which has
//another pointer pointer beside next which points to some random nodes;

class linkedList
{
public:
  int data;
  linkedList* random;
  linkedList* next;
};

void insert_node(linkedList*& head,int d)
{
  linkedList* temp = head;
  linkedList* ptr = new linkedList();
  ptr->random = NULL;
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
    cout << temp->data << "->";
    cout << temp->random->data << " ";
    temp = temp->next;
  }
  cout << "\n";
}

linkedList* copy_linkedList(linkedList*&head)
{
  linkedList*temp = head;
  linkedList* head_cpy= NULL;
  linkedList* temp_cpy = NULL;

  //fist making a simple copy of original linked list
  //with random pointers pointing to the corresponding original liked list
  while(temp!= NULL)
  {
    if(head_cpy == NULL)
    {
      head_cpy = new linkedList();
      head_cpy->random = temp;
      head_cpy->data = temp->data;
      head_cpy->next = NULL;
      temp_cpy = head_cpy;
      temp= temp->next;
    }
    else
    {
      temp_cpy->next = new linkedList();
      temp_cpy->next->random = temp;
      temp_cpy->next->data = temp->data;
      temp_cpy->next->next = NULL;
      temp_cpy = temp_cpy->next;
      temp = temp->next;
    }
  }
  //End

  //Making Orignal linked list next pointer points to corresponding cloned
  //linked list
  linkedList* prev = head;
  linkedList* curr = head->next;
  temp_cpy = head_cpy;
  vector<linkedList*>v; //to store the address of original next pointers
  while(curr!= NULL)
  {
    v.emplace_back(curr);
    prev->next = temp_cpy;
    prev = curr;
    curr = curr->next;
    temp_cpy = temp_cpy->next;
  }
  prev->next = temp_cpy; //remaining last should also pointers
  //End

  //Main Concept
  temp_cpy = head_cpy;//restarting the cloned linked list pointer
  while(temp_cpy!= NULL)
  {
    temp_cpy->random = temp_cpy->random->random->next;
    temp_cpy = temp_cpy->next;
  }
  //End

  //restoring original array next pointers
  int l = v.size();
  temp = head;
  for(int i=0;i<l;i++)
  {
    temp->next = v[i];
    temp = temp->next;
  }
    temp->next = NULL;
  //End

  return head_cpy;
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
    insert_node(head,8);
    insert_node(head,4);
    insert_node(head,1);
    insert_node(head,6);
    //randomizing the random pointer
    head->random = head->next->next; // 8->1
    head->next->random = head->random->next; // 4->6
    head->random->random = head; // 1->8
    head->random->next->random = head->next; // 6->4
    print_linkedList(head);
    linkedList* head_cpy = copy_linkedList(head);
    print_linkedList(head_cpy);
}
