#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Student
{
    private:
    string sname;
    int roll;
    float eng, lang, math, sci, ssc, average;

    public:
    //the function below assigns values to all the variables
    void putData(string n, int r, float e, float l, float m, float sc, float ss)
    {
        sname = n;
        roll = r;
        eng = e;
        lang = l;
        math = m;
        sci = sc;
        ssc = ss;
        average = (lang + math + sci + ssc + eng)/5;
    }
    int getRoll()
    {
        return roll;
    }
    void report()
    {
        cout<<"STUDENT REPORT"<<endl;
        cout<<"=============="<<endl;
        cout<<"STUDENT NAME: "<<sname<<endl;
        cout<<"STUDENT ROLL NUMBER: "<<roll<<endl;
        cout<<"MARKS:"<<endl;
        cout<<"ENGLISH: "<<eng<<endl;      
        cout<<"LANGUAGE: "<<lang<<endl;
        cout<<"MATHEMATICS: "<<math<<endl;
        cout<<"SCIENCE: "<<sci<<endl;
        cout<<"SOCIAL SCIENCE: "<<ssc<<endl;
        cout<<"AVERAGE: "<<average<<endl;
        cout<<"GPA: "<<average/10<<endl;
    }
};

//vector is used below --> provides size extension
vector<Student> database;
int dbsize;
void viewReport(int roll)
{
    for(int i=0; i<dbsize; i++)
    {
        if(database[i].getRoll() == roll)
        {
            database[i].report();
            return;
        }
    }
    cout<<"THE ROLL NUMBER YOU ENTERED DOES NOT EXIST."<<endl;
} 
void resizeDatabase()
{
    database.resize(dbsize);
}

void showSize()
{
    cout<<"Size: "<<dbsize<<endl;
    cout<<"List Of Roll Numbers: "<<endl;
    if(dbsize==0)
    {
        cout<<"DATABASE IS EMPTY."<<endl;
        return;
    }
    for(int i=0; i<dbsize; i++)
    {
        cout<<database[i].getRoll()<<" ";
        cout<<"\n";
    }
}

void add()
{
	string name;
	int roll;
	float english, language, science, social_science, math;

	cout<<"\nPLEASE ENTER THE DETAILS OF THE STUDENT:" << endl;
	cout<<"STUDENT NAME: ";
	cin>>name;
	cout<<"STUDENT ROLL: ";
	cin>>roll;
	cout<<"MARKS IN ENGLISH: "<<endl;
    cin>>english;
    cout<<"MARKS IN LANGUAGE: "<<endl;
    cin>>language;
    cout<<"MARKS IN SCIENCE: "<<endl;
    cin>>science;
    cout<<"MARKS IN MATH: "<<endl;
    cin>>math;
    cout<<"MARKS IN SOCIAL SCIENCE: "<<endl;
    cin>>social_science;
	cout <<"\nSTUDENT DATA ADDED TO DATABASE"<<endl;
    dbsize++;
    resizeDatabase();
    database[dbsize - 1].putData(name, roll, english, language, science, social_science, math);
}

void remove(int roll)
{
    for(int i=0; i<dbsize; i++)
    {
        if(database[i].getRoll() == roll)
        {
            database[i].report();
            database.erase(database.begin() + i);
            cout <<"\nSTUDENT WITH ROLL " << roll<<" HAS BEEN REMOVED FROM THE DATABASE\n"<<endl;
			dbsize--;
			return;
        }
    }
    cout << "\nTHE ENTERED ROLL("<< roll<<") DOES NOT EXIST.\n"<< endl;
}

int main()
{
    int choice, roll;
    cout<<"STUDENT REPORT DATABASE MANAGEMENT"<<endl;
	cout<<"=================================="<<endl;
   
    do
    {
        cout <<"\n1. ADD NEW STUDENT DATA\n2. DELETE STUDENT DATA\n3. PRINT REPORT\n4. DATABASE STATS\n0. EXIT"<< endl;
		cout <<"YOUR CHOICE: ";
        cin>>choice;
        
        switch(choice)
        {
            case 1: add();
                    break;

            case 2: 
                    cout<<"ROLL: ";
			        cin>>roll;
			        remove(roll);
			        break;
            
            case 3: 
                    cout<<"ROLL: ";
			        cin>>roll;
                    viewReport(roll);
                    break;
            
            case 4: 
                    showSize();
                    break;

            case 0: break;
            
            default: cout<<"INVALID CHOICE"<<endl;
            break;
        }
    } while (choice!=0);

    return 0;    
}