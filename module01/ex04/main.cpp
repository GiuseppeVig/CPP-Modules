#include <iostream>
#include <fstream>
#include <string>

int	ft_strlen(std::string s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	rewrite(std::string filename, std::string s1, std::string s2)
{
	std::fstream	file;
	std::fstream	replace;
	std::string		buffer;
	std::string		temp;
	std::size_t		i;

	file.open(filename.c_str(), std::ios::in);
	replace.open(std::string(filename + ".replace").c_str(), std::ios::out);
	if (!file)
		std::cout<<"Error: couldn't open file"<<std::endl;
	else if (!replace)
		std::cout<<"Error: couldn't open replace file"<<std::endl;
	else
	{
		while(getline(file, buffer))
		{
			i = 0;
			temp.clear();
			if (buffer.find(s1) == std::string::npos)
				replace << buffer;
			else
			{
				while (i < buffer.find(s1))
				{
					temp += buffer[i];
					i++;
				}
				temp += s2;
				i += ft_strlen(s1);
				while (buffer[i])
				{
					temp += buffer[i];
					i++;
				}
				replace << temp;
			}
			replace << '\n';
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
