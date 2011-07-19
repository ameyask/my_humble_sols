#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void my_strrev(char *str, char *str_rev, int start, int end)
{
	int i=start;
		
	while ( i < end ) {
		*(str_rev+i) = *(str+(end-1)-i);
		i++;
	}

	*(str_rev+(end-start)) = '\0';
}

int main()
{
	char *str, *str_rev, *str_rev_word;
	int i, j, n;
	size_t max_n=100;
	
	str = (char *)malloc( sizeof(char) * (max_n+1) );
	str_rev = (char *)malloc( sizeof(char) * (max_n+1) );
	str_rev_word = (char *)malloc( sizeof(char) * (max_n+1) );
	 
	n = getline(&str, &max_n, stdin);
	
	if ( n == -1 ) {
		printf("Can not accept strings of these sizes!\n");
		exit(0);
	}

	*(str+ (strlen(str)-1) ) = '\0';

	printf("The String you entered is: %s\n", str);

	my_strrev(str, str_rev, 0, n-1);

	printf("The string reversed is: %s\n", str_rev);

	printf("The ans string is: ");

	n = strlen(str_rev);
	i = 0; j = 0;

	while (i<n) {

		if ( *(str_rev+i) == ' ' ) {

			my_strrev(str_rev+j, str_rev_word, j, i);
			printf("%s ", str_rev_word+j);
			j = i+1;
			i++;
			continue;

		}

		i++;

	}

	my_strrev(str_rev+j, str_rev_word, j, i);
	printf("%s\n", str_rev_word+j);
		
	return(1);
}

/*
Output of the program -->

switch the sentence
The String you entered is: switch the sentence
The string reversed is: ecnetnes eht hctiws
The ans string is: sentence the switch
*/
