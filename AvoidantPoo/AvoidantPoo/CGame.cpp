#include "CGame.h"
#include "CObjMgr.h"
#include <iostream>

using namespace std;

bool CGame::init()
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
				return false;
			}

		}
		//만약 윈도우 이닛에 실패하면 sdl 나가야함 - 안그러면 memory leak
		else
		{
			cout << "WINDOW INIT FAILED" << endl;
			SDL_Quit();
			return false;
		}

		// Create Image / jpg와 png flag 비트를 합쳐서 하나로 뭉쳐준다.
		int iImgInitFlags = IMG_INIT_JPG | IMG_INIT_PNG;
		int iResult = IMG_Init(iImgInitFlags);
		if ((iResult & iImgInitFlags) == iImgInitFlags)
		{
			cout << "IMAGE INIT SUCCESS" << endl;
		}
		else
		{
			cout << "IMAGE INIT FAILED" << endl;
			SDL_DestroyRenderer(m_pRenderer);
			SDL_DestroyWindow(m_pWindow);
			SDL_Quit();
			return false;
		}
	}
	//만약 SDL 이닛에 실패하면 그냥 실패했다고 띄워만 줘도 됌.
	else
	{
		cout << "SDL INIT FAILED" << endl;
		return false;
	}

	//Create Surface
	m_pSurface = IMG_Load("Assets/Coin.png");
	if (m_pSurface == nullptr)
	{
		cout << "Assets / Coin.png - IMG LOAD FAIELD(surface)" << endl;
		return false;
	}
	//Create Texture
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pSurface);
	if (m_pTexture == nullptr)
	{
		cout << "TEXTURE LOAD FAIELD" << endl;
		SDL_FreeSurface(m_pSurface);
		return false;
	}
	SDL_FreeSurface(m_pSurface);

	//objMgr 객체 생성
	m_pObjMgr = new CObjMgr;

	//생성된 객체를 오브젝트매니저에 넣어줌
	//m_pObjMgr->addOBJ(NEW플레이어,OBJ_PLAYER)
	//m_pObjMgr->addOBJ(똥,OBJ_PLAYER)
	//m_pObjMgr->addOBJ(코인,OBJ_PLAYER)
	//m_pObjMgr->addOBJ(버튼,OBJ_PLAYER)

	m_pObjMgr->init();

	return true;
}



void CGame::update(double deltaTime)
{
	m_pObjMgr->update(deltaTime);
}

void CGame::render()
{
	while (true)
	{
		//Back buffer에 지울 색을 정해주고, 지운다.
		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(m_pRenderer);

		m_pObjMgr->render();

		////Back buffer에 그린다.
		//SDL_Rect m_srcRect;
		//m_srcRect.x = 0;
		//m_srcRect.y = 0;
		//m_srcRect.w = 95;
		//m_srcRect.h = 97;

		//SDL_Rect m_dstRect;
		//m_dstRect.x = SCREEN_WIDTH * 0.5;
		//m_dstRect.y = SCREEN_HEIGHT * 0.5;
		//m_dstRect.w = 95;
		//m_dstRect.h = 97;

		//SDL_RenderCopy(m_pRenderer, m_pTexture, &m_srcRect, &m_dstRect);

		//Back buffer를 앞으로 빼준다.
		SDL_RenderPresent(m_pRenderer);
	}
}

void CGame::shutDown()
{
	m_pObjMgr->shutDown();

	cout << "SYSTEM SHUT DOWN" << endl;
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
}

