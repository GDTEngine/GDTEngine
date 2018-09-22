/**
 * @file     UIRenderer.hpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#pragma once

#include "BaseTypes.hpp"

#include <memory>
#include <GLM/glm.hpp>

namespace gdt
{
    namespace graphics
    {
        // Forward declartions.
        class CVertexArray;
        class CArrayBuffer;

        class CUIRenderer
        {
        private:

            struct SUIDefinition
            {
                glm::vec2 position;
            };

        public:

            /**
             * @breif Default constructor.
             */
            CUIRenderer();

            /**
             * @breif Copy constructor deleted.
             */
            CUIRenderer(const CUIRenderer& other) = delete;

            /**
             * @breif Move constructor.
             * @param other Source.
             */
            CUIRenderer(CUIRenderer&& other) noexcept;

            /**
             * @breif Destructor.
             */
            ~CUIRenderer();

            /**
             * @breif Assignment operator deleted.
             */
            void operator=(const CUIRenderer& rhs) = delete;

            void begin();

            void end();

            void submitPanel(const glm::vec2& position, const glm::vec2& size, const glm::vec2& anchor);

            void draw() const;

        private:

            SUIDefinition* m_pMap;
            int32 m_count;
            std::unique_ptr<CVertexArray> m_pVertexArray;
            std::unique_ptr<CArrayBuffer> m_pVertexBuffer;
        };
    }
}