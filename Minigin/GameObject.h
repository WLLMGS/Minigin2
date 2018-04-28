#pragma once
#include <vector>

#include "TransformComponent.h"
#include "ColliderComponent.h"

using namespace std;

namespace dae
{
	class Scene;

	class GameObject
	{
	public:
		GameObject();
		void RootUpdate(float elapsedSec);
		void RootRender();
		void Translate(float x, float y, float z);
		void AddComponent(BaseComponent* component);
		TransformComponent* Transform();


		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		virtual void OnCollisionEnter(ColliderComponent* other);
		void SetTag(string tag);
		string GetTag();

		void SetScene(Scene* scene);
		Scene* GetScene();
		void SetEnabled(const bool enable);
		bool IsEnabled();
		void Destroy();
		bool IsDestroyed();

	public:
		template<class T> T* GetComponent()
		{
			const type_info& ti = typeid(T);
			for (auto *component : m_pComponents)
			{
				if (component && typeid(*component) == ti)
					return static_cast<T*>(component);
			}
			return nullptr;
		}
	protected:
		virtual void Update(float elapsedSec);
		virtual void Render() const;

	private:
		string m_Tag = "Default";
		Scene* m_pScene;
		//Texture2D* m_pTexture2D;
		TransformComponent m_TransformComponent;
		vector<BaseComponent*> m_pComponents;
		bool m_IsEnabled = true;
		bool m_IsDestroyed = false;
	};
}
