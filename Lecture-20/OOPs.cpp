// OOPs
#include <iostream>
using namespace std;
///////////////////////// BLUEPRINT ////////////////////////////
class Car{
private:
	int price;// Private members can be accessed only inside the class
public:
	char *name;
	int model;
	// int price;
	int seats;
	
	// Constructor - We use constructor to create an Object, it helps to create an Object
	// 1. Default Constructor
	Car(){
		name = NULL;
		// cout<<"In Default Constructor"<<endl;
	}

	// 2. Parameterized Constructor
	Car(char *n,int m,int p,int s){
		// cout<<"Inside Parameterized Constructor"<<endl;
		name = new char[strlen(n)+1];
		strcpy(name,n);
		model = m;
		price = p;
		seats = s;
	}

	// Copy Constructor
	Car(Car &X){
		// cout<<"Inside Copy Constructor"<<endl;
		name = new char[strlen(X.name)+1];
		strcpy(name,X.name);
		// name = X.name;
		price = X.price;
		model = X.model;
		seats = X.seats;
	}

	// Copy Assignment Operator
	void operator=(Car X){
		cout<<"Inside Copy Assignment"<<endl;
		name = new char[strlen(X.name)+1];
		strcpy(name,X.name);
		price = X.price;
		model = X.model;
		seats = X.seats;
	}

	// Print all the details
	void Print(){
		cout<<"Name : "<<name<<endl;
		cout<<"Price: $"<<price<<endl;
		cout<<"Model: "<<model<<endl;
		cout<<"Seats: "<<seats<<endl<<endl;
	}

	void UpdateName(char *n){
		if(name != NULL){
			// There is some name already
			delete []name;
			name = NULL;
		}
		name = new char[strlen(n)+1];
		strcpy(name,n);
	}
	
	// Setter
	void setPrice(int p){
		if(p>200){
			price = p;
		}
		else{
			price = 200;
		}
	}
	
	// Getter
	int getPrice(){
		return price;
	}
	
	// Destructor
	~Car(){
		cout<<"In Destructor "<<name<<endl;
		delete []name;
	}
};
///////////////////////// !BLUEPRINT ////////////////////////////

int main(){
	Car A; // This takes space, when object is created constructor is called
	// Constructor creates the object, and it gets called when the object is created
	// A.name = "BMW";
	// strcpy(A.name,"BMW");
	A.UpdateName("BMW");
	// A.price = 100;
	A.setPrice(150);
	A.model = 2020;
	A.seats = 4;
	// A.UpdateName("Maruti");
	// A.Print();
	// cout<<A.name<<endl;
	// cout<<A.price<<endl;
	cout<<A.getPrice()<<endl;
	// cout<<A.model<<endl;
	// cout<<A.seats<<endl;
	// char x[100]="Audi";
	Car B("Audi",2019,150,2);
	
	
	Car C = B; // Car C(B);
	Car D = B; // Car C(B);

	C.name[0] = 'B';

	C = A;
	C.name[0] = 'D';
	A.Print();
	B.Print();
	C.Print();
	D.Print();
	
	return 0;
}