#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct linkedList {

  const char * key;
  linkedList* next;
  void* obj;

  linkedList(const char *, void*);

  void* get(const char *);
  bool set(const char *, void*);
  void delete_key(const char *);

};

#endif