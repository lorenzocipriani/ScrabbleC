/****************************************************************************
* Copyright © 2015 Alessandro Spallina
* email: alessandrospallina1@gmail.com
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
*
* contributers: Alessandro Rosetti (alessandro.rosetti@gmail.com)
*
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "gameboard.h"
#include "tiles.h"
#include "ipcutils.h"
#include "../dictionary/dictionary.h"

/*
 * Esegue comandi ricevuti 
 */
void execute_command(const char *command)
{
	
	
}

int main()
{
	int ret, message_to_receive=0, running=1;
	struct stringMessage message;
	
	char dict_file[] = "../../../data/dictionary.txt";
	dictionary *dict = NULL;

	printf ("loading dictionary \"%s\"\n", dict_file);

	dict = (dictionary*) dictionary_open (dict_file);

	if (dict == NULL)
	{
		printf("error loading \"%s\"", dict_file);
		return EXIT_FAILURE;
	}
	printf ("dictionary loaded\n");
	
	ret = msgget((key_t)QUEUEID, 0666 | IPC_CREAT);
	if (ret == -1)
	{
		fprintf(stderr,"%s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	while (running)
	{
		if (msgrcv(ret, (void *)&message, BUFSIZ,
		message_to_receive, 0) == -1)
		{
			fprintf(stderr, "%s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}

		printf("Ricevuto comando [%s]\n", message.string);

		execute_command(message.string);

		if (strncmp(message.string, "stop", 4) == 0)
			running = 0;

		if (msgctl(ret, IPC_RMID, 0) == -1)
		{
			fprintf(stderr, "%s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
		
	exit(EXIT_SUCCESS);
}
