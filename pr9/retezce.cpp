#include "retezce.h"
#include <cstring>
#include <iostream>

using namespace std;

void prnt(char *s) {
  while (*s != '\0') {
    cout << *s++;
  }
  cout << endl;
}

void strdel(char *s, int pozice, int pocet) {
  int i;
  for (i = pozice + pocet;; i++) {
    s[i - pocet] = s[i];
    if (s[i] == 0)
      break;
  }
  return;
}

void strinsII(char *s1, char *s2, int pozice) {
  int i = 0, len2 = strlen(s2);
  for (i = strlen(s1); i >= pozice; i--) {
    s1[i + len2] = s1[i];
  }
  for (i = 0; i < len2; i++) {
    s1[pozice + i] = s2[i];
  }
}

void strins(char *s1, char *s2, int pozice) {
  char s[strlen(s1)];
  int i;
  for (i = 0; i < pozice; i++) {
    s[i] = s1[i];
  }
  for (i = 0; i <= strlen(s2); i++) {
    s[i + pozice] = s2[i];
  }
  for (i = pozice; i <= strlen(s1) + 1; i++) {
    s[i + strlen(s2)] = s1[i];
  }
  i = 0;
  do {
    s1[i] = s[i];
    i++;
  } while (s[i] != '\0');
  // s1 = s;
  return;
}
