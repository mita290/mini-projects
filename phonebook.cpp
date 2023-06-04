#include <iostream>
#include <cstring>
using namespace std;

class node{
    public:
    char number[50];
    char email[50];
    char name[50];

    node *prev, *next;
    node(char n[], char num[], char e[]){
        strcpy(name, n);
        strcpy(number, num);
        strcpy(email, e);
        next=NULL;
        prev=NULL;
    }
    friend class list;
};

class list{
    node *head, *temp, *ptr;
    node *ptr1, *ptr2, *dup;

    public:

    node *prevn;

    void insert();
    void sort();
    void deleteContact(char n[20]);
    void deleteSameNumber();
    void deleteSameName();
    void deleteSameEmail();
    void SearchByName(char p[20]);
    void SearchByNumber(char no[30]);
    void SearchByEmail(char g[20]);

    void accept();
    void display();
    void update(char ch[10]);
    list(){
            head=NULL;
            temp=NULL;
            ptr=NULL;
            ptr1=NULL;
            ptr2=NULL;
            dup=NULL;
        }
};

void list::accept(){
    char number[50];
    char email[50];
    char name[50];
    char ans;

    do{
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter number: ";
        cin>>number;
        while(strlen(number)!=10){
            cout<<"Enter valid number: ";
            cin>>number;
        }
        cout<<"Enter email: ";
        cin>>email;
        temp =  new node(name, number, email);
        if(head==NULL){
            head=temp;
        }
        else{
            ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=temp;
            temp->prev=ptr;
        }
        cout<<"Do you wish to enter details for another contact?"<<endl;
        cin>>ans;    
    }while(ans=='y');
}

void list::display(){
    ptr=head;
    while(ptr!=NULL){
        cout<<"\n\nName: "<<ptr->name;
        cout<<"\nNUMBER:: +91-"<<ptr->number;
		cout<<"\nG-MAIL:: "<<ptr->email;
		ptr=ptr->next;

    }
}

void list::insert(){
    accept();
}

void list::sort(){
    node *i, *j;
    int temp;
    char n[10];
    for(i=head; i->next!=NULL;i=i->next){
        for(j=i->next; j!=NULL; j=j->next){
            temp=strcmp(i->name,j->name);
            if(temp>0){
                strcpy(n,i->name);
                strcpy(i->name,j->name);
                strcpy(j->name,n);
            }
        }
    }
}

void list::deleteContact(char s[20]){
    int c=0;
    ptr=head;
    while(ptr!=NULL){
        if(strcmp(s,ptr->name)==0){
            c=1;
            break;
        }
        else{
            c=2;
        }
        ptr=ptr->next;
    }
    if(c==1 && ptr!=head && ptr->next!=NULL){
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        delete(ptr);
        cout<<"Contact deleted."<<endl;
    }
    if(ptr==head){
        head=head->next;
        head->prev=NULL;
        delete(ptr);
        cout<<"Contact deleted."<<endl;
    }
    if(ptr->next==NULL){
        ptr->prev->next=NULL;
        ptr->prev=NULL;
        delete(ptr);
        cout<<"Contact deleted."<<endl;
    }
    if(c==2){
        cout<<"Name not in list."<<endl;
    }
}

void list::deleteSameEmail(){
    ptr1=head;
    while (ptr1 != NULL && ptr1->next != NULL){ 
        ptr2 = ptr1; 
        while (ptr2->next != NULL){ 
            if (strcmp(ptr1->email,ptr2->next->email)==0){ 
                dup = ptr2->next; 
                ptr2->next = ptr2->next->next; 
                delete(dup); 
            } 
            else{
                ptr2 = ptr2->next; 
            }
        }
    ptr1 = ptr1->next; 
    } 
}

void list::deleteSameNumber(){
    ptr1=head;
    while (ptr1 != NULL && ptr1->next != NULL){ 
        ptr2 = ptr1; 
        while (ptr2->next != NULL){ 
            if (strcmp(ptr1->number,ptr2->next->number)==0){ 
                dup = ptr2->next; 
                ptr2->next = ptr2->next->next; 
                delete(dup); 
            } 
            else{
                ptr2 = ptr2->next; 
            }
        }
    ptr1 = ptr1->next; 
    } 
}

void list::SearchByName(char N[10]){
    ptr=head;
    while(ptr!=NULL){
        if(strcmp(N,ptr->name)==0){
            cout<<"Name found!"<<endl;
            cout<<"Details are as follows: "<<endl;
            cout<<"\nName "<<ptr->name;
            cout<<"\nPhone Number: +91-"<<ptr->number;
            cout<<"\nEmail Id: "<<ptr->email;
        }
        ptr=ptr->next;
    }
}

void list::SearchByNumber(char N[20]){
    ptr=head;
    while(ptr!=NULL){
        if(strcmp(N,ptr->number)==0){
            cout<<"Number found!"<<endl;
            cout<<"Details are as follows: "<<endl;
            cout<<"\nName "<<ptr->name;
            cout<<"\nPhone Number: +91-"<<ptr->number;
            cout<<"\nEmail Id: "<<ptr->email;
        }
        ptr=ptr->next;
    }
}

void list::SearchByEmail(char N[20]){
    ptr=head;
    while(ptr!=NULL){
        if(strcmp(N,ptr->email)==0){
            cout<<"Email found!"<<endl;
            cout<<"Details are as follows: "<<endl;
            cout<<"\nName "<<ptr->name;
            cout<<"\nPhone Number: +91-"<<ptr->number;
            cout<<"\nEmail Id: "<<ptr->email;
        }
        ptr=ptr->next;
    }
}

void list::update(char N[20]){
    char ans;
    int c;
    ptr=head;
    while(ptr!=NULL){
        if(strcmp(N,ptr->name)==0){
            do{
                cout<<"What do you wish to update?\n";
                cout<<"1.NAME\n2.PHONE NUMBER\n3.EMAIL\n";
                cin>>c;
                switch(c){
                    case 1:
                        cout<<"Enter new name: ";
                        cin>>ptr->name;
                        break;
                    
                    case 2:
                        cout<<"Enter new number: ";
                        cin>>ptr->number;
                        while(strlen(ptr->number)!=10){
                            cout<<"Enter number: ";
                            cin>>ptr->number;
                        }
                        break;               
                    
                    case 3:
                        cout<<"Enter new email: ";
                        cin>>ptr->email;
                        break;    
                }
                cout<<"Do you wish to make further updates? ";
                cin>>ans; 
            }while(ans=='y');
        }
        ptr=ptr->next;
    }
}

int main(){
    char n[20];
    char nam[20];
    char name[10];
    char number[10];
    char email[20];

    list l1;
    char ans;
    int ch, a;
    cout<<"**************                                PHONE BOOK                          ********************";
    cout<<"\n\nWHAT IS YOUR NAME?\n";
    cin.getline(name,20); 
    cout<<"\n\n!!!!!!!!!!!!!!!!!!!!!!!   WELCOME "<<name<<"   !!!!!!!!!!!!!!!!!!!!!";
    cout<<"\n\n\nLET'S CREATE OUR PHONEBOOK "<<name<<"  \n\n";
    l1.accept();
    l1.sort(); 
    do{
        cout<<"\n\n\n\n1) DISPLAY YOUR PHONE BOOK\n2) INSERT NEW CONTACT\n3) UPDATE DETAILS ON EXISTING CONTACT\n4) DELETE CONTACT\n5) DELETE SAME NAME IN PHONEBOOK\n6) DELETE SAME NUMBERS IN PHONEBOOK\n7) SEARCH\n";
        cin>>ch;
        switch(ch){
            case 2:
                l1.insert();
                l1.sort();
                break;
    
            case 1:
                l1.display();
                break;

            case 3:
    
                cout<<"\n\nENTER THE NAME OF PERSON WHOSE DETAILS YOU WANT TO UPDATE...\n";
                cin>>n;
                l1.update(n);
                l1.sort();
                break;
            
            case 4:
                cout<<"\nENTER THE NAME YOU WANT TO DELETE FROM PHONEBOOK\n";
                cin>>name;
                l1.deleteContact(name);
                break;
     
            case 5:
                l1.deleteSameEmail();
                l1.display();
                break;
    
            case 6:
                l1.deleteSameNumber();
                l1.display();
                break;
    
            case 7:
                do{
                    cout<<"1.SEARCH BY NAME\n2.SEARCH BY NUMBER\n3.SEARCH BY GMAIL";
                    cin>>a;
                    switch(a){
                        case 1:
                            cout<<"ENTER THE NAME TO BE SEARCHED\n";
                            cin>>name;
                            l1.SearchByName(name);
                            break;
        
                        case 2:
                            cout<<"ENTER THE NUMBER TO BE SEARCHED\n";
                            cin>>number;
                            l1.SearchByNumber(number);
                            break;
        
                        case 3:
                            cout<<"ENTER THE EMAIL TO BE SEARCHED\n";
                            cin>>email;
                            l1.SearchByEmail(email);
                            break;
        
                        default:cout<<"\nNO PROPER INPUT GIVEN.....\n";
                    }
                    cout<<"DO YOU WANT TO CONTINUE SEARCHING?";
                    cin>>ans;
                }while(ans=='y');
                break;
    
                case 8:
                    l1.deleteSameEmail();
                    l1.display();
                    break;
    
                default:cout<<"\nNO PROPER INPUT GIVEN..\n";
            }
            cout<<"\n\nDO YOU WANT TO CONTINUE OPERATIONS?????????";
            cin>>ans;
    }while(ans=='y');
}      
