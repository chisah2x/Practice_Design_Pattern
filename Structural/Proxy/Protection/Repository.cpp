#include "Repository.h"


#include <iostream>
#include <string>

Repository::Repository(const std::string& repoPath):m_CurrentPath{repoPath}{
	if(!exists(m_CurrentPath)) {
		throw std::runtime_error{ "Path does not exist" };
	}
}

void Repository::CreateFile(const std::string& fileName) {
	auto path = m_CurrentPath;
	path /= fileName;
	if (exists(path)) {
		throw std::runtime_error{ "File already exists" };
	}std::ofstream out{ path };
	if(!out.is_open()) {
		throw std::runtime_error{ "Could not create file" };
	}
	std::cout << GetUser()->GetInfo() << "is creating a file\n";
	std::string filedata;
	std::cout << "Enter data:";
	std::getline(std::cin, filedata);
	out << filedata;
	std::cout << "File created successfully\n";
}

void Repository::DeleteFile(const std::string& fileName) {
	auto path = m_CurrentPath;
	path /= fileName;
	if(!exists(path)) {
		throw std::runtime_error{ "File does not exist" };
	}
	std::cout << GetUser()->GetInfo() << "is deleting a file\n";
	if (std::filesystem::remove(path)) {
		std::cout << "File deleted successfully\n";
	}
}

void Repository::UpdateFile(const std::string& fileName) {
	auto path = m_CurrentPath;
	path /= fileName;
	if (!exists(path)) {
		throw std::runtime_error{ "File does not exist" };
	}
	std::ofstream out{ path, out.app };
	if (!out.is_open()) {
		throw std::runtime_error{ "Could not open file" };
	}
	std::cout << GetUser()->GetInfo() << "is updating a file\n";
	std::string filedata;
	std::cout << "Enter data:";
	std::getline(std::cin, filedata);
	out << "\n##### UPDATE #####\n" << filedata;
	std::cout << "File updated successfully\n";
}

void Repository::ViewFile(const std::string& fileName) {
	auto path = m_CurrentPath;
	path /= fileName;
	if (!exists(path)) {
		throw std::runtime_error{ "File does not exist" };
	}
	std::ifstream in{ path};
	if (!in.is_open()) {
		throw std::runtime_error{ "Could not open file" };
	}
	std::cout << GetUser()->GetInfo() << "is viewing a file\n";
	std::string line;
	while(std::getline(in, line)) {
		std::cout << line << '\n';
	}
}
