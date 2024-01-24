#include "core/shapecreate2d.h"

void ShapeCreate2D::ShapeCreate2DEvents(SDL_Event* events) {

	/* < CONTROLS >
	* shift = enter/exit creation mode
	* l_mouse button = add point
	* hover -> r_mouse button = delete created point
	* ctrl (while in creation mode) = precision placement
	*/
}

void ShapeCreate2D::ShapeCreate2DUpdate() {

}

void ShapeCreate2D::ShapeCreate2DRender(SDL_Renderer* renderer, const int SCREEN_WIDTH, const int SCREEN_HEIGHT) {
	
	for (auto it{ this->shapes_.begin() }; it != this->shapes_.end(); ++it) {

		it->RenderPlane2D(renderer);
	}

	if (this->in_creation_) {

		SDL_SetRenderDrawColor(renderer, 156, 156, 156, 255);

		for (int x{ this->cell_size_ }; x < SCREEN_WIDTH; x += this->cell_size_) {

			SDL_RenderDrawLine(renderer, x, 0, x, SCREEN_HEIGHT);
		}

		for (int y{ this->cell_size_ }; y < SCREEN_HEIGHT; y += this->cell_size_) {

			SDL_RenderDrawLine(renderer, 0, y, SCREEN_WIDTH, y);
		}

		for (auto it{ this->added_points_.begin() }; it != this->added_points_.end(); ++it) {

			it->second.RenderPlane2D(renderer);
		}
	}
}

void ShapeCreate2D::AddPoint(const float x, const float y) {

	std::pair<float, float> new_point{x, y};
	SDL_Vertex new_vertex({x, y}, {255, 255, 255, 255}, {1, 1});

	this->vertices_.emplace(new_point, new_vertex);
	this->added_points_.emplace(new_point, Plane2D(new_vertex));
}

void ShapeCreate2D::DeletePoint(const float x, const float y) {

	if (this->in_creation_) {

		std::pair<float, float> target_point{ x, y };

		this->vertices_.erase(target_point);
		this->added_points_.erase(target_point);
	}
}

void ShapeCreate2D::CreateShape(const bool fill) {

	this->shapes_.push_back(Plane2D(this->vertices_, fill));

	this->vertices_.clear();
	this->added_points_.clear();

	this->in_creation_ = false;
}

void ShapeCreate2D::DeleteShape(const size_t index) {

	if (!this->in_creation_) {

		this->shapes_.erase(this->shapes_.begin() + index);
	}
}