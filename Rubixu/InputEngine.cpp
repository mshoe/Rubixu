#include "InputEngine.h"

InputEngine::InputEngine(Rubixu * rubixu)
{
	this->rubixu = rubixu;
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
			case SDLK_r:
				if (event.key.keysym.mod && KMOD_SHIFT) {
					rubixu->rubixu3->Ri();
					std::cout << "shift + r" << std::endl;
				}
				else {
					rubixu->rubixu3->R();
					std::cout << "r" << std::endl;
				}
				break;
			case SDLK_l:
				if (event.key.keysym.mod && KMOD_SHIFT) {
					rubixu->rubixu3->Li();
					std::cout << "shift + l" << std::endl;
				}
				else {
					rubixu->rubixu3->L();
					std::cout << "l" << std::endl;
				}
				break;
			case SDLK_u:
				if (event.key.keysym.mod && KMOD_SHIFT) {
					rubixu->rubixu3->Ui();
					std::cout << "shift + u" << std::endl;
				}
				else {
					rubixu->rubixu3->U();
					std::cout << "u" << std::endl;
				}
				break;
			case SDLK_d:
				if (event.key.keysym.mod && KMOD_SHIFT) {
					rubixu->rubixu3->Di();
					std::cout << "shift + d" << std::endl;
				}
				else {
					rubixu->rubixu3->D();
					std::cout << "d" << std::endl;
				}
				break;
			case SDLK_f:
				if (event.key.keysym.mod && KMOD_SHIFT) {
					rubixu->rubixu3->Fi();
					std::cout << "shift + f" << std::endl;
				}
				else {
					rubixu->rubixu3->F();
					std::cout << "f" << std::endl;
				}
				break;
			case SDLK_b:
				if (event.key.keysym.mod && KMOD_SHIFT) {
					rubixu->rubixu3->Bi();
					std::cout << "shift + b" << std::endl;
				}
				else {
					rubixu->rubixu3->B();
					std::cout << "b" << std::endl;
				}
				break;
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
			//if (glm::abs(event.motion.xrel) < 100 && glm::abs(event.motion.yrel < 100) && !stop_camera_direction)
			//std::cout << "Mouse : (" << event.motion.xrel << ", " << event.motion.yrel << ")" << std::endl;
			break;
		default:
			break;
		}
	}
}
