#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>  // File that contains all of the necessary structures

#include <arpa/inet.h>



int main(int argc, char *argv[]) {
    // Declaring the necessary structure
    struct hostent *address_structure;
    struct in_addr *h_addr;

    // Error checking if the argument are not complete
    if (argc < 2) {
        printf("Usage: %s < hostname to look up > \n", argv[0]);
        exit(1);
    }

    // gethostbyname returns a pointer to the structure hostent. address_structure is of that type.
    address_structure = gethostbyname(argv[1]);

    // Error checking if the pointer is NULL.
    if (address_structure == NULL) {
        printf("Unable to look up the name %s", argv[1]);
        exit(1);
    }
    // Getting the filed that has the ip address and type casting it to type struct in_addr
    // h_addr is of the required type.
    h_addr = (struct in_addr *) (address_structure -> h_addr_list[0]);

    // print out the ip address in the host byte order. The pointer is dereference so it prints what it holds.
    printf("The ip address for the name %s is %s\n", argv[1], inet_ntoa(*h_addr));


}
