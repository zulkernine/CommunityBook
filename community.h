#include<bits/stdc++.h>

//base class
class Person{
  protected:
    std::string first_name,last_name;
    std::string number,pincode;
  public:
    Person(){
        first_name = "\0";
        last_name = "\0";
        number = "\0";
        pincode = "\0";
    }
};


//derived class
class Friend:public Person{
    std::string email,School;
  public:
    Friend(){
        email = "\0"; School = "\0";
    }
    friend std::ostream& operator<<(std::ostream& stream, Friend &f);
    friend std::istream& operator>>(std::istream& stream,Friend &f);
    friend std::ofstream& operator<<(std::ofstream& stream, Friend &f);
    friend std::ifstream& operator>>(std::ifstream& stream, Friend &f);

};

std::ostream& operator<<(std::ostream& stream, Friend &f){
    stream<<"Name: "<<f.first_name<<" "<<f.last_name<<std::endl;
    stream<<"School: "<<f.School<<std::endl;
    stream<<"Pincode: "<<f.pincode<<std::endl;
    stream<<"email: "<<f.email<<"\tNumber: "<<f.number<<std::endl;
    return stream;
}
std::istream& operator>>(std::istream& stream,Friend &f){
    std::cout<<"First Name: "; stream>>f.first_name;
    std::cout<<"Last Namae: "; stream>>f.last_name;
    std::cout<<"Number: "; stream>>f.number;
    std::cout<<"Area code: "; stream>>f.pincode;
    std::cout<<"Email Address: "; stream>>f.email;
    std::cout<<"School Namae: "; stream>>f.School;
    return stream;
}
std::ofstream& operator<<(std::ofstream& stream, Friend &f){
    stream<<f.first_name<<" " <<f.last_name<<" " <<f.School<<" " <<f.pincode<<" " <<f.email<<" " <<f.number<<std::endl;
    return stream;
}
std::ifstream& operator>>(std::ifstream& stream, Friend &f){
    stream>>f.first_name>>f.last_name>>f.School>>f.pincode>>f.email>>f.number;
    return stream;
}


//derived class
class relative: public Person{
    std::string relation;

};