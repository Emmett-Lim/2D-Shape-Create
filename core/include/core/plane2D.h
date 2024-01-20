#ifndef PLANE2D_H
#define PLANE2D_H

#include "utilities.h"

class Plane2D {
	
	public:
		Plane2D(const std::map<std::pair<float, float>, SDL_Vertex>& vertices, bool fill)
			: fill_(fill) { this->CreatePlane2D(vertices); }

		void CreatePlane2D(const std::map<std::pair<float, float>, SDL_Vertex>& vertices);

		std::pair<float, float> CalculateCentroid();

		void RenderPlane2D(SDL_Renderer* renderer);
	
	private:
		std::vector<SDL_Vertex> vertices_;
		std::vector<int> indices_;
		bool fill_;
};

#endif // PLANE2D_H