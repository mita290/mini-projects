#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;

class student{
    string name;
    string residence;
    int roll;
    public: student()
    { 
        cout<<"Student Database"<<endl;
        cout<<"****************"<<endl;
    }
    void getData()
    {
        cout<<"STUDENT NAME: ";
        cin>>name;
        cout<<"STUDENT ROLL NUMBER: ";
        cin>>roll;
        cout<<"PLACE OF RESIDENCE: ";
        cin>>residence;
    }
    void putData()
    {
        cout<<"\nSTUDENT NAME: "<<name<<endl;
        cout<<"STUDENT ROLL NUMBER: "<<roll<<endl;
        cout<<"PLACE OF RESIDENCE: "<<residence<<endl;
    }

};
class marks: public student{
    int eng, mat, sci, ssc, lang;
    float total;
    public:
    void getMarks()
    {
        getData();
        cout<<"MARKS: \n"<<endl;
        cout<<"------"<<endl;
        cout<<"ENGLISH: ";
        cin>>eng;
        cout<<"LANGUAGE: ";
        cin>>lang;
        cout<<"MATHEMATICS: ";
        cin>>mat;
        cout<<"SCIENCE: ";
        cin>>sci;
        cout<<"SOCIAL SCIENCE: ";
        cin>>ssc;
        total = (eng + lang + mat + sci + ssc)/5;
    }
    char calculate()
    {
        if(total>=90)
        {
            return 'A';
        }
        else if(total<90 && total>=75)
        {
            return 'B';
        }
        else if(total<75 && total>=55)
        {
            return 'C';
        }
        else
        {
            return 'D';
        }
    }
    string passFail()
    {
        char x;
        x = calculate();
        if(x == 'A' || x == 'B' || x == 'C')
        {
            return "PASS";
        }
        return "FAIL";
    }
    void putMarks()
    {
        putData();
        cout<<"MARKS: "<<endl;
        cout<<"------"<<endl;
        cout<<"ENGLISH: "<<eng<<endl;
        cout<<"LANGUAGE: "<<lang<<endl;
        cout<<"MATHEMATICS: "<<mat<<endl;
        cout<<"SCIENCE: "<<sci<<endl;
        cout<<"SOCIAL SCIENCE: "<<ssc<<endl;
        cout<<"TOTAL PERCENTAGE: "<<fixed<<setprecision(2)<<total<<endl;
        cout<<"GRADE: "<<calculate()<<endl;
        cout<<"STATUS: "<<passFail();
    }
};

int main()
{
    marks obj;
    obj.getMarks();
    obj.putMarks();
    return 0;
}