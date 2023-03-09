#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *dev_file = fopen("/dev/VAR4", "r+");
    FILE *proc_file = fopen("/proc/VAR4", "r+");
   
    if (dev_file != NULL && proc_file != NULL)  {
    	
    	printf("10 spaces was entered\n");
    	fputs("10          spaces", dev_file);
    
    	printf("OK\n");
    	
    	char message[BUFFER_SIZE];
    	
    	while (feof(proc_file) == 0) {
    		fgets(message, BUFFER_SIZE, proc_file);	
    		
    		if (message == NULL) {
    			printf("Error\n");
    			break;
    		}
    		
    		printf("%s", message);
    	}
    	
        fclose(dev_file);
        fclose(proc_file);
    } else {
        printf("file is not found.\n");
    }
    
    return 0;
}


