#include "Game.h"
#include "BoxObject.h"
#include <d3dcompiler.h>
#include "ConstantBuffer.h"

BoxObject::BoxObject(Game* game, Vertex* vertex, float boxSize) : GameObject(game, vertex), m_boxSize(boxSize)
{
	const std::vector<Vertex> vertices =
	{
		// Top vertices
		{
			{vertex->pos.x + boxSize, vertex->pos.y + boxSize, vertex->pos.z + boxSize},
			{vertex->color.R(), vertex->color.G(), vertex->color.B(), vertex->color.A()}
		},
		{
			{vertex->pos.x + boxSize, vertex->pos.y + boxSize, vertex->pos.z - boxSize},
			{vertex->color.R(), vertex->color.G(), vertex->color.B(), vertex->color.A()}
		},
		{
			{vertex->pos.x - boxSize, vertex->pos.y + boxSize, vertex->pos.z - boxSize},
			{vertex->color.R(), vertex->color.G(), vertex->color.B(), vertex->color.A()}
		},
		{
			{vertex->pos.x - boxSize, vertex->pos.y + boxSize, vertex->pos.z + boxSize},
			{vertex->color.R(), vertex->color.G(), vertex->color.B(), vertex->color.A()}
		},
		// Bottom vertices
		{
			{vertex->pos.x + boxSize, vertex->pos.y - boxSize, vertex->pos.z + boxSize},
			{vertex->color.R(), vertex->color.G(), vertex->color.B(), vertex->color.A()}
		},
		{
			{vertex->pos.x + boxSize, vertex->pos.y - boxSize, vertex->pos.z - boxSize},
			{vertex->color.R(), vertex->color.G(), vertex->color.B(), vertex->color.A()}
		},
		{
			{vertex->pos.x - boxSize, vertex->pos.y - boxSize, vertex->pos.z - boxSize},
			{vertex->color.R(), vertex->color.G(), vertex->color.B(), vertex->color.A()}
		},
		{
			{vertex->pos.x - boxSize, vertex->pos.y - boxSize, vertex->pos.z + boxSize},
			{vertex->color.R(), vertex->color.G(), vertex->color.B(), vertex->color.A()}
		}
	};

	const std::vector<unsigned short> indices =
	{
		0, 1, 3,
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
		4, 7, 5
	};
	indicesCount = std::size(indices);

	init(vertices, indices);
}

void BoxObject::preDraw()
{
	m_rotateDelta = static_cast<float>(DirectX::XM_PI) * m_game->deltaTime;
	
	const ConstantBuffer cb =
	{
		{
			Matrix::CreateRotationY(m_rotateDelta).Transpose()
		},
		m_game->gView.Transpose(),
		m_game->gProjection.Transpose(),
	};
	m_game->context->UpdateSubresource(pConstantBuffer.Get(), 0, NULL, &cb, 0, 0);
}
