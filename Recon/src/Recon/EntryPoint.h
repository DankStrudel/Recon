#pragma once

#ifdef RC_PLATFORM_WINDOWS

extern Recon::Application* Recon::CreateApplication();

int main(int argc, char** argv) {

	
	Recon::Log::Init();
	RC_CORE_WARN("Initiated Log!");
	int a = 5;
	RC_INFO("Hello! Var={0}", a);
	
	auto app = Recon::CreateApplication();
	app->Run();
	delete app;

}

#endif