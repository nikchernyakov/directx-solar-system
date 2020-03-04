#pragma once

#include <d3d11.h>
#include "SimpleMath.h"
#include "Transform.h"

class Game;
using namespace DirectX::SimpleMath;

class Camera
{
public:
	Camera(Game* game, Vector3 position);
	~Camera();

	Matrix getViewMatrix();
	Matrix getProjectionMatrix() const;

	void rotate(float dx, float dy);
	void translate(Vector3 translation);

private:
	Transform transform;

	float yaw = 0;
	float pitch = 0;

	float rotationSpeed = 0.05;
	float moveSpeed = 0.1;
	
	Matrix projectionMatrix;
	
};

