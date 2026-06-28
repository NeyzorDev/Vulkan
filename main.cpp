#include "Window.h"
#include "GraphicsMgr.h"


int main()
{
	Window* w = new Window();
	

	w->Initialize();
	GRAPHICSMGR->Initialize();

	w->MainLoop();

	GRAPHICSMGR->Shutdown();
	w->Shutdown();

	return 0;
}



