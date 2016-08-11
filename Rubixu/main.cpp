#include "Rubixu.h"

Rubixu *rubixu;

int main(int argc, char *argv[])
{
	std::cout << "AG v0.001" << std::endl;
	rubixu = new Rubixu;
	if (rubixu->init == -1)
		return -1;

	rubixu->Loop();

	return 0;
}