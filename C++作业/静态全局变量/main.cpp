#include <iostream>
#include "1.h"
#include "2.h"
using namespace std;
extern int i;
int main(int argc, char** argv) {
	f();
	g();
	cout<<"i="<<i;
	return 0;
}
