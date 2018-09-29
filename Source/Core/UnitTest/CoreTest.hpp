/**
 * @file     CoreTest.hpp
 * @author   Ludvig Arlebrink
 * @date     9/29/2018
 */

#pragma once

#include <gtest/gtest.h>
#include <memory>

namespace gdt
{
    namespace core
    {
        namespace test
        {
            /**
             * @brief Base class for graphics unit tests.
             */
            class CCoreTest : public ::testing::Test
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
                 * Setup before each test.
                 */
                void SetUp() override
                {
                }

                /*
                 * Cleanup after each test.
                 */
                void TearDown() override
                {
                }

            protected:

            };
        }
    }
}
