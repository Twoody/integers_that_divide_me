#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
    printf("Hello world!\n");
    printf("Please, enter a number:");
    scanf("%d",&number);

    printf("Our number is %d\n", number);
    a       =       integers_that_divide_me(number);
    getchar();
    printf("Integers that divide %d consist of the following:\n",number);
    printf(" __________\n");
    curr2 = head2;
    while(curr2)
    {
        printf("|    %d     \n", curr2->val);
        curr2 = curr2->next ;
    }
    printf("|__________\n");
    printf("Finished with main()");
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

/******************************************************************************************************************/
int integers_that_divide_me(int number)										/**/
{														/**/
    head = NULL;												/**/
    int counter, candidates,i,x,tempz,indexed_node,count,bewl;							/**/
     //  candidates will be used as a countdown, counter will be used for loops					/**/
    pool_of_primes(number); //  Creating a list of the primes that compose our number				/**/
    printf("We are seeing what is created from our pool of primes\n\n");					/**/
    printf(" __________\n");											/**/
    curr =  head;												/**/
    while(curr)													/**/
    {														/**/
        printf("|    %d     \n", curr->val);									/**/
        curr = curr->next ;											/**/
    }														/**/
    printf("|__________\n");											/**/
    getchar();                                                                                                  /**/
/***************************************************************************************************************/
    item* temp  = head;     //  assigning a temp node to the head of 1st list to find the size of prime pool	/**/
    candidates  = 0;												/**/
    i           = 0;												/**/
    tempz       = 1;												/**/
														/**/
    int length  = 0;												/**/
    while(temp)													/**/
    {														/**/
        for (i=0;i<length;i++){											/**/
            tempz = tempz*2;											/**/
        }													/**/
        candidates  += tempz;											/**/
        length++;												/**/
        temp         = temp->next;  //  move to next node							/**/
        tempz        = 1;											/**/
    }														/**/
/***************************************************************************************************************/
/*We now have a length*/											/**/
	if (length >=21)        //  If there are to many integers						/**/
	{													/**/
		printf("\nTo many possible candidates for integers that divide our number.\n");			/**/
		return 0;											/**/
	}													/**/
/***************************************************************************************************************/
	/*nList.append(1): while loop does not provide this in our list*/					/**/
    curr2        = (item2 *)malloc(sizeof(item2));                                      			/**/
    curr2->val   = 1;                                                                   			/**/
    curr2->next  = head2;                                                               			/**/
    head2        = curr2;                                                               			/**/
/***************************************************************************************************************/
    while (candidates != 0)											/**/
    {														/**/
	x       =   1;												/**/
	bewl    =   1;												/**/
	for (counter=0; counter<=length;counter++)								/**/
	{													/**/
		if(candidates & (1<<counter))									/**/
		{												/**/
		    curr = head;                        							/**/
                    count = 0;											/**/
                   while (curr)                             							/**/
                   {                                                   						/**/
                   	if (count == counter)									/**/
                    	{                              								/**/
                        	indexed_node = curr->val;							/**/
                        	x   = 	x * indexed_node;							/**/
                    	}                        								/**/
                    count++;                                         						/**/
                    curr    =   curr->next;                         						/**/
                    }												/**/
            	}												/**/
	}													/**/
        curr2   =   head2;											/**/
        while(curr2)												/**/
        {													/**/
            if(x == curr2->val)											/**/
            {													/**/
                bewl = 0;											/**/
            }													/**/
            curr2 = curr2->next ;										/**/
        }													/**/
        if (bewl == 1)												/**/
        {													/**/
            curr2         = (item2 *)malloc(sizeof(item2));     						/**/
            curr2->val    = x;                               							/**/
            curr2->next   = head2;                             							/**/
            head2         = curr2;										/**/
        }													/**/
		candidates 	    -=	1;									/**/
    }														/**/
/***************************************************************************************************************/
	return 1;												/**/
}														/**/
/******************************************************************************************************************/

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
