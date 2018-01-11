#include<iostream>
#include<unistd.h>
using namespace std;
int main(){
int a[10];
for(int i=0;i<10;i++)
a[i]=i;

sleep(5);
a[10]=101;
sleep(12);
return 0;
}
