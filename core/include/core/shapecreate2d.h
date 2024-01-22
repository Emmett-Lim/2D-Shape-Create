#ifndef SHAPECREATE2D_H
#define SHAPECREATE2D_H

#include "shapecreate2d_utilities.h"

class ShapeCreate2D {

	public:
		ShapeCreate2D() : in_creation_(false) {}

		void ShapeCreate2DEvents(SDL_Event* events);
		void ShapeCreate2DUpdate();
		void ShapeCreate2DRender(SDL_Renderer* renderer);

		void AddPoint(const float x, const float y);
		void DeletePoint(const float x, const float y);

		void CreateShape(const bool fill);
		void DeleteShape(const size_t index);

	private:
		bool in_creation_;

		std::map<std::pair<float, float>, SDL_Vertex> vertices_; // Holds vertices of a shape

		std::stack<std::pair<float, float>> inputted_points_; // Allows for undoing previously made points
		std::vector<Plane2D> shapes_; // Allows for undoing previously made shapes
};

#endif // SHAPECREATE2D_H