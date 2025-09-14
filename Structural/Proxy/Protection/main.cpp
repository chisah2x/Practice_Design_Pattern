#include <iostream>


#include "Employee.h"
#include "RepoProxy.h"
#include "Repository.h"


int main() {
	try {
		RepoProxy repo{ R"(./)" };
		repo.SetAuthorizedList({ "Manager", "Architect" });
		Employee e1{ "Umar", "Manager" };
		Employee e2{ "Ayaan", "Programmer" };
		Employee e3{ "Raihaan", "Architect"};
			
		repo.SetUser(&e2);
		//repo.CreateFile("data.txt");

		//repo.UpdateFile("data.txt");
		//repo.DeleteFile("data.txt");
		repo.ViewFile("data.txt");
	}catch(std::exception &ex) {
		std::cout << "[Exception]" << ex.what() << std::endl; 
	}
}

