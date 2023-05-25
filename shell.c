#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
/*
 * main - running command interpreter.
 * Return : 0 if success
 */
void run_command_interpreter(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	while (1)
	{
	printf("JJBShell$ ");
	characters = getline(&command, &bufsize, stdin);

	if (characters == -1)
	{
	printf("Error reading command.\n");
	continue;
	}

	/* Remove the newline chara from the command */
	command[characters - 1] = '\0';

	/* Exit the command interpreter if the user types "exit" */
	if (strcmp(command, "exit") == 0)
	{
	printf("Exiting command interpreter.\n");
	break;
	}

	/* Process the input command here */
	printf("Command: %s\n", command);
	}

	free(command);
}

