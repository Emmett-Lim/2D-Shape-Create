#include "core/shapecreate2d.h"

void ShapeCreate2D::ShapeCreate2DEvents(SDL_Event* events) {

}

void ShapeCreate2D::ShapeCreate2DUpdate() {

}

void ShapeCreate2D::ShapeCreate2DRender(SDL_Renderer* renderer) {
	
	for (auto it{ this->shapes_.begin() }; it != this->shapes_.end(); ++it) {

		it->RenderPlane2D(renderer);
	}
}

void ShapeCreate2D::AddPoint(const float x, const float y) {

	std::pair<float, float> new_point{x, y};
	SDL_Vertex new_vertex({x, y}, {255, 255, 255, 255}, {1, 1});

	this->inputted_points_.push(new_point);
	this->vertices_.emplace(new_point, new_vertex);
}

void ShapeCreate2D::DeletePoint(const float x, const float y) {

	this->inputted_points_.pop();
}

void ShapeCreate2D::CreateShape(const bool fill) {

	this->shapes_.push_back(Plane2D(this->vertices_, fill));
}

void ShapeCreate2D::DeleteShape(const size_t index) {

	this->shapes_.erase(this->shapes_.begin() + index);
}