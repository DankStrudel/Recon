#include "rcpch.h"
#include "Application.h"

#include "GLFW/glfw3.h"

namespace Recon {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)


	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(onEvent));
	}

	void Application::onEvent(Event& e) {
		
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		
		RC_CORE_TRACE("{0}",e);
	}

	Application::~Application() {

	}

	void Application::Run() {
		while (m_Running) {

			glClearColor(0.54,0.168,0.886,1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}
}