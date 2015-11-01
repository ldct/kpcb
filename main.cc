#include "map.h"
#include <cstring>
#include <iostream>

using namespace std;

int main() {

  map m(100);

  char kirby_desc[1000];
  strcpy(kirby_desc, "pink and fluffy");
  m.set("kirby", kirby_desc);
  cout << string((char*) (m.get("kirby"))) << endl;

  char kirby_desc_2[1000];
  strcpy(kirby_desc_2, "pink and lethal");
  m.set("kirby", kirby_desc_2);

  cout << string((char*) (m.get("kirby"))) << endl;



}