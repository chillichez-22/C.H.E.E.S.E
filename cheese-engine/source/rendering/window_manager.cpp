

#include <SDL3/SDL.h>

#include "rendering/window_manager.hpp"


WindowManager::~WindowManager(){

    SDL_DestroyWindow( m_windowPtr );
    m_windowPtr = nullptr;

}