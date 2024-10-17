#include <iostream>
#include <string>

class cliente {
public:
	int id;
	int age;
	std::string name;
	std::string lastName;
	long long int phone;
	std::string email;
	cliente* sig;
	cliente* ant;

public:
	cliente(int _id, int _age, std::string _name, std::string _lastName, long long int _phone, std::string _email) {
		id = _id;
		age = _age;
		name = _name;
		lastName = _lastName;
		phone = _phone;
		email = _email;
		std::cout << "------- Contructor cliente activated for:" << name << "with id" << id << std::endl;
	}

	cliente(){}
};
cliente* aux, *ini, *end = nullptr;

class store {
public:
	int id_store;
	std::string storeName;
	std::string pathLogo;
	product* sig;
	product* ant;
};

class product:public store{
	int id_product;
	float price;
	unsigned int units;
};

int main() {
	
	int opc = NULL;
	do {
		std::cout << "--------- MENU ---------" << std::endl;
		std::cout << "1) Agregar nuevo cliente" << std::endl;
		std::cout << "2) Imprimir lista de clientes ->" << std::endl;
		std::cout << "3) Imprimir lista de clientes <-" << std::endl;
		std::cout << "4) Eliminar lista de clientes <-" << std::endl;
		std::cout << "5) Salir" << std::endl;
		std::cin >> opc;
		switch (opc) {
		case 1: {
			//creating a obj
			aux = new cliente;
			aux->sig = nullptr;
			aux->ant = nullptr;
			if (ini == nullptr){
				ini = end = aux;
			}
			else {
				//adding the obj at the end of the list 
				aux->ant = end;
				end->sig = aux;
				end = aux;
				end->sig = nullptr;
			}
			std::cout << "ID: ";
			std::cin >> aux->id;
			std::cout << "Name: ";
			std::cin >> aux->name;
			std::cout << "Last Name: ";
			std::cin >> aux->lastName;
			std::cout << "Age: ";
			std::cin >> aux->age;
			std::cout << "Phone: ";
			std::cin >> aux->phone;
			std::cout << "Email: ";
			std::cin >> aux->email;
			break;
		}
		case 2: {
			if (ini == nullptr) { std::cout << std::endl << "EMPTY LIST (if this is unexpected ini/end pointers are lost)" << std::endl; break; }
			aux = ini;
			std::cout << "ID  |  NAME  |  LNAME  |  AGE  |  PHONE  |  EMAIL | ->" << std::endl;
			while (aux != nullptr) {
				std::cout << aux->id << " | " << aux->name << " | " << aux->lastName << " | " << aux->age << " | " << aux->phone << " | " << aux->email << std::endl;
				aux = aux->sig;
			}
			std::cout << "The list is over" << std::endl;
			break;
		}
		case 3: {
			if (end == nullptr) { std::cout << std::endl << "EMPTY LIST (if this is unexpected ini/end pointers are lost)" << std::endl; break; }
			aux = end;
			std::cout << "ID  |  NAME  |  LNAME  |  AGE  |  PHONE  |  EMAIL| <-" << std::endl;
			while (aux != nullptr) {
				std::cout << aux->id << " | " << aux->name << " | " << aux->lastName << " | " << aux->age << " | " << aux->phone << " | " << aux->email<< std::endl;
				aux = aux->ant;
			}
			std::cout << "The list is over" << std::endl;
			break;
		}
		case 4: {
			if (ini == nullptr || end == nullptr) { std::cout << std::endl << "EMPTY LIST (if this is unexpected ini/end pointers are lost)" << std::endl; break; }
			aux = ini;
			std::cout << "Deleting list..." << std::endl;
			while (aux->sig != nullptr) {
				aux = aux->sig;
				delete aux->ant;
			}
			delete end;
			ini = end = aux = nullptr;
			std::cout << "The list has been deleted" << std::endl;
			break;
		}
		default: { break; }
		}
		system("pause");
		system("cls");
	} while (opc != 5);
}