#include <iostream>
#include <vector>

using namespace std;

class User {
private:
	string username, password;

public:
	User(string name, string pass) {
		username = name;
		password = pass;
	}

	string getUsername() {
		return username;
	}

	string getPassword() {
		return password;
	}
};

class UserManager {
private:
	vector<User> users;
public:
	void RegisterUser() {
		string username, password, confirm_pass;
		cout << "Podaj Nazwe Uzytkownika : \n";
		cout << ">> ";
		cin >> username;
		cout << "Podaj Haslo: \n";
		cout << ">> ";
		cin >> password;
		cout << "Potwierdz Haslo: \n";
		cout << ">> ";
		cin >> confirm_pass;

		if (password != confirm_pass) {
			cout << ">--Hasla sa rozne!--<\n";
		}

		User NewUser(username, password);
		users.push_back(NewUser);
		if (password == confirm_pass)
		{
		cout << ">--Zostales pomyslnie zarejestrowany!--<\n";
		}
	}

	bool LoginUser(string name, string pass) {
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i].getUsername() == name && users[i].getPassword() == pass) {
				cout << ">--Zostales pomyslnie zalogowany!--<\n";
				return true;
			}
			else {
				cout << ">--Nie poprawny login lub haslo!--<\n";
				return false;
			}
		}
	}

	void ShowUsers() {
		for (int i = 0; i < users.size(); i++)
		{
			string show = users[i].getUsername();
			cout << show << endl;
		}
	}

	void SearchForUser(string username) {
		for (int i = 0; i < users.size(); i++) {
			if (users[i].getUsername() == username) cout << ">--Uzytkownik Znaleziony!--< \n" << endl;
		}
	}

	void DeleteUser(string name, string pass) {
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i].getUsername() == name && users[i].getPassword() == pass) {
				users.erase(users.begin() + i);
				cout << ">--Uzytkownik zostal usuniety!--<\n"
			}
		}
	}
};


int main()
{
	UserManager usermanager;
	bool program = true;
	int wybor;
	string username, password;

	while (program) {
		cout << " 1. Zarejestrowac uzytkownika\n 2. Zalogowac uzytkownika\n 3. Pokazac liste uzytkownikow\n 4. Wyszukac uzytkownika\n 5. Usunac uzytkownika\n 6. Zakonczyc program\n";
		cout << ">> ";
		cin >> wybor;

		switch (wybor)
		{
		case 1:
			usermanager.RegisterUser();
			break;
		case 2:
			cout << "Wprowadz login: \n";
			cout << ">> ";
			cin >> username;

			cout << "Wprowadz haslo: \n";
			cout << ">> ";
			cin >> password;

			usermanager.LoginUser(username, password);
			break;
		case 3:
			usermanager.ShowUsers();
			break;
		case 4:
			cout << "Podaj nazwe uzytkownika ktorego szukasz: \n";
			cout << ">> ";
			cin >> username;

			usermanager.SearchForUser(username);
			break;
		case 5:
			cout << "Podaj nazwe uzytkownika ktorego chcesz usunac: \n";
			cout << ">> ";
			cin >> username;
				
			cout << "Podaj haslo tego uzytkownika: \n";
			cout << ">> ";
			cin >> password;

			usermanager.DeleteUser(username, password);
			break;
		case 6:
			cout << ">--Wybrano Zakonczenie Programu!--\n<"
			program = false;

			break;
		default:
			break;
		
	}
}

}
	
