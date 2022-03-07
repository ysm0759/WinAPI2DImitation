#pragma once
#include "Scene.h"

class SceneTool : public Scene
{
public:
	SceneTool();
	~SceneTool();


	virtual void update();
	virtual void enter();
	virtual void exit();
};

