#include <iostream>
#include "Agenda.h"
#include "Contact.h"
#include "Coleg.h"
#include "Cunoscut.h"
#include "Prieten.h"

using namespace std;

int main() {
	Agenda agenda;
	
	
	Prieten* p1 = new Prieten("Popescu", "Ion", "21.03.2000", "0747200726", "Str. Nucului");
	Prieten* p2 = new Prieten("Andrei", "Dan", "30.01.1997", "0746378294", "Str. Soarelui");
	Cunoscut* c = new Cunoscut("Danila", "Nicu", "07636532442");
	Coleg* coleg1 = new Coleg("Ionescu", "Raul", "07487262728", "Dins", "Str. N. Maniu");
	
	agenda.addContact(p1);
	agenda.addContact(p2);
	agenda.addContact(c);
	agenda.addContact(coleg1);

}