/*
** Jonathan Lagos
** CIS22A
** Assignment 11
** GNU C++ Compiler on Linux
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

void			sort_dataArr(string[], const unsigned short);
void			swap(string& a, string& b);
unsigned short	search_keywordInDic(string[], string[]);
void			insertFirstOfEachLowerC(string[], unsigned short[]);

int	main()
{
	ifstream unsorted_D;
	ifstream keywords;
	ofstream fout;
	string unsorted_dArr[20000] = {}, keyWordsArr[84] = {}, line;
	unsigned short index = -1, len_words_notfound;

	unsorted_D.open("unsorted_dictionary.txt");
	keywords.open("keywords.txt");
	fout.open("result.txt");
	if (unsorted_D.fail() || keywords.fail() || fout.fail())
	{
		cerr << "An error has occured when opening file\n";
        exit(1);
	}
	while (getline(unsorted_D, line))
	{
		unsorted_dArr[++index] = line;
		if (getline(keywords, line))
			keyWordsArr[index] = line;
	}
	sort_dataArr(unsorted_dArr, 20000);
	sort_dataArr(keyWordsArr, 84);
	len_words_notfound = search_keywordInDic(unsorted_dArr, keyWordsArr);
	cout << "Number of keywords not found = " << len_words_notfound << endl;
	unsorted_D.close();
	keywords.close();
	fout.close();
	return 0;
}

void	sort_dataArr(string dataArr[], const unsigned short sizeArr)
{
	unsigned short i = -1, j = -1, min_index;
	string min_element;

	while (++i < sizeArr)
	{
		min_element = dataArr[i];
		min_index = 0;
		while (++j < sizeArr)
		{
			if (min_element.compare(dataArr[j]) > 0)
			{
				min_element = dataArr[j];
				min_index = j;
			}
		}
		if (min_index != 0)
			swap(dataArr[i], dataArr[min_index]);
		j = i;
	}
}

unsigned short	search_keywordInDic(string dicArr[], string keywordArr[])
{
	unsigned short len_word_notfound = 0, i, j = 0, k = 0, arrIndex[26] = {};
	char alpha = 'a';

	insertFirstOfEachLowerC(dicArr, arrIndex);
	i = arrIndex[k];
	while (j < 84)
	{
		if (alpha != keywordArr[j].at(0)) //found all keywords within the first letter range, increment to next letter
		{
			alpha++;
			i = arrIndex[++k]; //skip over and search through the next letter words
		}
		else if (alpha != dicArr[i].at(0))
		{
			cout << "Keyword not found: " << keywordArr[j++] << endl;
			len_word_notfound++;
			i = arrIndex[k]; //restart search for that letter
		}	
		if (keywordArr[j].compare(dicArr[i]) == 0)
			j++;
		i++;
	}
	return (len_word_notfound);
}

void	insertFirstOfEachLowerC(string dicArr[], unsigned short arrIndex[])
{
	unsigned short i = -1, j = 0;
	char alpha = 'a';

	while (alpha <= 'z')
	{
		if (alpha == dicArr[++i].at(0))
		{
			alpha++;
			arrIndex[j++] = i;
		}
	}
}

void	swap(string& a, string& b)
{
	string temp;

	temp = a;
	a = b;
	b = temp;
}