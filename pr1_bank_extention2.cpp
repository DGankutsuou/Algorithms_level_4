#include "bank.hpp"

enum e_manage_users_options
{
	e_show_users_list = 1,
	e_add_new_user = 2,
	e_delete_user = 3,
	e_update_user_infos = 4,
	e_find_user = 5,
	e_main_menu = 6
};

bank::s_user split_user_record(string record)
{
	bank::s_user t_user;
	vector<string> v_user;

	v_user = ft::spliter(record, "#//#");
	t_user.username = v_user[0];
	t_user.password = v_user[1];
	t_user.permissions = (char)stoi(v_user[2]);
	return (t_user);
}

vector<bank::s_user> load_users_file_to_structs(string file_name)
{
	vector<bank::s_user> v_users;
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

bool check_login(bank::s_user &user)
{
	vector<bank::s_user> v_users;

	v_users = load_users_file_to_structs(USERS_FILE);
	for (bank::s_user checker : v_users)
	{
		if (checker.username == user.username && checker.password == user.password)
		{
			user.permissions = checker.permissions;
			return (true);
		}
	}
	cerr << "\nIncorrect username or password, try again\n"
		 << endl;
	return (false);
}

short read_manage_users_option(void)
{
	short option;

	option = input::read_number_in_range(1, 6, "Enter your option ");
	return (option);
}

void back_to_manage_users_menu(bank::s_user t_user)
{
	char back;

	cout << "press any key to go back to manage users menu...";
	cin >> back;
	show_manage_users_screen(t_user);
}

void print_users_header(short number_of_users)
{
	cout << "\n\t\t***users list (" << number_of_users << ")***\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "____________________";
	}
	cout << '\n';
	cout << "| Username\t| Password\t| Prmissions\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "____________________";
	}
	cout << endl;
}

void user_line_printer(bank::s_user &user)
{
	cout << "| " << left << setw(14) << user.username;
	cout << "| " << left << setw(14) << user.password;
	cout << "| " << left << setw(14) << user.permissions;
	cout << endl;
}

void print_users_table(void)
{
	vector<bank::s_user> v_user;

	v_user = load_users_file_to_structs(USERS_FILE);
	if (v_user.size() == 0)
		cout << "No available clients in the system" << endl;
	else
	{
		print_users_header(v_user.size());
		for (bank::s_user &user : v_user)
		{
			user_line_printer(user);
		}
		for (int i = 0; i < 3; i++)
		{
			cout << "____________________";
		}
	}
	cout << endl;
}

void perform_manage_users_option(e_manage_users_options option, bank::s_user t_user)
{
	switch (option)
	{
	case e_manage_users_options::e_show_users_list:
		system("clear");
		print_users_table();
		back_to_manage_users_menu(t_user);
		break;
	// case e_manage_users_options::e_add_new_user:
	// 	system("clear");
	// 	show_add_new_users_screen();
	// 	back_to_manage_users_menu(t_user);
	// 	break;
	// case e_manage_users_options::e_delete_user:
	// 	system("clear");
	// 	show_delete_user_screen();
	// 	back_to_manage_users_menu(t_user);
	// 	break;
	// case e_manage_users_options::e_update_user_infos:
	// 	system("clear");
	// 	show_update_user_screen();
	// 	back_to_manage_users_menu(t_user);
	// 	break;
	// case e_manage_users_options::e_find_user:
	// 	system("clear");
	// 	show_find_user_screen();
	// 	back_to_manage_users_menu(t_user);
	// 	break;
	case e_manage_users_options::e_main_menu:
		system("clear");
		bank::show_main_menu_screen(t_user);
		break;
	default:
		exit(0);
	}
}

void show_manage_users_screen(bank::s_user t_user)
{
	system("clear");
	cout << "=====================================\n";
	cout << "             Manage users            \n";
	cout << "=====================================\n";
	cout << "\t[1]: Show users list\n";
	cout << "\t[2]: Add new user\n";
	cout << "\t[3]: Delete user\n";
	cout << "\t[4]: Update user infos\n";
	cout << "\t[5]: Find user\n";
	cout << "\t[6]: Back to main menu\n";
	cout << "=====================================\n";
	cout << endl;
	perform_manage_users_option(e_manage_users_options(read_manage_users_option()), t_user);
}

void show_login_screen(void)
{
	bank::s_user user;

	system("clear");
	cout << "=========================\n";
	cout << "     login screen\n";
	cout << "=========================" << endl;
	do
	{
		user.username = input::read_string("username: ");
		user.password = input::read_string("password: ");
	} while (!check_login(user));
	bank::show_main_menu_screen(user);
}

int main(void)
{
	show_login_screen();
	return (0);
}
