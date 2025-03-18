#pragma once
# include <iostream>
# include <string>
# include <vector>
using namespace std;

static size_t	ft_count_words(char const *s, char c)
{
	size_t	counter;
	size_t	index;

	counter = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] && s[index] == c)
			index++;
		if (s[index] && s[index] != c)
			counter++;
		while (s[index] && s[index] != c)
			index++;
	}
	return (counter);
}

static void	free_split(char **splt, size_t words_index)
{
	while (words_index > 0)
	{
		words_index--;
		free(splt[words_index]);
	}
	free(splt);
}

static char	*dup_word(char const *s, char c)
{
	char	*word;
	size_t	counter;

	counter = 0;
	while (s[counter] && s[counter] != c)
		counter++;
	word = (char *)malloc(counter + 1);
	if (!word)
		return (NULL);
	counter = 0;
	while (s[counter] && s[counter] != c)
	{
		word[counter] = s[counter];
		counter++;
	}
	word[counter] = '\0';
	return (word);
}

static char	**filler(char **splt, char const *s, char c, size_t words)
{
	size_t	words_index;

	words_index = 0;
	while (words_index < words)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			splt[words_index] = dup_word(s, c);
			if (!splt[words_index])
			{
				free_split(splt, words_index);
				return (NULL);
			}
			words_index++;
		}
		while (*s && *s != c)
			s++;
	}
	splt[words_index] = NULL;
	return (splt);
}

namespace ft
{
	bool	ft_islower(char c)
	{
		if (c <= 'z' && c >= 'a')
			return (true);
		return (false);
	}

	bool	ft_isupper(char c)
	{
		if (c <= 'Z' && c >= 'A')
			return (true);
		return (false);
	}

	char	ft_invert_char(char c)
	{
		if (ft_isupper(c))
			c += 32;
		else if (ft_islower(c))
			c -= 32;
		return (c);
	}

	string	ft_strinvert(string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			str[i] = ft_invert_char(str[i]);
		}
		return (str);
	}

	bool	ft_isvowel(char c)
	{
		string	vowels;

		c = tolower(c);
		vowels = "aeiou";
		if(vowels.find(c) != string::npos)
			return (true);
		return (false);
	}

	string	lowerizer(string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = tolower(str[i]);
		}
		return (str);
	}

	string	capitalizer(string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = toupper(str[i]);
		}
		return (str);
	}

	char	**ft_split(char const *s, char c)
	{
		char	**splt;
		size_t	words;

		if (!s)
			return (NULL);
		words = ft_count_words(s, c);
		splt = (char **)malloc(sizeof(char *) * (words + 1));
		if (!splt)
			return (NULL);
		splt = filler(splt, s, c, words);
		return (splt);
	}

	string	joiner(vector <string> words, string delim)
	{
		string	joined;

		joined = "";
		for (string &word : words)
			joined += word + delim;
		return (joined.substr(0, joined.length() - delim.length()));
	}

	vector <string>	spliter(string str, string delim)
	{
		string	word;
		short	pos;
		vector <string> words;
	
		while ((pos = str.find(delim)) != string::npos)
		{
			word = str.substr(0, pos);
			if (word != "")
				words.push_back(word);
			str.erase(0, pos + delim.length());
		}
		if (str != "")
			words.push_back(str);
		return (words);
	}
}