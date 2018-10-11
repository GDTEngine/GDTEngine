/**
 * @file     FileIterator.hpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "CoreAPI.hpp"

#include <string>

#ifdef _WIN32
#include <Windows.h>
#elif __linux__
 // @todo Linux implementation.
#endif // _WIN32

namespace gdt
{
    namespace core
    {
        /**
         * @brief Used to scan for files in a directory.
         * 
         * Begin by finding the first file, then iterate trough the directory.
         */
        class CORE_API CFileIterator final
        {
        public:
            
            /**
             * @brief Default constructor.
             */
            CFileIterator();

            CFileIterator(const CFileIterator&) = delete;

            CFileIterator(CFileIterator&&) = delete;

            /**
             * @brief Destructor.
             */
            ~CFileIterator();

            void operator=(const CFileIterator&) = delete;

            /**
             * @brief Find the first file in the directory.
             * @return true if any file is found.
             */
            bool findFirstFile(const std::string& directoryPath);

            /**
             * @brief Find the next file in the directory.
             * @return true if another file is found.
             */
            bool findNext();

            /**
             * @brief Get the name of found file.
             * @return Name of the found file.
             */
            std::string getFilename() const;

        private:

        #ifdef _WIN32
            HANDLE m_pFileHandle;
            WIN32_FIND_DATAA m_fileData;
        #elif __linux__
            // @todo Linux implementation.
        #endif // _WIN32
        };
    }
}
