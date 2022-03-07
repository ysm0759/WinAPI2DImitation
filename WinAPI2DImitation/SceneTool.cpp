#include "framework.h"
#include "SceneTool.h"

SceneTool::SceneTool()
{
}

SceneTool::~SceneTool()
{
}

void SceneTool::update()
{
	Scene::update();

	if (KEYDOWN(VK_ESCAPE))
	{
		CHANGESCN(GROUP_SCENE::START_SCENE);
	}
}

void SceneTool::enter()
{
}

void SceneTool::exit()
{
}
