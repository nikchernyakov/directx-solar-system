#include "Game.h"
#include "PyramidObject.h"
#include "ConstantBuffer.h"

using namespace DirectX;

PyramidObject::PyramidObject(Game* game, Vector3 position, Vector4 color) : GameObject(game, position, color)
{

	// �������� ������ ������ (���� ����� ��������)
	const std::vector<Vertex> vertices =
	{
		/* ���������� X, Y, Z				���� R, G, B, A					 */
		{XMFLOAT3(0.0f, 1.5f, 0.0f), XMFLOAT4(1.0f, 1.0f, 0.0f, 1.0f)},
		{XMFLOAT3(-1.0f, 0.0f, -1.0f), XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f)},
		{XMFLOAT3(1.0f, 0.0f, -1.0f), XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f)},
		{XMFLOAT3(-1.0f, 0.0f, 1.0f), XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f)},
		{XMFLOAT3(1.0f, 0.0f, 1.0f), XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f)}
	};

	// �������� ������ ��������:
	// �������� ������� � �������
	const std::vector<unsigned short> indices =
	{
		// ������� ������� vertices[], �� ������� �������� ������������
		0, 2, 1, /* ����������� 1 = vertices[0], vertices[2], vertices[3] */
		0, 3, 4, /* ����������� 2 = vertices[0], vertices[3], vertices[4] */
		0, 1, 3, /* � �. �. */
		0, 4, 2,
		1, 2, 3,
		2, 4, 3,
	};

	indicesCount = std::size(indices);

	init(vertices, indices);
}

void PyramidObject::preDraw()
{
	m_rotateDelta += static_cast<float>(DirectX::XM_PI) * m_game->deltaTime;
	
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
