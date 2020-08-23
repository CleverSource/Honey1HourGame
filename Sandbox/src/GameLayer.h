#pragma once

#include "Honey.h"

#include "Level.h"
#include <imgui/imgui.h>

class GameLayer : public Honey::Layer
{
public:
	GameLayer();
	virtual ~GameLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Honey::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Honey::Event& e) override;
	bool OnMouseButtonPressed(Honey::MouseButtonPressedEvent& e);
	bool OnWindowResize(Honey::WindowResizeEvent& e);
private:
	void CreateCamera(uint32_t width, uint32_t height);
private:
	Honey::Scope<Honey::OrthographicCamera> m_Camera;
	Level m_Level;
	ImFont* m_Font;
	float m_Time = 0.0f;
	bool m_Blink = false;

	enum class GameState
	{
		Play = 0, MainMenu = 1, GameOver = 2
	};

	GameState m_State = GameState::MainMenu;
};