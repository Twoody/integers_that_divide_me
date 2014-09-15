#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <math.h>

/******************************//**/
struct list_el {                /**/
   int val;                     /**/
   struct list_el * next;       /**/
};                              /**/
                                /**/
typedef struct list_el item;    /**/
/******************************//**/
item * curr, * head;            /**/
/******************************//**/

/******************************//**/
struct list_e2 {                /**/
   int val;                     /**/
   struct list_e2 * next;       /**/
};                              /**/
                                /**/
typedef struct list_e2 item2;    /**/
/******************************//**/
item2 * curr2, * head2;          /**/
/******************************//**/


int main()
{
    head2   =   NULL;
    int     a, number;
    printf("Hello world!\n\n\n");

    number  =       99;
    printf("Our number is %d\n", number);
    a       =       integers_that_divide_me(number);
    while(curr2)
    {
        printf("%d\n", curr2->val);
        curr2 = curr2->next ;
    }
    printf("\n\nFinished with main()\n\n");
    return 0;
}


/**************************************************************/
int is_prime(int x)                                         /**/
{                                                           /**/
    int counter;                                            /**/
    if (x<=1)                                               /**/
    {                                                       /**/
        return 0;                                           /**/
    }                                                       /**/
    if( x%2==0 )                                            /**/
    {                                                       /**/
        if( x==2 )//Is prime!                               /**/
        {                                                   /**/
            return 1;                                       /**/
        }                                                   /**/
        return 0;//Else, not prime!                         /**/
    }                                                       /**/
    if( x%3==0 )                                            /**/
    {                                                       /**/
        if( x==3 )//Is prime!                               /**/
        {                                                   /**/
            return 1;                                       /**/
        }                                                   /**/
        return 0;//Else, not prime!                         /**/
    }                                                       /**/
    for (counter=3; counter<=(sqrt(x)+1);counter+=2)        /**/
    {                                                       /**/
        if( (x % counter) == 0 )//Not Prime!                /**/
        {                                                   /**/
            return 0;                                       /**/
        }                                                   /**/
    }                                                       /**/
    return 1; //Is prime!                                   /**/
}//End of is_prime(x)                                       /**/
/**************************************************************/


int integers_that_divide_me(number)
{
    head = NULL;
    int counter, candidates,i;
     //  candidates will be used as a countdown, counter will be used for loops
    pool_of_primes(number); //  Creating a list of the primes that compose our number
    printf("\n\nWE ARE INSIDE OF INTS_.._ME()\n\n");
    printf("We are seeing what is created from our pool of primes\n\n");
    while(curr)
    {
        printf("%d\n", curr->val);
        curr = curr->next ;
    }
    printf("DONE\n\n");
/*********************************************************************************************************/
    item* temp  = head;     //  assigning a temp node to the head of 1st list to find the size of prime pool
    candidates  = 0;
    i           = 0;
    int length  = 0;
    while(temp)
    {
        candidates = (candidates+(2^i));
        length++;
        i++;
        temp = temp->next;  //  move to next node
    }
    printf("The length     of list is %d\n\n",length);
    printf("The candidates of list is %d\n\n",candidates);
/*********************************************************************************************************/
/*We now have a length*/
	if (length >=21)        //  If there are to many integers
	{
		printf("\nTo many possible candidates for integers that divide our number.\n");
		return 0;
	}
/*********************************************************************************************************/
	/*nList.append(1): while loop does not provide this in our list*/
    curr2        = (item2 *)malloc(sizeof(item2));                                      /**/
    curr2->val   = 1;                                                                   /**/
    curr2->next  = head2;                                                               /**/
    head2        = curr2;                                                               /**/
/*********************************************************************************************************/
	while (candidates != 0)
	{
		int x 	=	1;
		int indexed_node, count;
		for (counter=0; counter<=length;counter++)
		{
		    printf("%d, %d\n",counter,candidates);
		    x   =   1;
			if(candidates & (1<<counter))
			{
			    curr = head;                        /**/
                count = 0;
                while (curr)                             /**/
                {                                                   /**/
                    if (count == counter)
                    {                              /**/
                        indexed_node = curr->val;
                        printf("indexed_node = %d\n",indexed_node);
                    }                        /**/
                    count++;                                         /**/
                    curr = curr->next;                         /**/
                x   = 	x * indexed_node;
                /*BUG*/ //  * is raising x to the node we are returning instead of just multiplying.
                printf("The x is %d\n\n",x);
                }
                printf("The x adding to the list is %d\n\n",x);
                curr2        = (item2 *)malloc(sizeof(item2));     /**/
                curr2->val   = x;                               /**/
                curr2->next  = head2;                             /**/
                head2        = curr2;
            }
		}
		/*BUG*/ //  Should check for doubles here
		candidates 	-=	1;
	}
/*********************************************************************************************************/
	printf("\n\nDONE WITH CONSTRUCTING MAIN LIST\n\n");
	return 1;
}

/**************************************************************/
int pool_of_primes(int x)                                   /**/
{                                                           /**/
    int i;                                                  /**/
    if (x <= 0)                                             /**/
    {                                                       /**/
        if (x == 0)                                         /**/
        {// x cannot be divided anything definitely         /**/
            return 0;                                       /**/
        }                                                   /**/
        else                                                /**/
        {                                                   /**/
            x           = (x/(-1));                         /**/
            curr        = (item *)malloc(sizeof(item));     /**/
            curr->val   = -1;                               /**/
            curr->next  = head;                             /**/
            head        = curr;                             /**/
            return pool_of_primes(x);                       /**/
        }                                                   /**/
    }                                                       /**/
    if (is_prime(x) == 1)                                   /**/
    {                                                       /**/
        curr        = (item *)malloc(sizeof(item));         /**/
        curr->val   = x;                                    /**/
        curr->next  = head;                                 /**/
        head        = curr;                                 /**/
        return 1;                                           /**/
    }                                                       /**/
    else                                                    /**/
    {                                                       /**/
        if ((x % 2) == 0)                                   /**/
        {                                                   /**/
            x           = (x/2);                            /**/
            curr        = (item *)malloc(sizeof(item));     /**/
            curr->val   = 2;                                /**/
            curr->next  = head;                             /**/
            head        = curr;                             /**/
            return pool_of_primes(x);                       /**/
        }                                                   /**/
    }                                                       /**/
        //for i in range(3,int(x**.5))                      /**/
        for (i=3;i<=(sqrt(x)+1);i+=2)                       /**/
        {                                                   /**/
            if((x % i) == 0)                                /**/
            {                                               /**/
                x           = (x/i);                        /**/
                curr        = (item *)malloc(sizeof(item)); /**/
                curr->val   = i;                            /**/
                curr->next  = head;                         /**/
                head        = curr;                         /**/
                return pool_of_primes(x);                   /**/
            }                                               /**/
        }                                                   /**/
        printf("DONE WITH CREATING POOL\n");
}//End of pool_of_primes(x)                                 /**/
/**************************************************************/
