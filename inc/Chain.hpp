#pragma once
#include <iostream>
#include "Link.hpp"

using std::cout;
using std::endl;

template <typename T>
class Chain
{
public:
  Chain();
  ~Chain();

  T *GetNext();
  void Insert(T *data);
  void Insert(T *data, int order);
  void SetIterToHead();

private:
  Link<T> *head;
  Link<T> *iter;
  Link<T> *tail;
};

template <typename T>
Chain<T>::Chain()
    : head(nullptr),
      iter(nullptr),
      tail(nullptr)
{
}

template <typename T>
Chain<T>::~Chain()
{
  Link<T> *it = head;
  Link<T> *next;
  while (it)
  {
    next = it->next;
    delete it;
    it = next;
  }

  cout << "links destructed  = " << numLinksDestructed << endl;
}

template <typename T>
void Chain<T>::Insert(T *data)
{
  Insert(data, 0);
}

template <typename T>
T *Chain<T>::GetNext()
{
  if (iter)
  {
    Link<T> *link = iter;
    iter = iter->next;
    return link->data;
  }
  return nullptr;
}

template <typename T>
void Chain<T>::Insert(T *data, int order)
{
  if (!head)
  {
    head = tail = new Link<T>(data, nullptr, nullptr, order);
    cout << "links constructed = " << numLinksConstructed << endl;
    return;
  }
  Link<T> *it = head;
  do
  {
    if (it->order >= order)
    {
      Link<T> *link = new Link<T>(data, it->prior, it, order);
      if (it->prior)
      {
        it->prior->next = link;
      }
      else
      {
        head = link;
      }
      it->prior = link;
      cout << "links constructed = " << numLinksConstructed << endl;
      return;
    }
    it = it->next;
  } while (it);
  tail = tail->next = new Link<T>(data, tail, nullptr, order);
  cout << "links constructed = " << numLinksConstructed << endl;
}

template <typename T>
void Chain<T>::SetIterToHead()
{
  iter = head;
}
