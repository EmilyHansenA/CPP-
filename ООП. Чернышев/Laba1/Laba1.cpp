#include <iostream>
#include <string>

using namespace std;

//Enum для марок автомобилей
enum CarBrand {
	TOYOTA,
	HONDA,
	BMW,
	MERCEDES,
	FORD,
	AUDI
};


class Person {

private:

	string personFirstName;
	string personSurName;
	string personMiddleName;

	int personAge;

public:

	//Конструкторы. 
	// Const string& — передает по ссылке + защита от изменений. Для int не надо, 
	// Ибо передается значение переменной, а не сама переменная.
	Person() : personFirstName(""), personSurName(""), personMiddleName(""), personAge(0) {}

	Person(const string& fName, const string& sName, const string& mName, int age) :
		personFirstName(fName), personSurName(sName), personMiddleName(mName), personAge(age) {}

	//Get and set in c++. (где мой синтаксический сахар из c#..)
	//Сеттер и геттер для имени пользователя с проверкой длины.
	string getFirstName() const { return personFirstName; }
	void setFirstName(const string& fName) {
		if (fName.length() <= 20) {
			personFirstName = fName;
		}
		else
		{
			cout << "Ошибка. Имя слишком длинное. Максимальное количество символов 20." << endl;
		}
	}
	//Сеттер и геттер для фамилии пользователя с проверкой длины.
	string getSurName() const { return personSurName; }
	void setSurName(const string& sName) {
		if (sName.length() <= 20) {
			personSurName = sName;
		}
		else
		{
			cout << "Ошибка. Фамилия слишком длинная. Максимальное количество символов 20." << endl;
		}
	}
	//Сеттер и геттер для отчества пользователя с проверкой длины.
	string getMiddleName() const { return personMiddleName; }
	void setMiddleName(const string& mName) {
		if (mName.length() <= 20) {
			personMiddleName = mName;
		}
		else
		{
			cout << "Ошибка. Имя слишком длинное. Максимальное количество символов 20." << endl;
		}
	}

	// Метод для получения возраста пользователя.
	int getAge() const { return personAge; }

	//Сеттер для возраста пользователя с проверкой значения.
	void setAge(int age) {
		if (age >= 0 && age <= 200) {
			personAge = age;
		}
		else
		{
			cout << "Ошибка. Возраст должен находится от 0 до 200 лет." << endl;
		}
	}

	// Метод вывода информации о пользователя на экран.
	void printPersonInfo() const {
		cout << "Имя: " << personFirstName << endl;
		cout << "Фамилия: " << personSurName << endl;
		cout << "Отчество: " << personMiddleName << endl;
		cout << "Возраст: " << personAge << endl;
	}
};

//Класс автомобиль
class Car {

private:
	Person driver;
	CarBrand brand;
	string carNumber;
public:

	//Конструктор по умолчанию.
	Car() : brand(TOYOTA), carNumber("") {}

	//Конструктор с параметрами.
	Car(CarBrand brand, const string& carNumber)
		: brand(brand), carNumber(carNumber) {}

	// Метод для установки водителя автомобиля
	void setDriver(const Person& person) {
		if (person.getAge() < 18) {
			cout << "Предупреждение: водитель должен быть старше 18 лет!" << endl;
		}
		else {
			driver = person;
		}
	}

	// Метод для вывода информации об автомобиле
	void printInfo() const {
		cout << "Марка автомобиля: ";
		switch (brand) {
		case TOYOTA:
			cout << "Toyota";
			break;
		case HONDA:
			cout << "Honda";
			break;
		case BMW:
			cout << "BMW";
			break;
		case MERCEDES:
			cout << "Mercedes";
			break;
		case FORD:
			cout << "Ford";
			break;
		case AUDI:
			cout << "Audi";
			break;
		default:
			cout << "Неизвестная марка";
		}
		cout << endl;
		cout << "Номер автомобиля: " << carNumber << endl;
		cout << "Водитель:" << endl;
		driver.printPersonInfo();
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	// Создаем два объекта класса Person
	Person person1("Иван", "Иванов", "Иванович", 25);
	Person person2("Петр", "Петров", "Петрович", 17);

	// Выводим информацию о персонах
	cout << "Информация о персоне 1:" << endl;
	person1.printPersonInfo();
	cout << endl;
	cout << "Информация о персоне 2:" << endl;
	person2.printPersonInfo();
	cout << endl;

	// Создаем объект класса Car
	Car car(HONDA, "A123BC45");

	// Устанавливаем водителя автомобиля
	car.setDriver(person1);

	// Выводим информацию об автомобиле
	cout << "Информация об автомобиле:" << endl;
	car.printInfo();

	return 0;
}
