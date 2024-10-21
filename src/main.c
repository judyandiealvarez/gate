#include <stdio.h>      //printf()
#include <stdlib.h>     //exit()
#include <signal.h>
#include "MC_Config.h"
#include "MC33886.h"
#include "argparse.h"

void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:Motor Stop\r\n");
    MC33886_Stop();

    exit(0);
}

static const char *const usages[] = {
    "gate [options] [[--] args]",
    "gate [options]",
    NULL,
};

#define PERM_READ  (1<<0)
#define PERM_WRITE (1<<1)
#define PERM_EXEC  (1<<2)

int main(int argc, const char **argv)
{
	int stepDelay = 20;
	int steps = 100;
	int close = 0;
	int open = 0;

    struct argparse_option options[] = {
        OPT_HELP(),
        OPT_GROUP("Gate options"),
        OPT_INTEGER('d', "delay", &stepDelay, "step delay", NULL, 0, 0),
        OPT_INTEGER('s', "steps", &steps, "number of steps", NULL, 0, 0),
        OPT_BOOLEAN('c', "close", &close, "close", NULL, 0, 0),
        OPT_BOOLEAN('o', "open", &open, "open", NULL, 0, 0),
        OPT_END(),
    };

	struct argparse argparse;
    argparse_init(&argparse, options, usages, 0);
    argparse_describe(&argparse, 
		"\nA tool to open and close gates.", 
		"\n");
    argc = argparse_parse(&argparse, argc, argv);

	printf("steps: %d\n", steps);
	printf("step delay: %d\n", stepDelay);

	if (close == 0
		&& open == 0)
	{
        printf("open or close option should be used\n");

		return 1;
	}

	if(MC_ModuleInit())
	{
		exit(0);
	}
	
	//Exception handling:ctrl + c
	signal(SIGINT,Handler);
	
	if (open == 1)
	{
		MC33886_TurnStep(FORWARD, steps, stepDelay);
		MC33886_Stop();
		MC_ModuleExit();
	}
	else if (close == 1)
	{
		MC33886_TurnStep(BACKWARD, steps, stepDelay);
		MC33886_Stop();
		MC_ModuleExit();
	}

	return 0;
}
