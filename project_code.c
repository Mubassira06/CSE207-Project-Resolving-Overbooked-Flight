#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 50
#define MAX_PASSENGERS 100

typedef struct
{
    char personalName[MAX_NAME];
    char surname[MAX_NAME];
    int mileage;
    int years;
    int sequence;
    double priority;
} Passenger;

typedef struct
{
    Passenger heap[MAX_PASSENGERS];
    int qSize;
} PriorQueue;


typedef struct
{
    Passenger waitlist[MAX_PASSENGERS];
    int stackTop;
} WaitlistStack;


void initializeWaitlistStack(WaitlistStack*s)
{
    s->stackTop=-1;
}

void push(WaitlistStack*s,Passenger p)
{
    if(s->stackTop<MAX_PASSENGERS-1)
    {
        s->waitlist[++(s->stackTop)]=p;
    }
}

Passenger pop(WaitlistStack*s)
{
    if(s->stackTop>=0)
    {
        return s->waitlist[(s->stackTop)--];
    }

    Passenger empty={"", "", 0, 0, 0, 0.0};
    return empty;
}

void swapPassengers(Passenger*x,Passenger *y)
{
    Passenger temp=*x;
    *x=*y;
    *y=temp;
}

void enqueuePassenger( PriorQueue*flightQueue,Passenger passenger)
{
    flightQueue->heap[flightQueue->qSize]=passenger;

    int i=flightQueue->qSize;
    flightQueue->qSize++;

    for(;i>0;)
    {
        int parent=(i-1)/2;

        if(flightQueue->heap[parent].priority>=flightQueue->heap[i].priority)

        {
            break;
        }

        swapPassengers(&flightQueue->heap[parent],&flightQueue->heap[i]);
        i=parent;
    }
}

Passenger dequeueTopPriorPassenger(PriorQueue*flightQueue)
{
    Passenger root=flightQueue->heap[0];
    flightQueue->qSize--;
    flightQueue->heap[0]=flightQueue->heap[flightQueue->qSize];


    for(int i =0;i*2+1<flightQueue->qSize;)
    {
        int leftChild=i*2+1;
        int rightChild=i*2+2;
        int largest=i;

        if (leftChild<flightQueue->qSize&&flightQueue->heap[leftChild].priority>flightQueue->heap[largest].priority)

        {
            largest=leftChild;
        }

        if(rightChild<flightQueue->qSize&&flightQueue->heap[rightChild].priority>flightQueue->heap[largest].priority)
        {
            largest=rightChild;
        }

        if(largest==i)
        {
            break;
        }

        swapPassengers(&flightQueue->heap[i],&flightQueue->heap[largest]);
        i = largest;
    }

    return root;
}

double computePriorScore(int mileage,int years,int sequence)
{
    return (double)mileage/1000.0+years-sequence;
}

void printPassengerPriorityList(Passenger passengers[], int totalPassengers)
{
    printf("\n\n");
    printf("======================================================================================================================\n");
    printf("    List of waiting passengers in priority sequence and their details who took the flight later                 \n");
    printf("=====================================================================================================================\n\n");

    for(int i=totalPassengers-1;i>=0;i--)
    {
        Passenger c = passengers[i];
        printf("Priority #%d\n", totalPassengers - i);
        printf("------------------------------------------------------------\n");
        printf("Name:           %s %s\n", c.personalName, c.surname);
        printf("Mileage:        %d miles\n", c.mileage);
        printf("Years:          %d\n", c.years);
        printf("Sequence:       %d\n", c.sequence);
        printf("Priority Score: %.2f\n", c.priority);
        printf("\n\n");
    }

    printf("====================================================================================================================\n");
    printf("   End of Priority List waiting customers in priority sequence and their details who took the flight later          \n");
    printf("====================================================================================================================\n");
}

int main()
{
    FILE*file=fopen("passengers.txt", "r");

    if (!file)
    {
        printf("Error opening file check again!\n");
        return 1;
    }

    PriorQueue pq ={.qSize=0};
    WaitlistStack stack;
    initializeWaitlistStack(&stack);
    Passenger passenger;

    for(;;)
    {
        Passenger passenger;
        if (fscanf(file, "%s %s %d %d %d",passenger.personalName, passenger.surname,&passenger.mileage, &passenger.years, &passenger.sequence) != 5)
        {
            break;
        }
        passenger.priority = computePriorScore(passenger.mileage, passenger.years, passenger.sequence);
        enqueuePassenger(&pq,passenger);
    }

fclose(file);


    int totalPassengers=pq.qSize;

    Passenger sortedPassengers[MAX_PASSENGERS];

    for(int i=0;i<totalPassengers;i++)

    {
        push(&stack,dequeueTopPriorPassenger(&pq));
    }

    for(int i=0;i<totalPassengers;i++)

    {
        sortedPassengers[i]=pop(&stack);
    }

    printPassengerPriorityList(sortedPassengers, totalPassengers);

    return 0;
}



