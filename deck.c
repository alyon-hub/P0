#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Avriel Lyon
//Found in the shuffle program
//8/27/2021


//declare functions
int checkSame(char * string, size_t stringLength);
int checkAscending(char * string, size_t stringLength);

int main() {
  int numTest = 0;
  int i;
  int x = 0;
  
  scanf("%d", & numTest);
  
  //loops through amount of test cases
  for (i = 0; i < numTest; i++) {
    char s1[53];
    char s2[53];
    char string[105];

    if (i == numTest) {
      continue;
    }
    
    //scans two lines to get the deck of cards
    scanf("%s %s", s1, s2);
    
    //combining the string to one bigger string
    strcpy(string, s1);
    strcat(string, s2);

	//stringLength
    size_t stringLength = strlen(string);
    
    //checkSame determines the longest same-suit
    checkSame(string, stringLength);
    printf(" ");
    //checkAsceding determines the longest ascending pattern
    checkAscending(string, stringLength);
    printf("\n");
    
  }
  return 0;
}

//converts the char to int values then loops through the deck to find the longest ascending card order
int checkAscending(char * string, size_t stringLength) {
  int highestCount = 0;
  int i;
  int count = 0;
  int cardNumbers[105];

	//char to int for later loop
  for (i = 0; i < stringLength - 1; i++) {
    if (string[i] == 'A') {
      cardNumbers[i] = 1;
    } else if (string[i] == 'T') {
      cardNumbers[i] = 10;
    } else if (string[i] == 'J') {
      cardNumbers[i] = 11;
    } else if (string[i] == 'Q') {
      cardNumbers[i] = 12;
    } else if (string[i] == 'K') {
      cardNumbers[i] = 13;
    } else if (string[i] == 'S') {
      cardNumbers[i] = 20;
    } else if (string[i] == 'C') {
      cardNumbers[i] = 25;
    } else if (string[i] == 'H') {
      cardNumbers[i] = 30;
    } else if (string[i] == 'D') {
      cardNumbers[i] = 35;
    } else {
      cardNumbers[i] = string[i] - '0';
    }
  }

  //loops through every other index location in the array starting at 0
  for (i = 0; i < stringLength - 4; i += 2) {
  	
    //ex. if 5+1 == 6 then it is in ascending order, also checks for going back to Ace
    if ((cardNumbers[i] + 1) == cardNumbers[i + 2]) {
      count++;
    } else if ((cardNumbers[i] == 13) && (cardNumbers[i + 2] == 1)) {
      count++;
    } else {
      count = 1;
    }

    //check if current count is the highest count
    if (count > highestCount) {
      highestCount = count;
    }
  }
  
  printf("%d", highestCount);
  return highestCount;
}

//compares each of the suits to see if the character values are the same or not, keeps track of the highest same-suit count
int checkSame(char * string, size_t stringLength) {
  int highestSame = 1;
  int i;
  int count = 0;

//loops through every other index location in the array starting at 1
  for (i = 1; i < stringLength - 4; i += 2) {

    if (string[i] != string[i + 2]) {
      count = 1;
    } else {
      count++;
    }

    if (count > highestSame) {
      highestSame = count;
    }
  }

  printf("%d", highestSame);

  return highestSame;
}
