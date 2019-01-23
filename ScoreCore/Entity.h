#pragma once
#include <string>
namespace ScoreCore
{
	class Entity
	{
	public:
		const char* m_Name;
	private:
		float m_XPos, m_YPos;
		char* data;
	public:
		Entity(const char* name, float xPos, float yPos);
		void DisplayImage(const char*);
		char* GetData();
		void Move(float deltaX, float deltaY);
		inline float GetXPosition() const { return m_XPos; };
		inline float GetYPosition() const { return m_YPos; };
	};
}