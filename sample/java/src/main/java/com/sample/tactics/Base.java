package com.sample.tactics;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import com.vxlisp.vx.*;
import com.vxlisp.vx.web.*;
import com.vxlisp.vx.data.*;


public final class Base {


  /**
   * type: ability
   * (type ability)
   */
  public interface Type_ability extends Base.Type_card {
    public Base.Type_ability vx_new(final Object... vals);
    public Base.Type_ability vx_copy(final Object... vals);
    public Base.Type_ability vx_empty();
    public Base.Type_ability vx_type();
    public Core.Type_string name();
    public Core.Type_string titles();
    public Core.Type_string references();
    public Core.Type_string summary();
  }

  public static class Class_ability extends Core.Class_base implements Type_ability {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_titles;

    @Override
    public Core.Type_string titles() {
      return this.vx_p_titles == null ? Core.e_string : this.vx_p_titles;
    }

    protected Core.Type_string vx_p_references;

    @Override
    public Core.Type_string references() {
      return this.vx_p_references == null ? Core.e_string : this.vx_p_references;
    }

    protected Core.Type_string vx_p_summary;

    @Override
    public Core.Type_string summary() {
      return this.vx_p_summary == null ? Core.e_string : this.vx_p_summary;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":titles":
        output = this.titles();
        break;
      case ":references":
        output = this.references();
        break;
      case ":summary":
        output = this.summary();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":titles", this.titles());
      output.put(":references", this.references());
      output.put(":summary", this.summary());
      return Core.immutablemap(output);
    }

    @Override
    public Type_ability vx_new(final Object... vals) {return e_ability.vx_copy(vals);}

    @Override
    public Type_ability vx_copy(final Object... vals) {
      Class_ability output = new Class_ability();
      Type_ability val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":titles");
      validkeys.add(":references");
      validkeys.add(":summary");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new ability) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new ability :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":titles":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_titles = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_titles = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new ability :titles " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":references":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_references = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_references = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new ability :references " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":summary":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_summary = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_summary = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new ability :summary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new ability) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_ability vx_empty() {return e_ability;}
    @Override
    public Type_ability vx_type() {return t_ability;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "ability", // name
        ":struct", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_ability e_ability = new Class_ability();
  public static final Type_ability t_ability = new Class_ability();

  /**
   * type: abilitylist
   * (type abilitylist)
   */
  public interface Type_abilitylist extends Core.Type_list {
    public Base.Type_abilitylist vx_new(final Object... vals);
    public Base.Type_abilitylist vx_copy(final Object... vals);
    public Base.Type_abilitylist vx_empty();
    public Base.Type_abilitylist vx_type();
    public List<Base.Type_ability> vx_listability();
    public Base.Type_ability vx_ability(final Core.Type_int index);
  }

  public static class Class_abilitylist extends Core.Class_base implements Type_abilitylist {

    protected List<Base.Type_ability> vxlist = Core.immutablelist(new ArrayList<Base.Type_ability>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Base.Type_ability vx_ability(final Core.Type_int index) {
      Base.Type_ability output = Base.e_ability;
      Class_abilitylist list = this;
      int iindex = index.vx_int();
      List<Base.Type_ability> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Base.Type_ability> vx_listability() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_ability(index);
    }

    @Override
    public Type_abilitylist vx_new(final Object... vals) {return e_abilitylist.vx_copy(vals);}

    @Override
    public Type_abilitylist vx_copy(final Object... vals) {
      Class_abilitylist output = new Class_abilitylist();
      Type_abilitylist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Base.Type_ability> listval = new ArrayList<>(val.vx_listability());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Base.Type_ability) {
          listval.add((Base.Type_ability)valsub);
        } else if (valsub instanceof Base.Type_ability) {
          listval.add((Base.Type_ability)valsub);
        } else if (valsub instanceof Type_abilitylist) {
          Type_abilitylist multi = (Type_abilitylist)valsub;
          listval.addAll(multi.vx_listability());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Base.Type_ability) {
              Base.Type_ability valitem = (Base.Type_ability)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new abilitylist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_abilitylist vx_empty() {return e_abilitylist;}
    @Override
    public Type_abilitylist vx_type() {return t_abilitylist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "abilitylist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Base.t_ability), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_abilitylist e_abilitylist = new Class_abilitylist();
  public static final Type_abilitylist t_abilitylist = new Class_abilitylist();

  /**
   * type: book
   * (type book)
   */
  public interface Type_book extends Base.Type_card {
    public Base.Type_book vx_new(final Object... vals);
    public Base.Type_book vx_copy(final Object... vals);
    public Base.Type_book vx_empty();
    public Base.Type_book vx_type();
    public Core.Type_string name();
    public Core.Type_string titles();
    public Core.Type_string references();
    public Core.Type_string summary();
    public Base.Type_chapterlist chapterlist();
  }

  public static class Class_book extends Core.Class_base implements Type_book {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_titles;

    @Override
    public Core.Type_string titles() {
      return this.vx_p_titles == null ? Core.e_string : this.vx_p_titles;
    }

    protected Core.Type_string vx_p_references;

    @Override
    public Core.Type_string references() {
      return this.vx_p_references == null ? Core.e_string : this.vx_p_references;
    }

    protected Core.Type_string vx_p_summary;

    @Override
    public Core.Type_string summary() {
      return this.vx_p_summary == null ? Core.e_string : this.vx_p_summary;
    }

    protected Base.Type_chapterlist vx_p_chapterlist;

    @Override
    public Base.Type_chapterlist chapterlist() {
      return this.vx_p_chapterlist == null ? Base.e_chapterlist : this.vx_p_chapterlist;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":titles":
        output = this.titles();
        break;
      case ":references":
        output = this.references();
        break;
      case ":summary":
        output = this.summary();
        break;
      case ":chapterlist":
        output = this.chapterlist();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":titles", this.titles());
      output.put(":references", this.references());
      output.put(":summary", this.summary());
      output.put(":chapterlist", this.chapterlist());
      return Core.immutablemap(output);
    }

    @Override
    public Type_book vx_new(final Object... vals) {return e_book.vx_copy(vals);}

    @Override
    public Type_book vx_copy(final Object... vals) {
      Class_book output = new Class_book();
      Type_book val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      output.vx_p_chapterlist = val.chapterlist();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":titles");
      validkeys.add(":references");
      validkeys.add(":summary");
      validkeys.add(":chapterlist");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new book) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new book :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":titles":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_titles = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_titles = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new book :titles " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":references":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_references = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_references = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new book :references " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":summary":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_summary = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_summary = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new book :summary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":chapterlist":
            if (valsub instanceof Base.Type_chapterlist) {
              output.vx_p_chapterlist = (Base.Type_chapterlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new book :chapterlist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new book) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_book vx_empty() {return e_book;}
    @Override
    public Type_book vx_type() {return t_book;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "book", // name
        ":struct", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_book e_book = new Class_book();
  public static final Type_book t_book = new Class_book();

  /**
   * type: booklist
   * (type booklist)
   */
  public interface Type_booklist extends Core.Type_list {
    public Base.Type_booklist vx_new(final Object... vals);
    public Base.Type_booklist vx_copy(final Object... vals);
    public Base.Type_booklist vx_empty();
    public Base.Type_booklist vx_type();
    public List<Base.Type_book> vx_listbook();
    public Base.Type_book vx_book(final Core.Type_int index);
  }

  public static class Class_booklist extends Core.Class_base implements Type_booklist {

    protected List<Base.Type_book> vxlist = Core.immutablelist(new ArrayList<Base.Type_book>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Base.Type_book vx_book(final Core.Type_int index) {
      Base.Type_book output = Base.e_book;
      Class_booklist list = this;
      int iindex = index.vx_int();
      List<Base.Type_book> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Base.Type_book> vx_listbook() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_book(index);
    }

    @Override
    public Type_booklist vx_new(final Object... vals) {return e_booklist.vx_copy(vals);}

    @Override
    public Type_booklist vx_copy(final Object... vals) {
      Class_booklist output = new Class_booklist();
      Type_booklist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Base.Type_book> listval = new ArrayList<>(val.vx_listbook());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Base.Type_book) {
          listval.add((Base.Type_book)valsub);
        } else if (valsub instanceof Base.Type_book) {
          listval.add((Base.Type_book)valsub);
        } else if (valsub instanceof Type_booklist) {
          Type_booklist multi = (Type_booklist)valsub;
          listval.addAll(multi.vx_listbook());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Base.Type_book) {
              Base.Type_book valitem = (Base.Type_book)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new booklist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_booklist vx_empty() {return e_booklist;}
    @Override
    public Type_booklist vx_type() {return t_booklist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "booklist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Base.t_book), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_booklist e_booklist = new Class_booklist();
  public static final Type_booklist t_booklist = new Class_booklist();

  /**
   * type: card
   * (type card)
   */
  public interface Type_card extends Core.Type_struct {
    public Base.Type_card vx_new(final Object... vals);
    public Base.Type_card vx_copy(final Object... vals);
    public Base.Type_card vx_empty();
    public Base.Type_card vx_type();
    public Core.Type_string name();
    public Core.Type_string titles();
    public Core.Type_string references();
    public Core.Type_string summary();
  }

  public static class Class_card extends Core.Class_base implements Type_card {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_titles;

    @Override
    public Core.Type_string titles() {
      return this.vx_p_titles == null ? Core.e_string : this.vx_p_titles;
    }

    protected Core.Type_string vx_p_references;

    @Override
    public Core.Type_string references() {
      return this.vx_p_references == null ? Core.e_string : this.vx_p_references;
    }

    protected Core.Type_string vx_p_summary;

    @Override
    public Core.Type_string summary() {
      return this.vx_p_summary == null ? Core.e_string : this.vx_p_summary;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":titles":
        output = this.titles();
        break;
      case ":references":
        output = this.references();
        break;
      case ":summary":
        output = this.summary();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":titles", this.titles());
      output.put(":references", this.references());
      output.put(":summary", this.summary());
      return Core.immutablemap(output);
    }

    @Override
    public Type_card vx_new(final Object... vals) {return e_card.vx_copy(vals);}

    @Override
    public Type_card vx_copy(final Object... vals) {
      Class_card output = new Class_card();
      Type_card val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":titles");
      validkeys.add(":references");
      validkeys.add(":summary");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new card) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new card :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":titles":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_titles = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_titles = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new card :titles " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":references":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_references = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_references = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new card :references " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":summary":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_summary = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_summary = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new card :summary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new card) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_card vx_empty() {return e_card;}
    @Override
    public Type_card vx_type() {return t_card;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "card", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_card e_card = new Class_card();
  public static final Type_card t_card = new Class_card();

  /**
   * type: cardlist
   * (type cardlist)
   */
  public interface Type_cardlist extends Core.Type_list {
    public Base.Type_cardlist vx_new(final Object... vals);
    public Base.Type_cardlist vx_copy(final Object... vals);
    public Base.Type_cardlist vx_empty();
    public Base.Type_cardlist vx_type();
    public List<Base.Type_card> vx_listcard();
    public Base.Type_card vx_card(final Core.Type_int index);
  }

  public static class Class_cardlist extends Core.Class_base implements Type_cardlist {

    protected List<Base.Type_card> vxlist = Core.immutablelist(new ArrayList<Base.Type_card>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Base.Type_card vx_card(final Core.Type_int index) {
      Base.Type_card output = Base.e_card;
      Class_cardlist list = this;
      int iindex = index.vx_int();
      List<Base.Type_card> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Base.Type_card> vx_listcard() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_card(index);
    }

    @Override
    public Type_cardlist vx_new(final Object... vals) {return e_cardlist.vx_copy(vals);}

    @Override
    public Type_cardlist vx_copy(final Object... vals) {
      Class_cardlist output = new Class_cardlist();
      Type_cardlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Base.Type_card> listval = new ArrayList<>(val.vx_listcard());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Base.Type_card) {
          listval.add((Base.Type_card)valsub);
        } else if (valsub instanceof Base.Type_card) {
          listval.add((Base.Type_card)valsub);
        } else if (valsub instanceof Type_cardlist) {
          Type_cardlist multi = (Type_cardlist)valsub;
          listval.addAll(multi.vx_listcard());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Base.Type_card) {
              Base.Type_card valitem = (Base.Type_card)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new cardlist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_cardlist vx_empty() {return e_cardlist;}
    @Override
    public Type_cardlist vx_type() {return t_cardlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "cardlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Base.t_card), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_cardlist e_cardlist = new Class_cardlist();
  public static final Type_cardlist t_cardlist = new Class_cardlist();

  /**
   * type: chapter
   * (type chapter)
   */
  public interface Type_chapter extends Base.Type_card {
    public Base.Type_chapter vx_new(final Object... vals);
    public Base.Type_chapter vx_copy(final Object... vals);
    public Base.Type_chapter vx_empty();
    public Base.Type_chapter vx_type();
    public Core.Type_string name();
    public Core.Type_string titles();
    public Core.Type_string references();
    public Core.Type_string summary();
    public Base.Type_sectionlist sectionlist();
  }

  public static class Class_chapter extends Core.Class_base implements Type_chapter {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_titles;

    @Override
    public Core.Type_string titles() {
      return this.vx_p_titles == null ? Core.e_string : this.vx_p_titles;
    }

    protected Core.Type_string vx_p_references;

    @Override
    public Core.Type_string references() {
      return this.vx_p_references == null ? Core.e_string : this.vx_p_references;
    }

    protected Core.Type_string vx_p_summary;

    @Override
    public Core.Type_string summary() {
      return this.vx_p_summary == null ? Core.e_string : this.vx_p_summary;
    }

    protected Base.Type_sectionlist vx_p_sectionlist;

    @Override
    public Base.Type_sectionlist sectionlist() {
      return this.vx_p_sectionlist == null ? Base.e_sectionlist : this.vx_p_sectionlist;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":titles":
        output = this.titles();
        break;
      case ":references":
        output = this.references();
        break;
      case ":summary":
        output = this.summary();
        break;
      case ":sectionlist":
        output = this.sectionlist();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":titles", this.titles());
      output.put(":references", this.references());
      output.put(":summary", this.summary());
      output.put(":sectionlist", this.sectionlist());
      return Core.immutablemap(output);
    }

    @Override
    public Type_chapter vx_new(final Object... vals) {return e_chapter.vx_copy(vals);}

    @Override
    public Type_chapter vx_copy(final Object... vals) {
      Class_chapter output = new Class_chapter();
      Type_chapter val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      output.vx_p_sectionlist = val.sectionlist();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":titles");
      validkeys.add(":references");
      validkeys.add(":summary");
      validkeys.add(":sectionlist");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new chapter) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new chapter :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":titles":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_titles = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_titles = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new chapter :titles " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":references":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_references = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_references = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new chapter :references " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":summary":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_summary = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_summary = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new chapter :summary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":sectionlist":
            if (valsub instanceof Base.Type_sectionlist) {
              output.vx_p_sectionlist = (Base.Type_sectionlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new chapter :sectionlist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new chapter) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_chapter vx_empty() {return e_chapter;}
    @Override
    public Type_chapter vx_type() {return t_chapter;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "chapter", // name
        ":struct", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_chapter e_chapter = new Class_chapter();
  public static final Type_chapter t_chapter = new Class_chapter();

  /**
   * type: chapterlist
   * (type chapterlist)
   */
  public interface Type_chapterlist extends Core.Type_list {
    public Base.Type_chapterlist vx_new(final Object... vals);
    public Base.Type_chapterlist vx_copy(final Object... vals);
    public Base.Type_chapterlist vx_empty();
    public Base.Type_chapterlist vx_type();
    public List<Base.Type_chapter> vx_listchapter();
    public Base.Type_chapter vx_chapter(final Core.Type_int index);
  }

  public static class Class_chapterlist extends Core.Class_base implements Type_chapterlist {

    protected List<Base.Type_chapter> vxlist = Core.immutablelist(new ArrayList<Base.Type_chapter>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Base.Type_chapter vx_chapter(final Core.Type_int index) {
      Base.Type_chapter output = Base.e_chapter;
      Class_chapterlist list = this;
      int iindex = index.vx_int();
      List<Base.Type_chapter> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Base.Type_chapter> vx_listchapter() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_chapter(index);
    }

    @Override
    public Type_chapterlist vx_new(final Object... vals) {return e_chapterlist.vx_copy(vals);}

    @Override
    public Type_chapterlist vx_copy(final Object... vals) {
      Class_chapterlist output = new Class_chapterlist();
      Type_chapterlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Base.Type_chapter> listval = new ArrayList<>(val.vx_listchapter());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Base.Type_chapter) {
          listval.add((Base.Type_chapter)valsub);
        } else if (valsub instanceof Base.Type_chapter) {
          listval.add((Base.Type_chapter)valsub);
        } else if (valsub instanceof Type_chapterlist) {
          Type_chapterlist multi = (Type_chapterlist)valsub;
          listval.addAll(multi.vx_listchapter());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Base.Type_chapter) {
              Base.Type_chapter valitem = (Base.Type_chapter)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new chapterlist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_chapterlist vx_empty() {return e_chapterlist;}
    @Override
    public Type_chapterlist vx_type() {return t_chapterlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "chapterlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Base.t_chapter), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_chapterlist e_chapterlist = new Class_chapterlist();
  public static final Type_chapterlist t_chapterlist = new Class_chapterlist();

  /**
   * type: deck
   * (type deck)
   */
  public interface Type_deck extends Base.Type_card {
    public Base.Type_deck vx_new(final Object... vals);
    public Base.Type_deck vx_copy(final Object... vals);
    public Base.Type_deck vx_empty();
    public Base.Type_deck vx_type();
    public Core.Type_string name();
    public Core.Type_string titles();
    public Core.Type_string references();
    public Core.Type_string summary();
    public Base.Type_cardlist cardlist();
  }

  public static class Class_deck extends Core.Class_base implements Type_deck {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_titles;

    @Override
    public Core.Type_string titles() {
      return this.vx_p_titles == null ? Core.e_string : this.vx_p_titles;
    }

    protected Core.Type_string vx_p_references;

    @Override
    public Core.Type_string references() {
      return this.vx_p_references == null ? Core.e_string : this.vx_p_references;
    }

    protected Core.Type_string vx_p_summary;

    @Override
    public Core.Type_string summary() {
      return this.vx_p_summary == null ? Core.e_string : this.vx_p_summary;
    }

    protected Base.Type_cardlist vx_p_cardlist;

    @Override
    public Base.Type_cardlist cardlist() {
      return this.vx_p_cardlist == null ? Base.e_cardlist : this.vx_p_cardlist;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":titles":
        output = this.titles();
        break;
      case ":references":
        output = this.references();
        break;
      case ":summary":
        output = this.summary();
        break;
      case ":cardlist":
        output = this.cardlist();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":titles", this.titles());
      output.put(":references", this.references());
      output.put(":summary", this.summary());
      output.put(":cardlist", this.cardlist());
      return Core.immutablemap(output);
    }

    @Override
    public Type_deck vx_new(final Object... vals) {return e_deck.vx_copy(vals);}

    @Override
    public Type_deck vx_copy(final Object... vals) {
      Class_deck output = new Class_deck();
      Type_deck val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      output.vx_p_cardlist = val.cardlist();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":titles");
      validkeys.add(":references");
      validkeys.add(":summary");
      validkeys.add(":cardlist");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new deck) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new deck :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":titles":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_titles = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_titles = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new deck :titles " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":references":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_references = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_references = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new deck :references " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":summary":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_summary = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_summary = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new deck :summary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":cardlist":
            if (valsub instanceof Base.Type_cardlist) {
              output.vx_p_cardlist = (Base.Type_cardlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new deck :cardlist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new deck) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_deck vx_empty() {return e_deck;}
    @Override
    public Type_deck vx_type() {return t_deck;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "deck", // name
        ":struct", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_deck e_deck = new Class_deck();
  public static final Type_deck t_deck = new Class_deck();

  /**
   * type: decklist
   * (type decklist)
   */
  public interface Type_decklist extends Core.Type_list {
    public Base.Type_decklist vx_new(final Object... vals);
    public Base.Type_decklist vx_copy(final Object... vals);
    public Base.Type_decklist vx_empty();
    public Base.Type_decklist vx_type();
    public List<Base.Type_deck> vx_listdeck();
    public Base.Type_deck vx_deck(final Core.Type_int index);
  }

  public static class Class_decklist extends Core.Class_base implements Type_decklist {

    protected List<Base.Type_deck> vxlist = Core.immutablelist(new ArrayList<Base.Type_deck>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Base.Type_deck vx_deck(final Core.Type_int index) {
      Base.Type_deck output = Base.e_deck;
      Class_decklist list = this;
      int iindex = index.vx_int();
      List<Base.Type_deck> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Base.Type_deck> vx_listdeck() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_deck(index);
    }

    @Override
    public Type_decklist vx_new(final Object... vals) {return e_decklist.vx_copy(vals);}

    @Override
    public Type_decklist vx_copy(final Object... vals) {
      Class_decklist output = new Class_decklist();
      Type_decklist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Base.Type_deck> listval = new ArrayList<>(val.vx_listdeck());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Base.Type_deck) {
          listval.add((Base.Type_deck)valsub);
        } else if (valsub instanceof Base.Type_deck) {
          listval.add((Base.Type_deck)valsub);
        } else if (valsub instanceof Type_decklist) {
          Type_decklist multi = (Type_decklist)valsub;
          listval.addAll(multi.vx_listdeck());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Base.Type_deck) {
              Base.Type_deck valitem = (Base.Type_deck)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new decklist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_decklist vx_empty() {return e_decklist;}
    @Override
    public Type_decklist vx_type() {return t_decklist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "decklist", // name
        ":list", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.t_typelist.vx_new(Base.t_deck), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_decklist e_decklist = new Class_decklist();
  public static final Type_decklist t_decklist = new Class_decklist();

  /**
   * type: item
   * (type item)
   */
  public interface Type_item extends Base.Type_card {
    public Base.Type_item vx_new(final Object... vals);
    public Base.Type_item vx_copy(final Object... vals);
    public Base.Type_item vx_empty();
    public Base.Type_item vx_type();
    public Core.Type_string name();
    public Core.Type_string titles();
    public Core.Type_string references();
    public Core.Type_string summary();
    public Core.Type_string mass();
  }

  public static class Class_item extends Core.Class_base implements Type_item {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_titles;

    @Override
    public Core.Type_string titles() {
      return this.vx_p_titles == null ? Core.e_string : this.vx_p_titles;
    }

    protected Core.Type_string vx_p_references;

    @Override
    public Core.Type_string references() {
      return this.vx_p_references == null ? Core.e_string : this.vx_p_references;
    }

    protected Core.Type_string vx_p_summary;

    @Override
    public Core.Type_string summary() {
      return this.vx_p_summary == null ? Core.e_string : this.vx_p_summary;
    }

    protected Core.Type_string vx_p_mass;

    @Override
    public Core.Type_string mass() {
      return this.vx_p_mass == null ? Core.e_string : this.vx_p_mass;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":titles":
        output = this.titles();
        break;
      case ":references":
        output = this.references();
        break;
      case ":summary":
        output = this.summary();
        break;
      case ":mass":
        output = this.mass();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":titles", this.titles());
      output.put(":references", this.references());
      output.put(":summary", this.summary());
      output.put(":mass", this.mass());
      return Core.immutablemap(output);
    }

    @Override
    public Type_item vx_new(final Object... vals) {return e_item.vx_copy(vals);}

    @Override
    public Type_item vx_copy(final Object... vals) {
      Class_item output = new Class_item();
      Type_item val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      output.vx_p_mass = val.mass();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":titles");
      validkeys.add(":references");
      validkeys.add(":summary");
      validkeys.add(":mass");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new item) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new item :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":titles":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_titles = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_titles = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new item :titles " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":references":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_references = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_references = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new item :references " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":summary":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_summary = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_summary = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new item :summary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":mass":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_mass = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_mass = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new item :mass " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new item) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_item vx_empty() {return e_item;}
    @Override
    public Type_item vx_type() {return t_item;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "item", // name
        ":struct", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_item e_item = new Class_item();
  public static final Type_item t_item = new Class_item();

  /**
   * type: itemlist
   * (type itemlist)
   */
  public interface Type_itemlist extends Core.Type_list {
    public Base.Type_itemlist vx_new(final Object... vals);
    public Base.Type_itemlist vx_copy(final Object... vals);
    public Base.Type_itemlist vx_empty();
    public Base.Type_itemlist vx_type();
    public List<Base.Type_item> vx_listitem();
    public Base.Type_item vx_item(final Core.Type_int index);
  }

  public static class Class_itemlist extends Core.Class_base implements Type_itemlist {

    protected List<Base.Type_item> vxlist = Core.immutablelist(new ArrayList<Base.Type_item>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Base.Type_item vx_item(final Core.Type_int index) {
      Base.Type_item output = Base.e_item;
      Class_itemlist list = this;
      int iindex = index.vx_int();
      List<Base.Type_item> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Base.Type_item> vx_listitem() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_item(index);
    }

    @Override
    public Type_itemlist vx_new(final Object... vals) {return e_itemlist.vx_copy(vals);}

    @Override
    public Type_itemlist vx_copy(final Object... vals) {
      Class_itemlist output = new Class_itemlist();
      Type_itemlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Base.Type_item> listval = new ArrayList<>(val.vx_listitem());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Base.Type_item) {
          listval.add((Base.Type_item)valsub);
        } else if (valsub instanceof Base.Type_item) {
          listval.add((Base.Type_item)valsub);
        } else if (valsub instanceof Type_itemlist) {
          Type_itemlist multi = (Type_itemlist)valsub;
          listval.addAll(multi.vx_listitem());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Base.Type_item) {
              Base.Type_item valitem = (Base.Type_item)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new itemlist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_itemlist vx_empty() {return e_itemlist;}
    @Override
    public Type_itemlist vx_type() {return t_itemlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "itemlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Base.t_item), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_itemlist e_itemlist = new Class_itemlist();
  public static final Type_itemlist t_itemlist = new Class_itemlist();

  /**
   * type: location
   * (type location)
   */
  public interface Type_location extends Base.Type_card {
    public Base.Type_location vx_new(final Object... vals);
    public Base.Type_location vx_copy(final Object... vals);
    public Base.Type_location vx_empty();
    public Base.Type_location vx_type();
    public Core.Type_string name();
    public Core.Type_string titles();
    public Core.Type_string references();
    public Core.Type_string summary();
    public Base.Type_locationlist locationlist();
    public Base.Type_unitlist unitlist();
  }

  public static class Class_location extends Core.Class_base implements Type_location {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_titles;

    @Override
    public Core.Type_string titles() {
      return this.vx_p_titles == null ? Core.e_string : this.vx_p_titles;
    }

    protected Core.Type_string vx_p_references;

    @Override
    public Core.Type_string references() {
      return this.vx_p_references == null ? Core.e_string : this.vx_p_references;
    }

    protected Core.Type_string vx_p_summary;

    @Override
    public Core.Type_string summary() {
      return this.vx_p_summary == null ? Core.e_string : this.vx_p_summary;
    }

    protected Base.Type_locationlist vx_p_locationlist;

    @Override
    public Base.Type_locationlist locationlist() {
      return this.vx_p_locationlist == null ? Base.e_locationlist : this.vx_p_locationlist;
    }

    protected Base.Type_unitlist vx_p_unitlist;

    @Override
    public Base.Type_unitlist unitlist() {
      return this.vx_p_unitlist == null ? Base.e_unitlist : this.vx_p_unitlist;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":titles":
        output = this.titles();
        break;
      case ":references":
        output = this.references();
        break;
      case ":summary":
        output = this.summary();
        break;
      case ":locationlist":
        output = this.locationlist();
        break;
      case ":unitlist":
        output = this.unitlist();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":titles", this.titles());
      output.put(":references", this.references());
      output.put(":summary", this.summary());
      output.put(":locationlist", this.locationlist());
      output.put(":unitlist", this.unitlist());
      return Core.immutablemap(output);
    }

    @Override
    public Type_location vx_new(final Object... vals) {return e_location.vx_copy(vals);}

    @Override
    public Type_location vx_copy(final Object... vals) {
      Class_location output = new Class_location();
      Type_location val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      output.vx_p_locationlist = val.locationlist();
      output.vx_p_unitlist = val.unitlist();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":titles");
      validkeys.add(":references");
      validkeys.add(":summary");
      validkeys.add(":locationlist");
      validkeys.add(":unitlist");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new location) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new location :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":titles":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_titles = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_titles = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new location :titles " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":references":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_references = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_references = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new location :references " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":summary":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_summary = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_summary = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new location :summary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":locationlist":
            if (valsub instanceof Base.Type_locationlist) {
              output.vx_p_locationlist = (Base.Type_locationlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new location :locationlist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":unitlist":
            if (valsub instanceof Base.Type_unitlist) {
              output.vx_p_unitlist = (Base.Type_unitlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new location :unitlist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new location) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_location vx_empty() {return e_location;}
    @Override
    public Type_location vx_type() {return t_location;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "location", // name
        ":struct", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_location e_location = new Class_location();
  public static final Type_location t_location = new Class_location();

  /**
   * type: locationlist
   * (type locationlist)
   */
  public interface Type_locationlist extends Core.Type_list {
    public Base.Type_locationlist vx_new(final Object... vals);
    public Base.Type_locationlist vx_copy(final Object... vals);
    public Base.Type_locationlist vx_empty();
    public Base.Type_locationlist vx_type();
    public List<Base.Type_location> vx_listlocation();
    public Base.Type_location vx_location(final Core.Type_int index);
  }

  public static class Class_locationlist extends Core.Class_base implements Type_locationlist {

    protected List<Base.Type_location> vxlist = Core.immutablelist(new ArrayList<Base.Type_location>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Base.Type_location vx_location(final Core.Type_int index) {
      Base.Type_location output = Base.e_location;
      Class_locationlist list = this;
      int iindex = index.vx_int();
      List<Base.Type_location> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Base.Type_location> vx_listlocation() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_location(index);
    }

    @Override
    public Type_locationlist vx_new(final Object... vals) {return e_locationlist.vx_copy(vals);}

    @Override
    public Type_locationlist vx_copy(final Object... vals) {
      Class_locationlist output = new Class_locationlist();
      Type_locationlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Base.Type_location> listval = new ArrayList<>(val.vx_listlocation());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Base.Type_location) {
          listval.add((Base.Type_location)valsub);
        } else if (valsub instanceof Base.Type_location) {
          listval.add((Base.Type_location)valsub);
        } else if (valsub instanceof Type_locationlist) {
          Type_locationlist multi = (Type_locationlist)valsub;
          listval.addAll(multi.vx_listlocation());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Base.Type_location) {
              Base.Type_location valitem = (Base.Type_location)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new locationlist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_locationlist vx_empty() {return e_locationlist;}
    @Override
    public Type_locationlist vx_type() {return t_locationlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "locationlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Base.t_location), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_locationlist e_locationlist = new Class_locationlist();
  public static final Type_locationlist t_locationlist = new Class_locationlist();

  /**
   * type: playingcard
   * (type playingcard)
   */
  public interface Type_playingcard extends Base.Type_card {
    public Base.Type_playingcard vx_new(final Object... vals);
    public Base.Type_playingcard vx_copy(final Object... vals);
    public Base.Type_playingcard vx_empty();
    public Base.Type_playingcard vx_type();
    public Core.Type_string name();
    public Core.Type_string titles();
    public Core.Type_string references();
    public Core.Type_string summary();
    public Base.Type_rank rank();
    public Base.Type_suit suit();
  }

  public static class Class_playingcard extends Core.Class_base implements Type_playingcard {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_titles;

    @Override
    public Core.Type_string titles() {
      return this.vx_p_titles == null ? Core.e_string : this.vx_p_titles;
    }

    protected Core.Type_string vx_p_references;

    @Override
    public Core.Type_string references() {
      return this.vx_p_references == null ? Core.e_string : this.vx_p_references;
    }

    protected Core.Type_string vx_p_summary;

    @Override
    public Core.Type_string summary() {
      return this.vx_p_summary == null ? Core.e_string : this.vx_p_summary;
    }

    protected Base.Type_rank vx_p_rank;

    @Override
    public Base.Type_rank rank() {
      return this.vx_p_rank == null ? Base.e_rank : this.vx_p_rank;
    }

    protected Base.Type_suit vx_p_suit;

    @Override
    public Base.Type_suit suit() {
      return this.vx_p_suit == null ? Base.e_suit : this.vx_p_suit;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":titles":
        output = this.titles();
        break;
      case ":references":
        output = this.references();
        break;
      case ":summary":
        output = this.summary();
        break;
      case ":rank":
        output = this.rank();
        break;
      case ":suit":
        output = this.suit();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":titles", this.titles());
      output.put(":references", this.references());
      output.put(":summary", this.summary());
      output.put(":rank", this.rank());
      output.put(":suit", this.suit());
      return Core.immutablemap(output);
    }

    @Override
    public Type_playingcard vx_new(final Object... vals) {return e_playingcard.vx_copy(vals);}

    @Override
    public Type_playingcard vx_copy(final Object... vals) {
      Class_playingcard output = new Class_playingcard();
      Type_playingcard val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      output.vx_p_rank = val.rank();
      output.vx_p_suit = val.suit();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":titles");
      validkeys.add(":references");
      validkeys.add(":summary");
      validkeys.add(":rank");
      validkeys.add(":suit");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new playingcard) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new playingcard :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":titles":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_titles = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_titles = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new playingcard :titles " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":references":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_references = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_references = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new playingcard :references " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":summary":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_summary = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_summary = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new playingcard :summary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":rank":
            if (valsub instanceof Base.Type_rank) {
              output.vx_p_rank = (Base.Type_rank)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new playingcard :rank " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":suit":
            if (valsub instanceof Base.Type_suit) {
              output.vx_p_suit = (Base.Type_suit)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new playingcard :suit " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new playingcard) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_playingcard vx_empty() {return e_playingcard;}
    @Override
    public Type_playingcard vx_type() {return t_playingcard;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "playingcard", // name
        ":struct", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_playingcard e_playingcard = new Class_playingcard();
  public static final Type_playingcard t_playingcard = new Class_playingcard();

  /**
   * type: power
   * (type power)
   */
  public interface Type_power extends Base.Type_card {
    public Base.Type_power vx_new(final Object... vals);
    public Base.Type_power vx_copy(final Object... vals);
    public Base.Type_power vx_empty();
    public Base.Type_power vx_type();
    public Core.Type_string name();
    public Core.Type_string titles();
    public Core.Type_string references();
    public Core.Type_string summary();
    public Base.Type_rating rating();
    public Base.Type_abilitylist abilitylist();
    public Base.Type_specialtylist specialtylist();
  }

  public static class Class_power extends Core.Class_base implements Type_power {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_titles;

    @Override
    public Core.Type_string titles() {
      return this.vx_p_titles == null ? Core.e_string : this.vx_p_titles;
    }

    protected Core.Type_string vx_p_references;

    @Override
    public Core.Type_string references() {
      return this.vx_p_references == null ? Core.e_string : this.vx_p_references;
    }

    protected Core.Type_string vx_p_summary;

    @Override
    public Core.Type_string summary() {
      return this.vx_p_summary == null ? Core.e_string : this.vx_p_summary;
    }

    protected Base.Type_rating vx_p_rating;

    @Override
    public Base.Type_rating rating() {
      return this.vx_p_rating == null ? Base.e_rating : this.vx_p_rating;
    }

    protected Base.Type_abilitylist vx_p_abilitylist;

    @Override
    public Base.Type_abilitylist abilitylist() {
      return this.vx_p_abilitylist == null ? Base.e_abilitylist : this.vx_p_abilitylist;
    }

    protected Base.Type_specialtylist vx_p_specialtylist;

    @Override
    public Base.Type_specialtylist specialtylist() {
      return this.vx_p_specialtylist == null ? Base.e_specialtylist : this.vx_p_specialtylist;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":titles":
        output = this.titles();
        break;
      case ":references":
        output = this.references();
        break;
      case ":summary":
        output = this.summary();
        break;
      case ":rating":
        output = this.rating();
        break;
      case ":abilitylist":
        output = this.abilitylist();
        break;
      case ":specialtylist":
        output = this.specialtylist();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":titles", this.titles());
      output.put(":references", this.references());
      output.put(":summary", this.summary());
      output.put(":rating", this.rating());
      output.put(":abilitylist", this.abilitylist());
      output.put(":specialtylist", this.specialtylist());
      return Core.immutablemap(output);
    }

    @Override
    public Type_power vx_new(final Object... vals) {return e_power.vx_copy(vals);}

    @Override
    public Type_power vx_copy(final Object... vals) {
      Class_power output = new Class_power();
      Type_power val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      output.vx_p_rating = val.rating();
      output.vx_p_abilitylist = val.abilitylist();
      output.vx_p_specialtylist = val.specialtylist();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":titles");
      validkeys.add(":references");
      validkeys.add(":summary");
      validkeys.add(":rating");
      validkeys.add(":abilitylist");
      validkeys.add(":specialtylist");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new power) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new power :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":titles":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_titles = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_titles = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new power :titles " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":references":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_references = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_references = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new power :references " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":summary":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_summary = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_summary = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new power :summary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":rating":
            if (valsub instanceof Base.Type_rating) {
              output.vx_p_rating = (Base.Type_rating)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new power :rating " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":abilitylist":
            if (valsub instanceof Base.Type_abilitylist) {
              output.vx_p_abilitylist = (Base.Type_abilitylist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new power :abilitylist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":specialtylist":
            if (valsub instanceof Base.Type_specialtylist) {
              output.vx_p_specialtylist = (Base.Type_specialtylist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new power :specialtylist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new power) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_power vx_empty() {return e_power;}
    @Override
    public Type_power vx_type() {return t_power;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "power", // name
        ":struct", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_power e_power = new Class_power();
  public static final Type_power t_power = new Class_power();

  /**
   * type: powerlist
   * (type powerlist)
   */
  public interface Type_powerlist extends Core.Type_list {
    public Base.Type_powerlist vx_new(final Object... vals);
    public Base.Type_powerlist vx_copy(final Object... vals);
    public Base.Type_powerlist vx_empty();
    public Base.Type_powerlist vx_type();
    public List<Base.Type_power> vx_listpower();
    public Base.Type_power vx_power(final Core.Type_int index);
  }

  public static class Class_powerlist extends Core.Class_base implements Type_powerlist {

    protected List<Base.Type_power> vxlist = Core.immutablelist(new ArrayList<Base.Type_power>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Base.Type_power vx_power(final Core.Type_int index) {
      Base.Type_power output = Base.e_power;
      Class_powerlist list = this;
      int iindex = index.vx_int();
      List<Base.Type_power> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Base.Type_power> vx_listpower() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_power(index);
    }

    @Override
    public Type_powerlist vx_new(final Object... vals) {return e_powerlist.vx_copy(vals);}

    @Override
    public Type_powerlist vx_copy(final Object... vals) {
      Class_powerlist output = new Class_powerlist();
      Type_powerlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Base.Type_power> listval = new ArrayList<>(val.vx_listpower());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Base.Type_power) {
          listval.add((Base.Type_power)valsub);
        } else if (valsub instanceof Base.Type_power) {
          listval.add((Base.Type_power)valsub);
        } else if (valsub instanceof Type_powerlist) {
          Type_powerlist multi = (Type_powerlist)valsub;
          listval.addAll(multi.vx_listpower());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Base.Type_power) {
              Base.Type_power valitem = (Base.Type_power)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new powerlist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_powerlist vx_empty() {return e_powerlist;}
    @Override
    public Type_powerlist vx_type() {return t_powerlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "powerlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Base.t_power), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_powerlist e_powerlist = new Class_powerlist();
  public static final Type_powerlist t_powerlist = new Class_powerlist();

  /**
   * type: rank
   * (type rank)
   */
  public interface Type_rank extends Base.Type_card {
    public Base.Type_rank vx_new(final Object... vals);
    public Base.Type_rank vx_copy(final Object... vals);
    public Base.Type_rank vx_empty();
    public Base.Type_rank vx_type();
    public Core.Type_string name();
    public Core.Type_string titles();
    public Core.Type_string references();
    public Core.Type_string summary();
  }

  public static class Class_rank extends Core.Class_base implements Type_rank {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_titles;

    @Override
    public Core.Type_string titles() {
      return this.vx_p_titles == null ? Core.e_string : this.vx_p_titles;
    }

    protected Core.Type_string vx_p_references;

    @Override
    public Core.Type_string references() {
      return this.vx_p_references == null ? Core.e_string : this.vx_p_references;
    }

    protected Core.Type_string vx_p_summary;

    @Override
    public Core.Type_string summary() {
      return this.vx_p_summary == null ? Core.e_string : this.vx_p_summary;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":titles":
        output = this.titles();
        break;
      case ":references":
        output = this.references();
        break;
      case ":summary":
        output = this.summary();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":titles", this.titles());
      output.put(":references", this.references());
      output.put(":summary", this.summary());
      return Core.immutablemap(output);
    }

    @Override
    public Type_rank vx_new(final Object... vals) {return e_rank.vx_copy(vals);}

    @Override
    public Type_rank vx_copy(final Object... vals) {
      Class_rank output = new Class_rank();
      Type_rank val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":titles");
      validkeys.add(":references");
      validkeys.add(":summary");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new rank) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new rank :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":titles":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_titles = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_titles = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new rank :titles " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":references":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_references = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_references = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new rank :references " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":summary":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_summary = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_summary = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new rank :summary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new rank) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_rank vx_empty() {return e_rank;}
    @Override
    public Type_rank vx_type() {return t_rank;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "rank", // name
        ":struct", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_rank e_rank = new Class_rank();
  public static final Type_rank t_rank = new Class_rank();

  /**
   * type: rating
   * (type rating)
   */
  public interface Type_rating extends Base.Type_card {
    public Base.Type_rating vx_new(final Object... vals);
    public Base.Type_rating vx_copy(final Object... vals);
    public Base.Type_rating vx_empty();
    public Base.Type_rating vx_type();
    public Core.Type_string name();
    public Core.Type_string titles();
    public Core.Type_string references();
    public Core.Type_string summary();
    public Core.Type_int level();
    public Core.Type_int scale();
  }

  public static class Class_rating extends Core.Class_base implements Type_rating {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_titles;

    @Override
    public Core.Type_string titles() {
      return this.vx_p_titles == null ? Core.e_string : this.vx_p_titles;
    }

    protected Core.Type_string vx_p_references;

    @Override
    public Core.Type_string references() {
      return this.vx_p_references == null ? Core.e_string : this.vx_p_references;
    }

    protected Core.Type_string vx_p_summary;

    @Override
    public Core.Type_string summary() {
      return this.vx_p_summary == null ? Core.e_string : this.vx_p_summary;
    }

    protected Core.Type_int vx_p_level;

    @Override
    public Core.Type_int level() {
      return this.vx_p_level == null ? Core.e_int : this.vx_p_level;
    }

    protected Core.Type_int vx_p_scale;

    @Override
    public Core.Type_int scale() {
      return this.vx_p_scale == null ? Core.e_int : this.vx_p_scale;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":titles":
        output = this.titles();
        break;
      case ":references":
        output = this.references();
        break;
      case ":summary":
        output = this.summary();
        break;
      case ":level":
        output = this.level();
        break;
      case ":scale":
        output = this.scale();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":titles", this.titles());
      output.put(":references", this.references());
      output.put(":summary", this.summary());
      output.put(":level", this.level());
      output.put(":scale", this.scale());
      return Core.immutablemap(output);
    }

    @Override
    public Type_rating vx_new(final Object... vals) {return e_rating.vx_copy(vals);}

    @Override
    public Type_rating vx_copy(final Object... vals) {
      Class_rating output = new Class_rating();
      Type_rating val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      output.vx_p_level = val.level();
      output.vx_p_scale = val.scale();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":titles");
      validkeys.add(":references");
      validkeys.add(":summary");
      validkeys.add(":level");
      validkeys.add(":scale");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new rating) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new rating :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":titles":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_titles = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_titles = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new rating :titles " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":references":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_references = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_references = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new rating :references " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":summary":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_summary = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_summary = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new rating :summary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":level":
            if (valsub instanceof Core.Type_int) {
              output.vx_p_level = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              output.vx_p_level = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new rating :level " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":scale":
            if (valsub instanceof Core.Type_int) {
              output.vx_p_scale = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              output.vx_p_scale = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new rating :scale " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new rating) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_rating vx_empty() {return e_rating;}
    @Override
    public Type_rating vx_type() {return t_rating;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "rating", // name
        ":struct", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_rating e_rating = new Class_rating();
  public static final Type_rating t_rating = new Class_rating();

  /**
   * type: rule
   * (type rule)
   */
  public interface Type_rule extends Base.Type_card {
    public Base.Type_rule vx_new(final Object... vals);
    public Base.Type_rule vx_copy(final Object... vals);
    public Base.Type_rule vx_empty();
    public Base.Type_rule vx_type();
    public Core.Type_string name();
    public Core.Type_string titles();
    public Core.Type_string references();
    public Core.Type_string summary();
  }

  public static class Class_rule extends Core.Class_base implements Type_rule {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_titles;

    @Override
    public Core.Type_string titles() {
      return this.vx_p_titles == null ? Core.e_string : this.vx_p_titles;
    }

    protected Core.Type_string vx_p_references;

    @Override
    public Core.Type_string references() {
      return this.vx_p_references == null ? Core.e_string : this.vx_p_references;
    }

    protected Core.Type_string vx_p_summary;

    @Override
    public Core.Type_string summary() {
      return this.vx_p_summary == null ? Core.e_string : this.vx_p_summary;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":titles":
        output = this.titles();
        break;
      case ":references":
        output = this.references();
        break;
      case ":summary":
        output = this.summary();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":titles", this.titles());
      output.put(":references", this.references());
      output.put(":summary", this.summary());
      return Core.immutablemap(output);
    }

    @Override
    public Type_rule vx_new(final Object... vals) {return e_rule.vx_copy(vals);}

    @Override
    public Type_rule vx_copy(final Object... vals) {
      Class_rule output = new Class_rule();
      Type_rule val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":titles");
      validkeys.add(":references");
      validkeys.add(":summary");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new rule) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new rule :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":titles":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_titles = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_titles = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new rule :titles " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":references":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_references = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_references = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new rule :references " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":summary":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_summary = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_summary = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new rule :summary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new rule) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_rule vx_empty() {return e_rule;}
    @Override
    public Type_rule vx_type() {return t_rule;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "rule", // name
        ":struct", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_rule e_rule = new Class_rule();
  public static final Type_rule t_rule = new Class_rule();

  /**
   * type: rulelist
   * (type rulelist)
   */
  public interface Type_rulelist extends Core.Type_list {
    public Base.Type_rulelist vx_new(final Object... vals);
    public Base.Type_rulelist vx_copy(final Object... vals);
    public Base.Type_rulelist vx_empty();
    public Base.Type_rulelist vx_type();
    public List<Base.Type_rule> vx_listrule();
    public Base.Type_rule vx_rule(final Core.Type_int index);
  }

  public static class Class_rulelist extends Core.Class_base implements Type_rulelist {

    protected List<Base.Type_rule> vxlist = Core.immutablelist(new ArrayList<Base.Type_rule>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Base.Type_rule vx_rule(final Core.Type_int index) {
      Base.Type_rule output = Base.e_rule;
      Class_rulelist list = this;
      int iindex = index.vx_int();
      List<Base.Type_rule> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Base.Type_rule> vx_listrule() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_rule(index);
    }

    @Override
    public Type_rulelist vx_new(final Object... vals) {return e_rulelist.vx_copy(vals);}

    @Override
    public Type_rulelist vx_copy(final Object... vals) {
      Class_rulelist output = new Class_rulelist();
      Type_rulelist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Base.Type_rule> listval = new ArrayList<>(val.vx_listrule());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Base.Type_rule) {
          listval.add((Base.Type_rule)valsub);
        } else if (valsub instanceof Base.Type_rule) {
          listval.add((Base.Type_rule)valsub);
        } else if (valsub instanceof Type_rulelist) {
          Type_rulelist multi = (Type_rulelist)valsub;
          listval.addAll(multi.vx_listrule());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Base.Type_rule) {
              Base.Type_rule valitem = (Base.Type_rule)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new rulelist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_rulelist vx_empty() {return e_rulelist;}
    @Override
    public Type_rulelist vx_type() {return t_rulelist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "rulelist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Base.t_rule), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_rulelist e_rulelist = new Class_rulelist();
  public static final Type_rulelist t_rulelist = new Class_rulelist();

  /**
   * type: scenario
   * (type scenario)
   */
  public interface Type_scenario extends Base.Type_card {
    public Base.Type_scenario vx_new(final Object... vals);
    public Base.Type_scenario vx_copy(final Object... vals);
    public Base.Type_scenario vx_empty();
    public Base.Type_scenario vx_type();
    public Core.Type_string name();
    public Core.Type_string titles();
    public Core.Type_string references();
    public Core.Type_string summary();
    public Base.Type_unitlist unitlist();
  }

  public static class Class_scenario extends Core.Class_base implements Type_scenario {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_titles;

    @Override
    public Core.Type_string titles() {
      return this.vx_p_titles == null ? Core.e_string : this.vx_p_titles;
    }

    protected Core.Type_string vx_p_references;

    @Override
    public Core.Type_string references() {
      return this.vx_p_references == null ? Core.e_string : this.vx_p_references;
    }

    protected Core.Type_string vx_p_summary;

    @Override
    public Core.Type_string summary() {
      return this.vx_p_summary == null ? Core.e_string : this.vx_p_summary;
    }

    protected Base.Type_unitlist vx_p_unitlist;

    @Override
    public Base.Type_unitlist unitlist() {
      return this.vx_p_unitlist == null ? Base.e_unitlist : this.vx_p_unitlist;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":titles":
        output = this.titles();
        break;
      case ":references":
        output = this.references();
        break;
      case ":summary":
        output = this.summary();
        break;
      case ":unitlist":
        output = this.unitlist();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":titles", this.titles());
      output.put(":references", this.references());
      output.put(":summary", this.summary());
      output.put(":unitlist", this.unitlist());
      return Core.immutablemap(output);
    }

    @Override
    public Type_scenario vx_new(final Object... vals) {return e_scenario.vx_copy(vals);}

    @Override
    public Type_scenario vx_copy(final Object... vals) {
      Class_scenario output = new Class_scenario();
      Type_scenario val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      output.vx_p_unitlist = val.unitlist();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":titles");
      validkeys.add(":references");
      validkeys.add(":summary");
      validkeys.add(":unitlist");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new scenario) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new scenario :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":titles":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_titles = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_titles = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new scenario :titles " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":references":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_references = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_references = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new scenario :references " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":summary":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_summary = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_summary = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new scenario :summary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":unitlist":
            if (valsub instanceof Base.Type_unitlist) {
              output.vx_p_unitlist = (Base.Type_unitlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new scenario :unitlist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new scenario) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_scenario vx_empty() {return e_scenario;}
    @Override
    public Type_scenario vx_type() {return t_scenario;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "scenario", // name
        ":struct", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_scenario e_scenario = new Class_scenario();
  public static final Type_scenario t_scenario = new Class_scenario();

  /**
   * type: scenariolist
   * (type scenariolist)
   */
  public interface Type_scenariolist extends Core.Type_list {
    public Base.Type_scenariolist vx_new(final Object... vals);
    public Base.Type_scenariolist vx_copy(final Object... vals);
    public Base.Type_scenariolist vx_empty();
    public Base.Type_scenariolist vx_type();
    public List<Base.Type_scenario> vx_listscenario();
    public Base.Type_scenario vx_scenario(final Core.Type_int index);
  }

  public static class Class_scenariolist extends Core.Class_base implements Type_scenariolist {

    protected List<Base.Type_scenario> vxlist = Core.immutablelist(new ArrayList<Base.Type_scenario>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Base.Type_scenario vx_scenario(final Core.Type_int index) {
      Base.Type_scenario output = Base.e_scenario;
      Class_scenariolist list = this;
      int iindex = index.vx_int();
      List<Base.Type_scenario> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Base.Type_scenario> vx_listscenario() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_scenario(index);
    }

    @Override
    public Type_scenariolist vx_new(final Object... vals) {return e_scenariolist.vx_copy(vals);}

    @Override
    public Type_scenariolist vx_copy(final Object... vals) {
      Class_scenariolist output = new Class_scenariolist();
      Type_scenariolist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Base.Type_scenario> listval = new ArrayList<>(val.vx_listscenario());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Base.Type_scenario) {
          listval.add((Base.Type_scenario)valsub);
        } else if (valsub instanceof Base.Type_scenario) {
          listval.add((Base.Type_scenario)valsub);
        } else if (valsub instanceof Type_scenariolist) {
          Type_scenariolist multi = (Type_scenariolist)valsub;
          listval.addAll(multi.vx_listscenario());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Base.Type_scenario) {
              Base.Type_scenario valitem = (Base.Type_scenario)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new scenariolist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_scenariolist vx_empty() {return e_scenariolist;}
    @Override
    public Type_scenariolist vx_type() {return t_scenariolist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "scenariolist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Base.t_scenario), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_scenariolist e_scenariolist = new Class_scenariolist();
  public static final Type_scenariolist t_scenariolist = new Class_scenariolist();

  /**
   * type: section
   * (type section)
   */
  public interface Type_section extends Base.Type_card {
    public Base.Type_section vx_new(final Object... vals);
    public Base.Type_section vx_copy(final Object... vals);
    public Base.Type_section vx_empty();
    public Base.Type_section vx_type();
    public Core.Type_string name();
    public Core.Type_string titles();
    public Core.Type_string references();
    public Core.Type_string summary();
    public Base.Type_decklist decklist();
    public Base.Type_itemlist itemlist();
    public Base.Type_locationlist locationlist();
    public Base.Type_powerlist powerlist();
    public Base.Type_rulelist rulelist();
    public Base.Type_scenariolist scenariolist();
    public Base.Type_sectionlist sectionlist();
    public Base.Type_skilllist skilllist();
    public Base.Type_suitlist suitlist();
    public Base.Type_unitlist unitlist();
  }

  public static class Class_section extends Core.Class_base implements Type_section {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_titles;

    @Override
    public Core.Type_string titles() {
      return this.vx_p_titles == null ? Core.e_string : this.vx_p_titles;
    }

    protected Core.Type_string vx_p_references;

    @Override
    public Core.Type_string references() {
      return this.vx_p_references == null ? Core.e_string : this.vx_p_references;
    }

    protected Core.Type_string vx_p_summary;

    @Override
    public Core.Type_string summary() {
      return this.vx_p_summary == null ? Core.e_string : this.vx_p_summary;
    }

    protected Base.Type_decklist vx_p_decklist;

    @Override
    public Base.Type_decklist decklist() {
      return this.vx_p_decklist == null ? Base.e_decklist : this.vx_p_decklist;
    }

    protected Base.Type_itemlist vx_p_itemlist;

    @Override
    public Base.Type_itemlist itemlist() {
      return this.vx_p_itemlist == null ? Base.e_itemlist : this.vx_p_itemlist;
    }

    protected Base.Type_locationlist vx_p_locationlist;

    @Override
    public Base.Type_locationlist locationlist() {
      return this.vx_p_locationlist == null ? Base.e_locationlist : this.vx_p_locationlist;
    }

    protected Base.Type_powerlist vx_p_powerlist;

    @Override
    public Base.Type_powerlist powerlist() {
      return this.vx_p_powerlist == null ? Base.e_powerlist : this.vx_p_powerlist;
    }

    protected Base.Type_rulelist vx_p_rulelist;

    @Override
    public Base.Type_rulelist rulelist() {
      return this.vx_p_rulelist == null ? Base.e_rulelist : this.vx_p_rulelist;
    }

    protected Base.Type_scenariolist vx_p_scenariolist;

    @Override
    public Base.Type_scenariolist scenariolist() {
      return this.vx_p_scenariolist == null ? Base.e_scenariolist : this.vx_p_scenariolist;
    }

    protected Base.Type_sectionlist vx_p_sectionlist;

    @Override
    public Base.Type_sectionlist sectionlist() {
      return this.vx_p_sectionlist == null ? Base.e_sectionlist : this.vx_p_sectionlist;
    }

    protected Base.Type_skilllist vx_p_skilllist;

    @Override
    public Base.Type_skilllist skilllist() {
      return this.vx_p_skilllist == null ? Base.e_skilllist : this.vx_p_skilllist;
    }

    protected Base.Type_suitlist vx_p_suitlist;

    @Override
    public Base.Type_suitlist suitlist() {
      return this.vx_p_suitlist == null ? Base.e_suitlist : this.vx_p_suitlist;
    }

    protected Base.Type_unitlist vx_p_unitlist;

    @Override
    public Base.Type_unitlist unitlist() {
      return this.vx_p_unitlist == null ? Base.e_unitlist : this.vx_p_unitlist;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":titles":
        output = this.titles();
        break;
      case ":references":
        output = this.references();
        break;
      case ":summary":
        output = this.summary();
        break;
      case ":decklist":
        output = this.decklist();
        break;
      case ":itemlist":
        output = this.itemlist();
        break;
      case ":locationlist":
        output = this.locationlist();
        break;
      case ":powerlist":
        output = this.powerlist();
        break;
      case ":rulelist":
        output = this.rulelist();
        break;
      case ":scenariolist":
        output = this.scenariolist();
        break;
      case ":sectionlist":
        output = this.sectionlist();
        break;
      case ":skilllist":
        output = this.skilllist();
        break;
      case ":suitlist":
        output = this.suitlist();
        break;
      case ":unitlist":
        output = this.unitlist();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":titles", this.titles());
      output.put(":references", this.references());
      output.put(":summary", this.summary());
      output.put(":decklist", this.decklist());
      output.put(":itemlist", this.itemlist());
      output.put(":locationlist", this.locationlist());
      output.put(":powerlist", this.powerlist());
      output.put(":rulelist", this.rulelist());
      output.put(":scenariolist", this.scenariolist());
      output.put(":sectionlist", this.sectionlist());
      output.put(":skilllist", this.skilllist());
      output.put(":suitlist", this.suitlist());
      output.put(":unitlist", this.unitlist());
      return Core.immutablemap(output);
    }

    @Override
    public Type_section vx_new(final Object... vals) {return e_section.vx_copy(vals);}

    @Override
    public Type_section vx_copy(final Object... vals) {
      Class_section output = new Class_section();
      Type_section val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      output.vx_p_decklist = val.decklist();
      output.vx_p_itemlist = val.itemlist();
      output.vx_p_locationlist = val.locationlist();
      output.vx_p_powerlist = val.powerlist();
      output.vx_p_rulelist = val.rulelist();
      output.vx_p_scenariolist = val.scenariolist();
      output.vx_p_sectionlist = val.sectionlist();
      output.vx_p_skilllist = val.skilllist();
      output.vx_p_suitlist = val.suitlist();
      output.vx_p_unitlist = val.unitlist();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":titles");
      validkeys.add(":references");
      validkeys.add(":summary");
      validkeys.add(":decklist");
      validkeys.add(":itemlist");
      validkeys.add(":locationlist");
      validkeys.add(":powerlist");
      validkeys.add(":rulelist");
      validkeys.add(":scenariolist");
      validkeys.add(":sectionlist");
      validkeys.add(":skilllist");
      validkeys.add(":suitlist");
      validkeys.add(":unitlist");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new section) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new section :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":titles":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_titles = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_titles = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new section :titles " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":references":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_references = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_references = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new section :references " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":summary":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_summary = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_summary = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new section :summary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":decklist":
            if (valsub instanceof Base.Type_decklist) {
              output.vx_p_decklist = (Base.Type_decklist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new section :decklist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":itemlist":
            if (valsub instanceof Base.Type_itemlist) {
              output.vx_p_itemlist = (Base.Type_itemlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new section :itemlist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":locationlist":
            if (valsub instanceof Base.Type_locationlist) {
              output.vx_p_locationlist = (Base.Type_locationlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new section :locationlist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":powerlist":
            if (valsub instanceof Base.Type_powerlist) {
              output.vx_p_powerlist = (Base.Type_powerlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new section :powerlist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":rulelist":
            if (valsub instanceof Base.Type_rulelist) {
              output.vx_p_rulelist = (Base.Type_rulelist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new section :rulelist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":scenariolist":
            if (valsub instanceof Base.Type_scenariolist) {
              output.vx_p_scenariolist = (Base.Type_scenariolist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new section :scenariolist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":sectionlist":
            if (valsub instanceof Base.Type_sectionlist) {
              output.vx_p_sectionlist = (Base.Type_sectionlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new section :sectionlist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":skilllist":
            if (valsub instanceof Base.Type_skilllist) {
              output.vx_p_skilllist = (Base.Type_skilllist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new section :skilllist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":suitlist":
            if (valsub instanceof Base.Type_suitlist) {
              output.vx_p_suitlist = (Base.Type_suitlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new section :suitlist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":unitlist":
            if (valsub instanceof Base.Type_unitlist) {
              output.vx_p_unitlist = (Base.Type_unitlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new section :unitlist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new section) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_section vx_empty() {return e_section;}
    @Override
    public Type_section vx_type() {return t_section;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "section", // name
        ":struct", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_section e_section = new Class_section();
  public static final Type_section t_section = new Class_section();

  /**
   * type: sectionlist
   * (type sectionlist)
   */
  public interface Type_sectionlist extends Core.Type_list {
    public Base.Type_sectionlist vx_new(final Object... vals);
    public Base.Type_sectionlist vx_copy(final Object... vals);
    public Base.Type_sectionlist vx_empty();
    public Base.Type_sectionlist vx_type();
    public List<Base.Type_section> vx_listsection();
    public Base.Type_section vx_section(final Core.Type_int index);
  }

  public static class Class_sectionlist extends Core.Class_base implements Type_sectionlist {

    protected List<Base.Type_section> vxlist = Core.immutablelist(new ArrayList<Base.Type_section>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Base.Type_section vx_section(final Core.Type_int index) {
      Base.Type_section output = Base.e_section;
      Class_sectionlist list = this;
      int iindex = index.vx_int();
      List<Base.Type_section> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Base.Type_section> vx_listsection() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_section(index);
    }

    @Override
    public Type_sectionlist vx_new(final Object... vals) {return e_sectionlist.vx_copy(vals);}

    @Override
    public Type_sectionlist vx_copy(final Object... vals) {
      Class_sectionlist output = new Class_sectionlist();
      Type_sectionlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Base.Type_section> listval = new ArrayList<>(val.vx_listsection());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Base.Type_section) {
          listval.add((Base.Type_section)valsub);
        } else if (valsub instanceof Base.Type_section) {
          listval.add((Base.Type_section)valsub);
        } else if (valsub instanceof Type_sectionlist) {
          Type_sectionlist multi = (Type_sectionlist)valsub;
          listval.addAll(multi.vx_listsection());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Base.Type_section) {
              Base.Type_section valitem = (Base.Type_section)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new sectionlist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_sectionlist vx_empty() {return e_sectionlist;}
    @Override
    public Type_sectionlist vx_type() {return t_sectionlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "sectionlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Base.t_section), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_sectionlist e_sectionlist = new Class_sectionlist();
  public static final Type_sectionlist t_sectionlist = new Class_sectionlist();

  /**
   * type: skill
   * (type skill)
   */
  public interface Type_skill extends Base.Type_card {
    public Base.Type_skill vx_new(final Object... vals);
    public Base.Type_skill vx_copy(final Object... vals);
    public Base.Type_skill vx_empty();
    public Base.Type_skill vx_type();
    public Core.Type_string name();
    public Core.Type_string titles();
    public Core.Type_string references();
    public Core.Type_string summary();
    public Base.Type_rating rating();
    public Base.Type_abilitylist abilitylist();
    public Base.Type_specialtylist specialtylist();
  }

  public static class Class_skill extends Core.Class_base implements Type_skill {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_titles;

    @Override
    public Core.Type_string titles() {
      return this.vx_p_titles == null ? Core.e_string : this.vx_p_titles;
    }

    protected Core.Type_string vx_p_references;

    @Override
    public Core.Type_string references() {
      return this.vx_p_references == null ? Core.e_string : this.vx_p_references;
    }

    protected Core.Type_string vx_p_summary;

    @Override
    public Core.Type_string summary() {
      return this.vx_p_summary == null ? Core.e_string : this.vx_p_summary;
    }

    protected Base.Type_rating vx_p_rating;

    @Override
    public Base.Type_rating rating() {
      return this.vx_p_rating == null ? Base.e_rating : this.vx_p_rating;
    }

    protected Base.Type_abilitylist vx_p_abilitylist;

    @Override
    public Base.Type_abilitylist abilitylist() {
      return this.vx_p_abilitylist == null ? Base.e_abilitylist : this.vx_p_abilitylist;
    }

    protected Base.Type_specialtylist vx_p_specialtylist;

    @Override
    public Base.Type_specialtylist specialtylist() {
      return this.vx_p_specialtylist == null ? Base.e_specialtylist : this.vx_p_specialtylist;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":titles":
        output = this.titles();
        break;
      case ":references":
        output = this.references();
        break;
      case ":summary":
        output = this.summary();
        break;
      case ":rating":
        output = this.rating();
        break;
      case ":abilitylist":
        output = this.abilitylist();
        break;
      case ":specialtylist":
        output = this.specialtylist();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":titles", this.titles());
      output.put(":references", this.references());
      output.put(":summary", this.summary());
      output.put(":rating", this.rating());
      output.put(":abilitylist", this.abilitylist());
      output.put(":specialtylist", this.specialtylist());
      return Core.immutablemap(output);
    }

    @Override
    public Type_skill vx_new(final Object... vals) {return e_skill.vx_copy(vals);}

    @Override
    public Type_skill vx_copy(final Object... vals) {
      Class_skill output = new Class_skill();
      Type_skill val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      output.vx_p_rating = val.rating();
      output.vx_p_abilitylist = val.abilitylist();
      output.vx_p_specialtylist = val.specialtylist();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":titles");
      validkeys.add(":references");
      validkeys.add(":summary");
      validkeys.add(":rating");
      validkeys.add(":abilitylist");
      validkeys.add(":specialtylist");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new skill) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new skill :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":titles":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_titles = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_titles = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new skill :titles " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":references":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_references = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_references = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new skill :references " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":summary":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_summary = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_summary = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new skill :summary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":rating":
            if (valsub instanceof Base.Type_rating) {
              output.vx_p_rating = (Base.Type_rating)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new skill :rating " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":abilitylist":
            if (valsub instanceof Base.Type_abilitylist) {
              output.vx_p_abilitylist = (Base.Type_abilitylist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new skill :abilitylist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":specialtylist":
            if (valsub instanceof Base.Type_specialtylist) {
              output.vx_p_specialtylist = (Base.Type_specialtylist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new skill :specialtylist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new skill) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_skill vx_empty() {return e_skill;}
    @Override
    public Type_skill vx_type() {return t_skill;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "skill", // name
        ":struct", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_skill e_skill = new Class_skill();
  public static final Type_skill t_skill = new Class_skill();

  /**
   * type: skilllist
   * (type skilllist)
   */
  public interface Type_skilllist extends Core.Type_list {
    public Base.Type_skilllist vx_new(final Object... vals);
    public Base.Type_skilllist vx_copy(final Object... vals);
    public Base.Type_skilllist vx_empty();
    public Base.Type_skilllist vx_type();
    public List<Base.Type_skill> vx_listskill();
    public Base.Type_skill vx_skill(final Core.Type_int index);
  }

  public static class Class_skilllist extends Core.Class_base implements Type_skilllist {

    protected List<Base.Type_skill> vxlist = Core.immutablelist(new ArrayList<Base.Type_skill>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Base.Type_skill vx_skill(final Core.Type_int index) {
      Base.Type_skill output = Base.e_skill;
      Class_skilllist list = this;
      int iindex = index.vx_int();
      List<Base.Type_skill> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Base.Type_skill> vx_listskill() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_skill(index);
    }

    @Override
    public Type_skilllist vx_new(final Object... vals) {return e_skilllist.vx_copy(vals);}

    @Override
    public Type_skilllist vx_copy(final Object... vals) {
      Class_skilllist output = new Class_skilllist();
      Type_skilllist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Base.Type_skill> listval = new ArrayList<>(val.vx_listskill());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Base.Type_skill) {
          listval.add((Base.Type_skill)valsub);
        } else if (valsub instanceof Base.Type_skill) {
          listval.add((Base.Type_skill)valsub);
        } else if (valsub instanceof Type_skilllist) {
          Type_skilllist multi = (Type_skilllist)valsub;
          listval.addAll(multi.vx_listskill());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Base.Type_skill) {
              Base.Type_skill valitem = (Base.Type_skill)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new skilllist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_skilllist vx_empty() {return e_skilllist;}
    @Override
    public Type_skilllist vx_type() {return t_skilllist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "skilllist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Base.t_skill), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_skilllist e_skilllist = new Class_skilllist();
  public static final Type_skilllist t_skilllist = new Class_skilllist();

  /**
   * type: specialty
   * (type specialty)
   */
  public interface Type_specialty extends Base.Type_card {
    public Base.Type_specialty vx_new(final Object... vals);
    public Base.Type_specialty vx_copy(final Object... vals);
    public Base.Type_specialty vx_empty();
    public Base.Type_specialty vx_type();
    public Core.Type_string name();
    public Core.Type_string titles();
    public Core.Type_string references();
    public Core.Type_string summary();
  }

  public static class Class_specialty extends Core.Class_base implements Type_specialty {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_titles;

    @Override
    public Core.Type_string titles() {
      return this.vx_p_titles == null ? Core.e_string : this.vx_p_titles;
    }

    protected Core.Type_string vx_p_references;

    @Override
    public Core.Type_string references() {
      return this.vx_p_references == null ? Core.e_string : this.vx_p_references;
    }

    protected Core.Type_string vx_p_summary;

    @Override
    public Core.Type_string summary() {
      return this.vx_p_summary == null ? Core.e_string : this.vx_p_summary;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":titles":
        output = this.titles();
        break;
      case ":references":
        output = this.references();
        break;
      case ":summary":
        output = this.summary();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":titles", this.titles());
      output.put(":references", this.references());
      output.put(":summary", this.summary());
      return Core.immutablemap(output);
    }

    @Override
    public Type_specialty vx_new(final Object... vals) {return e_specialty.vx_copy(vals);}

    @Override
    public Type_specialty vx_copy(final Object... vals) {
      Class_specialty output = new Class_specialty();
      Type_specialty val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":titles");
      validkeys.add(":references");
      validkeys.add(":summary");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new specialty) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new specialty :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":titles":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_titles = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_titles = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new specialty :titles " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":references":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_references = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_references = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new specialty :references " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":summary":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_summary = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_summary = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new specialty :summary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new specialty) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_specialty vx_empty() {return e_specialty;}
    @Override
    public Type_specialty vx_type() {return t_specialty;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "specialty", // name
        ":struct", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_specialty e_specialty = new Class_specialty();
  public static final Type_specialty t_specialty = new Class_specialty();

  /**
   * type: specialtylist
   * (type specialtylist)
   */
  public interface Type_specialtylist extends Core.Type_list {
    public Base.Type_specialtylist vx_new(final Object... vals);
    public Base.Type_specialtylist vx_copy(final Object... vals);
    public Base.Type_specialtylist vx_empty();
    public Base.Type_specialtylist vx_type();
    public List<Base.Type_specialty> vx_listspecialty();
    public Base.Type_specialty vx_specialty(final Core.Type_int index);
  }

  public static class Class_specialtylist extends Core.Class_base implements Type_specialtylist {

    protected List<Base.Type_specialty> vxlist = Core.immutablelist(new ArrayList<Base.Type_specialty>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Base.Type_specialty vx_specialty(final Core.Type_int index) {
      Base.Type_specialty output = Base.e_specialty;
      Class_specialtylist list = this;
      int iindex = index.vx_int();
      List<Base.Type_specialty> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Base.Type_specialty> vx_listspecialty() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_specialty(index);
    }

    @Override
    public Type_specialtylist vx_new(final Object... vals) {return e_specialtylist.vx_copy(vals);}

    @Override
    public Type_specialtylist vx_copy(final Object... vals) {
      Class_specialtylist output = new Class_specialtylist();
      Type_specialtylist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Base.Type_specialty> listval = new ArrayList<>(val.vx_listspecialty());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Base.Type_specialty) {
          listval.add((Base.Type_specialty)valsub);
        } else if (valsub instanceof Base.Type_specialty) {
          listval.add((Base.Type_specialty)valsub);
        } else if (valsub instanceof Type_specialtylist) {
          Type_specialtylist multi = (Type_specialtylist)valsub;
          listval.addAll(multi.vx_listspecialty());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Base.Type_specialty) {
              Base.Type_specialty valitem = (Base.Type_specialty)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new specialtylist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_specialtylist vx_empty() {return e_specialtylist;}
    @Override
    public Type_specialtylist vx_type() {return t_specialtylist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "specialtylist", // name
        ":list", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.t_typelist.vx_new(Base.t_specialty), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_specialtylist e_specialtylist = new Class_specialtylist();
  public static final Type_specialtylist t_specialtylist = new Class_specialtylist();

  /**
   * type: suit
   * (type suit)
   */
  public interface Type_suit extends Base.Type_card {
    public Base.Type_suit vx_new(final Object... vals);
    public Base.Type_suit vx_copy(final Object... vals);
    public Base.Type_suit vx_empty();
    public Base.Type_suit vx_type();
    public Core.Type_string name();
    public Core.Type_string titles();
    public Core.Type_string references();
    public Core.Type_string summary();
  }

  public static class Class_suit extends Core.Class_base implements Type_suit {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_titles;

    @Override
    public Core.Type_string titles() {
      return this.vx_p_titles == null ? Core.e_string : this.vx_p_titles;
    }

    protected Core.Type_string vx_p_references;

    @Override
    public Core.Type_string references() {
      return this.vx_p_references == null ? Core.e_string : this.vx_p_references;
    }

    protected Core.Type_string vx_p_summary;

    @Override
    public Core.Type_string summary() {
      return this.vx_p_summary == null ? Core.e_string : this.vx_p_summary;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":titles":
        output = this.titles();
        break;
      case ":references":
        output = this.references();
        break;
      case ":summary":
        output = this.summary();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":titles", this.titles());
      output.put(":references", this.references());
      output.put(":summary", this.summary());
      return Core.immutablemap(output);
    }

    @Override
    public Type_suit vx_new(final Object... vals) {return e_suit.vx_copy(vals);}

    @Override
    public Type_suit vx_copy(final Object... vals) {
      Class_suit output = new Class_suit();
      Type_suit val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":titles");
      validkeys.add(":references");
      validkeys.add(":summary");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new suit) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new suit :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":titles":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_titles = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_titles = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new suit :titles " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":references":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_references = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_references = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new suit :references " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":summary":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_summary = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_summary = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new suit :summary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new suit) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_suit vx_empty() {return e_suit;}
    @Override
    public Type_suit vx_type() {return t_suit;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "suit", // name
        ":struct", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_suit e_suit = new Class_suit();
  public static final Type_suit t_suit = new Class_suit();

  /**
   * type: suitlist
   * (type suitlist)
   */
  public interface Type_suitlist extends Core.Type_list {
    public Base.Type_suitlist vx_new(final Object... vals);
    public Base.Type_suitlist vx_copy(final Object... vals);
    public Base.Type_suitlist vx_empty();
    public Base.Type_suitlist vx_type();
    public List<Base.Type_suit> vx_listsuit();
    public Base.Type_suit vx_suit(final Core.Type_int index);
  }

  public static class Class_suitlist extends Core.Class_base implements Type_suitlist {

    protected List<Base.Type_suit> vxlist = Core.immutablelist(new ArrayList<Base.Type_suit>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Base.Type_suit vx_suit(final Core.Type_int index) {
      Base.Type_suit output = Base.e_suit;
      Class_suitlist list = this;
      int iindex = index.vx_int();
      List<Base.Type_suit> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Base.Type_suit> vx_listsuit() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_suit(index);
    }

    @Override
    public Type_suitlist vx_new(final Object... vals) {return e_suitlist.vx_copy(vals);}

    @Override
    public Type_suitlist vx_copy(final Object... vals) {
      Class_suitlist output = new Class_suitlist();
      Type_suitlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Base.Type_suit> listval = new ArrayList<>(val.vx_listsuit());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Base.Type_suit) {
          listval.add((Base.Type_suit)valsub);
        } else if (valsub instanceof Base.Type_suit) {
          listval.add((Base.Type_suit)valsub);
        } else if (valsub instanceof Type_suitlist) {
          Type_suitlist multi = (Type_suitlist)valsub;
          listval.addAll(multi.vx_listsuit());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Base.Type_suit) {
              Base.Type_suit valitem = (Base.Type_suit)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new suitlist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_suitlist vx_empty() {return e_suitlist;}
    @Override
    public Type_suitlist vx_type() {return t_suitlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "suitlist", // name
        ":list", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.t_typelist.vx_new(Base.t_suit), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_suitlist e_suitlist = new Class_suitlist();
  public static final Type_suitlist t_suitlist = new Class_suitlist();

  /**
   * type: unit
   * (type unit)
   */
  public interface Type_unit extends Base.Type_card {
    public Base.Type_unit vx_new(final Object... vals);
    public Base.Type_unit vx_copy(final Object... vals);
    public Base.Type_unit vx_empty();
    public Base.Type_unit vx_type();
    public Core.Type_string name();
    public Core.Type_string titles();
    public Core.Type_string references();
    public Core.Type_string summary();
    public Base.Type_rating body();
    public Base.Type_rating mind();
    public Base.Type_rating will();
    public Base.Type_rating move();
    public Core.Type_string mass();
    public Base.Type_skilllist skills();
    public Base.Type_powerlist powers();
  }

  public static class Class_unit extends Core.Class_base implements Type_unit {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_titles;

    @Override
    public Core.Type_string titles() {
      return this.vx_p_titles == null ? Core.e_string : this.vx_p_titles;
    }

    protected Core.Type_string vx_p_references;

    @Override
    public Core.Type_string references() {
      return this.vx_p_references == null ? Core.e_string : this.vx_p_references;
    }

    protected Core.Type_string vx_p_summary;

    @Override
    public Core.Type_string summary() {
      return this.vx_p_summary == null ? Core.e_string : this.vx_p_summary;
    }

    protected Base.Type_rating vx_p_body;

    @Override
    public Base.Type_rating body() {
      return this.vx_p_body == null ? Base.e_rating : this.vx_p_body;
    }

    protected Base.Type_rating vx_p_mind;

    @Override
    public Base.Type_rating mind() {
      return this.vx_p_mind == null ? Base.e_rating : this.vx_p_mind;
    }

    protected Base.Type_rating vx_p_will;

    @Override
    public Base.Type_rating will() {
      return this.vx_p_will == null ? Base.e_rating : this.vx_p_will;
    }

    protected Base.Type_rating vx_p_move;

    @Override
    public Base.Type_rating move() {
      return this.vx_p_move == null ? Base.e_rating : this.vx_p_move;
    }

    protected Core.Type_string vx_p_mass;

    @Override
    public Core.Type_string mass() {
      return this.vx_p_mass == null ? Core.e_string : this.vx_p_mass;
    }

    protected Base.Type_skilllist vx_p_skills;

    @Override
    public Base.Type_skilllist skills() {
      return this.vx_p_skills == null ? Base.e_skilllist : this.vx_p_skills;
    }

    protected Base.Type_powerlist vx_p_powers;

    @Override
    public Base.Type_powerlist powers() {
      return this.vx_p_powers == null ? Base.e_powerlist : this.vx_p_powers;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":titles":
        output = this.titles();
        break;
      case ":references":
        output = this.references();
        break;
      case ":summary":
        output = this.summary();
        break;
      case ":body":
        output = this.body();
        break;
      case ":mind":
        output = this.mind();
        break;
      case ":will":
        output = this.will();
        break;
      case ":move":
        output = this.move();
        break;
      case ":mass":
        output = this.mass();
        break;
      case ":skills":
        output = this.skills();
        break;
      case ":powers":
        output = this.powers();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":titles", this.titles());
      output.put(":references", this.references());
      output.put(":summary", this.summary());
      output.put(":body", this.body());
      output.put(":mind", this.mind());
      output.put(":will", this.will());
      output.put(":move", this.move());
      output.put(":mass", this.mass());
      output.put(":skills", this.skills());
      output.put(":powers", this.powers());
      return Core.immutablemap(output);
    }

    @Override
    public Type_unit vx_new(final Object... vals) {return e_unit.vx_copy(vals);}

    @Override
    public Type_unit vx_copy(final Object... vals) {
      Class_unit output = new Class_unit();
      Type_unit val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      output.vx_p_body = val.body();
      output.vx_p_mind = val.mind();
      output.vx_p_will = val.will();
      output.vx_p_move = val.move();
      output.vx_p_mass = val.mass();
      output.vx_p_skills = val.skills();
      output.vx_p_powers = val.powers();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":titles");
      validkeys.add(":references");
      validkeys.add(":summary");
      validkeys.add(":body");
      validkeys.add(":mind");
      validkeys.add(":will");
      validkeys.add(":move");
      validkeys.add(":mass");
      validkeys.add(":skills");
      validkeys.add(":powers");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new unit) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new unit :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":titles":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_titles = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_titles = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new unit :titles " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":references":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_references = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_references = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new unit :references " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":summary":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_summary = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_summary = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new unit :summary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":body":
            if (valsub instanceof Base.Type_rating) {
              output.vx_p_body = (Base.Type_rating)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new unit :body " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":mind":
            if (valsub instanceof Base.Type_rating) {
              output.vx_p_mind = (Base.Type_rating)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new unit :mind " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":will":
            if (valsub instanceof Base.Type_rating) {
              output.vx_p_will = (Base.Type_rating)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new unit :will " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":move":
            if (valsub instanceof Base.Type_rating) {
              output.vx_p_move = (Base.Type_rating)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new unit :move " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":mass":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_mass = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_mass = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new unit :mass " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":skills":
            if (valsub instanceof Base.Type_skilllist) {
              output.vx_p_skills = (Base.Type_skilllist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new unit :skills " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":powers":
            if (valsub instanceof Base.Type_powerlist) {
              output.vx_p_powers = (Base.Type_powerlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new unit :powers " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new unit) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_unit vx_empty() {return e_unit;}
    @Override
    public Type_unit vx_type() {return t_unit;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "unit", // name
        ":struct", // extends
        Core.t_typelist.vx_new(Base.t_card), // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_unit e_unit = new Class_unit();
  public static final Type_unit t_unit = new Class_unit();

  /**
   * type: unitlist
   * (type unitlist)
   */
  public interface Type_unitlist extends Core.Type_list {
    public Base.Type_unitlist vx_new(final Object... vals);
    public Base.Type_unitlist vx_copy(final Object... vals);
    public Base.Type_unitlist vx_empty();
    public Base.Type_unitlist vx_type();
    public List<Base.Type_unit> vx_listunit();
    public Base.Type_unit vx_unit(final Core.Type_int index);
  }

  public static class Class_unitlist extends Core.Class_base implements Type_unitlist {

    protected List<Base.Type_unit> vxlist = Core.immutablelist(new ArrayList<Base.Type_unit>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Base.Type_unit vx_unit(final Core.Type_int index) {
      Base.Type_unit output = Base.e_unit;
      Class_unitlist list = this;
      int iindex = index.vx_int();
      List<Base.Type_unit> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Base.Type_unit> vx_listunit() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_unit(index);
    }

    @Override
    public Type_unitlist vx_new(final Object... vals) {return e_unitlist.vx_copy(vals);}

    @Override
    public Type_unitlist vx_copy(final Object... vals) {
      Class_unitlist output = new Class_unitlist();
      Type_unitlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Base.Type_unit> listval = new ArrayList<>(val.vx_listunit());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Base.Type_unit) {
          listval.add((Base.Type_unit)valsub);
        } else if (valsub instanceof Base.Type_unit) {
          listval.add((Base.Type_unit)valsub);
        } else if (valsub instanceof Type_unitlist) {
          Type_unitlist multi = (Type_unitlist)valsub;
          listval.addAll(multi.vx_listunit());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Base.Type_unit) {
              Base.Type_unit valitem = (Base.Type_unit)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new unitlist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_unitlist vx_empty() {return e_unitlist;}
    @Override
    public Type_unitlist vx_type() {return t_unitlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "tactics/base", // pkgname
        "unitlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Base.t_unit), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_unitlist e_unitlist = new Class_unitlist();
  public static final Type_unitlist t_unitlist = new Class_unitlist();

  /**
   * Constant: card-ace-spade
   * {playingcard}
   */
  public static class Const_card_ace_spade extends Base.Class_playingcard {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "tactics/base", // pkgname
        "card-ace-spade", // name
        Core.typedef_new(
          "tactics/base", // pkgname
          "playingcard", // name
          ":struct", // extends
          Core.t_typelist.vx_new(Base.t_card), // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
    }

    public static Const_card_ace_spade const_new() {
      Const_card_ace_spade output = new Const_card_ace_spade();
      Base.Type_playingcard val = Core.f_new(
        Base.t_playingcard,
        Core.t_anylist.vx_new(
                Core.t_string.vx_new_from_string(":rank"),
                Base.c_rank_ace,
                Core.t_string.vx_new_from_string(":suit"),
                Base.c_suit_spade
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_titles = val.titles();
      output.vx_p_references = val.references();
      output.vx_p_summary = val.summary();
      output.vx_p_rank = val.rank();
      output.vx_p_suit = val.suit();
      return output;
    }


  }

  public static final Const_card_ace_spade c_card_ace_spade = Const_card_ace_spade.const_new();


  /**
   * Constant: rank-ace
   * {rank}
   */
  public static class Const_rank_ace extends Base.Class_rank {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "tactics/base", // pkgname
        "rank-ace", // name
        Core.typedef_new(
          "tactics/base", // pkgname
          "rank", // name
          ":struct", // extends
          Core.t_typelist.vx_new(Base.t_card), // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
    }

    public static Const_rank_ace const_new() {
      Const_rank_ace output = new Const_rank_ace();
      return output;
    }


  }

  public static final Const_rank_ace c_rank_ace = Const_rank_ace.const_new();


  /**
   * Constant: suit-club
   * {suit}
   */
  public static class Const_suit_club extends Base.Class_suit {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "tactics/base", // pkgname
        "suit-club", // name
        Core.typedef_new(
          "tactics/base", // pkgname
          "suit", // name
          ":struct", // extends
          Core.t_typelist.vx_new(Base.t_card), // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
    }

    public static Const_suit_club const_new() {
      Const_suit_club output = new Const_suit_club();
      return output;
    }


  }

  public static final Const_suit_club c_suit_club = Const_suit_club.const_new();


  /**
   * Constant: suit-diamond
   * {suit}
   */
  public static class Const_suit_diamond extends Base.Class_suit {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "tactics/base", // pkgname
        "suit-diamond", // name
        Core.typedef_new(
          "tactics/base", // pkgname
          "suit", // name
          ":struct", // extends
          Core.t_typelist.vx_new(Base.t_card), // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
    }

    public static Const_suit_diamond const_new() {
      Const_suit_diamond output = new Const_suit_diamond();
      return output;
    }


  }

  public static final Const_suit_diamond c_suit_diamond = Const_suit_diamond.const_new();


  /**
   * Constant: suit-heart
   * {suit}
   */
  public static class Const_suit_heart extends Base.Class_suit {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "tactics/base", // pkgname
        "suit-heart", // name
        Core.typedef_new(
          "tactics/base", // pkgname
          "suit", // name
          ":struct", // extends
          Core.t_typelist.vx_new(Base.t_card), // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
    }

    public static Const_suit_heart const_new() {
      Const_suit_heart output = new Const_suit_heart();
      return output;
    }


  }

  public static final Const_suit_heart c_suit_heart = Const_suit_heart.const_new();


  /**
   * Constant: suit-spade
   * {suit}
   */
  public static class Const_suit_spade extends Base.Class_suit {

    public Core.Type_constdef constdef() {
      return Core.constdef_new(
        "tactics/base", // pkgname
        "suit-spade", // name
        Core.typedef_new(
          "tactics/base", // pkgname
          "suit", // name
          ":struct", // extends
          Core.t_typelist.vx_new(Base.t_card), // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
    }

    public static Const_suit_spade const_new() {
      Const_suit_spade output = new Const_suit_spade();
      return output;
    }


  }

  public static final Const_suit_spade c_suit_spade = Const_suit_spade.const_new();


}
