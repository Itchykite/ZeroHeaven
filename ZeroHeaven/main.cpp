#define SDL_MAIN_USE_CALLBACKS

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_init.h>

static SDL_Window* window = nullptr;
static SDL_Renderer* renderer = nullptr;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char** argv)
{
	SDL_SetAppMetadata("Test", "1.0", "com.example.test");

	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("Error initializing SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	if (!SDL_CreateWindowAndRenderer("examples/renderer/lines", 640, 480, 0, &window, &renderer))
	{
		SDL_Log("Error creating window/renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
	if (event->type == SDL_EVENT_QUIT) 
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