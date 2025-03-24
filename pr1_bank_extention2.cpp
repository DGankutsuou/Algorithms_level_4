#include "bank.hpp"

bank::s_user	split_user_record(string record)
{
	bank::s_user			t_user;
	vector <string>	v_user;

	v_user = ft::spliter(record, "#//#");
	t_user.username = v_user[0];
	t_user.password = v_user[1];
	t_user.permissions = (char)stoi(v_user[2]);
	return (t_user);
}

vector <bank::s_user>	load_users_file_to_structs()
{
	vector <bank::s_user>	v_users;
	fstream			ufile;
	string			line;

	ufile.open(USERS_FILE, ios::in);
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
		exit (1);
	}
	if (v_users.size() == 0)
	{
		cerr << "Error: No users in the system" << endl;
		exit (1);
	}
	return (v_users);
}

bool	check_login(bank::s_user &user)
{
	vector <bank::s_user>	v_users;

	v_users = load_users_file_to_structs();
	for (bank::s_user checker : v_users)
	{
		if (checker.username == user.username && checker.password == user.password)
		{
			user.permissions = checker.permissions;
			return (true);
		}
	}
	cerr << "\nIncorrect username or password, try again\n" << endl;
	return (false);
}

void show_login_screen(void)
{
	bank::s_user	user;

	system("clear");
	cout << "=========================\n";
	cout << "     login screen\n";
	cout << "=========================" << endl;
	do
	{
		user.username = input::read_string("username: ");
		user.password = input::read_string("password: ");
	} while (!check_login(user));
	bank::show_main_menu_screen();
}

int main(void)
{
	show_login_screen();
	return (0);
}
