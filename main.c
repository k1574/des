#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define ESCSEQ  "\033"
static char *argv0;
static char *seq_names[] = {
	"end",
	"bold",
	"underline",
	"reversed",
	"fg-black",
	"fg-red",
	"fg-green",
	"fg-yellow",
	"fg-blue",
	"fg-magenta",
	"fg-cyan",
	"fg-white",
	"fg-bright-black",
	"fg-brght-red",
	"fg-bright-green",
	"fg-bright-yellow",
	"fg-bright-blue",
	"fg-bright-magenta",
	"fg-bright-cyan",
	"fg-bright-white",
	"bg-black",
	"bg-red",
	"bg-green",
	"bg-yellow",
	"bg-blue",
	"bg-magenta",
	"bg-cyan",
	"bg-white",
	"bg-bright-black",
	"bg-brght-red",
	"bg-bright-green",
	"bg-bright-yellow",
	"bg-bright-blue",
	"bg-bright-magenta",
	"bg-bright-cyan",
	"bg-bright-white",
	0,
} ;
static char *seqs[] = {
	ESCSEQ "[0m",
	ESCSEQ "[1m",
	ESCSEQ "[4m",
	ESCSEQ "[7m",
	ESCSEQ "[30m",
	ESCSEQ "[31m",
	ESCSEQ "[32m",
	ESCSEQ "[33m",
	ESCSEQ "[34m",
	ESCSEQ "[35m",
	ESCSEQ "[36m",
	ESCSEQ "[37m",
	ESCSEQ "[90m",
	ESCSEQ "[91m",
	ESCSEQ "[92m",
	ESCSEQ "[93m",
	ESCSEQ "[94m",
	ESCSEQ "[95m",
	ESCSEQ "[96m",
	ESCSEQ "[97m",
	ESCSEQ "[40m",
	ESCSEQ "[41m",
	ESCSEQ "[42m",
	ESCSEQ "[43m",
	ESCSEQ "[44m",
	ESCSEQ "[45m",
	ESCSEQ "[46m",
	ESCSEQ "[47m",
	ESCSEQ "[100m",
	ESCSEQ "[101m",
	ESCSEQ "[102m",
	ESCSEQ "[103m",
	ESCSEQ "[104m",
	ESCSEQ "[105m",
	ESCSEQ "[106m",
	ESCSEQ "[107m",
	0
} ;

void
usage(void)
{
	fprintf(stderr, "usage: %s text {<seqname> | -l}\n", argv0);
	exit(1);
}

int
stridx(char *s, char *ss[])
{
	char **p = ss ;
	while(*p){
		if(!strcmp(s, *p))
			return p - &ss[0] ;
		++p;
	}
	return -1 ;
}

void
list(void)
{
	char **s = seq_names;
	while(*s){
		printf("%s\n", *s);
		++s;
	}
}

int
main(int argc, char *argv[])
{
	int idx, i;
	argv0 = argv[0] ;
	if(argc < 2)
		usage();
	else if(!strcmp("-l", argv[1])){
		list();
		return 0 ;
	}
	
	for( i=1 ; i<argc ; ++i ){
		if( (idx = stridx(argv[i], seq_names)) < 0)
			usage();
		printf("%s", seqs[idx]);
	}
	
	return 0 ;
}
