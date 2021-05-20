#pragma once
#include "Contact.h"
#include "Prieten.h"
#include "Coleg.h"
#include "Cunoscut.h"
#include "Prieten.h"

#include <vector>
class Agenda{
	std::vector<Contact*> contacte;
public:
	const Contact& find_by_name(std::string name) {
		for (auto contact : contacte) {
			if (contact->nume == name) {
				return *contact;
			}
		}
	}
	std::vector<Contact*> getFriendsList() {
		std::vector<Contact*> friends;
		for (auto contact : contacte) {
			if (contact->getContactType() == TipPrieten) {
				friends.push_back(contact);
			}
		}
		return friends;
	}

	void deleteContactByName(std::string name) {
		for (int i = 0; i < contacte.size(); i++) {
			if (contacte[i]->nume == name) {
				contacte.erase(contacte.begin() + i);
			}
		}
	}

	void addContact(Contact* newContact) {
		contacte.push_back(newContact);
	}
};

