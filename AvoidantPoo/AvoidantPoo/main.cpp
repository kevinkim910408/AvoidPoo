#include "CGame.h"

int main(int argc, char* args[])
{
	CGame GameInst;
	bool bResult = GameInst.init();
	if (bResult == true)
	{
		GameInst.render();
		
	}


	GameInst.shutDown();

	

	return 0;
}