#include <iostream>
using namespace std;
class b{
public:
b(){};

};
class a{
private:
int n;
public:
a():n(0){}
void ss(int a){
	
	cout << a;
}
friend void b::kk(a ss);
};
void b::kk(a s){cout << s::n;}
int main() {
	// your code goes here
	const int a=11;

	return 0;
}
