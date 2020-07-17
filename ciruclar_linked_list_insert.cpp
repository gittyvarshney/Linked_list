#include<bits/stdc++.h>
using namespace std;

class ciruclar_list
{
public:
  int data;
  ciruclar_list* next;
};

void insert(ciruclar_list*& head,int n)
{
  ciruclar_list* ptr = new ciruclar_list();
  ptr->data = n;
  ptr->next = head;
  ciruclar_list* temp_ptr = head;
  if(head != NULL)
  {
    cout << "head is not null \n";
    while(temp_ptr->next != head)
    {
      cout << "while ";
      temp_ptr = temp_ptr->next;
    }
    cout << "\n";
    temp_ptr->next = ptr;
  }
  else
  {
    cout << "head is null \n";
    ptr->next = ptr;
    head = ptr;
  }
  //return head;
}

void print(ciruclar_list* head)
{
  ciruclar_list* temp = head;
  if(temp!= NULL)
  {
    cout << temp->data;
    while(temp->next != head)
    {
      temp = temp->next;
      cout << temp->data;
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
  ciruclar_list* head = NULL;
  insert(head,1);
  print(head);
  insert(head,2);
  print(head);
  insert(head,3);
  print(head);
  insert(head,4);
  print(head);
}
