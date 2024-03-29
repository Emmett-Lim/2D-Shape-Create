#include "application.h"

bool Application::ApplicationInit() {

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {

		std::cerr << "SDL failed to intialize! Error: " << SDL_GetError() << "\n";
		return false;
	}

	window_ = SDL_CreateWindow("2D Shape Creator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window_ == nullptr) {

		std::cerr << "Window failed to initialize! Error: " << SDL_GetError() << "\n";
		return false;
	}

	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer_ == nullptr) {

		std::cerr << "Renderer failed to initialize! Error: " << SDL_GetError() << "\n";
		return false;
	}

	/* Remove comment if needed
	int img_flags{ IMG_INIT_PNG };
	if (!(IMG_Init(img_flags) & img_flags)) {

		std::cerr << "SDL_Image failed to initialize! Error: " << IMG_GetError() << "\n";
		return false;
	}
	*/

	return true;
}

void Application::ApplicationLoop() {

	while (is_running_) {

		HandleEvents();
		Update();
		Render();
	}
}

void Application::HandleEvents() {

	SDL_Event e;

	while (SDL_PollEvent(&e)) {

		if (e.type == SDL_QUIT) {

			is_running_ = false;
		}
	}

	const Uint8* key_states = SDL_GetKeyboardState(nullptr);

	if (key_states[SDL_SCANCODE_ESCAPE]) {

		is_running_ = false;
	}

}

void Application::Update() {

}

void Application::Render() {

	SDL_SetRenderDrawColor(renderer_, 40, 40, 40, 225);
	SDL_RenderClear(renderer_);

	SDL_RenderPresent(renderer_);
}

void Application::ApplicationClose() {

	//SDL_DestroyTexture(texture_);
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);

	// IMG_Quit();
	SDL_Quit();
}