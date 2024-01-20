#ifndef SHAPECREATE2D_H
#define SHAPECREATE2D_H

#include "shapecreate2d_utilities.h"

class ShapeCreate2D {

	public:
		ShapeCreate2D() {};

		void ShapeCreate2DEvents(SDL_Event* events);
		void ShapeCreate2DUpdate();
		void ShapeCreate2DRender(SDL_Renderer* renderer);

		void AddPoint(const float x, const float y);
		void DeletePoint(const float x, const float y);

		void CreateShape(const bool fill);
		void DeleteShape();

	private:
		bool in_creation_;

		std::map<std::pair<float, float>, SDL_Vertex> vertices_; // Used to create a single shape
		std::pair<float, float> prev_point_; // Allows for undoing points

		std::map<std::pair<float, float>, Plane2D> shapes_; // Stores all shapes based on their center position (switch with stack container?)
};

#endif // SHAPECREATE2D_H