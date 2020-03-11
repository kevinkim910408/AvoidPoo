#include "CObjMgr.h"
#include "CObject.h"

bool CObjMgr::init()
{
	return false;
}

void CObjMgr::update(double deltaTime)
{
	// iterator 생성
	list <CObject*>::iterator itrBegin; 
	list <CObject*>::iterator itrEnd; 

	//objectManager[] 이 array를 처음부터 끝까지 돌린다.
	for (int i = 0; i < OBJ_END; ++i)
	{
		//iterator begin,end에 array의 시작과 끝다음을 넣어준다
		itrBegin = objectManager[i].begin();
		itrEnd = objectManager[i].end();

		//이제 list를 하나하나 돌아준다.
		for (; itrBegin != itrEnd; ++itrBegin)
		{
			//*이유: iterator라서
			(*itrBegin)->update(deltaTime);
		}
	}
	
}

void CObjMgr::render()
{
	// iterator 생성
	list <CObject*>::iterator itrBegin;
	list <CObject*>::iterator itrEnd;

	//objectManager[] 이 array를 처음부터 끝까지 돌린다.
	for (int i = 0; i < OBJ_END; ++i)
	{
		//iterator begin,end에 array의 시작과 끝다음을 넣어준다
		itrBegin = objectManager[i].begin();
		itrEnd = objectManager[i].end();

		//이제 list를 하나하나 돌아준다.
		for (; itrBegin != itrEnd; ++itrBegin)
		{
			//*이유: iterator라서
			(*itrBegin)->render();
		}
	}
}

void CObjMgr::shutDown()
{
	// iterator 생성
	list <CObject*>::iterator itrBegin;
	list <CObject*>::iterator itrEnd;

	//objectManager[] 이 array를 처음부터 끝까지 돌린다.
	for (int i = 0; i < OBJ_END; ++i)
	{
		//iterator begin,end에 array의 시작과 끝다음이라고 어딘지 알려준다
		itrBegin = objectManager[i].begin();
		itrEnd = objectManager[i].end();

		//이제 list를 하나하나 돌아준다.
		for (; itrBegin != itrEnd; ++itrBegin)
		{
			//*이유: iterator라서, DEREFERENCING
			// 여기서는 값에 접근
			(*itrBegin)->shutDown();

			//(*itrBegin) = CObject*이런상태임, 그래서 얘를 지워주면, 오브젝트 하나하나를 다 지워줍니다.
			delete (*itrBegin);
		}
	}
}

//obj_index에 eunm을 넣어주고, object들을 obj에 넣어줘서 list에 object들을 추가해주는 함수
// generalize - cobject를 넣어줘서 모든 오브젝트를 넣을 수 있게(부모-자식)
void CObjMgr::addOBJ(CObject* obj, OBJ_ENUM obj_index)
{
		objectManager[obj_index].push_back(obj);
}