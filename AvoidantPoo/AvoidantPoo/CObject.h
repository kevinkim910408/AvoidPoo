#ifndef _COBJECT_H_
#define _COBJECT_H_

class CObject 
{
private:

public:
	bool init();
	void update(double deltaTime);
	void render();
	void shutDown();
};



#endif	