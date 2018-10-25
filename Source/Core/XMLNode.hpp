/**
 * @file     XMLNode.hpp
 * @author   Ludvig Arlebrink
 * @date     10/14/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "CoreAPI.hpp"

#include <string>
#include <vector>

namespace gdt
{
    namespace core
    {
        class CXMLNode
        {
        public:

            CXMLNode();

            ~CXMLNode();

        private:

            static void tokenizer(const std::string& code);

            static void parser();
        };
    }
}
