# File: dpdlSimpleC.h
#
# Example: This script executes embedded ANSI C code 
#
# (c)opyright 2009
# SEE Solutions
#
# e-mail: info@seesolutions.it
#
#

# main
# starting with Dpdl, pushing parameters on the stack and embedding C

println("testing embedded C code in Dpdl")

int n = 6
double x = 10.0
string a = "test"

dpdl_stack_push(n, x, a)

>>c
	#include <stdio.h>
	
	int main(int argc, char **argv){
		printf("Hello C from Dpdl!\n");
		printf("\n");
		printf("num params: %d\n", argc);
		int cnt;
	    for (cnt = 0; cnt < argc; cnt++){
	        printf("	param %d: %s\n", cnt, argv[cnt]);
	    }
	    return 0;
	}
<<
int exit_code = dpdl_exit_code()

println("ebedded C exit code: " + exit_code);

# again Dpdl...

object str = loadObj("String", "Dpdl embedded C")
bool b = str.contains("C")
println("Dpdl contains C: " + b)
