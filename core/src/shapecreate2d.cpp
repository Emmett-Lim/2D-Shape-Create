#include "core/shapecreate2d.h"

void ShapeCreate2D::ShapeCreate2DEvents(SDL_Event* events) {

}

void ShapeCreate2D::ShapeCreate2DUpdate() {

}

void ShapeCreate2D::ShapeCreate2DRender(SDL_Renderer* renderer) {

}

void ShapeCreate2D::AddPoint(const float x, const float y) {

	std::pair<float, float> current_point{x, y};

	if (!this->vertices_.empty()) {

		this->prev_point_ = std::make_pair(this->vertices_.at(this->prev_point_).position.x,
										   this->vertices_.at(this->prev_point_).position.y);
	} else {

		this->prev_point_ = current_point;
	}
	
	SDL_Vertex new_vertex({x, y}, {255, 255, 255, 255}, {1, 1});
	this->vertices_.emplace(current_point, new_vertex);
}

void ShapeCreate2D::DeletePoint(const float x, const float y) {

	this->vertices_.erase(this->prev_point_);
}

void ShapeCreate2D::CreateShape(const bool fill) {
	
}

void ShapeCreate2D::DeleteShape() {

}