/**
 * @file     EngineTest.hpp
 * @author   Ludvig Arlebrink
 * @date     9/16/2018
 */

#pragma once

#include <gtest/gtest.h>
#include <memory>

namespace gdt
{
    namespace engine
    {
        namespace test
        {
            /**
             * @brief Base class for engine unit tests.
             */
            class CEngineTest : public ::testing::Test
            {
            protected:

                /*
                * Define ctor for to initialize for whole duration of test.
                */
                // CGraphicsTestBase(){}

                /*
                * Define dtor to cleanup after the whole test suite.
                */
                // ~CGraphicsTestBase(){}

                /*
                 * @brief Setup before each test.
                 */
                void SetUp() override
                {
                }

                /*
                 * @brief Cleanup after each test.
                 */
                void TearDown() override
                {
                }
            };
        }
    }
}
