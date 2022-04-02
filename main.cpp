#include "main.h"
 
using namespace std;
 
class BoxCaller
{
public:
	//设置长宽高
    void setLength( double len ){
        box.length = len;  // 可以访问Box的private变量
    }
    void setBreadth( double bre ){
        box.breadth = bre;
    }
    void setHeight( double hei ){
        box.height = hei;
    }

    void Show()
    {
        cout << "BoxCaller has box: " << box << endl;
    }
 
	//获取长宽高
	double getLength(){
        return box.length;
    }
	double getBreadth(){
        return box.breadth;
    }
	double getHeight(){
        return box.height;
    }
 
	//获取体积
	double getVolume(){
		return box.getVolume();
	}
	//获取面积
	double getArea(){
		return box.getArea();
	}
 
private:
      Box box;
};
 
int main(int argc, char**  argv)
{
	BoxCaller caller;
	caller.setLength(5);
    cout << "length : " << caller.getLength() << endl;
 
    caller.setBreadth(6);
    cout << "breadth : " <<  caller.getBreadth() << endl;
 
	caller.setHeight(7);
    cout << "height : " << caller.getHeight() << endl;
 
	double volume = caller.getVolume();
	cout << "volume : " << volume << endl;
 
	double area = caller.getArea();
	cout << "area : " << area << endl;

    caller.Show();
	return 0;
}
