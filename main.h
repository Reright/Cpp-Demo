#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

#include <iostream>
using namespace std;
 
class Box
{
public:
	  friend class BoxCaller;
      friend ostream& operator<<(ostream& os, Box& box)  // 可以作为教科书般的用法了
      {
        os << "length: "  << box.length << " breadth: " << box.breadth 
           << " height: " << box.height << endl;
        return os;
      }
private:
      double getVolume(void);
	  double getArea(void);
   
      double length;      // 长度
      double breadth;     // 宽度
      double height;      // 高度
};

double Box::getVolume(void)
{
    return length * breadth * height;
}
 
double Box::getArea(void)
{
    return length * breadth;
}