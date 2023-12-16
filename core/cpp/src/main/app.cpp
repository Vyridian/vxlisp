
#include <iostream>
#include "vx/core.hpp"

int main(int iarglen, char* arrayarg[]) {
  int output = 0;
  try {
    vx_core::Type_anylist arglist = vx_core::vx_anylist_from_arraystring(iarglen, arrayarg, true);
				vx_core::vx_reserve(arglist);
    vx_core::Type_context context = vx_core::e_context;
    std::string soutput = "";
    context = vx_core::f_context_main(arglist);
    vx_core::vx_reserve_context(context);
    vx_core::Type_string mainstring = vx_core::f_main(arglist);
    soutput = mainstring->vx_string();
    vx_core::vx_release(mainstring);
		  vx_core::vx_release_one(arglist);
  		std::cout << soutput << std::endl;
    vx_core::vx_memory_leak_test();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    output = -1;
  } catch (...) {
    std::cerr << "Untrapped Error!" << std::endl;
    output = -1;
  }
  return output;
}
