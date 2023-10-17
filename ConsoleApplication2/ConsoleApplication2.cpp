#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


using namespace std;

// Базовый класс "Книга"
class Book {
protected:
    string title;
    string author;
    int year;
public:
    Book(string title, string author, int year) {
        this->title = title;
        this->author = author;
        this->year = year;
    }

    Book() {
        title = "NO";
        author = "NO";
        year = 0;
    }

    string getName() {
        return title;
    }
         
    virtual void printInfo() {
        std::cout << std::setw(15) << std::left << "Название:" << title << std::endl;
        std::cout << std::setw(15) << std::left << "Автор:" << author << std::endl;
        std::cout << std::setw(15) << std::left << "Год издания:" << year << std::endl;
    }
    virtual void enterInfo() {
        cout << "Название: " << endl;
        cin >> title;
        cout << "Автор: " << endl;
        cin >> author;
        cout << "Год издания: " << endl;
        try {                                       //ПЕРЕНАПРАВЛЕНИЕ ИСКЛЮЧИТЕЛЬНЫХ СИТУАЦИЙ
            cin >> year;
            if (year < 0 || year > 2023) throw 1;
            else if (year > 0 && year < 2024) {}
            else throw 1;
        }
        catch (int) {
            cout << "Данные введены неверно" << endl;
            throw;                  
        }
    }
};

// Класс "Художественная книга"
class FictionBook : public Book {
private:
    string genre;
public:
    FictionBook(string title, string author, int year, string genre) {
        Book(title, author, year);
        this->genre = genre;
    }
        
    FictionBook() {
        Book();
        genre = "NO";
    }

    void printInfo() override {
        cout << std::setw(15) << std::left << "Художественная книга" << endl;
        Book::printInfo();
        cout << std::setw(15) << std::left << "Жанр: " << genre << endl;
    }

    void enterInfo() override {
        Book::enterInfo();
        cout << "Введите жанр: " << endl;
        cin >> genre;
    }
};

// Класс "Учебник"
class Textbook : public Book {
private:
    string subject;
    int grade;
public:
    Textbook(string& title, string& author, int year, string& subject, int grade)
        : Book(title, author, year), subject(subject), grade(grade) {}

    Textbook() {
        Book:Book();
        subject = "0";
        grade = 0;
    }

    void printInfo() override {
        cout << std::setw(15) << std::left << "Учебник" << endl;
        Book::printInfo();
        cout << std::setw(15) << std::left << "Предмет: " << subject << endl;
        cout << std::setw(15) << std::left << "Класс: " << grade << endl;
    }
    void enterInfo() override {
        cout << "Учебник" << endl;
        Book::enterInfo();
        cout << "Предмет: " << endl;
        cin >> subject;
        cout << "Класс: " << endl;
        while (true) {
            cin >> grade;
            if (cin.good()) {//если нет ошибок
                break;
            }//выйти из цикла
            cin.clear();//Очистить биты ошибок
            cout << "Неправильный ввод данных\n";
            cin.ignore(10, '\n');//удалить из потока 10 символов до
            //знака перехода на новую строку
        }
        if (grade < 0 || grade > 11) throw 1;  //выбрасывание исключения в случае неверного ввода
        else if (grade > 0 && grade < 12) {}
        else throw 1;
    }
};

// Класс "Заказ"
class Order {
private:
    int number;
public:
    int getNumber() {
        return number;
    }

    void printInfo(){
        cout << std::setw(15) << std::left << "Номер заказа: " << number << endl;
    }

    void enterInfo() {
        cout << "Введите номер заказа: " << endl;
        cin >> number;
    }

    Order(int number = 0) {
        this->number = number;
    }

    ~Order() {
        cout << "Удаление заказа, завершите программу" << endl;
    }

    void exitFoo() {          //собственная функция завершения
        cout << "Функция exitFoo вызвана функцией terminate()" << endl;
        exit(-1);             //само завершение программы вручную
    }
};

// Создаем пользовательский класс исключения
class MyException : public exception {
public:
    const char* what() const throw() {
        return "Произошло пользовательское исключение!";
    }
};

void myExitFunction() {
    cout << "Выполняется моя собственная функция завершения кода" << endl;
    exit(0);
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<FictionBook> fictionBook;
    vector<Textbook> textbook;
    FictionBook a;
    int count, s, num, size, bb;
    Textbook b;
    string name;
    vector<Order> order1;
    int* numbers;
    Order r;
    cout.setf(ios::right, ios::skipws);
    try {
        while (true) {
            if (cout.eof()) {
                cout << "Достигнут конец потока cout." << endl;
            }
            else {
                cout << "Меню:" << endl;
                cout << "1. Просмотр:" << endl;
                cout << "2. Добавление:" << endl;
                cout << "3. Редактирование:" << endl;
                cout << "4. Поиск:" << endl;
                cout << "5. Оформить заказ:" << endl;
                cout << "6. Сортировка:" << endl;
                cout << "0. Выход:" << endl;
            }
            int ans;
            while (true) {
                cout << "Введите пункт меню: ";
                cin >> ans;
                if (cin.good()) {                      //если нет ошибок
                    break;
                }                                      //выйти из цикла
                cin.clear();                           //Очистить биты ошибок
                cout << "Неправильный ввод данных\n";
                cin.ignore(10, '\n');                  //Удалить разделитель строк
            }
            switch (ans) {
            case 1:
                cout << "Меню:" << endl;
                cout << "1. Просмотр всех книг фантастики:" << endl;
                cout << "2. Просмотр всех учебников:" << endl;
                cout << "3. Просмотр всех заказов:" << endl;
                cin >> ans;
                if (ans == 1) {
                    for (int i = 0; i < fictionBook.size(); i++) {
                        fictionBook[i].printInfo();
                    }
                }
                else if (ans == 2) {
                    for (int i = 0; i < textbook.size(); i++) {
                        textbook[i].printInfo();
                    }
                }
                else if (ans == 3) {
                    for (int i = 0; i < order1.size(); i++) {
                        order1[i].printInfo();
                    }
                }
                else {
                    cout << "Неверный ввод" << endl;
                }
                break;

            case 2:
                if (cout.bad()) {
                    cout << "Произошла критическая ошибка потока cout." << endl;
                }
                else {
                    cout << "Меню:" << endl;
                    cout << "1. Добавление книг фантастики:" << endl;
                    cout << "2. Добавление учебников:" << endl;
                }
                cin >> bb;
                if (bb == 1) {
                    a.enterInfo();
                    fictionBook.push_back(a);
                }
                else if (bb == 2) {
                    b.enterInfo();
                    textbook.push_back(b);
                }
                else {
                    cout << "Неверный ввод" << endl;
                }
                break;

            case 3:
                cout << "Меню:" << endl;
                cout << "1. Редактировать книги фантастики:" << endl;
                cout << "2. Редактировать учебники:" << endl;
                cin >> ans;
                if (ans == 1) {
                    for (int i = 0; i < fictionBook.size(); i++) {
                        fictionBook[i].printInfo();
                    }
                    cout << "Введите номер книги которую хотите редактировать: " << endl;
                    cin >> num;
                    fictionBook[num].enterInfo();
                }
                else if (ans == 2) {
                    for (int i = 0; i < textbook.size(); i++) {
                        fictionBook[i].printInfo();
                    }
                    cout << "Введите номер учебника который вы хотите редактировать: " << endl;
                    cin >> num;
                    textbook[num].enterInfo();
                }
                else {
                    cout << "Неверный ввод" << endl;
                }
                break;
            
            case 4:
                cout << "Меню:" << endl;
                cout << "1. Поиск книг фантастики:" << endl;
                cout << "2. Поиск учебников:" << endl;
                cin >> ans;
                if (ans == 1) {
                    cout << "Введите название книги: " << endl;
                    cin >> name;
                    for (int i = 0; i < fictionBook.size(); i++) {
                        if (fictionBook[i].getName() == name) {
                            fictionBook[i].printInfo();
                        }
                    }
                    cout << "Поиск окончен!" << endl;
                }
                else if (ans == 2) {
                    cout << "Введите название учебника: " << endl;
                    cin >> name;
                    for (int i = 0; i < textbook.size(); i++) {
                        if (textbook[i].getName() == name) {
                            textbook[i].printInfo();
                        }
                    }
                    cout << "Поиск окончен!" << endl;
                }
                else {
                    cout << "Неверный ввод" << endl;
                }
                break;

            case 5:
                r.enterInfo();
                order1.push_back(r);
                cout << "Ваш заказ:" << endl;
                for (int i = 0; i < order1.size(); i++) {
                    order1[i].printInfo();
                }
                for (int i = 0; i < textbook.size(); i++) {
                    textbook[i].printInfo();
                }
                for (int i = 0; i < fictionBook.size(); i++) {
                    fictionBook[i].printInfo();
                }
                break;

            case 6:
                size = order1.size();
                numbers = new int[size];
                for (int i = 0; i < size; i++) {
                    numbers[i] = order1[i].getNumber();
                }
                cout << "Сортировка заказов по номерам....." << endl;
                for (int i = 0; i < size - 1; i++) {
                    for (int j = 0; j < size - i - 1; j++) {
                        if (numbers[j] > numbers[j + 1]) {
                            int temp = numbers[j];
                            numbers[j] = numbers[j + 1];
                            numbers[j + 1] = temp;
                        }
                    }
                }
                cout << "Готово!" << endl;
                cout << "Ваши заказы: " << endl;
                for (int i = 0; i < size; i++) {
                    cout << numbers[i] << endl;
                }
                break;

            case 0:
                return 0;
                break;
            }
        }
    }


    catch (int) {
        cout << "Данные введены неккоректно!" << endl;
    }
    catch (...) {
        cout << "Данные введены неккоректно!" << endl;
    }

    //вызов пользовательского исключения
    try {
        cout << "Вызов пользовательского исключения" << endl;
        throw MyException();
    }
    catch (MyException& e) {
        cout << "Исключение поймано: " << e.what() << endl;
    }
    catch (exception& e) {
        cout << "Поймано стандартное исключение: " << e.what() << endl;
    }

    // Очистка флагов ошибок
    cout.clear();

    set_terminate(myExitFunction);   
}




