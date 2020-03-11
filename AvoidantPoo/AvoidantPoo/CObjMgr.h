#pragma once
//Object Manger
#include <list>
#include "Enum.h"

using namespace std;

class CObject; // #include "CObject.h" 객체를 만드는게아니라, object의 타입만 알면되니까, 헤더에있는걸 다 가져올 필요가없다.

class CObjMgr
{
private:
	//오브젝트중에 똥이나 코인은 실시간으로 만들어야하기떄문에, 포인터로함. (new-delete)
	list <CObject*> objectManager[OBJ_END];
public:
	bool init();
	void update(double deltaTime);
	void render();
	void shutDown();

	void addOBJ(CObject* obj, OBJ_ENUM obj_index);

};

