#include <iostream>
#include <vector>

using namespace std;

class User {
  private:
    string username, password;
  public:
    string User(string username, string password) {
      username = name;
      password = pass;
    }
  
    string GetUsername() {
      return username;
    }
    string GetPassword() {
      return password;
    }
}

class UserManager {
  private:
    vector<User> users;
  public:
    void RegisterUser() {
      string username, password;
  
      cout << "Podaj Nazwe Uzytkownika: \n>> ";
      cin >> username;
      cout << "Podaj Haslo: \n>> ";
      cin >> password;
  
      User NewUser(username, password);
      users.pushback(NewUser);
  }

  void LoginUser(string name, string pass) {
    for(int i = 0; i < users.size(); i++){
      if(users[i].GetUsername() == name && users[i].GetPassword() == pass){
        cout << "Zostales pomyslnie zalogowany!\n";
      }
    }
  }

  void ShowUsers() {
    for(int i = 0; i < users.size(); i++){
      cout << users[i].GetUsername() << endl;
    }
  }

  void SearchUser(string name) {
    for(int i = 0; i < users.size(); i++){
      if(users[i].GetUsername() == name){
        cout << "Znaleziono uzytkownika " << name << endl;
      }
  }

  void DeleteUser(string name) {
    for(int i = 0; i < users.size(); i++){
      if(users[i].GetUsername() == name){
        users[i].erase(users.begin() + i)
      }
  }
  
}

int Main() {
  UserManager usermanager;
  bool program = true;
  int wybor;
  string username, password;
  
  while(program) {
    cout << "Co chcesz zrobic?\n";
    cout << "1. Zarejestrowac uzytkownika \n2. Zalogowac uzytkownika \n3. Pokazac uzytkownikow \n4. Wyszukac uzytkownika \n5. Usunac uzytkownika\n>> ";
    cin >> wybor;
    switch(wybor){
      case 1:
          usermanager RegisterUser();
        break;
      case 2:
          cout << "Podaj Login: \n>> ";
          cin >> username;
          cout << "Podaj Haslo: \n>> ";
          cin >> password;
          usermanager LoginUser(string username, string password);
        break;
      case 3:
          usermanager ShowUsers();
        break;
      case 4:
          cout << "Podaj nazwe uzytkownika ktorego chcesz wyszukac: \n>> ";
          cin >> username;
          usermanager SearchUser(string username);
        break;
      case 5:
          cout << "Podaj nazwe uzytkownika ktorego chcesz usunac: \n>> ";
          cin >> username;
          usermanager DeleteUser(string username);
        break;
      case 6:
          program = false;
        break;
    }
  }

}
