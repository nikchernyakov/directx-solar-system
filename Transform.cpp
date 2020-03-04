#include "Transform.h"

Transform::Transform(Vector3 pos) : m_position(pos)
{
}

Vector3 Transform::getPosition()
{
	return m_position;
}

void Transform::setPosition(Vector3 pos)
{
	m_position = pos;
}

void Transform::addPosition(Vector3 pos)
{
	m_position += pos;
}
