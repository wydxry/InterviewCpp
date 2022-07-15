#include <iostream>
#include "person.h"
using namespace std;

int main() {

	Person<string, int> p("wydxry", 30);
	p.showPerson();

	return 0;
}