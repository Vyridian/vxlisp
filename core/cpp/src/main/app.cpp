
#include <iostream>
#include "vx/core.hpp"

int main(int argc, char* argv[]) {
  //vx_core::Type_any a_any = new vx_core::Type_any();
  vx_core::Type_string mystring = vx_core::t_string;
  std::cout << mystring->vx_iref;
	return 0;
}
