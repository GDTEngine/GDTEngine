#include "Log.hpp"
#include "RenderWindow.hpp"
#include "Shader.hpp"
#include "Shaders/UberShaderSource.hpp"

using namespace gdt;

int main(int argc, char* argv[])
{
    CRenderWindow* pRenderWindow = new CRenderWindow("GDTEngine", 1280, 720);

    CShader uberShader(shader::uberVertex, shader::uberFragment);

    if (uberShader.getStatus() == EStatus::Failure)
    {
        LOG(uberShader.getErrorString());
    }

    while (true)
    {
        pRenderWindow->clear();
        pRenderWindow->display();

        glfwPollEvents();
    }

    return 0;
}