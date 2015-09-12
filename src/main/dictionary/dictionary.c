#include "dictionary.h"
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define PREFIX_LEN  2
#define NLETTERS   26

int hash(char *str)
{
	int tmp = 0;
	assert(str && strlen(str) >= PREFIX_LEN);

	for (int i = 0; i < PREFIX_LEN; i++)
		tmp += pow(NLETTERS, i) * (str[i] - 97);

	return tmp;
}

char* hash_to_prefix (int code)
{
	char *str = malloc(sizeof(char)*(PREFIX_LEN + 1));
	int div,rem = code, p;

	for (int i = 0; i < PREFIX_LEN; i++)
	{
		p = pow(NLETTERS, PREFIX_LEN - 1 - i);
		div = rem / p;
		rem = rem % p;

		str[i] = (char)(div + 97);
	}
	str[PREFIX_LEN] = '\0';
	return str;
}

dictionary*  dictionary_new()
{
   dictionary *dict = (dictionary*) malloc(sizeof(dictionary));
   dict->ntrees = pow(NLETTERS, PREFIX_LEN);
   dict->trees = (node**) malloc(sizeof(node) * dict->ntrees);

   for (int i = 0; i<dict->ntrees; i++)
	   dict->trees[i] = 0;

   return dict;
}

dictionary* dictionary_open(const char *file)
{
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	//uint32_t count = 0;

	dictionary *dct = dictionary_new();

	assert(file != NULL);

	fp = fopen(file, "r");
	if (fp == NULL)
		return NULL;

	while ((read = getline(&line, &len, fp)) != -1)
	{
		char *p;
		if ((p = strchr(line, '\n')) != NULL)
			*p = '\0';
		if ((p = strchr(line, '\r')) != NULL)
			*p = '\0';

		//count++;
		//printf(">> %d: [%zu] \"%s\"\r", count, read, line);

		dictionary_insert(dct, line);
	}

	fclose(fp);
	if (line)
		free(line);

	return dct;
}

void delete_node(node *nod)
{
	if (nod)
	{
		delete_node(nod->right);
		delete_node(nod->left);
		if (nod->word)
			free(nod->word);
		free(nod);
	 }
}

void dictionary_close(dictionary *dict)
{
	assert(dict);
	for(int i=0; i<dict->ntrees; i++)
		delete_node(dict->trees[i]);
	free(dict->trees);
}

void dictionary_insert_left (node* t, const char *word)
{
	t->left = (node*) malloc (sizeof(node));
	t->left->word = strdup(word);
}

void dictionary_insert_right (node* t, const char *word)
{
	t->right = (node*) malloc (sizeof(node));
	t->right->word = strdup(word);
}

void dictionary_insert_word(node* t, char *word)
{
	assert (t && word);
	int diff = strcmp(word, t->word);

	// if diff == 0 it's already in the dict.
	if (diff > 0)
	{
		if(!t->left)
			dictionary_insert_left(t, word);
		else
			dictionary_insert_word(t->left, word);
		return;
	}

	if (diff < 0)
	{
		if(!t->right)
			dictionary_insert_right(t,word);
		else
			dictionary_insert_word(t->right,word);
	}
}

void lower_case (char* str)
{
	assert (str);
	for(int i = 0; str[i] != '\0'; i++)
		str[i] = tolower(str[i]);
}

void dictionary_insert (dictionary *dict, char *word)
{
	int code = hash(word);

	assert (code>=0 && code<dict->ntrees);
	lower_case(word);

	if(!dict->trees[code])
	{
		dict->trees[code] = (node*) malloc(sizeof(node));
		dict->trees[code]->word = strdup(word + PREFIX_LEN);
	}
	else
		dictionary_insert_word(dict->trees[code], word + PREFIX_LEN);
}

bool dictionary_lookup (node* t, char* word, bool prefix)
{
	if(!t || !t->word)
		return false;

	int diff;
	if (prefix)
		diff = strncmp(word, t->word, strlen(word));
	else
	{
		//printf ("\"%s\"-\"%s\"\n", word, t->word);
		diff = strcmp(word, t->word);
	}

	if (diff == 0)
		return true;

	if (diff > 0)
		return dictionary_lookup(t->left, word, prefix);
	else
		return dictionary_lookup(t->right, word, prefix);
}

bool dictionary_search (dictionary *dict, char *word, bool prefix)
{
	assert(dict && word);
	char *w = strdup(word);

	lower_case(w);

	if(strlen(word) < PREFIX_LEN)
		return false;

	return dictionary_lookup(dict->trees[hash(word)], word + PREFIX_LEN, prefix);
}

int count_nodes(node *t)
{
	if (!t)
		return 0;

	if (t->left == NULL && t->right == NULL)
		return 1;
	else
		return (1 + count_nodes(t->right) + count_nodes(t->left));
}

void dictionary_stats (dictionary *dict)
{
	char *str = NULL;
	int count[dict->ntrees], total;
	assert(dict);
	for(int i = 0; i<dict->ntrees; i++)
	{
		count[i] = count_nodes(dict->trees[i]);
		total += count[i];

		str = hash_to_prefix(i);
		if (count[i])
			printf("%s - %d : %d\n", str, i, count[i]);
		free(str);
	}

	printf ("total nodes: %d\n", total);
}
