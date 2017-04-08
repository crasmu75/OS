#include <stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(){
   int ret, fd;
	 int num = 12; 
   printf("Starting device test code example...\n");
   fd = open("/dev/sleepy0", O_RDWR);             // Open the device with read/write access
   if (fd < 0){
      perror("Failed to open the device...");
      return errno;
   }
   
   printf("Writing message to the device.\n");
   ret = write(fd, &num, sizeof(num)); // Send the string to the LKM
   if (ret < 0){
      perror("Failed to write the message to the device.");
      return errno;
   }
 
	 printf("return val = %d\n", ret);
   printf("End of the program\n");
   return 0;
}
