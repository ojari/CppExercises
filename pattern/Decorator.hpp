#include <string>
using namespace std;

struct Flower
{
  virtual string str() = 0;
};

struct Rose : Flower
{
  string str() override {
    return "A rose";
  }
};

struct RedFlower : Flower
{
  RedFlower(Flower &base) : base(base)
  {}
  /** cleaner implementation would be to Flower have list of colors.
   *  But decorator should not change the base class.
  */
  string str() override {
    string bstr = base.str();
    if (bstr.find("that is red") != string::npos) // discard duplicates
      return bstr;
    if (bstr.find("that is blue") != string::npos)  // use and for two colors
      return bstr + " and red";
    return base.str() + " that is red";
  }

  Flower &base;
};

struct BlueFlower : Flower
{
  BlueFlower(Flower &base) : base(base)
  {}
  string str() override {
    string bstr = base.str();
    if (bstr.find("that is blue") != string::npos) // discard duplicates
      return bstr;
    if (bstr.find("that is red") != string::npos)  // use and for two colors
      return bstr + " and blue";
    return base.str() + " that is blue";
  }

  Flower &base;
};
