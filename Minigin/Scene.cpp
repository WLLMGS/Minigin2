#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "ColliderComponent.h"
#include <algorithm>

unsigned int dae::Scene::idCounter = 0;

dae::Scene::Scene(const std::string& name) : mName(name) { }


dae::Scene::~Scene()
{
	for(GameObject* object: m_pGameObjects)
	{
		delete object;
		object = nullptr;
	}
}

void dae::Scene::Destroy(size_t index)
{
	delete m_pGameObjects[index];
	m_pGameObjects[index] = nullptr;

	m_pGameObjects.erase(remove(m_pGameObjects.begin(), m_pGameObjects.end(), m_pGameObjects[index]), m_pGameObjects.end());
}

void dae::Scene::AddChild(GameObject* obj)
{
	m_pGameObjects.push_back(obj);
	obj->SetScene(this);
}

void dae::Scene::RootUpdate(float elapsedSec)
{
	Update(elapsedSec);
	/*for (auto gameObject : m_pGameObjects)*/
	for (size_t t{0}; t < m_pGameObjects.size(); ++t)
	{
		auto gameObject = m_pGameObjects[t];

		if(!gameObject->IsDestroyed())
		{
			if (gameObject->IsEnabled())
			{
				gameObject->RootUpdate(elapsedSec);
			}

			//do collision
			if (gameObject->GetComponent<ColliderComponent>())
			{
				if (gameObject->GetComponent<ColliderComponent>()->IsDynamic() && gameObject->IsEnabled())
				{
					for (auto other : m_pGameObjects)
					{
						if (other->GetComponent<ColliderComponent>() && other != gameObject && gameObject->IsEnabled())
						{
							gameObject->GetComponent<ColliderComponent>()->CheckCollision(other->GetComponent<ColliderComponent>());
						}
					}
				}
			}
		}
		else
		{
			//destroy
			Destroy(t);
		}
		
	}

	
}

void dae::Scene::RootRender()
{
	Render();
	for (const auto gameObject : m_pGameObjects)
	{
		if(gameObject->IsEnabled())	gameObject->RootRender();
	}

	Logger::GetInstance().Render();
}

void dae::Scene::RootPostUpdate()
{
	

	
}

void dae::Scene::Update(float elapsedSec)
{
	UNREFERENCED_PARAMETER(elapsedSec);
}

void dae::Scene::Render() const
{
	
}

string dae::Scene::GetName() const
{
	return mName;
}

