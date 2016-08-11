#include "InputEngine.h"

InputEngine::InputEngine(Rubixu * rubixu)
{
	Init();
}

InputEngine::~InputEngine()
{
	CleanUp();
}

void InputEngine::Init()
{

}

void InputEngine::CleanUp()
{

}

void InputEngine::Keyboard()
{
	SDL_Event event;
	/* Poll for events. SDL_PollEvent() returns 0 when there are no  */
	/* more events on the event queue, our while loop will exit when */
	/* that occurs.                                                  */
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			
			case SDLK_SPACE:
				stop_camera_direction = !stop_camera_direction;
				std::cout << "space" << std::endl;
				break;
			default:
				break;
			}
		case SDL_MOUSEMOTION:
			// for some reason mouse goes crazy after you press a button
			// here is a ghetto solution
			if (glm::abs(event.motion.xrel) < 100 && glm::abs(event.motion.yrel < 100) && !stop_camera_direction)
			std::cout << "Mouse : (" << event.motion.xrel << ", " << event.motion.yrel << ")" << std::endl;
			break;
		default:
			break;
		}
	}
}
