#include "CPlayer.h"
#include <SDL.h>

bool CPlayer::init()
{
	return true;
}

void CPlayer::update(double deltaTime)
{
}

void CPlayer::render()
{
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
}

void CPlayer::shutDown()
{
}
