#include "Window.h"
#include "GraphicsMgr.h"


int main()
{
	WINDOWMGR->Initialize();
	GRAPHICSMGR->Initialize();

	WINDOWMGR->MainLoop();

	GRAPHICSMGR->Shutdown();
	WINDOWMGR->Shutdown();

	return 0;
}



