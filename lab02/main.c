#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab02.h"


int main(int argc, char **argv)
{
   // strdup makes a newly allocated (malloced) copy of a string
   char *orig = strdup("the internet is a series of tubes");
   char *copy = strdup(orig);

   /* ********************************** */
   /*    test of whitespace removal      */
   /* ********************************** */
   printf("remove whitespace: before <%s> after <%s>\n", orig, removewhitespace(copy));

   free(copy);                    // free modified copy
   copy = strdup(orig);           // make new copy


   /* ********************************** */
   /*  c to pascal and back to c tests   */
   /* ********************************** */
   char *pascalstr = c2pascal(copy);
   printf("made pascal string out of %s; orig strlen was %d and pascal strlen is %d\n", orig, (int)strlen(orig), (int)pascalstr[0]);
   char *cstr = pascal2c(pascalstr);
   printf("converted pascal string back to c.  orig: <%s> reconversion: <%s>\n", orig, cstr);
   free(copy);



   /* ********************************** */
   /*          tokenify test             */
   /* ********************************** */
   copy = strdup(orig);
   char **x = tokenify(copy);
   int i = 0;
   printf("tokenified <%s>.  next output should show each token on a separate line.\n", orig);
   while (x[i]) {
       printf("\t<%s>\n", x[i]);
       i++;
   }

   return 0;
}

