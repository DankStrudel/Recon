#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Recon/Events/ApplicationEvent.h"
#include "Window.h"

namespace Recon {

	class RECON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void onEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};

	//To be defined in CLIENT
	Application* CreateApplication();

}
