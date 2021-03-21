#pragma once

static int numLinksConstructed = 0;
static int numLinksDestructed = 0;

template <typename T>
class Chain;

template <typename T>
class Link
{
private:
  friend class Chain<T>;

  Link(T *data, Link<T> *prior, Link<T> *next, int order = 0);
  ~Link();

  T *data;
  Link<T> *prior;
  Link<T> *next;
  int order;
};

template <typename T>
Link<T>::Link(T *data, Link<T> *prior, Link<T> *next, int order)
    : data(data),
      prior(prior),
      next(next),
      order(order)
{
  ++numLinksConstructed;
}

template <typename T>
Link<T>::~Link()
{
  ++numLinksDestructed;
  if (prior)
  {
    prior->next = this->next;
  }
  if (next)
  {
    next->prior = this->prior;
  }
  delete data;
  data = nullptr;
}
