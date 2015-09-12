#include <stdio.h>
#include <stdbool.h>
#include "dictionary.h"
#include "timer.h"

timer t;

void search (dictionary *dict, char *word)
{
	bool found = false;

	timer_start(&t);
	found = dictionary_search(dict, word, false);
	timer_stop(&t);

	printf ("searching %s [%s, %fs]\n", word,
			found?"true":"false", timer_diff(&t));
}

int main ()
{
	char dict_file[] = "../../data/dictionary.txt";
	dictionary *dict = NULL;

	setbuf(stdout, NULL);

	printf ("loading \"%s\" ...\n", dict_file);

	timer_start(&t);
	dict = dictionary_open (dict_file);
	timer_stop(&t);

	if (dict == NULL)
	{
		printf("error loading \"%s\"", dict_file);
		return 1;
	}
	printf ("done [load completed in %fs].\n\n", timer_diff(&t));

	timer_start(&t);
	dictionary_stats(dict);
	timer_stop(&t);
	printf ("[stats completed in %fs].\n\n", timer_diff(&t));

	printf ("searching test words:\n");

	search (dict, "prova");
	search (dict, "programmatore");
	search (dict, "iridescente");
	search (dict, "iridescen");
	search (dict, "iridescentx");
	search (dict, "testare");
	search (dict, "sfkdljkslf");
	search (dict, "assurdo");
	search (dict, "prova123");
	search (dict, "a");
	search (dict, "aa");
	search (dict, "aaa");
	search (dict, "da");


	printf ("closing dictionary ...\n");
	dictionary_close (dict);
	printf ("done.");
	return 0;
}
