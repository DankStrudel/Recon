#include "Application.h"

#include "Recon/Events/ApplicationEvent.h"
#include "Recon/Log.h"

namespace Recon {


	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {

		WindowResizedEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			RC_TRACE("We are in App!");
			RC_WARN(e);
		}
		while (true);
	}

}