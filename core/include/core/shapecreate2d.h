#ifndef SHAPECREATE2D_H
#define SHAPECREATE2D_H

#include "shapecreate2d_utilities.h"

class ShapeCreate2D {

	public:
		ShapeCreate2D() : in_creation_(false), cell_size_(32) {}

		void ShapeCreate2DEvents(SDL_Event* events);
		void ShapeCreate2DUpdate();
		void ShapeCreate2DRender(SDL_Renderer* renderer, const int SCREEN_WIDTH, const int SCREEN_HEIGHT);

		void AddPoint(const float x, const float y);
		void DeletePoint(const float x, const float y);

		void CreateShape(const bool fill);
		void DeleteShape(const size_t index);

	private:
		int cell_size_;
		bool in_creation_;

		std::map<std::pair<float, float>, SDL_Vertex> vertices_;
		std::map<std::pair<float, float>, Plane2D> added_points_;

		std::vector<Plane2D> shapes_;
};

#endif // SHAPECREATE2D_H