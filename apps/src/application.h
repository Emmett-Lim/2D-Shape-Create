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

		const int SCREEN_WIDTH{ 1600 };
		const int SCREEN_HEIGHT{ 768 };
	
		bool is_running_{ true };
	
		SDL_Window* window_{ nullptr };
		SDL_Renderer* renderer_{ nullptr };

		ShapeCreate2D& shapecreate2d_instance_ = ShapeCreate2D::ShapeCreate2DInstance();
		// SDL_Texture* texture_{ nullptr };
};

#endif // APPLICATION_H