#include <iostream>
#include "substring.h"

//const int MAX_ARRAY_SIZE = 100;
using namespace std;

bool is_prefix(char first[], char second[]) {
  // pointer to the first element in first
  static char* first_origin = NULL;
  // pointer to the first matching element between first and second
  static char* first_match = NULL;
  // flag to indicate if its in the checking of the rest of elements
  // after the first matching is found
  static bool in_checking = false;

  // initialise first_origin to point to the first element in first string
  if(first_match == NULL && in_checking == false)
    first_origin = first;

  // if the first matching is not found or its not in checking status
  if(in_checking == false) {

    // search for the first matching point
    while(*second != '\0') {
      if(*first == *second) 
	first_match = second;
      second++;
    }

    // if no matching of the first elememnt can be found
    if (first_match == NULL)
      return false;
    // if the first matching can be found, test if the 
    // rest of first string is a prefix of the rest of second string
    else {
      in_checking = true;
      return (is_prefix(first++, second++));
    }
  }

  // if the first matching is found (recursive part)
  else {
    // if the end of first string is reached
    if(first == NULL)
      return true;
    // if the end of second string is reached but not the first string
    else if(second == NULL)
      return false;
    // if the next maching is found, do the text for the rest of strings
    else if(*first == *second)
      return (is_prefix(first++,second++));
    // if the element in first string is not equal to that in second
    else {
      // checking has failed
      // update the starting point of checking in second string 
      second = ++first_match;
      in_checking = false;
      return (is_prefix(first_origin,second));
    }
  }
}

int substring_position(char substring[], char string[]) {
  static int count = 0;

  if (*substring == '\0')
    return count;

  if (is_prefix(substring,string)) {

    for (; *substring != *string; count++) {
      string++;
    }
    if (is_prefix(substring,string))
      return count;
    else {
      count++;
      return (substring_position(substring,string++));
    }
  }

  else
    return -1;
}
