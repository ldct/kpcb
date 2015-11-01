#include "linkedlist.h"
#include <cstring>

linkedList::linkedList(const char * key, void* obj) :
  key(key),
  next(0),
  obj(obj) { }

void* linkedList::get(const char * target_key) {
  if (strcmp(key, target_key) == 0) return obj;
  if (!next) return 0;
  return next->get(target_key);
}

bool linkedList::set(const char * target_key, void* target_value) {
  if (strcmp(key, target_key) == 0) {
    obj = target_value;
    return true;
  }
  if (!next) return false;
  return next->set(target_key, target_value);
}

void linkedList::delete_key(const char * key) {
  if (!next) return;
  if (strcmp(next->key, key) == 0) {
    linkedList* to_delete = next;
    next = next->next;
    delete to_delete;
    return;
  }
  next->delete_key(key);
}