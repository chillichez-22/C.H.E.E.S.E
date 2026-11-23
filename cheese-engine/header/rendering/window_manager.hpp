#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>

class WindowManager{

private:

    SDL_Window* m_windowPtr = nullptr;   /*< Pointer to the SDL window. */


private:

    /**
     * @brief Runs initialisations on the window manager.
     */
    void initialise();


public:

    /**
     * @brief Default constructor for the window manager.
     */
    WindowManager() = default;

    /**
     * @brief Destructor for the window manager.
     */
    ~WindowManager();



    // Getters

    /**
     * @brief Getter for the window.
     * 
     * @returns `SDL_Window*&" - Reference to the window pointer.
     */
    SDL_Window*& getWindow();

};