#include "inputslib.h"
#include <vector>

#define USERS_FILE "data_of_clients.txt"

struct s_user
{
	string account_number;
	string pin_code;
	double account_balance;
};

s_user current_user;

vector<s_user> load_users_file_to_structs(string file_name)
{
	vector<s_user> v_users;
	fstream ufile;
	string line;

	ufile.open(file_name, ios::in);
	if (ufile.is_open())
	{
		while (getline(ufile, line))
		{
			v_users.push_back(split_user_record(line));
		}
	}
	else
	{
		cerr << "Error: Unable to open the users file" << endl;
		exit(1);
	}
	if (v_users.size() == 0)
	{
		cerr << "Error: No users in the system" << endl;
		exit(1);
	}
	return (v_users);
}

bool check_login(s_user &user)
{
	vector<s_user> v_users;

	v_users = load_users_file_to_structs(USERS_FILE);
	for (s_user checker : v_users)
	{
		if (checker.account_number == user.account_number && checker.password == user.password)
		{
			user.permissions = checker.permissions;
			return (true);
		}
	}
	return (false);
}

void show_login_screen(void)
{
	bool login_success = true;

	do
	{
		system("clear");
		cout << "=========================\n";
		cout << "     login screen\n";
		cout << "=========================" << endl;
		if (!login_success)
			cerr << "\nIncorrect acount number or pin code, try again\n\n";
		current_user.account_number = input::read_string("acount number: ");
		current_user.pin_code = input::read_string("pin code: ");
		login_success = check_login(current_user);
	} while (!login_success);
	show_main_menu_screen();
}

int main(void)
{
	show_login_screen();
}
