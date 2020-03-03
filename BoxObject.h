#pragma once

#include "GameObject.h"

class BoxObject : public GameObject
{

public:
	BoxObject(Game* game, Vector3 position, Vector4 color, float boxSize);

	void preDraw();
private:
	float m_boxSize;
	float m_rotateDelta;
};

