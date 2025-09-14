#pragma once
#include <fstream>
#include <filesystem>

#include "Storage.h"

class Repository : public Storage
{
	Employee* m_pEmp;
	std::filesystem::path m_CurrentPath{};
public:
	Employee* GetUser()const {
		return m_pEmp;
	}
	void SetUser(Employee* emp) {
		m_pEmp = emp;
	}
	Repository(const std::string& repoPath);
	void CreateFile(const std::string& fileName)override;
	void DeleteFile(const std::string& fileName)override;
	void UpdateFile(const std::string& fileName)override;
	void ViewFile(const std::string& fileName)  override;
};

