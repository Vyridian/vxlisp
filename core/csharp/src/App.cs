/**
 * App
 */

class App {

  static void Main(string[] args) {
    try {
      string output = "";
      Vx.Core.Type_anylist arglist = Vx.Core.vx_anylist_from_arraystring(args);
      Vx.Core.Type_context context = Vx.Translation.En.f_context_en(arglist);
      Vx.Core.Type_string mainstring = Vx.Core.f_main(arglist);
      output = mainstring.vx_string();
      System.Console.WriteLine(output);
    } catch (Exception e) {
      System.Console.WriteLine("Untrapped Error!" + e.ToString());
    }
  }

}
