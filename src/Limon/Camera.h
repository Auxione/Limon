#pragma once
#include "Vector2f.h"

namespace limon {
	class Camera {
	public:
		Vector2f position;
		Vector2f size;
		float scale;

		void ScreenToWorld(double& x, double& y);
	public:
		void Begin();
		void End();
	};
}