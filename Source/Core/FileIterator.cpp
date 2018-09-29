/**
 * @file     FileIterator.cpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#include "FileIterator.hpp"

using namespace gdt;
using namespace core;

CFileIterator::CFileIterator()
    : m_pFileHandle(nullptr)
{
}

CFileIterator::~CFileIterator()
{
}

bool CFileIterator::findFirstFile(const std::string& directoryPath)
{
#ifdef _WIN32
    m_pFileHandle = FindFirstFileA(directoryPath.c_str(), &m_fileData);

    if (m_pFileHandle == reinterpret_cast<void*>(ERROR_INVALID_HANDLE) || m_pFileHandle == reinterpret_cast<void*>(ERROR_FILE_NOT_FOUND))
    {
        return false;
    }

#elif __linux__

    // @todo Linux implementation.

#endif // _WIN32

    return true;
}

bool CFileIterator::findNext()
{
#ifdef _WIN32
    return FindNextFileA(m_pFileHandle, &m_fileData);
#elif __linux__
    // @todo Linux implementation.
    return false;
#endif // _WIN32
}

std::string CFileIterator::getFilename() const
{
#ifdef _WIN32
    return m_fileData.cFileName;
#elif __linux__
    // @todo Linux implementation.
    return "";
#endif
}
