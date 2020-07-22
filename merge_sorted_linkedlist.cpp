#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
//the question is that we have given to sorted linked list and have to
//merge them so that new linked list is also sorted
//the concept is to take that list which has the least element
//and take to pointers one at first element and other at next element
//if the element of second list is in between these two elements insert it
//otherwise increment the first list

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

void sort_linkedList(linkedList*& head) //bublesort
{
  int temp;
  linkedList* ptr = NULL;
  bool is_swapped=true;
  if(head == NULL)
  {
    return;
  }
  while(is_swapped==true)
  {
    ptr = head;
    is_swapped=false; //when there is no swap means linked list is sorted
    while(ptr->next!= NULL)
    {
      if(ptr->data>ptr->next->data)
      {
        //swapping
        temp = ptr->data;
        ptr->data = ptr->next->data;
        ptr->next->data = temp;
        is_swapped = true;
      }
      ptr = ptr->next;
    }
  }
}

void merge_sorted_util(linkedList*& head1, linkedList*& head2)
{
  if(head1->next == NULL) //if only one element is there we cannot able to
  {//follow our in between algorithm so just make head of next entire second list
    head1->next = head2;
  }
  else
  {
    linkedList* curr1 = head1;
    linkedList* next1 = curr1->next;
    linkedList* curr2 = head2;
    linkedList* next2 = curr2->next;
    while(next1 != NULL && curr2!= NULL)
    {
      if(curr2->data >= curr1->data && curr2->data <= next1->data)
      {
        next2 = curr2->next; //incrementing the second list pointer to point next
        curr1->next = curr2; //inserting in between
        curr2->next = next1; //inserting in between
        curr1 = curr2; // simply incrementing the first list pointer
        curr2 = next2; // now curr2 becomes next2 incremented
      }
      else
      {
        curr1 = next1;
        next1 = next1->next;
      }
    }
    if(curr2!= NULL)
    {
      curr1->next = curr2;
    }
  }
}


linkedList* merge_sorted(linkedList*& head1, linkedList*& head2)
{
  if(head1 == NULL)
  {
    return head2;
  }
  if(head2 == NULL)
  {
    return head1;
  }

  if(head1->data < head2->data)
  {
    merge_sorted_util(head1,head2); //taking the least element out of two list
    return head1;//as head
  }
  else
  {
    merge_sorted_util(head2,head1);
    return head2;
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
    linkedList* head_1 = NULL;
    //first linked list
    insert_node(head_1,8);
    insert_node(head_1,4);
    insert_node(head_1,1);
    insert_node(head_1,6);
    sort_linkedList(head_1);
    print_linkedList(head_1);

    //second linked linkedList
    linkedList* head_2 = NULL;
    insert_node(head_2,7);
    insert_node(head_2,5);
    insert_node(head_2,3);
    insert_node(head_2,2);
    insert_node(head_2,13);
    insert_node(head_2,9);
    sort_linkedList(head_2);
    print_linkedList(head_2);
    //merge them in sorted order
    linkedList* new_head = merge_sorted(head_1,head_2);
    print_linkedList(new_head);
}
