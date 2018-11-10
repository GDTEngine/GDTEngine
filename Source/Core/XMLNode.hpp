/**
 * @file     XMLNode.hpp
 * @author   Ludvig Arlebrink
 * @date     10/14/2018
 */

#pragma once

#include "BaseTypes.hpp"
#include "CoreAPI.hpp"

#include <string>
#include <unordered_map>
#include <vector>

namespace gdt
{
    namespace core
    {
        /**
         * @brief XML node.
         */
        class CORE_API CXMLNode
        {
        public:

            enum class EAttributeType
            {
                Float,
                Int,
                String
            };

        private:

            struct SAttributeInfo
            {
                EAttributeType attributeType;
                std::string attributeValue;
            };

        public:

            /**
             * @brief Constructor.
             */
            CXMLNode();

            /**
             * @brief Load a XML file.
             * @param filepath Path to file.
             */
            explicit CXMLNode(const std::string& filepath);

            /**
             * @brief Destructor.
             */
            ~CXMLNode();

            void addAttribute(const std::string& attribute, f32 value);

            void addAttribute(const std::string& attribute, int32 value);

            void addAttribute(const std::string& attribute, const std::string& value);

            CXMLNode* addChild(const std::string& name);

            /**
             * @brief Load a XML file.
             * @param filepath Path to file.
             */
            void load(const std::string& filepath);

            f32 getAttributeAsFloat(const std::string& attribute) const;

            int32 getAttributeAsInt(const std::string& attribute) const;

            std::string getAttributeAsString(const std::string& attribute) const;

            CXMLNode* getChild(int32 index) const;

            int32 getNumChildren() const;

            void save(const std::string& filepath);

        private:

            static std::vector<std::pair<std::string, std::string>> generateTokens(const std::string& code);

            static void parse(const std::vector<std::pair<std::string, std::string>>& tokens, CXMLNode* pRoot);

            std::string saveRecursive(int32 depth);

        private:

            CXMLNode* m_pParent;

            std::string m_name;
            std::unordered_map<std::string, SAttributeInfo> m_attributes;
            std::vector<CXMLNode*> m_pChildren;
        };
    }
}
