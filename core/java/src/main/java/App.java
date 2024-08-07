/**
 * App
 */
import com.vxlisp.vx.Core;
import com.vxlisp.vx.translation.En;

public final class App {

  public static void main(String[] args) {
    try {
      String output = "";
      final Core.Type_anylist arglist = Core.vx_anylist_from_arraystring(args);
      final Core.Type_context context = En.f_context_en(arglist);
      final Core.Type_string mainstring = Core.f_main(arglist);
      output = mainstring.vx_string();
      System.out.println(output);
    } catch (Exception e) {
      System.out.println("Untrapped Error!" + e.toString());
    }
  }

}
