#include "Image.h"

void Image::SetFileName(const std::string& fileName) {
	m_FileName = fileName;
}

Image::Image(const std::string& fileName): m_FileName{fileName} {
}

const std::string& Image::GetFileName() const {
	return m_FileName;
}
