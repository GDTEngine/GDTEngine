/**
 * @file     Mesh.hpp
 * @author   Ludvig Arlebrink
 * @date     10/9/2018
 */


#pragma once

#include "ArrayBuffer.hpp"
#include "VertexArray.hpp"

#include <GLM/glm.hpp>
#include <memory>
#include <vector>

namespace gdt
{
    namespace engine
    {
        class CMesh
        {
        public:

            struct SVertex
            {
                glm::vec3 position;
                glm::vec3 color;
            };

        public:

            CMesh();

            ~CMesh();

            void bind();

            void setVertices(const std::vector<SVertex>& vertices);

            void draw();

        private:

            graphics::CArrayBuffer m_arrayBuffer;
            graphics::CVertexArray m_vertexArray;
            std::vector<SVertex> m_vertices;
        };
    }
}