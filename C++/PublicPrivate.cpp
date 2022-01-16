#include <iostream>
#include <string>
using namespace std;

//类的声明
class Student{
private:  //私有的
    string m_name;
    int m_age;
    float m_score;

public:  //共有的
    void setname(string name);
    void setage(int age);
    void setscore(float score);
    void show();
};

//成员函数的定义
void Student::setname(string name){
    m_name = name;
}
void Student::setage(int age){
    m_age = age;
}
void Student::setscore(float score){
    m_score = score;
}
void Student::show(){
    cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
}

int main(){
    //在栈上创建对象
    Student stu;
    stu.setname("小明");
    stu.setage(15);
    stu.setscore(92.5f);
    stu.show();


    //在堆上创建对象
    Student *pstu = new Student;
    pstu -> setname("李华");
    pstu -> setage(16);
    pstu -> setscore(96);
    pstu -> show();

    return 0;
}