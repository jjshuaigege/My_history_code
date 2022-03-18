#ifndef TICKETMACHINE_H_
#define TICKETMACHINE_H_

class TicketMachine{
	public:
		TicketMachine();
		virtual ~TicketMachine();
		void showprompt();
		void insertmoney(int money);
		void showbalance();
		void printticket();
		void showtotal();
	private:
	const int price;
	int balance;
	int total;	
};

#endif
