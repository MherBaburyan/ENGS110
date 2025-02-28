#include <stdio.h>

int main() {
    //Declaring variables
    long long bin;//long long so we can input big numbers
    int dec = 0, rem;

    //Scanning the value to the bin
    printf("Enter a binary number: ");
    scanf("%lld", &bin);

    //Converting binary to decimal
    while (bin != 0) {
        rem = bin % 10;//Devidind the bin by 10 and taking the remainder (0 or 1 in this case)
        dec = dec * 2 + rem;//Changing the value of the decimal, taking the remainder adding to the sum, during nexct iteration we take that remainder multiply by 2 and add the next remainder
        bin = bin / 10;//Updating the binary
    }

    //Printing
    printf("Decimal equivalent: %d\n", dec);

    return 0;
}
