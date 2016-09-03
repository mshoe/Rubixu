#include "Rubixu.h"

Rubixu *rubixu;

int main(int argc, char *argv[])
{
	std::cout << "Rubixu v0.001" << std::endl;
	rubixu = new Rubixu;
	if (rubixu->init == -1)
		return -1;

	rubixu->Loop();
	delete rubixu;
	return 0;
}