#define SDL_MAIN_USE_CALLBACKS

#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_opengl.h>

static SDL_Window* window = nullptr;
static SDL_Renderer* renderer = nullptr;
static SDL_GLContext glContext = nullptr;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char** argv)
{
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("Error initializing SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

    // Tworzenie okna SDL
    window = SDL_CreateWindow("OpenGL in SDL", 800, 600, SDL_WINDOW_OPENGL);
    if (!window) 
    {
        SDL_Log("Error creating window: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    // Tworzenie kontekstu OpenGL
    glContext = SDL_GL_CreateContext(window);
    if (!glContext) 
    {
        SDL_Log("Error creating OpenGL context: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    // Inicjalizacja GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) 
    {
        SDL_Log("Error initializing GLEW");
        return SDL_APP_FAILURE;
    }

    // Ustawienia OpenGL (przyk³adowe)
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Ustawienie koloru t³a na czarny

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
	if (event->type == SDL_EVENT_QUIT || event->key.key == SDLK_ESCAPE) 
	{
		return SDL_APP_SUCCESS; 
	}

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate)
{
	

	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result)
{

}