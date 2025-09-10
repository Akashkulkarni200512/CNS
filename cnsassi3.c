#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void calculate_parity_bits(int data_bits[], int parity_bits[]) {
    parity_bits[0] = data_bits[0] ^ data_bits[1] ^ data_bits[3]; // p1
    parity_bits[1] = data_bits[0] ^ data_bits[2] ^ data_bits[3]; // p2
    parity_bits[2] = data_bits[1] ^ data_bits[2] ^ data_bits[3]; // p4
}


void generate_hamming_code(int data_bits[], int hamming_code[]) {
    int parity_bits[3];
    calculate_parity_bits(data_bits, parity_bits);
    
    
    hamming_code[0] = parity_bits[0];
    hamming_code[1] = parity_bits[1];
    hamming_code[2] = data_bits[0];
    hamming_code[3] = parity_bits[2];
    hamming_code[4] = data_bits[1];
    hamming_code[5] = data_bits[2];
    hamming_code[6] = data_bits[3];
}


void input_bits(int data_bits[]) {
    char input[5];
    printf("Enter 4-bit binary number: ");
    scanf("%4s", input);
    
   
    if (strlen(input) != 4 || strspn(input, "01") != 4) {
        printf("Invalid input. Please enter a 4-bit binary number.\n");
        exit(1);
    }
    
    for (int i = 0; i < 4; i++) {
        data_bits[i] = input[i] - '0';
    }
}

int main() {
    int data_bits[4];
    int hamming_code[7];
    
    input_bits(data_bits);
    generate_hamming_code(data_bits, hamming_code);
    
    printf("Hamming code: ");
    for (int i = 0; i < 7; i++) {
        printf("%d", hamming_code[i]);
    }
    printf("\n");
    
    return 0;
}
