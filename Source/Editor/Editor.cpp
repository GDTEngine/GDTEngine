/**
 * @file     Editor.cpp
 * @author   Ludvig Arlebrink
 * @date     10/14/2018
 */

#include "Editor.hpp"
#include "EditorUI.hpp"
#include "Managers/EntityManager.hpp"
#include "Managers/EventManager.hpp"
#include "Managers/PluginManager.hpp"
#include "Object.hpp"
#include "RenderWindow.hpp"
#include "CSharp/CSAssembly.hpp"
#include "CSharp/CSClass.hpp"
#include "CSharp/CSDomain.hpp"
#include "CSharp/CSMethod.hpp"
#include "CSharp/CSObject.hpp"

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

using namespace gdt;
using namespace editor;

CEditor::CEditor()
{
}

CEditor::~CEditor()
{
}

MonoMethod* find_method(MonoClass* c, const char* name)
{
    MonoMethod* m = nullptr;
    void* iter = nullptr;
    while ((m = mono_class_get_methods(c, &iter)))
    {
        if (strcmp(mono_method_get_name(m), name) == 0)
        {
            return m;
        }
    }
}

void CEditor::run()
{
    graphics::CRenderWindow window;
    window.create("Window", 1280, 720);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    ImGui::GetIO().IniFilename = nullptr;

    ImGui_ImplGlfw_InitForOpenGL(window.getWindowHandle(), true);
    ImGui_ImplOpenGL3_Init("#version 450");

    ImGuiStyle& style = ImGui::GetStyle();

    style.GrabRounding = 0.f;
    style.WindowRounding = 0.f;
    style.ScrollbarRounding = 3.f;
    style.FrameRounding = 2.f;
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
    style.WindowBorderSize = 1.0f;
    style.ChildBorderSize = 1.0f;
    style.FramePadding = ImVec2(2.0f, 2.0f);

    style.Colors[ImGuiCol_Text] = ImVec4(0.73f, 0.73f, 0.73f, 1.00f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.13f, 0.195f, 0.95f);
    style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.14f, 0.14f, 0.21f, 1.00f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.13f, 0.13f, 0.195f, 1.00f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.105f, 0.105f, 0.1575f, 1.00f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.105f, 0.105f, 0.1575f, 1.00f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.16f, 0.16f, 1.00f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.16f, 0.16f, 0.16f, 1.00f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.16f, 0.16f, 0.16f, 1.00f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.18f, 0.18f, 0.27f, 1.00f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.18f, 0.18f, 0.27f, 1.00f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.18f, 0.18f, 0.27f, 1.00f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.13f, 0.13f, 0.195f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.18f, 0.18f, 0.27f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.18f, 0.18f, 0.27f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.18f, 0.18f, 0.27f, 1.00f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.78f, 0.78f, 0.78f, 1.00f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.74f, 0.74f, 0.74f, 1.00f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.74f, 0.74f, 0.74f, 1.00f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.18f, 0.18f, 0.27f, 1.00f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.215f, 0.215f, 0.322f, 1.00f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.18f, 0.18f, 0.36f, 1.00f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.18f, 0.18f, 0.36f, 1.00f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.18f, 0.18f, 0.36f, 1.00f);
    style.Colors[ImGuiCol_Column] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
    style.Colors[ImGuiCol_ColumnHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    style.Colors[ImGuiCol_ColumnActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.18f, 0.18f, 0.36f, 1.00f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.32f, 0.52f, 0.65f, 1.00f);
    style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.20f, 0.20f, 0.20f, 0.50f);

    mono_set_dirs("Data/Mono/lib", "Data/Mono/etc");

    // MonoDomain* domain = mono_jit_init("ManagedEditor");
    // MonoAssembly* assembly = mono_domain_assembly_open(domain, "ManagedEngine.dll");
    // MonoAssembly* assembly2 = mono_domain_assembly_open(domain, "ManagedEditor.dll");
    // MonoImage* image = mono_assembly_get_image(assembly);
    // MonoClass* mClass = mono_class_from_name(image, "GDT.Editor", "EditorWindow");
    // 
    // MonoObject* instance = mono_object_new(domain, mClass);
    // 
    // auto method = find_method(mClass, "Draw");

    core::CCSDomain* pDomain = new core::CCSDomain("GDTEngine");
    core::CCSAssembly* pEngineAssembly = pDomain->openAssembly("ManagedEngine.dll");
    core::CCSAssembly* pEditorAssembly = pDomain->openAssembly("ManagedEditor.dll");
    core::CCSClass* pClass = pEditorAssembly->getClass("GDT.Editor", "EditorWindow");
    core::CCSObject* pObject = pDomain->newObject(pClass);
    core::CCSMethod* pDrawMethod = pClass->findMethod("Draw");

    mono_add_internal_call("GDT.Editor.EditorUI::Button", reinterpret_cast<void*>(CEditorUI::button));
    mono_add_internal_call("GDT.Editor.EditorUI::FloatField", reinterpret_cast<void*>(CEditorUI::floatField));
    mono_add_internal_call("GDT.Editor.EditorUI::IntField", reinterpret_cast<void*>(CEditorUI::intField));
    mono_add_internal_call("GDT.Editor.EditorUI::Lable", reinterpret_cast<void*>(CEditorUI::lable));
    mono_add_internal_call("GDT.Editor.EditorUI::TextArea", reinterpret_cast<void*>(CEditorUI::textArea));
    mono_add_internal_call("GDT.Editor.EditorUI::TextField", reinterpret_cast<void*>(CEditorUI::textField));

    while (true)
    {
        window.handleInput();
        core::CWindow::pollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::BeginMainMenuBar();

        if (ImGui::BeginMenu("File"))
        {
            ImGui::MenuItem("True");
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();

        ImGui::SetNextWindowPos(ImVec2(0.0f, 18.0f));
        ImGui::SetNextWindowSize(ImVec2(1280.0f, 52.0f));
        ImGui::Begin("", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);
        ImGui::Button("asd", ImVec2(36.0f, 36.0f));
        ImGui::SameLine();
        ImGui::Button("asd", ImVec2(36.0f, 36.0f));
        ImGui::SameLine();
        ImGui::Button("asd", ImVec2(36.0f, 36.0f));
        ImGui::SameLine();
        ImGui::Button("asd", ImVec2(36.0f, 36.0f));
        ImGui::SameLine();
        ImGui::Button("asd", ImVec2(36.0f, 36.0f));
        ImGui::SameLine();
        ImGui::Button("asd", ImVec2(36.0f, 36.0f));
        ImGui::SameLine();
        ImGui::Button("asd", ImVec2(36.0f, 36.0f));
        ImGui::End();


        ImGui::SetNextWindowPos(ImVec2(0.0f, 70.0f));
        ImGui::SetNextWindowSize(ImVec2(240.0f, 470.0f));
        ImGui::Begin("Scene Graph", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);
        ImGui::Button("Button");
        ImGui::End();

        ImGui::SetNextWindowPos(ImVec2(240.0f, 70.0f));
        ImGui::SetNextWindowSize(ImVec2(800.0f, 470.0f));
        ImGui::Begin("World Builder", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);

        ImGui::Button("World Builder", ImVec2(120, 0));
        ImGui::SameLine();
        ImGui::Button("Game", ImVec2(120, 0));

        ImGui::BeginChild("What", ImVec2(0, 0), true);
        ImGui::Button("Button");
        ImGui::Button("Button");
        ImGui::Button("Button");

        ImGui::Text("This is some useful text.");
        ImGui::SameLine();
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::EndChild();
        ImGui::End();

        ImGui::SetNextWindowPos(ImVec2(1040.0f, 70.0f));
        ImGui::SetNextWindowSize(ImVec2(240.0f, 650.0f));
        ImGui::Begin("Inspector", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
        ImGui::Button("Button");
        ImGui::Text("This is some useful text.");
        ImGui::SameLine();
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();

        ImGui::SetNextWindowPos(ImVec2(0.0f, 540.0f));
        ImGui::SetNextWindowSize(ImVec2(1040.0f, 180.0f));
        ImGui::Begin("Project", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
        
        pDrawMethod->call(pObject);

        ImGui::End();
        window.clear();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        window.display();
    }
}
