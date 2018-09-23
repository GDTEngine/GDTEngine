#include "Log.hpp"
#include "Shader.hpp"
#include "Shaders/UberShaderSource.hpp"
#include "RenderWindow.hpp"
#include "VertexArray.hpp"
#include "ArrayBuffer.hpp"
#include "UIRenderer.hpp"
#include <GLM/gtc/matrix_transform.hpp>

#include <string>
#include <fstream>
#include <streambuf>

using namespace gdt;

// Using it here temporary.
using namespace graphics;

int main(int argc, char* argv[])
{
    CRenderWindow* pRenderWindow = new CRenderWindow("GDTEngine", 1280, 720);

    std::ifstream vsFile("../../Shaders/Uber.vs.glsl");
    std::string vs((std::istreambuf_iterator<char>(vsFile)),
        std::istreambuf_iterator<char>());

    vsFile.close();

    std::ifstream fsFile("../../Shaders/Uber.fs.glsl");
    std::string fs((std::istreambuf_iterator<char>(fsFile)),
        std::istreambuf_iterator<char>());
    fsFile.close();

    CShader uberShader(vs, fs);
    
    if (uberShader.getStatus() == EStatus::Failure)
    {
        LOG(uberShader.getErrorString());
    }

    CUIRenderer uiRenderer;

    while (true)
    {
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

        pRenderWindow->clear();

        uberShader.use();
        uberShader.setMat4("Projection", glm::ortho(0.0f, 1280.0f, 720.0f, 0.0f));
        uiRenderer.begin();

        for (auto x = 0; x < 10; ++x)
        {
            for (auto y = 0; y < 10; ++y)
            {
                uiRenderer.submitPanel(glm::vec2(24 * x, 24 * y), glm::vec2(22.0f), glm::vec2(0.0f));
            }
        }


        uiRenderer.end();

        uiRenderer.draw();

        pRenderWindow->display();

        glfwPollEvents();
    }

    return 0;
}