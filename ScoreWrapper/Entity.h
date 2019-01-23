#pragma once
#pragma once
#include "ManagedObject.h"
#include "../ScoreCore/ScoreCore.h"
using namespace System;
namespace ScoreWrapper
{
	public ref class Entity : public ManagedObject<ScoreCore::Entity>
	{
	public:

		Entity(String^ name, float xPos, float yPos);
		void Move(float deltaX, float deltaY);
		void DisplayImage(String^ path);
		String^ GetData();
		property float XPosition
		{
		public:
			float get()
			{
				return m_Instance->GetXPosition();
			}
		private:
			void set(float value)
			{
			}
		}
		property float YPosition
		{
		public:
			float get()
			{
				return m_Instance->GetYPosition();
			}
		private:
			void set(float value)
			{
			}
		}
	};
}