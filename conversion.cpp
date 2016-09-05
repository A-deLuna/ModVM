#include "conversion.h"
#include <cstdlib>
int chartoint (char* c) {
  int x = 0;
  for(int i = 0; i < 4; i++) {
    x <<= 8;
    x += c[i];
  }
  return x;
}

char* inttochar (int x) {
  char* c = (char*)malloc(4);
  for(int i = 3; i>= 0; i--) {
    c[i] = (char)x;
    x = x >> 8;
  }
  return c;
}

float chartofloat (char* c) {
  int x = chartoint(c);
  float f = *(float*)&x;
  return f;
}

char* floattochar (float f) {
  int x = *(int*)&f;
  return inttochar(x);
}

double chartodouble (char* c) {
  long x;
  for(int i=0; i<8; i++) {
    x = x << 8;
    x = c[i];
  }
  return *(double*)&x;
}

char* longtochar (long l) {
  char* c = (char*)malloc(8);
  for(int i=7; i>=0; i--) {
    c[i] = (char)l;
    l = l >> 8;
  }
  return c;
}

char* doubletochar (double d) {
  long l = *(long*)&d;
  return longtochar(l);
}
