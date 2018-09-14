#pragma once

/**
 * A window with an OpenGL context.
 */
class CRenderWindow final
{
public:
    /**
     * @breif Default constructor.
     */
    CRenderWindow();

    /**
     * @breif Copy constructor deleted.
     */
    CRenderWindow(const CRenderWindow& other) = delete;

    /**
     * @breif Destructor.
     */
    ~CRenderWindow();
};
