#include "Game.h"
#include "Camera.h"
#include "GameMath.h"

Camera::Camera(Game* game, Vector3 position)
{
	transform.setPosition(position);

	projectionMatrix = Matrix::CreatePerspectiveFieldOfView(
		60, static_cast<float>(game->screenWidth) / static_cast<float>(game->screenHeight),
		0.01f, 100.0f);
}

Camera::~Camera()
{
}

Matrix Camera::getViewMatrix()
{
	Vector3 target = { 0, 2, 2 };
	target.Transform(target, Matrix::CreateFromYawPitchRoll(yaw, pitch, 0));
	target += transform.getPosition();
	Vector3 up = { 0, -1, 0 };
	return Matrix::CreateLookAt(transform.getPosition(), target, up);
}

Matrix Camera::getProjectionMatrix() const
{
	return projectionMatrix;
}

void Camera::rotate(float dx, float dy)
{
	yaw = wrap_angle(yaw + dx * rotationSpeed);
	pitch = clamp(pitch + dy * rotationSpeed, 0.995f * -DirectX::XM_PIDIV2, 0.995f * -DirectX::XM_PIDIV2);
}

void Camera::translate(Vector3 translation)
{
	XMStoreFloat3(&translation, DirectX::XMVector3Transform(
		DirectX::XMLoadFloat3(&translation),
		DirectX::XMMatrixRotationRollPitchYaw(pitch, yaw, 0.0f) *
		DirectX::XMMatrixScaling(moveSpeed, moveSpeed, moveSpeed)
	));
	transform.addPosition({
		translation.x,
		translation.y,
		translation.z
		}
	);
}
