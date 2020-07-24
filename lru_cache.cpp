#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

class LRUCache
{
  list<int>dll;
  unordered_map<int,int> m;
  int max_cap;
  int curr_cap=0;
public:

  LRUCache(int capacity)
  {
    max_cap = capacity;
  }

  int get(int key)
  {
    if(m.find(key) == m.end())
    {
      return -1;
    }
    else
    {
      dll.erase(key);
      dll.push_front(key);
      return m[key];
    }
  }

  void put(int key, int value)
  {
    if(max_cap == curr_cap)
    {
      if(m.find(key) == m.end())
      {
        m.erase(dll.back());
        dll.pop_back();
      }
      else
      {
        dll.erase(key);
      }
      dll.push_front(key);
      m[key] = value;
    }
    else
    {
      if(m.find(key) == m.end())
      {
        cur_cap++;
      }
      else
      {
        dll.erase(key);
      }
      dll.push_front(key);
      m[key] = value;
    }
  }
};
