#ifndef PLANE2D_H
#define PLANE2D_H

#include "utilities.h"

class Plane2D {
	
	public:
		Plane2D(const std::map<std::pair<float, float>, SDL_Vertex>& vertices,
			const bool fill)
			: fill_(fill) {
			this->CreatePlane2D(vertices);
		}
		Plane2D(const SDL_Vertex& center_pos);

		void CreatePlane2D(const std::map<std::pair<float, float>, SDL_Vertex>& vertices);
		void CreateCircle2D(const SDL_Vertex& center_pos);

		std::pair<float, float> CalculateCentroid();

		void RenderPlane2D(SDL_Renderer* renderer);
	
	private:
		std::vector<SDL_Vertex> vertices_;
		std::vector<int> indices_;
		bool fill_;
};

#endif // PLANE2D_H