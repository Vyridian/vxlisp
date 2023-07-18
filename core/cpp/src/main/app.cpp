
#include <iostream>
#include "vx/core.hpp"

int main(int iarglen, char* arrayarg[]) {
  int status = 0;
	try {
    std::vector<std::string> listarg = vx_core::vx_liststring_from_arraystring(iarglen, arrayarg);
    vx_core::Type_string output = vx_core::vx_new_string("Hello World");
    std::cout << output->vx_string() << std::endl;
		vx_core::vx_release(output);
	  if (vx_core::refcount != 0) {
		  vx_core::vx_debug("memory leaks:" + std::to_string(vx_core::refcount));
	  }
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    status = -1;
  } catch (...) {
    std::cerr << "Untrapped Error!" << std::endl;
    status = -1;
  }
	return 0;
}
