#ifndef HASH_H
#define HASH_H

#include "linkedlist.h"

struct map {

  const int modulus;
  const int capacity;
  int size;

  linkedList** arr;

  map(int);
  ~map();

  bool set(const char *, void*);
  void* get(const char *);
  void* delete_key(const char *); /* cannot name this delete */
  float load();
};

#endif
