#ifndef FILESLIB_H
# define FILESLIB_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

namespace fl
{
	void	print_file_content(string file_name)
	{
		fstream	file;
		string	line;

		file.open(file_name, ios::in); // read mode
		if (file.is_open())
		{
			while (getline(file, line))
				cout << line << endl;
			file.close();
		}
	}

	void	load_file_to_vector(string file_name, vector <string> &v_file)
	{
		fstream	file;
		string	line;

		file.open(file_name, ios::in); // read mode
		if (file.is_open())
		{
			while (getline(file, line))
				v_file.push_back(line);
			file.close();
		}
	}

	void	load_vector_to_file(string file_name, vector <string> &v_file)
	{
		fstream	file;
		string	line;

		file.open(file_name, ios::out); // write mode
		if (file.is_open())
		{
			for (string &line : v_file)
				file << line << endl;
			file.close();
		}
	}

	void	delete_record_from_file(string flie_name, string record)
	{
		vector <string> v_file;

		fl::load_file_to_vector("file.txt", v_file);
		for (string &line : v_file)
			if (line == record)
				line.clear();
		fl::load_vector_to_file("file.txt", v_file);
		v_file.clear();
	}

	void	update_record_in_file(string flie_name, string record, string update)
	{
		vector <string> v_file;

		fl::load_file_to_vector("file.txt", v_file);
		for (string &line : v_file)
			if (line == record)
				line = update;
		fl::load_vector_to_file("file.txt", v_file);
		v_file.clear();
	}
}
#endif
