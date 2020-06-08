#include <iostream>

#include "Core.h"

//CONTROLLER ("people")
class PeopleController {

public:
	
	REQUEST_MAPPING("/put/age", AddPeople)
	void AddPeople(int age) {

	}


};



int main() {

}
