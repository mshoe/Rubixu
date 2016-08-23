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
				if (rubixu->rubixu3->rotatingFace == 0 && !rubixu->rubixu3->scramble) {
					if (event.key.keysym.mod && KMOD_SHIFT) {
						rubixu->rubixu3->rotatingFace = 2;
						std::cout << "shift + r" << std::endl;
					}
					else {
						rubixu->rubixu3->rotatingFace = 1;
						std::cout << "r" << std::endl;
					}
				}
				break;
			case SDLK_l:
				if (rubixu->rubixu3->rotatingFace == 0 && !rubixu->rubixu3->scramble) {
					if (event.key.keysym.mod && KMOD_SHIFT) {
						rubixu->rubixu3->rotatingFace = 4;
						std::cout << "shift + l" << std::endl;
					}
					else {
						rubixu->rubixu3->rotatingFace = 3;
						std::cout << "l" << std::endl;
					}
				}
				break;
			case SDLK_u:
				if (rubixu->rubixu3->rotatingFace == 0 && !rubixu->rubixu3->scramble) {
					if (event.key.keysym.mod && KMOD_SHIFT) {
						rubixu->rubixu3->rotatingFace = 6;
						std::cout << "shift + u" << std::endl;
					}
					else {
						rubixu->rubixu3->rotatingFace = 5;
						std::cout << "u" << std::endl;
					}
				}
				break;
			case SDLK_c:
				if (rubixu->rubixu3->rotatingFace == 0 && !rubixu->rubixu3->scramble) {
					if (event.key.keysym.mod && KMOD_SHIFT) {
						rubixu->rubixu3->rotatingFace = 8;
						std::cout << "shift + c" << std::endl;
					}
					else {
						rubixu->rubixu3->rotatingFace = 7;
						std::cout << "c" << std::endl;
					}
				}
				break;
			case SDLK_f:
				if (rubixu->rubixu3->rotatingFace == 0 && !rubixu->rubixu3->scramble) {
					if (event.key.keysym.mod && KMOD_SHIFT) {
						rubixu->rubixu3->rotatingFace = 10;
						std::cout << "shift + f" << std::endl;
					}
					else {
						rubixu->rubixu3->rotatingFace = 9;
						std::cout << "f" << std::endl;
					}
				}
				break;
			case SDLK_b:
				if (rubixu->rubixu3->rotatingFace == 0 && !rubixu->rubixu3->scramble) {
					if (event.key.keysym.mod && KMOD_SHIFT) {
						rubixu->rubixu3->rotatingFace = 12;
						std::cout << "shift + b" << std::endl;
					}
					else {
						rubixu->rubixu3->rotatingFace = 11;
						std::cout << "b" << std::endl;
					}
				}
				break;
			/*case SDLK_UP:
				rubixu->render->moveCameraPosition(FORWARD, rubixu->deltaTime);
				break;
			case SDLK_LEFT:
				rubixu->render->moveCameraPosition(LEFT, rubixu->deltaTime);
				break;
			case SDLK_DOWN:
				rubixu->render->moveCameraPosition(BACKWARD, rubixu->deltaTime);
				break;
			case SDLK_RIGHT:
				rubixu->render->moveCameraPosition(RIGHT, rubixu->deltaTime);
				break;*/
			case SDLK_h:
				stop_camera_direction = !stop_camera_direction;
				std::cout << "space" << std::endl;
				break;
			case SDLK_p:
				rubixu->rubixu3->scramble = !rubixu->rubixu3->scramble;
				std::cout << "s" << std::endl;
				break;
			default:
				break;
			}
		case SDL_MOUSEMOTION:
			// for some reason mouse goes crazy after you press a button
			// here is a ghetto solution
			if (glm::abs(event.motion.xrel) < 100 && glm::abs(event.motion.yrel < 100) && !stop_camera_direction)
				rubixu->render->moveCameraDirection(event.motion.xrel, -event.motion.yrel, false);
			/*if (event.motion.x > 795)
				rubixu->render->moveCameraDirection(5, 0, false);
			if (event.motion.x < 5)
				rubixu->render->moveCameraDirection(-5, 0, false);
			if (event.motion.y > 595)
				rubixu->render->moveCameraDirection(0, 5, false);
			if (event.motion.y < 5)
				rubixu->render->moveCameraDirection(0, -5, false);*/
			//std::cout << "Mouse : (" << event.motion.x << ", " << event.motion.y << ")" << std::endl;
			break;
		default:
			break;
		}
	}

	const Uint8* state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_W])
	{
		rubixu->render->moveCameraPosition(FORWARD, rubixu->deltaTime);
	}
	if (state[SDL_SCANCODE_S])
	{
		rubixu->render->moveCameraPosition(BACKWARD, rubixu->deltaTime);
	}
	if (state[SDL_SCANCODE_A])
	{
		rubixu->render->moveCameraPosition(LEFT, rubixu->deltaTime);
	}
	if (state[SDL_SCANCODE_D])
	{
		rubixu->render->moveCameraPosition(RIGHT, rubixu->deltaTime);
	}
	if (state[SDL_SCANCODE_SPACE])
	{
		rubixu->render->moveCameraPosition(UP, rubixu->deltaTime);
	}
	if (state[SDL_SCANCODE_Q])
	{
		rubixu->render->moveCameraPosition(DOWN, rubixu->deltaTime);
	}
}
