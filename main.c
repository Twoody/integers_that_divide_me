#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

/******************************************************//**/
/* Link list node */                                    /**/
struct node                                             /**/
{                                                       /**/
    int data;                                           /**/
    struct node* next;                                  /**/
};                                                      /**/
/******************************************************//**/
void push(struct node** head_ref, int new_data)         /**/
{                                                       /**/
    /* allocate node */                                 /**/
    struct node* new_node =                             /**/
            (struct node*) malloc(sizeof(struct node)); /**/
                                                        /**/
    /* put in the data  */                              /**/
    new_node->data  = new_data;                         /**/
                                                        /**/
    /* link the old list off the new node */            /**/
    new_node->next = (*head_ref);                       /**/
                                                        /**/
    /* move the head to point to the new node */        /**/
    (*head_ref)    = new_node;                          /**/
}                                                       /**/
/******************************************************//**/
int get_nth(struct node* head, int index)               /**/
{                                                       /**/
    struct node* current = head;                        /**/
    int count = 0;                                      /**/
    while (current != NULL)                             /**/
    {                                                   /**/
       if (count == index)                              /**/
          return(current->data);                        /**/
       count++;                                         /**/
       current = current->next;                         /**/
    }                                                   /**/
                                                        /**/
    return -1;                                          /**/
}                                                       /**/
/******************************************************//**/

typedef struct node data;
data * head, * current;
/******************************//**/
struct list_e2 {                /**/
   int val;                    /**/
   struct list_e2 * next;       /**/
};                              /**/
                                /**/
typedef struct list_e2 item2;    /**/
/******************************//**/
item2 * curr2, * head2;         /**/
/******************************//**/

int main()
{
    head = NULL;
    head2 = NULL;
    int a,i,number;
    for (i=1;i<100;i+=2)
    {
        a = is_prime(i);
        if (a==1)
        {
            printf("\n%d",i);
        }
    }
    number  =       58493;
    a       =       pool_of_primes(number);
    //If a==0, then we chose a prime number
    if(a==1)
    {
        head    =   NULL;
        i       =   0;
        printf("\n\nPool of primes for %d:\n\n",number);
        printf("Working1");
        while(current)
        {
            printf("Working2");
            printf("Element at index 3 is %d", get_nth(head, i));
            getchar();
            i++;
        }
    }
    a       =   integers_that_divide_me(number);
    if(a==1)
    {
        printf("\n\nCalling print_list()\n\n");
        while(curr2)
        {
            printf("%d\n", curr2->val);
            curr2 = curr2->next ;
        }
    }
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

/**************************************************************/
int pool_of_primes(int x)                                   /**/
{                                                           /**/
    //aList should be originally empty                      /**/
    //head = NULL;
    int i;                                                  /**/
    if (x <= 0)                                             /**/
    {                                                       /**/
        if (x == 0)                                         /**/
        {// x cannot be divided anything definitely         /**/
            return 0;                                       /**/
        }                                                   /**/
        x           = (x/(-1));                         /**/
        push(&head, -1);                            /**/
        return pool_of_primes(x);                       /**/
    }                                                       /**/
    if (is_prime(x) == 1)                                   /**/
    {                                                       /**/
        push(&head, x);                                     /**/
        return 1;                                           /**/
    }                                                       /**/
    else                                                    /**/
    {                                                       /**/
        if ((x % 2) == 0)                                   /**/
        {                                                   /**/
            x           = (x/2);                            /**/
            push(&head, 2);
            return pool_of_primes(x);                       /**/
        }                                                   /**/
    }                                                       /**/
        //for i in range(3,int(x**.5))                      /**/
        for (i=3;i<=(sqrt(x)+1);i+=2)                       /**/
        {                                                   /**/
            if((x % i) == 0)                                /**/
            {                                               /**/
                x           = (x/i);                        /**/
                push(&head, i);
                return pool_of_primes(x);                   /**/
            }                                               /**/
        }                                                   /**/
}//End of pool_of_primes(x)                                 /**/
/**************************************************************/

int integers_that_divide_me(number)
{
    head = NULL;
    head2 = NULL;
    pool_of_primes(number); //  Creating a list of the primes that compose our number
    struct node* temp = head;     //  assigning a temp node to the head of 1st list to find the size of prime pool
    int length = 0;
    while(temp)
    {
        length++;
        temp = temp->next;  //  move to next node
    }
/*We now have a length*/
	int counter, candidates; //  candidates will be used as a countdown, counter will be used for loops
	candidates 	=	length;
	if (length >=21)        //  If there are to many integers
	{
		printf("\nTo many possible candidates for integers that divide our number.\n");
		return 0;
	}
	/*nList.append(1): while loop does not provide this in our list*/
    curr2        = (item2 *)malloc(sizeof(item2));                                      /**/
    curr2->val   = 1;                                                                   /**/
    curr2->next  = head2;                                                               /**/
    head2        = curr2;                                                               /**/

	while (candidates != 0)
	{
		int x 	=	1;
		int indexed_node;
		for (counter=0; counter<=length;counter++)
		{
			if(candidates & (1<<counter))
			{
			    indexed_node    =   get_nth(head,counter);
				x 	            = 	x*indexed_node;
			}
		}
		/*BUG*/ //  Should check for doubles here
		/*nList.append(x)*/
        curr2        = (item2 *)malloc(sizeof(item2));     /**/
        curr2->val   = -1;                               /**/
        curr2->next  = head2;                             /**/
        head2        = curr2;                             /**/
		candidates 	-=	1;
	}
	return 1;
}
