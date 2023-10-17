#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//класс-интерфейс
class IPrintable {
public:
	virtual ~IPrintable() {}
	virtual void print() = 0; //реализацией этой функции займутся дочерние классы
	virtual void enter() = 0;
	virtual void change() = 0;
};

class Vehicle: public IPrintable { //транспортное средство
public:
	Vehicle(string type, float speed) {
		this->type = type;
		this->speed = speed;
	}
	Vehicle() {
		type = "No";
		speed = 0;
	}
	Vehicle(const Vehicle& p) {
		type = p.type;
		speed = p.speed;
	}
	void print() override {
		cout << "Type: " << type << endl;
		cout << "Speed: " << speed << endl;
	}
	void enter() override {
		cout << "Enter type and speed: " << endl;
		cin >> type;
		cin >> speed;
	}
	void menu() {
		cout << "1. Create" << endl;
		cout << "2. Enter" << endl;
		cout << "3. Print" << endl;
		cout << "4. Change" << endl;
		cout << "5. Exit" << endl;
	}
	void change() override {
		cout << "What do you want to change: 1.type or 2.speed?" << endl;
		int ans;
		cin >> ans;
		if (ans == 1) {
			cin >> type;
		}
		else if (ans == 2) {
			cin >> speed;
		}
		else {
			cout << "Wrong answer" << endl;
		}
	}
protected:
	string type;
	float speed;
};

class Color {
public:
	Color(string firstColor, string secondColor) {
		this->firstColor = firstColor;
		this->secondColor = secondColor;
	}
	Color() {
		firstColor = "No";
		secondColor = "No";
	}
	Color(Color& a) {
		firstColor = a.firstColor;
		secondColor = a.secondColor;
	}
	void print() {
		cout << "FirstColor: " << firstColor << endl;
		cout << "SecondColor: " << secondColor << endl;
	}
	void enter() {
		cout << "Enter two color: " << endl;
		cin >> firstColor;
		cin >> secondColor;
	}
	void change() {
		cout << "What do you want to change: 1.firstColor or 2.secondColor?" << endl;
		int ans;
		cin >> ans;
		if (ans == 1) {
			cin >> firstColor;
		}
		else if (ans == 2) {
			cin >> secondColor;
		}
		else {
			cout << "Wrong answer" << endl;
		}
	}
protected:
	string firstColor;
	string secondColor;
};

class Car :public Vehicle, public Color{ //автомобиль
public:
	Car(string brand, Color color) {
		this->brand = brand;
		this->color = color;
	}
	Car() {
		brand = "No";
	}
	Car(const Car& c) { 
		brand = c.brand;
		color = c.color;
	}
	void print() override {
		cout << "Brand: " << brand << endl;
		Vehicle::print();
		Color::print();
	}
	void enter() override {
		cout << "Enter brand: " << endl;
		cin >> brand;
		Vehicle::enter();
	    Color::enter();
	}
	void change() override {
		cout << "What do you want to change: 1.brand or 2.color?" << endl;
		int ans;
		cin >> ans;
		if (ans == 1) {
			cin >> brand;
		}
		else if (ans == 2) {
			Color::change();
		}
		else {
			cout << "Wrong answer" << endl;
		}
	}
protected:
	string brand;
	Color color;
};


class MilitaryCar :public virtual Vehicle { //военный автомобиль
public:
	MilitaryCar(string weapon, double damage) {
		this->weapon = weapon;
		this->damage = damage;
	}
	MilitaryCar() {
		weapon = "No";
		damage = 0;
	}
	MilitaryCar(const MilitaryCar& m) {
		weapon = m.weapon;
		damage = m.damage;
	}
	void print() override {
		cout << "Weapon: " << weapon << endl;
		cout << "Damage: " << damage << endl;
		Vehicle::print();
	}
	void enter() override {
		cout << "Enter weapon and damage: " << endl;
		cin >> weapon;
		cin >> damage;
		Vehicle::enter();
	}
	void change() override {
		cout << "What do you want to change: 1.weapon or 2.damage?" << endl;
		int ans;
		cin >> ans;
		if (ans == 1) {
			cin >> weapon;
		}
		else if (ans == 2) {
			cin >> damage;
		}
		else {
			cout << "Wrong answer" << endl;
		}
	}
protected:
	string weapon;
	double damage;
};

class Body :public IPrintable{ //кузов
public:
	Body() {
		height = 0;
		weight = 0;
	}
	Body(double height, double weight) {
		this->height = height;
		this->weight = weight;
	}
	Body(const Body& b) {
		height = b.height;
		weight = b.weight;
	}
	void print() override {
		cout << "Weight: " << weight << endl;
		cout << "Height: " << height << endl;
	}
	void enter() override {
		cout << "Enter weight and height: " << endl;
		cin >> weight;
		cin >> height;
	}
	void change() override {
		cout << "What do you want to change: 1.height or 2.weight?" << endl;
		int ans;
		cin >> ans;
		if (ans == 1) {
			cin >> height;
		}
		else if (ans == 2) {
			cin >> weight;
		}
		else {
			cout << "Wrong answer" << endl;
		}
	}
protected:
	double height;
	double weight;
};

class Engine: public IPrintable{ //двигатель  
public:
	Engine() {
		power = 0;
		producer = "No";
	}
	Engine(double power, string producer) {
		this->power = power;
		this->producer = producer;
	}
	Engine(const Engine& e) {
		power = e.power;
		producer = e.producer;
	}
	void print() override {
		cout << "Power: " << power << endl;
		cout << "Producer: " << producer << endl;
	}
	void enter() override {
		cout << "Enter power and producer: " << endl;
		cin >> power;
		cin >> producer;
	}
	void change() override {
		cout << "What do you want to change: 1.power or 2.producer?" << endl;
		int ans;
		cin >> ans;
		if (ans == 1) {
			cin >> power;
		}
		else if (ans == 2) {
			cin >> producer;
		}
		else {
			cout << "Wrong answer" << endl;
		}
	}
protected:
	double power;
	string producer;
};

int main() {
	int ans, ch, i, n/*, size*/;
	Vehicle a, x;
	Car q;
	MilitaryCar w;
	Body e;
	Engine r;
	vector<Vehicle> arr;
	vector<Engine> arr2;
	vector<Body> arr3;
	vector<Car> arr0;
	vector<MilitaryCar> arr5;
	while (true) {
		cout << "-------MENU-------" << endl;
		cout << "1. Vehicle" << endl;
		cout << "2. Car" << endl;
		cout << "3. Military car" << endl;
		cout << "4. Body" << endl;
		cout << "5. Engine" << endl;
		cout << "0. Exit" << endl;
		cin >> ans;
		switch (ans) {
		case 1:
			a.menu();
			cin >> ch;
			switch (ch) {
			case 1:
				cout << "Vehicle is create!" << endl;
				break;
			case 2:
				x.enter();
				arr.push_back(x);
				break;
			case 3:
				for (i = 0;i < arr.size();i++) {
					arr[i].print();
				}
				break;
			case 4:
				for (i = 0;i < arr.size();i++) {
					arr[i].print();
				}
				cout << "What number do you want change?" << endl;
				cin >> n;
				arr[n-1].change();
				break;
			case 5:
				return 0;
				break;
			}
			break;
		case 2:
			a.menu();
			cin >> ch;
			switch (ch) {
			case 1:
				cout << "Car is create!" << endl;
				break;
			case 2:
				q.enter();
				arr0.push_back(q);
				break;
			case 3:
				for (i = 0;i < arr0.size();i++) {
					arr0[i].print();
				}
				break;
			case 4:
				for (i = 0;i < arr0.size();i++) {
					arr0[i].print();
				}
				cout << "What number do you want change?" << endl;
				cin >> n;
				arr0[n-1].change();
				break;
			case 5:
				return 0;
				break;
			}
			break;
		case 3:
			a.menu();
			cin >> ch;
			switch (ch) {
			case 1:
				cout << "Military car is create!" << endl;
				break;
			case 2:
				w.enter();
				arr5.push_back(w);
				break;
			case 3:
				for (i = 0;i < arr5.size();i++) {
					arr5[i].print();
				}
				break;
			case 4:
				for (i = 0;i < arr5.size();i++) {
					arr5[i].print();
				}
				cout << "What number do you want change?" << endl;
				cin >> n;
				arr5[n-1].change();
				break;
			case 5:
				return 0;
				break;
			}
			break;
		case 4:
			a.menu();
			cin >> ch;
			switch (ch) {
			case 1:
				cout << "Body is create!" << endl;
				break;
			case 2:
				e.enter();
				arr3.push_back(e);
				break;
			case 3:
				for (i = 0;i < arr3.size();i++) {
					arr3[i].print();
				}
				break;
			case 4:
				for (i = 0;i < arr3.size();i++) {
					arr3[i].print();
				}
				cout << "What number do you want change?" << endl;
				cin >> n;
				arr3[n-1].change();
				break;
			case 5:
				return 0;
				break;
			}
			break;
		case 5:
			a.menu();
			cin >> ch;
			switch (ch) {
			case 1:
				cout << "Engine is create!" << endl;
				break;
			case 2:
				r.enter();
				arr2.push_back(r);
				break;
			case 3:
				for (i = 0;i < arr2.size();i++) {
					arr2[i].print();
				}
				break;
			case 4:
				for (i = 0;i < arr2.size();i++) {
					arr2[i].print();
				}
				cout << "What number do you want change?" << endl;
				cin >> n;
				arr2[n-1].change();
				break;
			case 5:
				return 0;
			}
			break;
		case 0:
			return 0;
		default:
			cout << "Error!" << endl;
			break;
		}
	}
	return 0;
}