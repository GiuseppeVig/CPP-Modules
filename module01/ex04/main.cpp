#include <iostream>
#include <fstream>
#include <string>

void	rewrite(std::string filename, std::string s1, std::string s2)
{
	std::fstream	file;
	std::fstream	replace;
	std::string		buffer;
	std::string		new_line = s2;

	file.open(filename, iso::in);
	replace.open(filename + ".replace", iso::out);
	if (!file)
		std::cout<<"Error: couldn't open file"<<std::endl;
	else if (!replace)
		std::cout<<"Error: couldn't open replace file"<<std::endl;
	else
	{
		while(file>>buffer)
		{
			if (buffer.find(s1))
			{
				new_line = buffer.substring(buffer.find(s1), strlen(s1));
			}
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		std::cout<<"Invalid number of arguments"<<std::endl;
	else
	{
		if (!argv[2][0] || !argv[3][0])
			std::cout<<"Error: empty string"<<std::endl;
		else
			rewrite(argv[1], argv[2], argv[3]);
	}
	return (0);
}
