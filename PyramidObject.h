#pragma once

#include "GameObject.h"

class PyramidObject : public GameObject
{

public:
	PyramidObject(Game* game, Vertex* vertex);

	void preDraw();
private:
	float m_rotateDelta;
};

