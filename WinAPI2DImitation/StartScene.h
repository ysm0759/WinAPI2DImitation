#pragma once
#include "Scene.h"

class StartScene : public Scene
{
public:
	StartScene();
	virtual ~StartScene();

	virtual void enter();
	virtual void exit();
};

