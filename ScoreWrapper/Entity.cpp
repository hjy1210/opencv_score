#include "Entity.h"
#include <string>
namespace ScoreWrapper
{
	Entity::Entity(String^ name, float xPos, float yPos)
		: ManagedObject(new ScoreCore::Entity(string_to_char_array(name), xPos, yPos))
	{
		Console::WriteLine("Creating a new Entity-wrapper object!");
	}
	void Entity::Move(float deltaX, float deltaY)
	{
		Console::WriteLine("The Move method from the Wrapper was called!");
		m_Instance->Move(deltaX, deltaY);
	}
	void Entity::DisplayImage(String^ path) {
		m_Instance->DisplayImage(string_to_char_array(path));
	}
	String^ Entity::GetData() {
		return gcnew String(m_Instance->GetData());
	}
}