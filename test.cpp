#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
void redHat(char a){
    if(a<'A')
        cout << " ";
        else if('A'<=a&&a<='Z')
            redHat(a+1);
            else
            cout <<"GG";
}
int main(){
    int ia[3][4]={{0},{4},{8}};
    int (*ip)[4]=ia;
    ip=&ia[2];
    cout << *ip[0] <<endl;		
    vector<string> svec(10);
    vector<string> *pvec1 = new vector<string>(10);
    cout << svec.size() << pvec1->size()<<endl;
    vector<string> *pvec2 = new vector<string>[10];
    int *p = new int[10]{0};
    cout << *p <<endl; 
    vector<string> *pv1 = &svec;
    vector<string> *pv2 = pvec1;
    //redHat('A');
}
