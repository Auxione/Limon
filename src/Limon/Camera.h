#pragma once 

namespace limon {
	class Camera {
	public:
		Camera() = default;
		~Camera() = default;

	public:
		float x = 0;
		float y = 0;
		float width = 0;
		float height = 0;

	public:
		void Begin();
		void End();
	};
}