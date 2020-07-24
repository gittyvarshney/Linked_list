#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
//You have given a some limited memory capacity in which you have
//to store key, value pairs you have to insert data & delete them according
//to least recently used concept
//It is implemented using the list stl having pair<int,int> value
//and unordered_map having int as key and list iterator as value to store the
//pointers of the memory locations of the linkedList

class LRUCache
{
  list<pair<int,int>>link_list; //to store key and value
  unordered_map<int,list<pair<int,int>>::iterator> m; //key and value as iterator of link_list
  //done in order to store the memory locations of the pointer
  int max_cap;
  int curr_cap=0; //current capacity is 0 initially
public:

  LRUCache(int capacity)
  {
    max_cap = capacity; //max capacity is alloted by constructor
  }

  int get(int key)
  {
    if(m.find(key) == m.end())
    {
      return -1; //if map[key] pointer not found return -1
    }
    else
    {
      int value = m[key]->second; //value is second element of linkedlist pair
      link_list.erase(m[key]);//erase this m[key] pointer to push at front
      link_list.push_front(make_pair(key,value)); //make new same pointer
      m[key] = link_list.begin(); // and rechange the address
      return value;
    }
  }

  void put(int key, int value)
  {
    if(max_cap == curr_cap)//if reached maximum capacity
    {
      if(m.find(key) == m.end()) //if not found then discard least used
      {
        m.erase(link_list.back().first);
        link_list.pop_back();
      }
      else //if found simply move it to the front
      {
        link_list.erase(m[key]);
      }
      link_list.push_front(make_pair(key,value));
      m[key] = link_list.begin();
    }
    else //if not reached maximum capacity
    {
      if(m.find(key) == m.end())
      {
        curr_cap++;
      }
      else
      {
        link_list.erase(m[key]);
      }
      link_list.push_front(make_pair(key,value));
      m[key] = link_list.begin();
    }
  }
};

int main()
{
  LRUCache* obj = new LRUCache(1);
  obj->put(2,1);
  cout << obj->get(2) << "\n";
  obj->put(3,2);
  cout << obj->get(2) << "\n";
  cout << obj->get(3) << "\n";


}
