#pragma once
#include <string>
#include <vector>


#include "Storage.h"

class Repository;
class RepoProxy : public Storage
{
	Repository* m_pRepo;
	bool IsAuthorized()const;
	std::vector<std::string> m_AuthorizedRoles;
public:
	Employee* GetUser()const;
	void SetUser(Employee* emp);
	void SetAuthorizedList(std::initializer_list<std::string> authorizedList);
	//Add support for add & remove
	RepoProxy(const std::string& path);
	void CreateFile(const std::string& fileName);
	void DeleteFile(const std::string& fileName);
	void UpdateFile(const std::string& fileName);
	void ViewFile(const std::string& fileName);
	~RepoProxy();
};

