
#include "answer01.h"

// NOTE: You are NOT to use the strings library on this assignment,
// as stated in the README.

// DO NOT BEGIN WORKING ON THIS FILE UNTIL YOU HAVE COMPLETELY AND
// THOROUGHLY READ THE README FILE!!!

int arraySum(int * array, int len)
{
  int sum =0;
  int count;

  for (count = 0; count<len; count++)
    {
      sum = sum + array[count];
    }

  return sum;
}

int arrayCountNegative(int * array, int len)
{
  int count;
  int sub = 0;

  for (count = 0; count < len; count++)
    {
      if (array[count]<0)
	{
	  sub++;
	}
    }

  return sub;
}

int arrayIsIncreasing(int * array, int len)
{    
  int i;
  int inc =1;

  for (i=1; i<len; i++)
    {
      if (array[i-1]>array[i])
	{
	  inc = 0;
	}
    }

  return inc;
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
  int count;
  int index=-1;
  for (count =0; count<len; count++)
    {
      if (haystack[count] == needle)
	{
	  index = count;
	}
    }
  return index;
}

int arrayFindSmallest(int * array, int len)
{
  int count;
  int small;
  int temp;
  int index = 0;
  
   if (array == NULL)
    {
      return 0;
    }
 
  small = array[0];
  for(count =0; count<len-1; count++)
    {
      if (array[count+1] < small)
		{
		  small = array[count+1];
		  index = count+1;
		}
    }
 
  temp = arrayIndexRFind(small, array,len);

  return temp;
}

size_t my_strlen(const char * str)
{
  int len = 0;
  while (*str != '\0')
    {
      len++;
      str++;
    }

  return len;
}


char * my_strchr(const char * str, int ch)
{
  
  int len = my_strlen(str);
  
  if (len ==0)
    {
      return NULL;
    }

  while (*str!= '\0')
    {
      if (*str == ch)
	return (char*)str;
      else
	str++;
    }
  return (char * )str;
}

char * my_strstr(const char * haystack, const char * needle)
{
  int count=0;
  int ind;
  int flag = 0;
  int temp;
  int haystack_len = my_strlen(haystack);
  int needle_len = my_strlen(needle);

  //haystack = "Hello World"    needle = "World"

  if (needle_len == 0)
    return (char *) haystack;

 for (ind = 0; ind < haystack_len; ind++)
    {
      if (needle[count] == haystack[ind])
     
	{
	  for (count = 0; count<needle_len; count++)
	    {
	      if (flag == 0)
		{ 
		  temp = ind;
		  flag = 1;
		}
	      
	      ind++;
	    }
	}	
      if ( count == needle_len)
	{
	  return (char *) &haystack[temp];
	}
      else
	{ flag =0; }
    }

 
 return NULL;

}

char * my_strcpy(char * dest, const char * src)
{
  while (*src != '\0')
    {
      *dest = *src;
      dest++;
      src++;
    }
  *dest = '\0';

  return dest; // what should this return?
}

char * my_strcat(char * dest, const char * src)
{
  int i=0;

    while (dest[i] != '\0')
    {
      i++;
     }

  while (*src != '\0')
    {
      dest[i] = *src;
      i++;
      src++;
    }

  dest[i] = '\0';

  return dest; //what should this return if it's returning a char?
}

int my_isspace(int ch)
{
  int space =0;
  if (ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r' || ch==' ')
    {
      space = 1;
    }

  return space;
}

int my_atoi(const char * str) //str = Today is 80 degrees
{
  
  //int len = my_strlen(str);

  int sign = 1;

  //Go through the string. If there's white space, move on
  // for (count = 0; count< len; len++)
  int ret = 0;

  while(*str != '\0')
    {
      if (my_isspace(*str)==1)
	{
	  str++;
	}
 
      if(*str=='-')
	{
	  str++;
	  sign = -1;
	}

     
      while ('0' <= *str && *str <= '9')
	{
	      ret = ret * 10 + (*str - '0');
	      str++;
	}
	
	str++;
	

    }



  if (sign == -1)
    {
	  return -ret;
    }
  else
    {
	  return ret;
    }


}


