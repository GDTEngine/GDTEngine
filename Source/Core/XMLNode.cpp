/**
 * @file     XMLNode.hpp
 * @author   Ludvig Arlebrink
 * @date     10/14/2018
 */

#include "XMLNode.hpp"

using namespace gdt;
using namespace core;

CXMLNode::CXMLNode()
{
}

CXMLNode::~CXMLNode()
{
}

void CXMLNode::tokenizer(const std::string& code)
{
    std::vector<std::pair<std::string, std::string>> tokens;

    int32 i = 0;
    int32 lineNumber = 1;

    while (i < code.length())
    {
        if (code[i] == ' ')
        {
            ++i;
            continue;
        }

        if (code[i] == '\n')
        {
            ++i;
            ++lineNumber;
            continue;
        }

        if (code[i] == '<')
        {
            ++i;
            tokens.push_back(std::pair<std::string, std::string>("bracket", "<"));
            continue;
        }

        if (code[i] == '>')
        {
            ++i;
            tokens.push_back(std::pair<std::string, std::string>("bracket", ">"));
            continue;
        }

        if (code[i] >= '0' && code[i] <= '9')
        {
            std::string number(std::to_string(code[i]));
            ++i;

            bool isFloat = false;
            while (code[i] >= '0' && code[i] <= '9' || code[i] == '.')
            {
                if (code[i] == '.')
                {
                    isFloat = true;
                }

                number.append(std::to_string(code[i]));
                ++i;
            }

            if (isFloat)
            {
                tokens.push_back(std::pair<std::string, std::string>("float", number));
            }
            else
            {
                tokens.push_back(std::pair<std::string, std::string>("integer", number));
            }

            continue;
        }

        if ((code[i] >= 'a' && code[i] <= 'z') || (code[i] >= 'A' && code[i] <= 'Z') || code[i] == '_')
        {

        }
    }
}

void CXMLNode::parser()
{
}
