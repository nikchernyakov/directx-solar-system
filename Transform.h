#pragma once

#include <d3d11.h>
#include "SimpleMath.h"

using namespace DirectX::SimpleMath;

struct Transform
{
public:
	Transform() = default;
	Transform(Vector3 pos);
	~Transform() = default;

	Vector3 getPosition();
	void setPosition(Vector3 pos);
	void addPosition(Vector3 pos);

private:
	Vector3 m_position;
};

