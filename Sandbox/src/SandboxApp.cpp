#include <Recon.h>

class Sandbox : public Recon::Application {

public:
	Sandbox() {

	}

	~Sandbox() {

	}

};

Recon::Application* Recon::CreateApplication() {
	return new Sandbox();
}
