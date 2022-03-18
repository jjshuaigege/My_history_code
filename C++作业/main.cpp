#include <iostream>
#include "TicketMachine.h"
using namespace std;
int main(int argc, char** argv) 
{
	#include"666.cpp"
	TicketMachine tm;
	tm.showprompt();
	tm.insertmoney(200);
	tm.showbalance();
	return 0;
}
