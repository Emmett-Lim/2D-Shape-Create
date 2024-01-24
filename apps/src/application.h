#ifndef APPLICATION_H
#define APPLICATION_H

#include <core/shapecreate2d.h>

class Application {

	public:
		bool ApplicationInit();
		void ApplicationLoop();
		void ApplicationClose();
	
	private:
		void HandleEvents();
		void Update();
		void Render();

		const int SCREEN_WIDTH{ 1280 };
		const int SCREEN_HEIGHT{ 736 };
	
		bool is_running_{ true };
	
		SDL_Window* window_{ nullptr };
		SDL_Renderer* renderer_{ nullptr };
		// SDL_Texture* texture_{ nullptr };

		// ShapeCreate2D create_;
};

#endif // APPLICATION_H