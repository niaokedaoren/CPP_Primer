#include <iostream>
#include "Message.h"
#include "Folder.h"

using namespace std;

int main()
{
	Folder fldr1("/home");
	Folder fldr2("/boot");
	Message msg1("Ok");
	Message msg2("Hi");
	Message msg3("Hey");

	fldr1.addMsg(&msg1);
	fldr1.addMsg(&msg2);
	fldr1.addMsg(&msg3);

	msg3.save(fldr2);
	msg3.remove(fldr1);

	Folder fldr3 = fldr1;
	Folder *fldr4 = new Folder(fldr3);

	msg1 = msg3;

	fldr1.print();
	fldr2.print();
	fldr3.print();
	fldr4->print();

	msg1.print();
	msg2.print();
	msg3.print();

	delete fldr4;

	fldr1.print();
	fldr2.print();
	fldr3.print();

	msg1.print();
	msg2.print();
	msg3.print();

	return 0;
}
