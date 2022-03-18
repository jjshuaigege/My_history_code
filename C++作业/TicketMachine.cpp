#include "TicketMachine.h"
#include <iostream>
using namespace std;
TicketMachine::TicketMachine():price(0)
{
	
}
TicketMachine::~TicketMachine()
{
	
}
void TicketMachine::showprompt()
{
	cout<<"something"<<endl;
}
void TicketMachine::insertmoney(int money)
{
	balance+=money;
}
void TicketMachine::showbalance()
{
	cout<<balance<<endl;
}


