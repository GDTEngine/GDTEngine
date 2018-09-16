/*
* @file     GraphicsTest.cpp
* @author   Marek Cernak
* @date     9/16/2018
*
* @brief Graphics module tests
*/

#include <gtest/gtest.h>
#include <memory>
#include "../RenderWindow.hpp"

namespace gdt
{
    namespace test
    {

        class GraphicsTestBase : public ::testing::Test {

        protected:

            /*
            * Define ctor for to initialize for whole duration of test.
            */
            // ~GraphicsTestBase(){}

            /*
            * Define dtor to cleanup after the whole test suite.
            */
            // GraphicsTestBase(){}

            /*
            * Setup before each test.
            */
            void SetUp() override
            {
                m_renderWindow = std::make_unique<CRenderWindow>("GDTEngine", 1280, 720);
            }

            /*
            * Cleanup after each test.
            */
            void TearDown() override
            {}

        protected:
            std::unique_ptr<gdt::CRenderWindow> m_renderWindow;
        };

        // This is just an example test. Provide proper tests when needed.
        TEST_F(GraphicsTestBase, ExampleTest)
        {
            EXPECT_EQ(m_renderWindow->getHeight(), 720);
            ASSERT_NE(m_renderWindow->getHeight(), 500);
            EXPECT_EQ(m_renderWindow->getWidth(), 1280);
            ASSERT_NE(m_renderWindow->getWidth(), 1200);
        }
    }
}
