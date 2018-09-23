/**
* @file     GraphicsTest.cpp
* @author   Marek Cernak
* @date     9/16/2018
*
* @breif Graphics module tests
*/

#include "../RenderWindow.hpp"
#include <gtest/gtest.h>
#include <memory>

namespace gdt
{
    namespace test
    {
        /**
        * Base class for graphics unit tests.
        */
        class CGraphicsTestBase : public ::testing::Test {

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
                m_pRenderWindow = std::make_unique<gdt::graphics::CRenderWindow>("GDTEngine", 1280, 720);
            }

            /*
            * Cleanup after each test.
            */
            void TearDown() override
            {}

        protected:
            std::unique_ptr<gdt::graphics::CRenderWindow> m_pRenderWindow;
        };

        // This is just an example test. Provide proper tests when needed.
        TEST_F(CGraphicsTestBase, ExampleTest)
        {
            EXPECT_EQ(m_pRenderWindow->getHeight(), 720);
            ASSERT_NE(m_pRenderWindow->getHeight(), 500);
            EXPECT_EQ(m_pRenderWindow->getWidth(), 1280);
            ASSERT_NE(m_pRenderWindow->getWidth(), 1200);
        }
    }
}
