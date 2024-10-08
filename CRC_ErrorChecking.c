#include <stdio.h>
#include <string.h>

void xorOperation(char *dividend, char *key) {
    for (int i = 0; i < strlen(key); i++) {
        dividend[i] = (dividend[i] == key[i]) ? '0' : '1';
    }
}

void crcSender(char *data, char *key, char *encodedData) {
    int dataLen = strlen(data);
    int keyLen = strlen(key);
    //makes a dupe array with data + key length
    char temp[dataLen + keyLen];
    char remainder[keyLen];

    // Append k-1 zeros to data
    strcpy(temp, data);
    for (int i = dataLen; i < dataLen + keyLen - 1; i++) {
        temp[i] = '0';
    }
    temp[dataLen + keyLen - 1] = '\0';

    // Perform modulo-2 division
    for (int i = 0; i < dataLen; i++) {
        //calls XOR only if element is 1 otherwise iterates to next bit
        if (temp[i] == '1') {
            xorOperation(&temp[i], key);
            //result replaces the element in the temp array
        }
    }

    strncpy(remainder, temp + dataLen, keyLen - 1);
    remainder[keyLen - 1] = '\0'; // Null-terminate the remainder string
    
    // Append the remainder to the original data
    strncpy(encodedData, data, dataLen);
    strcat(encodedData, remainder);
    
    printf("CRC Remainder: %s\n", remainder);
}

int crcReceiver(char *receivedData, char *key) {
    int dataLen = strlen(receivedData);
    int keyLen = strlen(key);
    char temp[dataLen + 1];

    strcpy(temp, receivedData);

    // Perform modulo-2 division
    for (int i = 0; i < dataLen - keyLen + 1; i++) {
        if (temp[i] == '1') {
            xorOperation(&temp[i], key);
        }
    }

    // Check the remainder
    for (int i = dataLen - keyLen + 1; i < dataLen; i++) {
        if (temp[i] == '1') {
            return 1; // Error detected
        }
    }
    return 0; // No error
}

int main() {
    char data[35] = {"100100"};
    char key[15] = {"1101"};
    char encodedData[50];

    
    printf("\n\nData : %s \nKey  : %s \n",data,key);
    crcSender(data, key, encodedData);
    printf("Encoded Data : %s\n", encodedData);

    // Simulating receiver
    
    printf("\nError Detection on errorfree data: \n");
    int error = crcReceiver(encodedData, key);
    if (error) {
        printf("Data corrupted.\n");
    } else {
        printf("Data received correctly.\n");
    }
    
    // case 2 : introduced error
    
    printf("\nError Detection on errored data:\nIntroducing error for detection\n");
     
    if (encodedData[0] == '1' ){
        encodedData[0] = '0';
        printf("--> inverted first bit to 0\n");

    } else {
        encodedData[0] = '1';
        printf("--> inverted first bit to 1\n");
    }
    
    error = crcReceiver(encodedData, key);
    if (error) {
        printf("Data corrupted.\n");
        printf("corrupted Data : %s\n",encodedData);
    } else {
        printf("Data received correctly.\n");
    }

    return 0;
}
