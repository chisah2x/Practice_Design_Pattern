#include "RepoProxy.h"

#include <iostream>

#include "Repository.h"

bool RepoProxy::IsAuthorized() const {
	if(m_AuthorizedRoles.empty()) {
		throw std::runtime_error{ "Authorized roles not set" };
	}
	return std::any_of(begin(m_AuthorizedRoles), end(m_AuthorizedRoles), 
		[this](const std::string& role) {
			return GetUser()->GetRole() == role;
	});
	/*for(const auto & role : m_AuthorizedRoles) {
		if(GetUser()->GetRole()==role) {
			return true;
		}
	}
	return false;*/
}

Employee* RepoProxy::GetUser() const {
	return m_pRepo->GetUser();
}

void RepoProxy::SetUser(Employee* emp) {
	m_pRepo->SetUser(emp);
}

void RepoProxy::SetAuthorizedList(std::initializer_list<std::string> authorizedList) {
	m_AuthorizedRoles.assign(authorizedList);
}

RepoProxy::RepoProxy(const std::string& path) :m_pRepo{ new Repository{path} } {
}

void RepoProxy::CreateFile(const std::string& fileName) {
	if(IsAuthorized()) {
		m_pRepo->CreateFile(fileName);
	}else {
		std::cout << GetUser()->GetInfo() << " is not authorized to create a file\n";
	}
}

void RepoProxy::DeleteFile(const std::string& fileName) {
	if (IsAuthorized()) {
		m_pRepo->DeleteFile(fileName);
	}
	else {
		std::cout << GetUser()->GetInfo() << " is not authorized to delete the file\n";
	}
}

void RepoProxy::UpdateFile(const std::string& fileName) {
	if (IsAuthorized()) {
		m_pRepo->UpdateFile(fileName);
	}
	else {
		std::cout << GetUser()->GetInfo() << " is not authorized to update the file\n";
	}
}

void RepoProxy::ViewFile(const std::string& fileName) {
	if (IsAuthorized()) {
		m_pRepo->ViewFile(fileName);
	}
	else {
		std::cout << GetUser()->GetInfo() << " is not authorized to view the file\n";
	}
}

RepoProxy::~RepoProxy() {
	delete m_pRepo;
}
