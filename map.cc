#include "map.h"
#include <cstring>

map::map(int capacity): size(0), capacity(capacity), modulus(capacity/10) {
  arr = new linkedList* [modulus];

  for (int i=0; i<modulus; i++) {
    arr[i] = 0;
  }

}

map::~map() {
  for (int i=0; i<modulus; i++) {
    linkedList* p = arr[i];
    linkedList* next_p;
    while (p) {
      next_p = p->next;
      delete p;
      p = next_p;
    }
  }
  delete[] arr;
}

long long djb2(const char* str) { /* http://www.cse.yorku.ca/~oz/hash.html */

  long long hash = 5381;
  int c;

  while (c = *str++) hash = ((hash << 5) + hash) + c;
  return hash;
}

bool map::set(const char* key, void* value) {
  long long hash = djb2(key);
  if (!arr[hash % modulus]) {
    arr[hash % modulus] = new linkedList(key, value);
  } else {
    if (arr[hash % modulus]->get(key)) {
      return arr[hash % modulus]->set(key, value);
    } else {
      if (size == capacity) return false;
      size++;
      arr[hash % modulus] = new linkedList(key, arr[hash % modulus]);
    }
  }
  return true;
}

void* map::get(const char * key) {
  long long hash = djb2(key);
  if (!arr[hash % modulus]) return 0;
  return arr[hash % modulus]->get(key);
}

void* map::delete_key(const char * key) {
  long long hash = djb2(key);
  if (!arr[hash % modulus]) return 0;
  void* target = arr[hash % modulus];
  if (!target) return 0;
  size--;
  if (strcmp(arr[hash % modulus]->key, key) == 0) {
    delete arr[hash % modulus];
    arr[hash % modulus] = 0;
  } else {
    arr[hash % modulus]->delete_key(key);
  }
  return target;
}

float map::load() {
  return size / capacity;
}