
#include <iostream>
#include "vx/core.hpp"
#include "vx/repl.hpp"

int main(int iarglen, char* arrayarg[]) {
  int output = 0;
	try {
		vx_core::Type_context context = vx_core::e_context();
    std::vector<std::string> listarg = vx_core::vx_liststring_from_arraystring(iarglen, arrayarg);
    std::string output = vx_repl::vx_string_from_listarg(vx_core::t_string(), listarg, context);
    std::cout << output << std::endl;
		vx_core::vx_release(context);
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
