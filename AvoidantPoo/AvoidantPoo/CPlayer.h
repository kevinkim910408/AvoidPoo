#pragma once
#include "CObject.h"


class CPlayer : public CObject
{
private:

public:
	bool init();
	void update(double deltaTime);
	void render();
	void shutDown();
};

