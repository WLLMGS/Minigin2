#include "MiniginPCH.h"
#include "TransformComponent.h"


dae::TransformComponent::TransformComponent() :
BaseComponent()
{
	m_Position = glm::vec3(0, 0, 0);
	m_Scale = glm::vec3(1, 1, 1);
	m_Angle = 0.0f;
}


dae::TransformComponent::~TransformComponent() = default;

void dae::TransformComponent::Update(float elapsedSec)
{
	UNREFERENCED_PARAMETER(elapsedSec);
}

void dae::TransformComponent::Render()
{
}

glm::vec3 dae::TransformComponent::GetPosition() const
{
	return m_Position;
}

glm::vec3 dae::TransformComponent::GetScale() const
{
	return m_Scale;
}

float dae::TransformComponent::GetAngle() const
{
	return m_Angle;
}

void dae::TransformComponent::Translate(float x, float y, float z)
{
	m_Position.x += x;
	m_Position.y += y;
	m_Position.z += z;
}

void dae::TransformComponent::SetScale(float x, float y, float z)
{
	m_Scale.x = x;
	m_Scale.y = y;
	m_Scale.z = z;
}

void dae::TransformComponent::SetRotation(const float angle)
{
	m_Angle = angle;
}
