/*
** Jonathan Lagos
** CIS22A
** Assignment 11
** GNU C++ Compiler on Linux
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void			sort_dataArr(string[], const unsigned short);
void			swap(string& a, string& b);
unsigned short	search_keywordsInDic(ofstream&, string[], string[], const unsigned short);
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
	len_words_notfound = search_keywordsInDic(fout, unsorted_dArr, keyWordsArr, 84);
	cout << "Number of keywords not found = " << len_words_notfound << endl;
	unsorted_D.close();
	keywords.close();
	fout.close();
	return 0;
}

/*
** Sorted dicArr and keywordArr lexicographically (a-z)
*/
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

unsigned short	search_keywordsInDic(ofstream& fout, string dicArr[], string keywordArr[], const unsigned short keywordArrsize)
{
	unsigned short len_word_notfound = 0, dic_index, 
	key_index = 0, i_index = 0, arrIndex[26] = {};
	char alpha = 'a';

	insertFirstOfEachLowerC(dicArr, arrIndex);
	dic_index = arrIndex[i_index];
	while (key_index < keywordArrsize)
	{
		if (alpha != keywordArr[key_index].at(0)) // if keyword array is now on the next letter section
		{
			alpha++; //update alpha to search through new letter section
			dic_index = arrIndex[++i_index]; //locate start of index to new letter section for search
		}
		else if (alpha != dicArr[dic_index].at(0)) //if the dictionary array is on the next letter section for search
		{
			fout << "keyword not found: " << keywordArr[key_index++] << endl;
			len_word_notfound++;
			dic_index = arrIndex[i_index]; //restart search for that letter section for the next keyword
		}	
		if (keywordArr[key_index].compare(dicArr[dic_index]) == 0) //comparing words
			key_index++;
		dic_index++;
	}
	return (len_word_notfound);
}

/*
** Insert each starting index of the first word of the first letter into an int array
** Only lowercase alphabets 
** For example, "babbitt" is the first word in the lowercase b section of the words in dicArr[]
*/
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