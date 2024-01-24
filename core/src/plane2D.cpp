#include "core/plane2d.h"

void Plane2D::CreatePlane2D(const std::map<std::pair<float, float>,
	SDL_Vertex>& vertices) {

	// Calculate distance using set of points P = {A, B, C} to target = D
	// Get two points from P with least distance to D to connect with

	/*
	size_t count{ 0 };
	for (auto i{ vertices.begin() }; i != vertices.end(); ++i) {

		if ((count >= 2) && this->fill_) {

			for (int amnt{ 2 }; amnt >= 0; --amnt) {

				this->indices_.push_back(static_cast<int>(count) - amnt);
			}
		}

		this->vertices_.push_back(i->second);

		++count;
	}
	*/

	for (auto i{ vertices.begin() }; i != vertices.end(); ++i) {

		this->vertices_.push_back(i->second);
	}
}

void Plane2D::CreateCircle2D(const SDL_Vertex& center_pos) {

	float error{ 0.25f };
	float radius{ 10.0f };
	float rad{ 2.0f * static_cast<float>(M_PI) };

	int num_sides{ static_cast<int>(floor(M_PI / acos(1 - error / radius))) };

	float x_pos{ center_pos.position.x };
	float y_pos{ center_pos.position.y };

	this->vertices_.push_back(center_pos);

	for (int i{ 1 }; i <= num_sides; ++i) {

		// Calculate inner angles of a polygon based on number of sides, then place points regarding the angle
		float angle{ (rad / num_sides) * i };

		float x_vertexpos{ x_pos + radius * cos(angle) };
		float y_vertexpos{ y_pos + radius * sin(angle) };

		// Push all vertices into std::vector for drawing onto window
		this->vertices_.push_back({ { x_vertexpos, y_vertexpos }, { 95, 131, 250, 125 }, { 1, 1 } });

		// Form a triangle with three points, main point being the center of circle
		this->indices_.push_back(0);
		this->indices_.push_back(i);
		this->indices_.push_back((i % num_sides) + 1);
	}
}

void Plane2D::RenderPlane2D(SDL_Renderer* renderer) {

	if (this->fill_) {

		SDL_RenderGeometry(renderer, nullptr,
						   this->vertices_.data(), static_cast<int>(this->vertices_.size()),
						   this->indices_.data(), static_cast<int>(this->indices_.size()));
	}
	else {

		// Start from common point (least (x, y)), draw two lines connecting to adjacent point
		// One line connect to point with high y value, other with low y value
		// Odd vertices: lines end same point
		// Even vertices: connect one of the lines to other point
		// Note ~ x-dir from least to greatest; starting 3 points x must !=
		// Time complexity = O(n)?
	}
}