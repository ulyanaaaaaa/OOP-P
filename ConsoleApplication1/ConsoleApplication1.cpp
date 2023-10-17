
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Interface {
public:
	virtual ~Interface() {}
	void virtual print() = 0;
	void virtual enter() = 0;
	void virtual edit() = 0;
};

template <class T>
struct Status {
	T* ptr;
	int counter;
};

enum State { 
	begin, 
	middle 
};

template<class T>
class Transaction // Транзакции
{
private:
	T* Current_State; // указатель на текущее состояние
	T* Prev_State; // указатель на прошлое состояние
public:
	Transaction() :Prev_State(NULL), Current_State(new T) // конструктор без параметров
	{}
	Transaction(const Transaction& obj) : Current_State(new T(*(obj.Current_State))), Prev_State(NULL) //конструктор копирования 
	{}
	~Transaction()
	{
		delete Current_State; 
		delete Prev_State;
	}

	Transaction& operator=(const Transaction& obj) //оператор писваивания
	{
		if (this != &obj) {
			delete Current_State;
			Current_State = new T(*(obj.Current_State));
		}
		return *this;
	}
	T* operator->() // оператор доступа к объекту через указатель
	{
		return Current_State;
	}
	T& operator*() // разыменование указателя
	{
		T* ptr = Current_State;
		return *ptr;
	}

	void showState(State state)
	{
		cout << "Состояние документа ";
		if (!state) cout << "до начала транзакции " << endl;
		else cout << "после выполнения транзакции " << endl;
		if (Prev_State)
		{
			cout << "prevState = ";
			Prev_State->print();
			cout << endl;
		}
		else {
			cout << "prevState = NULL" << endl;
			cout << "currentState = ";
			Current_State->print();
			cout << endl;
		}
	}
	int beginTransactions()
	{
		delete Prev_State;
		Prev_State = Current_State;
		Current_State = new T(*Prev_State);
		if (!Current_State) return 0;
		Current_State->edit();
		return 1;
	}
	void commit() // подтверждение транзакции
	{
		delete Prev_State;
		Prev_State = NULL;
	}
	void deleteTransactions()
	{
		if (Prev_State != NULL) {
			delete Current_State;
			Current_State = Prev_State;
			Prev_State = NULL;
		}
	}
	bool check_ptr(bool chek)
	{
		if (Prev_State != NULL)
			chek = false;
		return chek;
	}
};

class Document: public Interface {
private:
	int marks;
	string info;
public:
	Document() {
		marks = 0;
		info = "No";
	}
	Document(int marks, string info) {
		this->marks = marks;
		this->info = info;
	}
	Document(Document& copy) {
		marks = copy.marks;
		info = copy.info;
	}
	void print() {
		cout << "Оценки: " << marks << endl;
		cout << "Информация: " << info << endl;
	}
	void enter() {
		cout << "Введите оценки и информацию: " << endl;
		cin >> marks >> info;
	}
	void edit() {
		cout << "Введите новые оценки и информацию:" << endl;
		cin >> marks >> info;
	}
	~Document() {}
};


class Project: public Interface {
private:
	double salary;
	int telNumber;
public:
	Project() {
		salary = 0;
		telNumber = 0000000;
	}
	Project(double salary, int telNumber) {
		this->salary = salary;
		this->telNumber = telNumber;
	}
	Project(Project& copy) {
		salary = copy.salary;
		telNumber = copy.telNumber;
	}
	void print() {
		cout << "Зарплата: " << salary << endl;
		cout << "Номер телефона: " << telNumber << endl;
	}
	void enter() {
		cout << "Введите зарплату и номер телефона: " << endl;
		cin >> salary >> telNumber;
	}
	void edit() {
		cout << "Введите новую зарплату и номер телефона: " << endl;
		cin >> salary >> telNumber;
	}
	~Project() {}
};


template <class T>
class SmartPointer {
	Status<T>* smartPtr;
public:
	SmartPointer(T* ptr)
	{
		if (!ptr)
			smartPtr = NULL;
		else {
			smartPtr = new Status<T>();
			smartPtr->ptr = ptr;
			smartPtr->counter = 1;
		}
	}
	SmartPointer(const SmartPointer& obj) :smartPtr(obj.smartPtr)
	{
		if (smartPtr) smartPtr->counter++;
	}
	~SmartPointer()
	{
		if (smartPtr) {
			smartPtr->counter--;
			if (smartPtr->counter == 0) {
				delete[] smartPtr->ptr;
				delete smartPtr;
			}
		}
	}
	SmartPointer& operator=(const SmartPointer& obj)
	{
		if (smartPtr) {
			smartPtr->counter--;
			if (smartPtr->counter == 0) {
				delete smartPtr->ptr;
				delete smartPtr;
			}
		}
		smartPtr = obj.smartPtr;
		if (smartPtr) smartPtr->counter++;
		return *this;
	}
	T* operator->() const
	{
		if (smartPtr) return smartPtr->ptr;
		else return NULL;
	}
	T& operator*()
	{
		T* ptr = smartPtr->ptr;
		return *ptr;
	}
	T& operator[] (int index)
	{
		T* ptr = smartPtr->ptr;
		return ptr[index];
	}
};

class Teacher: public Interface {
private:
	int experience;
	int age;
public:
	Teacher() {
		experience = 0;
		age = 0;
	}
	Teacher(int experience, int age) {
		this->age = age;
		this->experience = experience;
	}
	Teacher(Teacher& copy) {
		experience = copy.experience;
		age = copy.age;
	}
	void print() {
		cout << "Опыт: " << experience << endl;
		cout << "Стаж: " << age << endl;
	}
	void enter() {
		cout << "Введите опыт и стаж: " << endl;
		cin >> experience >> age;
	}
	void edit() {
		cout << "Введите новый опыт и стаж: " << endl;
		cin >> experience >> age;
	}
	~Teacher(){}

	void Do_transaction(Transaction<Document>& doc)
	{
		bool b = true;
		while (b)
		{
			int choise;
			cout << "Выберете транзакцию:\n1 - Начать изменение документа\n2 - Закончить изменение документа\n3 - Отменить изменение документа\n>";
			cin >> choise;
			switch (choise)
			{
			case 1:
			{
				doc.beginTransactions();
				doc.showState(State::begin);
				cout << "Вы начали изменение документа" << endl;
				b = false;
			}break;
			case 2:
			{
				doc.commit();
				doc.showState(State::middle);
				cout << "Вы закончили изменять документ" << endl;
				b = false;
			}break;
			case 3:
			{
				doc.deleteTransactions();
				doc.showState(State::middle);
				cout << "Вы отменили изменения документа" << endl;
				b = false;
			}break;
			default:cout << "Неверный ввод!" << endl;
			}
		}
	} 
};

int main() {
	setlocale(LC_ALL, "RUS");
	SmartPointer<Teacher> emp(new Teacher[3]);
	Transaction<Document> doc1;
	Document doc;
	Project pro;
	int ans, i;
	while (true) {
		cout << "          Меню:" << endl;
		cout << "1 - Заполнить документы" << endl;
		cout << "2 - Просмотреть документы" << endl;
		cout << "3 - Редактировать документы" << endl;
		cout << "0 - Выход" << endl;
		cin >> ans;
		switch (ans)
		{
		case 1:
			pro.enter();
			cout << "Заполните учителей: " << endl;
			for (i = 0;i < 3;i++) {
				emp[i].enter();
			}
			cout << "Заполните информацию: " << endl;
			doc1->enter();
			break;
		case 2:
			cout << "Учителя:" << endl;
			for (i = 0;i < 3;i++) {
				cout << i + 1 << "." << endl;
				emp[i].print();
				cout << endl;
			}
			cout << "Документ учителя: " << endl;
			cout << "1. "; doc1->print(); cout << endl;
			break;
		case 3:
			cout << "Редактировать документ: " << endl;
			cout << "1. "; doc1->print(); cout << endl;
			emp[0].Do_transaction(doc1);
			break;
		case 0:
			return 0;
		default:
			cout << "Введен некорректный вариант!" << endl;
		}
	}
	return 0;
}


		
	

