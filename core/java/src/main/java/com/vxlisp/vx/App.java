package com.vxlisp.vx;

/**
 * App
 *
 */

import java.util.Arrays;
import java.util.List;
 
public final class App {

  public static void main(String[] args) {
    try {
			String output = "";
			Core.Type_anylist arglist = Core.vx_anylist_from_arraystring(args);
      Core.Type_context context = Core.f_context_main(arglist);
      Core.Type_string mainstring = Core.f_main(arglist);
      output = mainstring.vx_string();
      System.out.println(output);
    } catch (Exception e) {
      System.out.println("Untrapped Error!" + e.toString());
    }
  }

}
