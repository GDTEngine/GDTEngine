/**
 * @file     XMLNode.hpp
 * @author   Ludvig Arlebrink
 * @date     10/14/2018
 */

#include "XMLNode.hpp"
#include "Log.hpp"

#include <fstream>
#include <stack>
#include <streambuf>

using namespace gdt;
using namespace core;

CXMLNode::CXMLNode()
    : m_pParent(nullptr)
{
}

CXMLNode::CXMLNode(const std::string& filepath)
    : m_pParent(nullptr)
{
    load(filepath);
}

CXMLNode::~CXMLNode()
{
    for (int32 i = 0; i < m_pChildren.size(); ++i)
    {
        delete m_pChildren[i];
    }
}

void CXMLNode::addAttribute(const std::string& attribute, f32 value)
{
}

void CXMLNode::addAttribute(const std::string& attribute, int32 value)
{
}

void CXMLNode::addAttribute(const std::string& attribute, const std::string& value)
{
}

CXMLNode* CXMLNode::addChild(const std::string& name)
{
    return nullptr;
}

void CXMLNode::load(const std::string& filepath)
{
    std::ifstream t(filepath);
    if (t.is_open())
    {
        std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
        t.close();

        std::vector<std::pair<std::string, std::string>> tokens = generateTokens(str);
        parse(tokens, this);
    }
    else
    {
        // ERROR!
    }
}

f32 CXMLNode::getAttributeAsFloat(const std::string& attribute) const
{
    return f32();
}

int32 CXMLNode::getAttributeAsInt(const std::string& attribute) const
{
    return int32();
}

std::string CXMLNode::getAttributeAsString(const std::string& attribute) const
{
    return std::string();
}

CXMLNode* CXMLNode::getChild(int32 index) const
{
    return m_pChildren[index];
}

int32 CXMLNode::getNumChildren() const
{
    return m_pChildren.size();
}

void CXMLNode::save(const std::string& filepath)
{
    std::string str;
    for (int32 i = 0; i < m_pChildren.size(); ++i)
    {
        str.append(m_pChildren[i]->saveRecursive(0));
        str.append("\n");
    }

    std::ofstream t(filepath);
    t << str;
    t.close();
}

std::vector<std::pair<std::string, std::string>> CXMLNode::generateTokens(const std::string& code)
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

        if (code[i] == '=')
        {
            ++i;
            tokens.push_back(std::pair<std::string, std::string>("operator", "="));
            continue;
        }

        if (code[i] == '/')
        {
            ++i;
            tokens.push_back(std::pair<std::string, std::string>("operator", "/"));
            continue;
        }

        if (code[i] == '\"')
        {
            ++i;
            tokens.push_back(std::pair<std::string, std::string>("operator", "\""));
        }

        if (code[i] >= '0' && code[i] <= '9')
        {
            std::string number(std::string(1, code[i]));
            ++i;

            bool isFloat = false;
            while ((code[i] >= '0' && code[i] <= '9') || code[i] == '.')
            {
                if (code[i] == '.')
                {
                    isFloat = true;
                }

                number.append(std::string(1, code[i]));
                ++i;
            }

            if (isFloat)
            {
                tokens.push_back(std::pair<std::string, std::string>("float", number));
            }
            else
            {
                tokens.push_back(std::pair<std::string, std::string>("int", number));
            }

            continue;
        }

        if ((code[i] >= 'a' && code[i] <= 'z') || (code[i] >= 'A' && code[i] <= 'Z') || code[i] == '_')
        {
            std::string name(std::string(1, code[i]));
            ++i;

            while ((code[i] >= 'a' && code[i] <= 'z') || (code[i] >= 'A' && code[i] <= 'Z') || (code[i] >= '0' && code[i] <= '9') || code[i] == '.' || code[i] == '_')
            {
                name.append(std::string(1, code[i]));
                ++i;
            }

            tokens.push_back(std::pair<std::string, std::string>("name", name));
            continue;
        }

        // ERROR!
    }

    return tokens;
}

void CXMLNode::parse(const std::vector<std::pair<std::string, std::string>>& tokens, CXMLNode* pRoot)
{
    pRoot->m_name = "root";
    CXMLNode* pActiveNode = pRoot;

    std::stack<CXMLNode*> pNodes;
    pNodes.emplace(pActiveNode);

    int32 i = 0;

    while (i < tokens.size())
    {
        if (tokens[i].second == "<")
        {
            ++i;
            if (tokens[i].second == "/")
            {
                ++i;

                if (tokens[i].first == "name" && tokens[i].second == pActiveNode->m_name)
                {
                    ++i;

                    pActiveNode = pNodes.top();
                    pNodes.pop();

                    if (tokens[i].second == ">")
                    {
                        ++i;
                    }
                    else
                    {
                        // ERROR!
                    }
                }
                else
                {
                    // ERROR!
                }
            }
            else if (tokens[i].first == "name")
            {
                pNodes.emplace(pActiveNode);
                CXMLNode* newNode = new CXMLNode;
                pActiveNode->m_pChildren.push_back(newNode);
                pActiveNode = newNode;
                pActiveNode->m_name = tokens[i].second;
                ++i;

                while (tokens[i].second != ">")
                {
                    if (tokens[i].first == "name")
                    {
                        std::string attributeName = tokens[i].second;
                        ++i;
                        if (tokens[i].second == "=")
                        {
                            ++i;
                            if (tokens[i].second == "\"")
                            {
                                ++i;
                                if (tokens[i].first == "float")
                                {
                                    SAttributeInfo attributeInfo;
                                    attributeInfo.attributeType = EAttributeType::Float;
                                    attributeInfo.attributeValue = tokens[i].second;
                                    pActiveNode->m_attributes.emplace(attributeName, attributeInfo);

                                    ++i;
                                }
                                else if (tokens[i].first == "int")
                                {
                                    SAttributeInfo attributeInfo;
                                    attributeInfo.attributeType = EAttributeType::Int;
                                    attributeInfo.attributeValue = tokens[i].second;
                                    pActiveNode->m_attributes.emplace(attributeName, attributeInfo);

                                    ++i;
                                }
                                else if (tokens[i].first == "name")
                                {
                                    std::string attributeValue = tokens[i].second;
                                    ++i;

                                    while (tokens[i].second != "\"")
                                    {
                                        attributeValue.append(tokens[i].second);
                                        ++i;
                                    }

                                    SAttributeInfo attributeInfo;
                                    attributeInfo.attributeType = EAttributeType::String;
                                    attributeInfo.attributeValue = attributeValue;
                                    pActiveNode->m_attributes.emplace(attributeName, attributeInfo);
                                }
                                else
                                {
                                    // ERROR!
                                }

                                if (tokens[i].second == "\"")
                                {
                                    ++i;
                                }
                                else
                                {
                                    // ERROR!
                                }
                            }
                            else
                            {
                                // ERROR!
                            }
                        }
                        else
                        {
                            // ERROR!
                        }
                    }
                    else if (tokens[i].second == "/")
                    {
                        pActiveNode = pNodes.top();
                        pNodes.pop();

                        ++i;

                        if (tokens[i].second != ">")
                        {
                            // ERROR!
                        }
                    }
                    else
                    {
                        // ERROR!
                    }
                }

                if (tokens[i].second == ">")
                {
                    ++i;
                }
                else
                {
                    // ERROR!
                }
            }
        }
        else
        {
            // ERROR!
        }
    }
}

std::string CXMLNode::saveRecursive(int32 depth)
{
    std::string str = "";

    for (int32 i = 0; i < depth; ++i)
    {
        str.append("    ");
    }

    str.append("<");
    str.append(m_name);

    for (auto attribute : m_attributes)
    {
        str.append(" ");
        str.append(attribute.first);
        str.append("=\"");
        str.append(attribute.second.attributeValue);
        str.append("\"");
    }

    if (m_pChildren.empty())
    {
        str.append(" />");
    }
    else
    {
        str.append(">");

        for (int32 i = 0; i < m_pChildren.size(); ++i)
        {
            str.append("\n");
            str.append(m_pChildren[i]->saveRecursive(depth + 1));
        }

        str.append("\n");

        for (int32 i = 0; i < depth; ++i)
        {
            str.append("    ");
        }

        str.append("</");
        str.append(m_name);
        str.append(">");
    }

    return str;
}
