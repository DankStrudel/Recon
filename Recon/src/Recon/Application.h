#pragma once

#include "Core.h"

namespace Recon {

	class RECON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();

}
