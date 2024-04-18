#include "retezce.h"
#include <iostream>

using namespace std;

int main() {
  char s[10] = "Ahoj!";
  char s2[10] = "ho";
  // s="Ahoj"; ###NELZE!###
  // strcpy(s, "Ahoj!"); ###NEJLIP, #include <cstring>###
  prnt(s);
  strdel(s, 1, 2);
  prnt(s);
  strins(s, s2, 1);
  prnt(s);
  strdel(s, 1, 2);
  prnt(s);
  strinsII(s, s2, 1);
  prnt(s);
}
