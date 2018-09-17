#include "Log.hpp"
#include "Shader.hpp"
#include "Shaders/UberShaderSource.hpp"
#include "RenderWindow.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"

using namespace gdt;

int main(int argc, char* argv[])
{
    CRenderWindow* pRenderWindow = new CRenderWindow("GDTEngine", 1280, 720);

    CShader uberShader(shader::uberVertex, shader::uberFragment);

    float vertices[18] = {
        // First triangle.
        0.5f,  0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,

        // Second triangle.
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
    };

    CVertexArray* vao = new CVertexArray();
    CVertexBuffer* vbo = new CVertexBuffer();

    vbo->setData(vao, sizeof(vertices), vertices);
    vbo->setAttributePointer(vao, 0, 3, CBufferObject::EType::Float, sizeof(float) * 3, 0);

    // vbo.setData(&vao, )

    if (uberShader.getStatus() == EStatus::Failure)
    {
        LOG(uberShader.getErrorString());
    }

    while (true)
    {
        pRenderWindow->clear();

        uberShader.use();
        vao->drawArrays(0, 3);

        pRenderWindow->display();

        glfwPollEvents();
    }

    return 0;
}