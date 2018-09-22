/**
 * @file     BufferObject.hpp
 * @author   Ludvig Arlebrink
 * @date     9/21/2018
 */

#pragma once

#include <GLEW/glew.h>

namespace gdt
{
    namespace graphics
    {
        /**
         * @brief Abstract base class for buffer objects.
         */
        class CBufferObject
        {
        public:

            /**
             * @breif Enum class for basic data types.
             */
            enum class EType
            {
                /** Bool type. 8 bits. */
                Bool = GL_BOOL,

                /** Byte type, 8 bits. */
                Byte = GL_BYTE,

                /** Float type, 32 bits. */
                Float = GL_FLOAT,

                /** Int type, 32 bits. */
                Int = GL_INT,

                /** Unsigned byte type, 8 bits. */
                UnsignedByte = GL_UNSIGNED_BYTE,

                /** Unsigned int type, 32 bits. */
                UnsignedInt = GL_UNSIGNED_INT
            };

            /**
             * @breif Usage of the buffer.
             */
            enum class EUsage
            {
                /** 
                 * The data store contents will be modified repeatedly and used many times. The data store contents are
                 * modified by reading data from the GL, and used as the source for GL drawing and image specification
                 * commands.
                 */
                DynamicCopy = GL_DYNAMIC_COPY,

                /** 
                 * The data store contents will be modified repeatedly and used many times. The data store contents are
                 * modified by the application, and used as the source for GL drawing and image specification commands.
                 */
                DynamicDraw = GL_DYNAMIC_DRAW,

                /** 
                 * The data store contents will be modified repeatedly and used many times. The data store contents are 
                 * modified by reading data from the GL, and used to return that data when queried by the application.
                 */
                DynamicRead = GL_DYNAMIC_READ,

                /** 
                 * The data store contents will be modified once and used many times. The data store contents are
                 * modified by reading data from the GL, and used as the source for GL drawing and image specification
                 * commands.
                 */
                StaticCopy = GL_STATIC_COPY,

                /** 
                 * The data store contents will be modified once and used many times. The data store contents are modified 
                 * by the application, and used as the source for GL drawing and image specification commands.
                 */
                StaticDraw = GL_STATIC_DRAW,

                /** 
                 * The data store contents will be modified once and used many times. The data store contents are modified 
                 * by reading data from the GL, and used to return that data when queried by the application.
                 */
                StaticRead = GL_STATIC_READ,

                /** 
                 * Use when data store contents will be modified once and used at most a few times. The data store contents are
                 * modified by reading data from the GL, and used as the source for GL drawing and image specification
                 * commands.
                 */
                StreamCopy = GL_STREAM_COPY,

                /** 
                 * Use when data store contents will be modified once and used at most a few times. The data store contents are
                 * modified by the application, and used as the source for GL drawing and image specification commands.
                 */
                StreamDraw = GL_STREAM_DRAW,

                /** 
                 * Use when data store contents will be modified once and used at most a few times. The data store contents are
                 * modified by reading data from the GL, and used to return that data when queried by the application.
                 */
                StreamRead = GL_STREAM_READ
            };

        public:

            /**
             * @breif Default constructor.
             */
            CBufferObject();

            /**
             * @brief Set usage of the buffer object.
             */
            explicit CBufferObject(EUsage usage);

            /**
             * @breif Destructor.
             */
            virtual ~CBufferObject();

            /**
             * @breif Bind the buffer.
             */
            virtual void bind() const = 0;

            /**
             * @breif Get the usage of this buffer.
             * @return Usage of this buffer.
             */
            EUsage getUsage() const;

            /**
             * @breif Set the usage of this buffer.
             * @param usage Usage of this buffer.
             */
            void setUsage(EUsage usage);

        private:

            EUsage m_usage;
        };
    }
}