#include "inputslib.h"
#include <vector>

#define USERS_FILE "data_of_clients.txt"

struct s_user
{
	string account_number;
	string pin_code;
	double balance;
};

enum e_main_menu_options
{
	e_quick_withdraw = 1,
	e_normal_withdraw = 2,
	e_deposit = 3,
	e_check_balance = 4,
	e_logout = 5
};

s_user current_user;

void show_login_screen(void);

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

void back_to_main_menu()
{
	char back;

	cout << "press any key to go back to main menu...";
	cin >> back;
	show_main_menu_screen();
}

void perform_main_menu_option(e_main_menu_options option)
{
	switch (option)
	{
	case e_main_menu_options::e_quick_withdraw:
		system("clear");
		show_deposit_screen();
		back_to_main_menu_menu();
		break;
	case e_main_menu_options::e_normal_withdraw:
		system("clear");
		show_withdraw_screen();
		back_to_main_menu_menu();
		break;
	case e_main_menu_options::e_deposit:
		system("clear");
		show_total_balances_screen();
		back_to_main_menu_menu();
		break;
	case e_main_menu_options::e_check_balance:
		system("clear");
		break;
	case e_main_menu_options::e_logout:
		system("clear");
		show_login_screen();
		break;
	default:
		exit(0);
	}
}

short read_main_menu_option(void)
{
	short option;

	option = input::read_number_in_range(1, 5, "Enter your option ");
	return (option);
}

void show_main_menu_screen()
{
	system("clear");
	cout << "=====================================\n";
	cout << "             Main menu\n";
	cout << "=====================================\n";
	cout << "\t[1]: Quick Withdraw\n";
	cout << "\t[2]: Normal Withdraw\n";
	cout << "\t[3]: Deposit\n";
	cout << "\t[4]: Check Balance\n";
	cout << "\t[5]: Logout\n";
	cout << "=====================================\n"
		 << endl;
	perform_main_menu_option(e_main_menu_options(read_main_menu_option()));
}

bool check_login(s_user &user)
{
	vector<s_user> v_users;

	v_users = load_users_file_to_structs(USERS_FILE);
	for (s_user checker : v_users)
	{
		if (checker.account_number == user.account_number && checker.pin_code == user.pin_code)
		{
			user.balance = checker.balance;
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
