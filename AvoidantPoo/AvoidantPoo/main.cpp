#include <SDL.h>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
SDL_Renderer* m_pRenderer = nullptr;
SDL_Window* m_pWindow = nullptr;

int main(int argc, char* args[])
{
	// Init SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "SDL INIT SUCCESS" << endl;

		//Create Window - 윈도우는 캔버스임
		m_pWindow = SDL_CreateWindow("Poo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
		if (m_pWindow != nullptr)
		{
			cout << "WINDOW INIT SUCCESS" << endl;

			//Create Renderer - 렌더러는 화가임
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != nullptr)
			{
				cout << "RENDERER INIT SUCCESS" << endl;
			}
			//만약 렌더러 이닛에 실패하면, 윈도우부수고, sdl도 나가야함 - 안그러면 memory leak
			else
			{
				cout << "RENDERER INIT FAILED" << endl;
				SDL_DestroyWindow(m_pWindow);
				SDL_Quit();
				return 0;
			}

		}
		//만약 윈도우 이닛에 실패하면 sdl 나가야함 - 안그러면 memory leak
		else
		{
			cout << "WINDOW INIT FAILED" << endl;
			SDL_Quit();
			return 0;
		}
	}
	//만약 SDL 이닛에 실패하면 그냥 실패했다고 띄워만 줘도 됌.
	else
	{
		cout << "SDL INIT FAILED" << endl;
	}

	while (true)
	{
		//Back buffer에 지울 색을 정해주고, 지운다.
		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(m_pRenderer);

		//Back buffer를 앞으로 빼준다.
		SDL_RenderPresent(m_pRenderer);
	}
	
	
	cout << "SYSTEM SHUT DOWN" << endl;
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();


	return 0;
}