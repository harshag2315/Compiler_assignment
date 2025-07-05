#include<stdio.h>

int main(){
  int a;
  read("%d", a);
  write("The integer is::%d", a);
  float b;
  read("%d", b);
  if(a==b)
    write("a==b");
  else
    write("a!=b");
  return 0;
}
