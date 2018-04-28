#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::GameObject::GameObject()
{
	m_TransformComponent.m_pGameObject = this;
}

void dae::GameObject::RootUpdate(float elapsedSec)
{
	Update(elapsedSec);
	for (auto comp : m_pComponents) comp->Update(elapsedSec);
}

void dae::GameObject::RootRender()
{
	Render();
	for (auto comp : m_pComponents) comp->Render();
}

dae::GameObject::~GameObject()
{

	for(auto component : m_pComponents)
	{
		delete component;
		component = nullptr;
	}
}

void dae::GameObject::OnCollisionEnter(ColliderComponent* other)
{
	(other);
}

void dae::GameObject::SetTag(string tag)
{
	m_Tag = tag;
}

string dae::GameObject::GetTag()
{
	return m_Tag;
}

void dae::GameObject::SetScene(Scene* scene)
{
	m_pScene = scene;
}

dae::Scene* dae::GameObject::GetScene()
{
	return m_pScene;
}

void dae::GameObject::SetEnabled(const bool enable)
{
	m_IsEnabled = enable;
}

bool dae::GameObject::IsEnabled()
{
	return m_IsEnabled;
}

void dae::GameObject::Destroy()
{
	m_IsDestroyed = true;
}

bool dae::GameObject::IsDestroyed()
{
	return m_IsDestroyed;
}

void dae::GameObject::Update(float elapsedSec)
{
	for(auto component : m_pComponents)
	{
		component->Update(elapsedSec);
	}
}

void dae::GameObject::Render() const
{
	for(auto component : m_pComponents)
	{
		component->Render();
	}
}

void dae::GameObject::Translate(float x, float y, float z)
{
	m_TransformComponent.Translate(x, y, z);
}

void dae::GameObject::AddComponent(BaseComponent* component)
{
	m_pComponents.push_back(component);
	component->SetGameObject(this);
}

dae::TransformComponent* dae::GameObject::Transform()
{
	return &m_TransformComponent;
}



