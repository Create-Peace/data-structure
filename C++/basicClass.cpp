#include <iostream>
#include <string>
//通过class关键字类定义类
using namespace std;
class Student{
public:
    //类包含的变量
    string name;
    int age;
    float score;
    //类包含的函数
    void say(){
        cout << "name: " << name << " age: " << age << " score:" << score << endl;
    }
};
int main(){
    //通过类来定义变量，即创建对象
    class Student stu1;  //也可以省略关键字class
    //为类的成员变量赋值
    // strcpy(stu1.name, "小明");
    stu1.name = "小明";
    stu1.age = 15;
    stu1.score = 92.5f;
    //调用类的成员函数
    stu1.say();
    return 0;
}