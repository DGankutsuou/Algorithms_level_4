#pragma once
# include <iostream>
# include <stdlib.h>
# include <cstdlib>
# include <iomanip>
# include <fstream>
# include "inputslib.h"
# include "libft.hpp"

# define FILE_NAME "data_of_clients.txt"
# define USERS_FILE "users.txt"


namespace bank
{
	enum e_main_menu_options
	{
		e_show_clients_list = 1,
		e_add_new_client = 2,
		e_delete_client = 3,
		e_update_client_infos = 4,
		e_find_client = 5,
		e_transactions = 6,
		e_manage_users = 7,
		e_logout = 8
	};

	enum e_transactions_options
	{
		e_deposit = 1,
		e_withdraw = 2,
		e_total_balances = 3,
		e_main_menu = 4
	};

	enum e_manage_users_options
	{
		e_show_users_list = 1,
		e_add_new_user = 2,
		e_delete_user = 3,
		e_update_user_infos = 4,
		e_find_user = 5,
		e_go_main_menu = 6
	};

	enum e_user_permissions
	{
		p_all = 0b11111111,
		p_show_clients_list = 0b00000001,
		p_add_new_client = 1<<1, // 2 = 0b00000010
		p_delete_client = 1<<2, //  4 = 0b00000100
		p_update_client = 1<<3, //  8 = 0b00001000
		p_find_client = 1<<4, //   16 = 0b00010000
		p_transactions = 1<<5, //  32 = 0b00100000
		p_manage_users = 1<<6 //   64 = 0b01000000
	};

	struct s_data
	{
		string acount_number;
		string pin_code;
		string name;
		string phone;
		double account_balance;
		bool to_be_deleted = false;
	};

	struct	s_user
	{
		string	username;
		string	password;
		short	permissions;
		bool	to_be_deleted = false;
	};

	s_user	current_user;

	void show_transactions_screen();
	void show_main_menu_screen();
	void show_manage_users_screen();
	void back_to_main_menu(void);
	void show_no_permission_screen(void);

	bool	check_access_permission(e_user_permissions permission)
	{
		if ((current_user.permissions & permission) == permission)
			return (true);
		else
			return (false);
	}

	string read_account_number(void)
	{
		string account_number;

		cout << "Enter client's account number: ";
		getline(cin >> ws, account_number);
		return (account_number);
	}

	s_data split_record(string str)
	{
		s_data data;
		vector<string> splited;

		splited = ft::spliter(str, "#//#");
		data.acount_number = splited[0];
		data.pin_code = splited[1];
		data.name = splited[2];
		data.phone = splited[3];
		data.account_balance = stod(splited[4]);
		return (data);
	}

	void print_data(s_data &data)
	{
		cout << "\nClient data:\n\n";
		cout << "Acount number : " << data.acount_number << "\n";
		cout << "Pin code      : " << data.pin_code << "\n";
		cout << "Client name   : " << data.name << "\n";
		cout << "Phone number  : " << data.phone << "\n";
		cout << "Acount balance: " << data.account_balance << '$' << endl;
	}

	vector<s_data> load_file_to_data_vector(string file_name)
	{
		vector<s_data> v_data;
		fstream file;
		string line;
		s_data data;

		file.open(file_name, ios::in); // read mode
		if (file.is_open())
		{
			while (getline(file, line))
			{
				data = split_record(line);
				v_data.push_back(data);
			}
			file.close();
		}
		else
		{
			cerr << "Error: unable to open file" << endl;
			exit(0);
		}
		return (v_data);
	}

	bool search_by_id(vector<s_data> &v_data, string id, s_data &client)
	{
		for (s_data &data : v_data)
		{
			if (data.acount_number == id)
			{
				client = data;
				return (true);
			}
		}
		return (false);
	}

	string record_data(s_data &data)
	{
		string record;
		string delim;

		record = "";
		delim = "#//#";
		record += data.acount_number + delim;
		record += data.pin_code + delim;
		record += data.name + delim;
		record += data.phone + delim;
		record += to_string(data.account_balance) + "$";
		return (record);
	}

	bool mark_client_to_be_deleted_by_id(string id, vector<s_data> &v_data)
	{
		for (s_data &data : v_data)
		{
			if (data.acount_number == id)
			{
				data.to_be_deleted = true;
				return (true);
			}
		}
		cerr << "Error: Account number (" << id << ") not found" << endl;
		return (false);
	}

	void save_clients_to_file(string file_name, vector<s_data> &v_data)
	{
		fstream file;
		string record;

		file.open(FILE_NAME, ios::out);
		if (file.is_open())
		{
			for (s_data &data : v_data)
			{
				if (!data.to_be_deleted)
				{
					record = record_data(data);
					file << record << endl;
				}
			}
			file.close();
		}
		else
		{
			cerr << "Failed to open file :(" << endl;
			exit(1);
		}
	}

	bool delete_client_by_id(string id, vector<s_data> &v_data)
	{
		char answer;
		s_data client;

		answer = 'n';
		if (search_by_id(v_data, id, client))
		{
			print_data(client);
			cout << "Do you wish to delete this client? (Y/N)\n-> ";
			cin >> answer;
			if (answer == 'Y' || answer == 'y')
			{
				mark_client_to_be_deleted_by_id(id, v_data);
				save_clients_to_file(FILE_NAME, v_data);
				cout << "Client deleted successfuly" << endl;
				return (true);
			}
		}
		else
		{
			cerr << "Error: Account number (" << id << ") not found" << endl;
			return (false);
		}
		return (false);
	}

	bool is_client_exist_by_id(string account_number, string file_name)
	{
		fstream file;

		file.open(file_name, ios::in);
		if (file.is_open() == true)
		{
			string line;
			s_data data;
			while (getline(file, line))
			{
				data = split_record(line);
				if (data.acount_number == account_number)
				{
					file.close();
					return (true);
				}
			}
			file.close();
			return (false);
		}
		else
		{
			cerr << "Error: Unable to open file: \"" << file_name << "\"" << endl;
			exit(1);
		}
	}

	s_data read_new_client(void)
	{
		s_data data;
		vector<s_data> v_data;

		v_data = load_file_to_data_vector(FILE_NAME);
		cout << "Enter accounnt number: ";
		getline(cin >> ws, data.acount_number);
		while (is_client_exist_by_id(data.acount_number, FILE_NAME))
		{
			cout << "This account number (" << data.acount_number
				 << ") allready exist\n";
			cout << "Enter another number: ";
			getline(cin >> ws, data.acount_number);
		}
		data.pin_code = input::read_string("Enter pin code: ");
		data.name = input::read_string("Enter client name: ");
		data.phone = input::read_string("Enter client phone number: ");
		data.account_balance = (double)input::read_positive_number("Enter account balance: ");
		return (data);
	}

	void save_record_to_file(string file_name, string record)
	{
		fstream file;

		file.open(file_name, ios::app);
		if (file.is_open())
		{
			file << record << endl;
			file.close();
		}
		else
		{
			cerr << "Failed to write in file :(" << endl;
			exit(1);
		}
	}

	void add_new_client(void)
	{
		s_data data;
		data = read_new_client();
		save_record_to_file(FILE_NAME, record_data(data));
	}

	void add_new_clients(void)
	{
		char add_more;

		add_more = 'y';
		do
		{
			cout << "\n*Adding new client*\n\n";
			add_new_client();
			cout << "\nClient added successfuly. Dost Thou desire to add more (Y/N)?\n-> ";
			cin >> add_more;
		} while (tolower(add_more) == 'y');
	}

	void load_file_to_str_vector(string file_name, vector<string> &v_file)
	{
		fstream file;
		string line;

		file.open(file_name, ios::in); // read mode
		if (file.is_open())
		{
			while (getline(file, line))
				v_file.push_back(line);
			file.close();
		}
	}

	void print_header(short number_of_clients)
	{
		cout << "\n\t\t***Clients list (" << number_of_clients << ")***\n";
		for (int i = 0; i < 5; i++)
		{
			cout << "____________________";
		}
		cout << '\n';
		cout << "| Acount number\t| Pin code\t| Client name\t\t";
		cout << "| Phone number\t| Acount balance\n";
		for (int i = 0; i < 5; i++)
		{
			cout << "____________________";
		}
		cout << endl;
	}

	void line_printer(s_data &data)
	{
		cout << "| " << left << setw(14) << data.acount_number;
		cout << "| " << left << setw(14) << data.pin_code;
		cout << "| " << left << setw(30) << data.name;
		cout << "| " << left << setw(14) << data.phone;
		cout << "| " << left << setw(14) << to_string(data.account_balance) + "$";
		cout << endl;
	}

	void print_clients_table(void)
	{
		vector<s_data> v_data;

		if (!check_access_permission(e_user_permissions::p_show_clients_list))
		{
			show_no_permission_screen();
			back_to_main_menu();
			return ;
		}
		v_data = load_file_to_data_vector(FILE_NAME);
		if (v_data.size() == 0)
			cout << "No available clients in the system" << endl;
		else
		{
			print_header(v_data.size());
			for (s_data &data : v_data)
			{
				line_printer(data);
			}
			for (int i = 0; i < 5; i++)
			{
				cout << "____________________";
			}
		}
		cout << endl;
	}

	s_data change_client_infos(string id)
	{
		s_data data;

		data.acount_number = id;
		cout << "Enter pin code: ";
		getline(cin >> ws, data.pin_code);
		data.name = input::read_string("Enter client name: ");
		data.phone = input::read_string("Enter client phone number: ");
		data.account_balance = (double)input::read_positive_number("Enter account balance: ");
		return (data);
	}

	bool update_client_by_id(string id, vector<s_data> &v_data)
	{
		char answer;
		s_data client;

		answer = 'n';
		if (search_by_id(v_data, id, client))
		{
			print_data(client);
			cout << "Do you wish to update this client infos? (Y/N)\n-> ";
			cin >> answer;
			if (answer == 'Y' || answer == 'y')
			{
				for (s_data &data : v_data)
				{
					if (data.acount_number == id)
					{
						data = change_client_infos(id);
						break;
					}
				}
				save_clients_to_file(FILE_NAME, v_data);
				cout << "Client updated successfuly" << endl;
				return (true);
			}
		}
		else
		{
			cerr << "Error: Account number (" << id << ") not found" << endl;
			return (false);
		}
		return (false);
	}

	void show_add_new_clients_screen(void)
	{
		if (!check_access_permission(e_user_permissions::p_add_new_client))
		{
			show_no_permission_screen();
			back_to_main_menu();
			return ;
		}
		cout << "________________________________\n";
		cout << "\tAdd new clients\n";
		cout << "________________________________\n"
			 << endl;
		add_new_clients();
	}

	void show_delete_client_screen(void)
	{
		string account_number;
		vector<s_data> v_data;

		if (!check_access_permission(e_user_permissions::p_delete_client))
		{
			show_no_permission_screen();
			back_to_main_menu();
			return ;
		}
		cout << "________________________________\n";
		cout << "\tDelete client\n";
		cout << "________________________________\n"
			 << endl;
		v_data = load_file_to_data_vector(FILE_NAME);
		account_number = read_account_number();
		delete_client_by_id(account_number, v_data);
	}

	void show_update_client_screen(void)
	{
		string account_number;
		vector<s_data> v_data;

		if (!check_access_permission(e_user_permissions::p_update_client))
		{
			show_no_permission_screen();
			back_to_main_menu();
			return ;
		}
		cout << "________________________________\n";
		cout << "\tUpdate client\n";
		cout << "________________________________\n"
			 << endl;
		v_data = load_file_to_data_vector(FILE_NAME);
		account_number = read_account_number();
		update_client_by_id(account_number, v_data);
	}

	void show_find_client_screen(void)
	{
		vector<s_data> v_data;
		s_data client;
		string account_number;

		if (!check_access_permission(e_user_permissions::p_find_client))
		{
			show_no_permission_screen();
			back_to_main_menu();
			return ;
		}
		cout << "________________________________\n";
		cout << "\tFind client\n";
		cout << "________________________________\n"
			 << endl;
		v_data = load_file_to_data_vector(FILE_NAME);
		account_number = read_account_number();
		if (search_by_id(v_data, account_number, client))
			print_data(client);
		else
		{
			cout << "Client with account number (" << account_number << ") is not found" << endl;
		}
	}

	void show_exit_screen(void)
	{
		cout << "________________________________\n";
		cout << "\tProgram exited\n";
		cout << "________________________________\n"
			 << endl;
	}

	void back_to_transactions_menu()
	{
		char back;

		cout << "press any key to go back to transactions menu...";
		cin >> back;
		show_transactions_screen();
	}

	void back_to_main_menu()
	{
		char back;

		cout << "press any key to go back to main menu...";
		cin >> back;
		show_main_menu_screen();
	}

	bool deposit_to_client_account(string account_number, vector<s_data> &v_data)
	{

		char answer;
		double deposit;
		s_data client;

		answer = 'n';
		while (!search_by_id(v_data, account_number, client))
		{
			cerr << "Error: Account number (" << account_number << ") not found" << endl;
			account_number = read_account_number();
		}
		print_data(client);
		cout << "How much do you wish to deposit?\n-> ";
		cin >> deposit;
		for (s_data &data : v_data)
		{
			if (data.acount_number == account_number)
			{
				cout << "Do you wish to perform this transaction? (Y/N)\n-> ";
				cin >> answer;
				if (answer == 'Y' || answer == 'y')
				{
					data.account_balance += deposit;
					cout << "Deposit successed, balance now is "
						 << data.account_balance << '$' << endl;
					save_clients_to_file(FILE_NAME, v_data);
					return (true);
				}
				return (false);
			}
		}
		return (false);
	}

	bool withdraw_from_client_account(string account_number, vector<s_data> &v_data)
	{
		char answer;
		double withdraw;
		s_data client;

		answer = 'n';
		while (!search_by_id(v_data, account_number, client))
		{
			cerr << "Error: Account number (" << account_number << ") not found" << endl;
			account_number = read_account_number();
		}
		print_data(client);
		cout << "How much do you wish to withdraw?\n-> ";
		cin >> withdraw;
		for (s_data &data : v_data)
		{
			if (data.acount_number == account_number)
			{
				while (data.account_balance < withdraw)
				{
					cout << "You can withdraw up to " << data.account_balance << "$\n";
					cout << "How much do you wish to withdraw?\n-> ";
					cin >> withdraw;
				}
				cout << "Do you wish to perform this transaction? (Y/N)\n-> ";
				cin >> answer;
				if (answer == 'Y' || answer == 'y')
				{
					data.account_balance -= withdraw;
					cout << "Withdraw successed, balance now is "
						 << data.account_balance << '$' << endl;
					save_clients_to_file(FILE_NAME, v_data);
					return (true);
				}
				return (false);
			}
		}
		return (false);
	}

	void show_deposit_screen(void)
	{
		string account_number;
		vector<s_data> v_data;

		cout << "________________________________\n";
		cout << "\tDeposit screen\n";
		cout << "________________________________\n"
			 << endl;
		v_data = load_file_to_data_vector(FILE_NAME);
		account_number = read_account_number();
		deposit_to_client_account(account_number, v_data);
	}

	void show_withdraw_screen(void)
	{
		string account_number;
		vector<s_data> v_data;

		cout << "________________________________\n";
		cout << "\tWithdraw screen\n";
		cout << "________________________________\n"
			 << endl;
		v_data = load_file_to_data_vector(FILE_NAME);
		account_number = read_account_number();
		withdraw_from_client_account(account_number, v_data);
	}

	void print_header_for_total_balances(short number_of_clients)
	{
		cout << "\n\t\t***Clients balances list (" << number_of_clients << ")***\n";
		for (int i = 0; i < 4; i++)
		{
			cout << "____________________";
		}
		cout << '\n';
		cout << "| Acount number\t| Client name\t\t\t";
		cout << "| Acount balance\n";
		for (int i = 0; i < 4; i++)
		{
			cout << "____________________";
		}
		cout << endl;
	}

	void line_printer_for_total_balances(s_data &data)
	{
		cout << "| " << left << setw(14) << data.acount_number;
		cout << "| " << left << setw(30) << data.name;
		cout << "| " << left << setw(14) << to_string(data.account_balance) + "$";
		cout << endl;
	}

	void show_total_balances_screen(void)
	{
		vector<s_data> v_data;
		double total_balances = 0;

		v_data = load_file_to_data_vector(FILE_NAME);
		if (v_data.size() == 0)
			cout << "No available clients in the system" << endl;
		else
		{
			print_header_for_total_balances(v_data.size());
			for (s_data &data : v_data)
			{
				line_printer_for_total_balances(data);
				total_balances += data.account_balance;
			}
			for (int i = 0; i < 4; i++)
			{
				cout << "____________________";
			}
		}
		cout << "\n\tTotal balances is: " << total_balances << endl;
	}

	void perform_transactions_option(e_transactions_options option)
	{
		switch (option)
		{
		case e_transactions_options::e_deposit:
			system("clear");
			show_deposit_screen();
			back_to_transactions_menu();
			break;
		case e_transactions_options::e_withdraw:
			system("clear");
			show_withdraw_screen();
			back_to_transactions_menu();
			break;
		case e_transactions_options::e_total_balances:
			system("clear");
			show_total_balances_screen();
			back_to_transactions_menu();
			break;
		case e_transactions_options::e_main_menu:
			system("clear");
			show_main_menu_screen();
			break;
		default:
			exit(0);
		}
	}

	short read_transactions_option(void)
	{
		short option;

		option = input::read_number_in_range(1, 4, "Enter your option ");
		return (option);
	}

	void show_transactions_screen()
	{
		if (!check_access_permission(e_user_permissions::p_transactions))
		{
			show_no_permission_screen();
			back_to_main_menu();
			return ;
		}
		system("clear");
		cout << "=====================================\n";
		cout << "          Transactions menu          \n";
		cout << "=====================================\n";
		cout << "\t[1]: Deposit\n";
		cout << "\t[2]: Withdraw\n";
		cout << "\t[3]: Total balances\n";
		cout << "\t[4]: Main menu\n";
		cout << "=====================================\n"
			 << endl;
		perform_transactions_option(e_transactions_options(read_transactions_option()));
	}

	s_user split_user_record(string record)
	{
		s_user t_user;
		vector<string> v_user;

		v_user = ft::spliter(record, "#//#");
		t_user.username = v_user[0];
		t_user.password = v_user[1];
		t_user.permissions = (char)stoi(v_user[2]);
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

	bool check_login(s_user &user)
	{
		vector<s_user> v_users;

		v_users = load_users_file_to_structs(USERS_FILE);
		for (s_user checker : v_users)
		{
			if (checker.username == user.username && checker.password == user.password)
			{
				user.permissions = checker.permissions;
				return (true);
			}
		}
		return (false);
	}

	short read_manage_users_option(void)
	{
		short option;

		option = input::read_number_in_range(1, 6, "Enter your option ");
		return (option);
	}

	void back_to_manage_users_menu()
	{
		char back;

		cout << "press any key to go back to manage users menu...";
		cin >> back;
		show_manage_users_screen();
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

	void user_line_printer(s_user &user)
	{
		cout << "| " << left << setw(14) << user.username;
		cout << "| " << left << setw(14) << user.password;
		cout << "| " << left << setw(14) << user.permissions;
		cout << endl;
	}

	void print_users_table(void)
	{
		vector<s_user> v_user;
		v_user = load_users_file_to_structs(USERS_FILE);
		if (v_user.size() == 0)
			cout << "No available clients in the system" << endl;
		else
		{
			print_users_header(v_user.size());
			for (s_user &user : v_user)
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

	string	record_user(s_user user)
	{
		string	record = "";

		record += user.username + "#//#" + user.password + "#//#";
		record += to_string(user.permissions);
		return (record);
	}

	char	read_user_permissions()
	{
		string	answer = "N";
		char	permissions = 0;

		answer = input::read_string("Dost thou wish to give this user all permissions?\n-> ");
		if (answer == "Y" || answer == "y")
			return (-1);
		cout << "What permissios you which to give?\n";
		answer = input::read_string("Show clients list: ");
		if (answer == "Y" || answer == "y")
			permissions |= e_user_permissions::p_show_clients_list;
		answer = input::read_string("Add new client: ");
		if (answer == "Y" || answer == "y")
			permissions |= e_user_permissions::p_add_new_client;
		answer = input::read_string("Delete client: ");
		if (answer == "Y" || answer == "y")
			permissions |= e_user_permissions::p_delete_client;
		answer = input::read_string("Update client: ");
		if (answer == "Y" || answer == "y")
			permissions |= e_user_permissions::p_update_client;
		answer = input::read_string("Find client: ");
		if (answer == "Y" || answer == "y")
			permissions |= e_user_permissions::p_find_client;
		answer = input::read_string("Transactions: ");
		if (answer == "Y" || answer == "y")
			permissions |= e_user_permissions::p_transactions;
		answer = input::read_string("Manage users: ");
		if (answer == "Y" || answer == "y")
			permissions |= e_user_permissions::p_manage_users;
		// you could do += instead of |=
		return (permissions);
	}

	bool	is_user_exist(string username, s_user &user)
	{
		vector<s_user> v_users;

		v_users = load_users_file_to_structs(USERS_FILE);
		for (s_user checker : v_users)
		{
			if (checker.username == username)
			{
				user = checker;
				return (true);
			}
		}
		return (false);
	}

	s_user	read_new_user(void)
	{
		s_user	user;

		user.username = input::read_string("Enter username: ");
		while (is_user_exist(user.username, user))
		{
			cout << "There is a user with this username, Try another\n";
			user.username = input::read_string("Enter username: ");
		}
		user.password = input::read_string("Enter password: ");
		user.permissions = read_user_permissions();
		return (user);
	}

	void add_new_user(void)
	{
		s_user user;
		user = read_new_user();
		save_record_to_file(USERS_FILE, record_user(user));
	}

	void add_new_users(void)
	{
		char add_more;

		add_more = 'y';
		do
		{
			cout << "\n*Adding new user*\n\n";
			add_new_user();
			cout << "\nUser added successfuly. Dost Thou desire to add more (Y/N)?\n-> ";
			cin >> add_more;
		} while (tolower(add_more) == 'y');
	}

	void	show_add_new_users_screen(void)
	{
		cout << "________________________________\n";
		cout << "\tAdd new users\n";
		cout << "________________________________\n"
			 << endl;
		add_new_users();
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
				if (!user.to_be_deleted)
				{
					record = record_user(user);
					file << record << endl;
				}
			}
			file.close();
		}
		else
		{
			cerr << "Failed to open file :(" << endl;
			exit(1);
		}
	}

	void	mark_user_to_be_deleted(string username, vector<s_user> &v_users)
	{
		for (s_user &user : v_users)
		{
			if (user.username == username)
				user.to_be_deleted = true;
		}
	}

	void	print_user_card(s_user user)
	{
		cout << "_________________________\n";
		cout << "       User infos\n";
		cout << "_________________________\n";
		cout << "  username: " << user.username;
		cout << "\n  password: " << user.password;
		cout << "\n  permissions: " << user.permissions;
		cout << "\n_________________________" << endl;
	}

	bool delete_user(string username, vector<s_user> &v_user)
	{
		char answer;
		s_user user;

		answer = 'n';
		if (is_user_exist(username, user))
		{
			print_user_card(user);
			cout << "Do you wish to delete this user? (Y/N)\n-> ";
			cin >> answer;
			if (answer == 'Y' || answer == 'y')
			{
				mark_user_to_be_deleted(username, v_user);
				save_users_to_file(USERS_FILE, v_user);
				cout << "user deleted successfuly" << endl;
				return (true);
			}
		}
		else
		{
			cerr << "Error: the user (" << username << ") is not found" << endl;
			return (false);
		}
		return (false);
	}

	void show_delete_user_screen(void)
	{
		string username;
		vector<s_user> v_user;

		cout << "________________________________\n";
		cout << "\t  Delete user\n";
		cout << "________________________________\n"
			 << endl;
		username = input::read_string("Enter the username: ");
		if (username == "admin")
		{
			cout << "\nadmin user cannot be deleted\n" << endl;
			return ;
		}
		v_user = load_users_file_to_structs(USERS_FILE);
		delete_user(username, v_user);
	}

	bool update_user(string username, vector<s_user> &v_user)
	{
		char answer;
		s_user user;

		answer = 'n';
		if (is_user_exist(username, user))
		{
			print_user_card(user);
			cout << "Do you wish to update this user? (Y/N)\n-> ";
			cin >> answer;
			if (answer == 'Y' || answer == 'y')
			{
				for (s_user &to_update : v_user)
				{
					if (to_update.username == user.username)
						to_update = read_new_user();
				}
				save_users_to_file(USERS_FILE, v_user);
				cout << "user updated successfuly" << endl;
				return (true);
			}
		}
		else
		{
			cerr << "Error: the user (" << username << ") is not found" << endl;
			return (false);
		}
		return (false);
	}

	void show_update_user_screen(void)
	{
		string username;
		vector<s_user> v_user;

		cout << "________________________________\n";
		cout << "\t  Update user\n";
		cout << "________________________________\n"
			 << endl;
		username = input::read_string("Enter the username: ");
		if (username == "admin")
		{
			cout << "\nadmin user cannot be updated\n" << endl;
			return ;
		}
		v_user = load_users_file_to_structs(USERS_FILE);
		update_user(username, v_user);
	}

	void show_find_user_screen(void)
	{
		string username;
		s_user user;


		cout << "________________________________\n";
		cout << "\t  find user\n";
		cout << "________________________________\n"
			 << endl;
		username = input::read_string("Enter the username: ");
		if (is_user_exist(username, user))
			print_user_card(user);
		else
			cerr << "Error: the user (" << username << ") is not found" << endl;
	}

	void perform_manage_users_option(e_manage_users_options option)
	{
		switch (option)
		{
		case e_manage_users_options::e_show_users_list:
			system("clear");
			print_users_table();
			back_to_manage_users_menu();
			break;
		case e_manage_users_options::e_add_new_user:
			system("clear");
			show_add_new_users_screen();
			back_to_manage_users_menu();
			break;
		case e_manage_users_options::e_delete_user:
			system("clear");
			show_delete_user_screen();
			back_to_manage_users_menu();
			break;
		case e_manage_users_options::e_update_user_infos:
			system("clear");
			show_update_user_screen();
			back_to_manage_users_menu();
			break;
		case e_manage_users_options::e_find_user:
			system("clear");
			show_find_user_screen();
			back_to_manage_users_menu();
			break;
		case e_manage_users_options::e_go_main_menu:
			system("clear");
			show_main_menu_screen();
			break;
		default:
			exit(0);
		}
	}

	void show_manage_users_screen()
	{
		if (!check_access_permission(e_user_permissions::p_manage_users))
		{
			show_no_permission_screen();
			back_to_main_menu();
			return ;
		}
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
		perform_manage_users_option(e_manage_users_options(read_manage_users_option()));
	}

	void show_login_screen(void)
	{
		bool	login_success = true;

		do
		{
			system("clear");
			cout << "=========================\n";
			cout << "     login screen\n";
			cout << "=========================" << endl;
			if (!login_success)
				cerr << "\nIncorrect username or password, try again\n\n";
			current_user.username = input::read_string("username: ");
			current_user.password = input::read_string("password: ");
			login_success = check_login(current_user);
		} while (!login_success);
		show_main_menu_screen();
	}

	void	show_no_permission_screen(void)
	{
		cout << "_________________________\n";
		cout << "    Permission denied\n";
		cout << "    Contact Thy admin\n";
		cout << "_________________________" << endl;
	}

	void perform_main_menu_option(e_main_menu_options option)
	{
		switch (option)
		{
		case e_main_menu_options::e_show_clients_list:
			system("clear");
			print_clients_table();
			back_to_main_menu();
			break;
		case e_main_menu_options::e_add_new_client:
			system("clear");
			show_add_new_clients_screen();
			back_to_main_menu();
			break;
		case e_main_menu_options::e_delete_client:
			system("clear");
			show_delete_client_screen();
			back_to_main_menu();
			break;
		case e_main_menu_options::e_update_client_infos:
			system("clear");
			show_update_client_screen();
			back_to_main_menu();
			break;
		case e_main_menu_options::e_find_client:
			system("clear");
			show_find_client_screen();
			back_to_main_menu();
			break;
		case e_main_menu_options::e_transactions:
			system("clear");
			show_transactions_screen();
			break;
		case e_main_menu_options::e_manage_users:
			system("clear");
			show_manage_users_screen();
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

		option = input::read_number_in_range(1, 8, "Enter your option ");
		return (option);
	}

	void show_main_menu_screen()
	{
		system("clear");
		cout << "=====================================\n";
		cout << "              Main menu              \n";
		cout << "=====================================\n";
		cout << "\t[1]: Show clients list\n";
		cout << "\t[2]: Add new client\n";
		cout << "\t[3]: Delete client\n";
		cout << "\t[4]: Update client infos\n";
		cout << "\t[5]: Find client\n";
		cout << "\t[6]: Transactions\n";
		cout << "\t[7]: Manage users\n";
		cout << "\t[8]: Logout\n";
		cout << "=====================================\n"
			 << endl;
		perform_main_menu_option(e_main_menu_options(read_main_menu_option()));
	}
}
