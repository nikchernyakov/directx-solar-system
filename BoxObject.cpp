#include "Game.h"
#include "BoxObject.h"
#include "ConstantBuffer.h"

BoxObject::BoxObject(Game* game, Vector3 position, Vector4 color, float boxSize)
	: GameObject(game, position, color), m_boxSize(boxSize)
{
	const std::vector<Vertex> vertices =
	{
		// Top vertices
		{
			{-boxSize, -boxSize, -boxSize}, color
		},
		{
			{-boxSize, +boxSize, -boxSize}, color
		},
		{
			{+boxSize, +boxSize, -boxSize}, color
		},
		{
			{ +boxSize, -boxSize, -boxSize}, color
		},
		// Bottom vertices
		{
			{-boxSize, -boxSize, +boxSize}, color
		},
		{
			{-boxSize, +boxSize, +boxSize}, color
		},
		{
			{+boxSize, +boxSize, +boxSize}, color
		},
		{
			{+boxSize, -boxSize, +boxSize}, color
		}
	};

	const std::vector<unsigned short> indices =
	{
		/*0, 1, 3,
		1, 2, 3,
		0, 4, 3,
		4, 7, 3,
		0, 5, 1,
		0, 4, 5,
		1, 5, 2,
		2, 5, 6,
		2, 6, 3,
		3, 6, 7,
		3, 7, 4,
		4, 7, 5*/
		
		// front face
		0, 1, 2,
		0, 2, 3,

		// back face
		4, 6, 5,
		4, 7, 6,

		// left face
		4, 5, 1,
		4, 1, 0,

		// right face
		3, 2, 6,
		3, 6, 7,

		// top face
		1, 5, 6,
		1, 6, 2,

		// bottom face
		4, 0, 3,
		4, 3, 7
	};
	indicesCount = std::size(indices);

	init(vertices, indices);
}

void BoxObject::preDraw()
{
	m_rotateDelta += static_cast<float>(DirectX::XM_PI) * m_game->deltaTime;
	//Matrix mWorld = ;
	//mWorld.Translation(transform.getPosition());
	const ConstantBuffer cb =
	{
		//mWorld.Transpose(),
		Matrix::CreateRotationY(m_rotateDelta).Transpose(),
		m_game->camera->getViewMatrix().Transpose(),
		m_game->camera->getProjectionMatrix().Transpose(),
	};
	m_game->context->UpdateSubresource(pConstantBuffer.Get(), 0, NULL, &cb, 0, 0);
}
