#include "Log.hpp"
#include "Shader.hpp"
#include "Shaders/UberShaderSource.hpp"
#include "RenderWindow.hpp"
#include "VertexArray.hpp"
#include "ArrayBuffer.hpp"
#include "UIRenderer.hpp"
#include <GLM/gtc/matrix_transform.hpp>

using namespace gdt;

// Using it here temporary.
using namespace graphics;

int main(int argc, char* argv[])
{
    CRenderWindow* pRenderWindow = new CRenderWindow("GDTEngine", 1280, 720);

    CShader uberShader(shader::uberVertex, shader::uberFragment);
    /*
    float vertices[18] = {
        // First triangle.
        0.5f,  0.5f,
        0.5f, -0.5f,
        -0.5f,  0.5f,

        // Second triangle.
        0.5f, -0.5f,
        -0.5f, -0.5f,
        -0.5f,  0.5f
    };

    CVertexArray vao;
    CArrayBuffer* vbo = new CArrayBuffer();

    vbo->setData(sizeof(vertices), vertices);

    vbo->setAttributePointer(vao, 0, 3, CArrayBuffer::EType::Float, sizeof(float) * 3, 0);
     */
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
        //vao.drawArrays(0, 6);

        uiRenderer.begin();

        for (auto x = 0; x < 70; ++x)
        {
            for (auto y = 0; y < 30; ++y)
            {
                uiRenderer.submitPanel(glm::vec2(24 * x, 24 * y), glm::vec2(16), glm::vec2(0.0f));
            }
        }


        uiRenderer.end();

        uiRenderer.draw();

        pRenderWindow->display();

        glfwPollEvents();
    }

    return 0;
}