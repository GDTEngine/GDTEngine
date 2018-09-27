/**
 * @file     KeyCode.hpp
 * @author   Ludvig Arlebrink
 * @date     9/28/2018
 */

#pragma once

#include "BaseTypes.hpp"

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

namespace gdt
{
    namespace core
    {
        enum class EKeyCode : int32
        {
            /** Key 0. */
            Key0 = GLFW_KEY_0,

            /** Key 1. */
            Key1 = GLFW_KEY_1,

            /** Key 2. */
            Key2 = GLFW_KEY_2,

            /** Key 3. */
            Key3 = GLFW_KEY_3,

            /** Key 4. */
            Key4 = GLFW_KEY_4,

            /** Key 5. */
            Key5 = GLFW_KEY_5,

            /** Key 6. */
            Key6 = GLFW_KEY_6,

            /** Key 7. */
            Key7 = GLFW_KEY_7,

            /** Key 8. */
            Key8 = GLFW_KEY_8,

            /** Key 9. */
            Key9 = GLFW_KEY_9,

            /** Key A. */
            KeyA = GLFW_KEY_A,

            /** Key B. */
            KeyB = GLFW_KEY_B,

            /** Key C. */
            KeyC = GLFW_KEY_C,

            /** Key D. */
            KeyD = GLFW_KEY_D,

            /** Key E. */
            KeyE = GLFW_KEY_E,

            /** Key F. */
            KeyF = GLFW_KEY_F,

            /** Key G. */
            KeyG = GLFW_KEY_G,

            /** Key H. */
            KeyH = GLFW_KEY_H,

            /** Key H. */
            KeyI = GLFW_KEY_I,

            /** Key J. */
            KeyJ = GLFW_KEY_J,

            /** Key K. */
            KeyK = GLFW_KEY_K,

            /** Key L. */
            KeyL = GLFW_KEY_L,

            /** Key M. */
            KeyM = GLFW_KEY_M,

            /** Key N. */
            KeyN = GLFW_KEY_N,

            /** Key O. */
            KeyO = GLFW_KEY_O,

            /** Key P. */
            KeyP = GLFW_KEY_P,

            /** Key Q. */
            KeyQ = GLFW_KEY_Q,

            /** Key R. */
            KeyR = GLFW_KEY_R,

            /** Key S. */
            KeyS = GLFW_KEY_S,

            /** Key T. */
            KeyT = GLFW_KEY_T,

            /** Key U. */
            KeyU = GLFW_KEY_U,

            /** Key V. */
            KeyV = GLFW_KEY_V,

            /** Key W. */
            KeyW = GLFW_KEY_W,

            /** Key X. */
            KeyX = GLFW_KEY_X,

            /** Key Y. */
            KeyY = GLFW_KEY_Y,

            /** Key Z. */
            KeyZ = GLFW_KEY_Z,

            /** Key right. */
            KeyRight = GLFW_KEY_RIGHT,

            /** Key left. */
            KeyLeft = GLFW_KEY_LEFT,

            /** Key down. */
            KeyDown = GLFW_KEY_DOWN,

            /** Key up. */
            KeyUp = GLFW_KEY_UP,
        };
    }
}
