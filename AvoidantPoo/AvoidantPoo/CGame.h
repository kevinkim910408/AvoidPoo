#ifndef _CGAME_H_
#define _CGAME_H_

#include <SDL.h>
#include <SDL_image.h>


class CGame
{
private:
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	SDL_Renderer* m_pRenderer = nullptr;
	SDL_Window* m_pWindow = nullptr;
	SDL_Surface* m_pSurface = nullptr;
	SDL_Texture* m_pTexture = nullptr;

public:
	bool init();
	void update(double deltaTime);
	void render();
	void shutDown();
};


#endif