#include "inputslib.h"
#include "libft.hpp"
#include <vector>
#include <fstream>

#define USERS_FILE "data_of_clients.txt"

struct s_user
{
	string account_number;
	string pin_code;
	string name;
	string phone;
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
void show_main_menu_screen(void);
void show_quick_withdraw_screen(void);
void show_normal_withdraw_screen(void);

s_user split_user_record(string record)
{
	s_user t_user;
	vector<string> v_user;

	v_user = ft::spliter(record, "#//#");
	t_user.account_number = v_user[0];
	t_user.pin_code = v_user[1];
	t_user.name = v_user[2];
	t_user.phone = v_user[3];
	t_user.balance = stod(v_user[4]);
	return (t_user);
}

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

void back_to_main_menu(void)
{
	char back;

	cout << "\npress any key to go back to main menu...";
	cin >> back;
	show_main_menu_screen();
}

void show_check_balance_screen(void)
{
	cout << "________________________________\n";
	cout << "\tCheck balance screen\n";
	cout << "________________________________\n";
	cout << "Your balance is: " << current_user.balance << "$" << endl;
}

string record_user(s_user &user)
{
	string record;
	string delim;

	record = "";
	delim = "#//#";
	record += user.account_number + delim;
	record += user.pin_code + delim;
	record += user.name + delim;
	record += user.phone + delim;
	record += to_string(user.balance) + "$";
	return (record);
}

void save_users_to_file(string file_name, vector<s_user> &v_user)
{
	fstream file;
	string record;

	file.open(USERS_FILE, ios::out);
	if (file.is_open())
	{
		for (s_user &user : v_user)
		{
			record = record_user(user);
			file << record << endl;
		}
		file.close();
	}
	else
	{
		cerr << "Failed to open file :(" << endl;
		exit(1);
	}
}

void deposit_to_user_account(vector<s_user> &v_user)
{
	char answer;
	double deposit;

	answer = 'n';
	cout << "Your balance is: " << current_user.balance << "$" << endl;
	cout << "\nHow much do you wish to deposit?\n";
	deposit = input::read_positive_number("Enter a positive deposite: ");
	for (s_user &user : v_user)
	{
		if (user.account_number == current_user.account_number)
		{
			cout << "Do you wish to perform this transaction? (Y/N)\n-> ";
			cin >> answer;
			if (answer == 'Y' || answer == 'y')
			{
				user.balance += deposit;
				current_user.balance += deposit;
				cout << "Deposit successed, balance now is "
					 << user.balance << '$' << endl;
				save_users_to_file(USERS_FILE, v_user);
			}
		}
	}
}

void show_deposit_screen(void)
{
	vector<s_user> v_user;

	cout << "________________________________\n";
	cout << "\tCheck balance screen\n";
	cout << "________________________________\n";
	v_user = load_users_file_to_structs(USERS_FILE);
	deposit_to_user_account(v_user);
}

bool withdraw_from_user_account(vector<s_user> &v_user, double withdraw, bool quick_withdraw = false)
{
	char answer;
	s_user user;

	answer = 'n';
	for (s_user &user : v_user)
	{
		if (user.account_number == current_user.account_number)
		{
			if (user.balance < withdraw)
			{
				system("clear");
				cout << "You can withdraw up to " << user.balance << "$\n";
				cout << "Make another choise" << endl;
				if (quick_withdraw)
					show_quick_withdraw_screen();
				else
					show_normal_withdraw_screen();
				return (false);
			}
			cout << "Do you wish to perform this transaction? (Y/N)\n-> ";
			cin >> answer;
			if (answer == 'Y' || answer == 'y')
			{
				user.balance -= withdraw;
				current_user.balance -= withdraw;
				cout << "Withdraw successed, balance now is "
					 << user.balance << '$' << endl;
				save_users_to_file(USERS_FILE, v_user);
				return (true);
			}
			return (false);
		}
	}
	return (false);
}

double quick_withdraw_menu()
{
	short	option = 0;
	double	withdraw[8] = {20, 50, 100, 200, 400, 600, 800, 1000};

	cout << "________________________________\n";
	cout << "[1] 20\t\t\t[2] 50\n";
	cout << "[3] 100\t\t\t[4] 200\n";
	cout << "[5] 400\t\t\t[6] 600\n";
	cout << "[7] 800\t\t\t[8] 1000\n";
	cout << "[9] Exit" << endl;
	cout << "________________________________\n";
	option = input::read_number_in_range(1, 9, "Enter your option ");
	if (option == 9)
		show_main_menu_screen();
	return (withdraw[option - 1]);
}

void show_quick_withdraw_screen(void)
{
	double	withdraw;
	vector<s_user> v_user;

	cout << "________________________________\n";
	cout << "\tQuick withdraw screen\n";
	cout << "________________________________\n";
	cout << "Your current balance is: " << current_user.balance << "$\n";
	cout << "________________________________\n";
	v_user = load_users_file_to_structs(USERS_FILE);
	withdraw = quick_withdraw_menu();
	withdraw_from_user_account(v_user, withdraw, true);
}

void show_normal_withdraw_screen(void)
{
	double	withdraw = 1;
	vector<s_user> v_user;

	cout << "________________________________\n";
	cout << "\tNormal withdraw screen\n";
	cout << "________________________________\n";
	cout << "Your current balance is: " << current_user.balance << "$" << endl;
	cout << "________________________________\n";
	v_user = load_users_file_to_structs(USERS_FILE);
	cout << "How much do you wish to withdraw?\n";
	while ((int)withdraw % 5 != 0)
	{
		withdraw = input::read_positive_number("must be mltiple of 5: ");
	}
	withdraw_from_user_account(v_user, withdraw);
}

void perform_main_menu_option(e_main_menu_options option)
{
	switch (option)
	{
	case e_main_menu_options::e_quick_withdraw:
		system("clear");
		show_quick_withdraw_screen();
		back_to_main_menu();
		break;
	case e_main_menu_options::e_normal_withdraw:
		system("clear");
		show_normal_withdraw_screen();
		back_to_main_menu();
		break;
	case e_main_menu_options::e_deposit:
		system("clear");
		show_deposit_screen();
		back_to_main_menu();
		break;
	case e_main_menu_options::e_check_balance:
		system("clear");
		show_check_balance_screen();
		back_to_main_menu();
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
	for (s_user &checker : v_users)
	{
		if (checker.account_number == user.account_number && checker.pin_code == user.pin_code)
		{
			current_user = checker;
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
