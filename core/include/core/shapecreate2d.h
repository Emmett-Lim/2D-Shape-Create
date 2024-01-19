#ifndef SHAPECREATE2D_H
#define SHAPECREATE2D_H

#include "shapecreate2d_utilities.h"

// One instance of this class since main purpose is to manage planes, etc.
class ShapeCreate2D {

	public:
		static ShapeCreate2D& ShapeCreate2DInstance() {
			static ShapeCreate2D instance;
			return instance;
		}

		static void ShapeCreate2DEvents(SDL_Event* events);
		static void ShapeCreate2DUpdate();
		static void ShapeCreate2DRender(SDL_Renderer* renderer);

		static void CreateShape();
		static void CreateShapeCustom();

		// Non-static member functions here:

	private:
		// Private constructor to prevent instantiation
		ShapeCreate2D() {};
		// Private destructor to prevent deletion
		~ShapeCreate2D() {};

		// Non-static member variables here:

		// Private copy constructor and assignment operator to prevent copying
		ShapeCreate2D(const ShapeCreate2D&) = delete;
		ShapeCreate2D& operator=(const ShapeCreate2D&) = delete;
};

#endif // SHAPECREATE2D_H