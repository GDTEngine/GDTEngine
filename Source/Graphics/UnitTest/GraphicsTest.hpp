/**
 * @file     GraphicsTest.hpp
 * @author   Marek Cernak
 * @date     9/16/2018
 */

#pragma once

#include "RenderWindow.hpp"
#include <gtest/gtest.h>
#include <memory>

namespace gdt
{
    namespace graphics
    {
        namespace test
        {
            /**
             * @brief Base class for graphics unit tests.
             */
            class CGraphicsTest : public ::testing::Test
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
                    pRenderWindow = std::make_unique<CRenderWindow>("Test Window", 1280, 720);
                }

                /*
                 * Cleanup after each test.
                 */
                void TearDown() override
                {
                }

            protected:

                std::unique_ptr<CRenderWindow> pRenderWindow;
            };

            // This is just an example test. Provide proper tests when needed.
            TEST_F(CGraphicsTest, ExampleTest)
            {
                EXPECT_EQ(pRenderWindow->getHeight(), 720);
                ASSERT_NE(pRenderWindow->getHeight(), 500);
                EXPECT_EQ(pRenderWindow->getWidth(), 1280);
                ASSERT_NE(pRenderWindow->getWidth(), 1200);
            }
        }
    }
}
