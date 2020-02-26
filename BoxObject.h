#pragma once

#include "GameObject.h"

class BoxObject : public GameObject
{

public:
	BoxObject(Game* game, Vertex* vertex, float boxSize);

	void preDraw();
private:
	float m_boxSize;
	float m_rotateDelta;
};

