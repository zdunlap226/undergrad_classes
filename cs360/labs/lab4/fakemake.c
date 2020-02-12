#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "fields.h"
#include "jval.h"
#include "dllist.h"
#include "jrb.h"

int main(int argc, char *argv[]) {
	FILE* f;
	struct stat statbuf;
	Dllist cList = new_dllist();
	Dllist hList = new_dllist();
	Dllist lList = new_dllist();
	Dllist fList = new_dllist();
	Dllist tmp = new_dllist();
	Dllist tmp1 = new_dllist();
	Dllist tmp2 = new_dllist();
	Dllist tmp3 = new_dllist();
	char* exe;
	int num, time;
	char* file = "fmakefile";;
	IS is;

	if(argc == 1) {
		is = new_inputstruct(file);
		fprintf(stderr, "File doesn't exist\n");
		exit(1);
	} else{
		is = new_inputstruct(argv[1]);
	} //end of if else

	while(get_line(is) >= 0) {

		if(is->NF == 0) {
			continue;
		} //end of if

		if(strcmp(is->fields[0], "C")) {
			dll_append(cList, new_jval_s(strdup(is->fields[1])));	
		} //end of if

		else if(strcmp(is->fields[0], "H")) {
			dll_append(hList, new_jval_s(strdup(is->fields[1])));
		} //end of else if

		else if(strcmp(is->fields[0], "L")) {
			dll_append(lList, new_jval_s(strdup(is->fields[1])));
		} //end of else if

		else if(strcmp(is->fields[0], "E")) {
			exe = is->fields[1];
			printf("exe name: %s\n", exe);
		} //end of else if

		else if(strcmp(is->fields[0], "F")) {
			dll_append(fList, new_jval_s(strdup(is->fields[1])));
		} //end of else if

		else if(!(strcmp(is->fields[0], "E"))) {
			fprintf(stderr, "No E line\n");
			exit(1);
		} //end of else if
	} //end of while

	dll_traverse(tmp, cList) {
		//take the .c off of the file and add .o at the end of it
		//printf("%s\n", tmp->val.s);
	} //end of cList travers

	dll_traverse(tmp1, hList) {		    
		num = stat(tmp1->val.s, &statbuf);
		if(num < 0) {
			fprintf(stderr, "File doesn't exist");
		} //end of if

		else {
			time = statbuf.st_mtime;
		} //end of else
		//printf("%s\n", tmp1->val.s);
	} //end of hList traverse

	dll_traverse(tmp2, lList) {
		//printf("%s\n", tmp2->val.s);
	} //end of lList traverse

	dll_traverse(tmp3, fList) {
		//printf("%s\n", tmp3->val.s);
	} //end of fList traverse
}//end of main  

