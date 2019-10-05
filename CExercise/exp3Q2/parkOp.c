//
// Created by astzls on 2019-10-05.
//
#include"header.h"
Node newNode(unsigned id){
    Node n=(Node)malloc(sizeof(struct node));
    if(!n)
    {
        puts("Memory fulled!");
        return NULL;
    }
    n->data=(Car)malloc(sizeof(struct car));
    n->data->ID=id;

    n->data->tick=0;/*when car which is in queue enter to park, its tick
    should be the time of the car which is leaving now!*/

    n->next=NULL;
    return n;
}
Park createPark(unsigned n){
    Park p=(Park)malloc(sizeof(struct park));
    if(!p)
    {
        puts("Out of memory.");
        return NULL;
    }
    p->capacity=n;
    p->topPark=EMPTY;
    p->parking=(Car*)calloc(n,sizeof(Car));
    return p;
}
int arrival(Park p,Car data,Queue q){
    if(parkIsFull(p))
    {
        puts("Park fulled, car waiting in queue!");
        enQueue(q,data);
        return 0;
    }
    else
    {
        (p->parking)[++(p->topPark)]=(Car)malloc(sizeof(struct car));
        if(!(p->parking)[p->topPark])
        {
            puts("Out of memory!");
            return -1;
        }
        (p->parking)[p->topPark]->ID=data->ID;
        (p->parking)[p->topPark]->tick=data->tick;
        return 1;
    }
}
Car departure(Park p){
    if(parkIsEmpty(p))
    {
        puts("Park empty!");
        return NULL;
    }
    else
    {
        Car rtv=(p->parking)[p->topPark--];
        return rtv;
    }
}
bool parkIsEmpty(Park p){
    return p->topPark==-1? true: false;
}
bool parkIsFull(Park p){
    return (p->topPark+1)==p->capacity? true:false;
}
Queue createQueue(){
    Queue q=malloc(sizeof(struct queue));
    if(!q)
    {
        puts("Memory insufficient!");
        return NULL;
    }
    q->size=0;
    q->front=NULL;
    q->rear=NULL;
    return q;
}
void enQueue(Queue q,Car data){
    Node n=newNode(data->ID);
    if(q->rear)
    {
        q->rear->next=n;
        q->rear=n;
    }
    else
        q->rear=n;
    if(!q->front)//first car in queue.
        q->front=n;
    q->size++;
}
unsigned deQueue(Queue q){
    if(!queueEmpty(q)) {
        Node tmp = q->front;
        q->front = tmp->next;
        if(!q->front)// when queue is empty.
            q->rear=NULL;
        tmp->next = NULL;
        unsigned tmpData = tmp->data->ID;
        q->size--;
        free(tmp);
        tmp=NULL; // avoid ye point.
        return tmpData;
    }
    else{
        puts("Queue is empty!");
        return 0;// thus, id cannot be set 0!
    }
}
bool queueEmpty(Queue q){
    return q->size==0?true:false;
}
void carBehaviourStream(Park p,Queue q){
    char behaviour;
    puts("~~Now enter your data~~");
    while(scanf("%c",&behaviour)!=0&&behaviour!='E'){
        int status;// manage car stop position.
        int scale;// store queue length.
        Car tmpCar=(Car)malloc(sizeof(struct car));
        Info carBill=(Info)malloc(sizeof(struct info));
        Park tmpPark=createPark(p->capacity);
        switch(behaviour){
            case 'A':
                scanf("%u %u",&tmpCar->ID,&tmpCar->tick);
                getchar();// clean \n in buffer.

                status=arrival(p,tmpCar,q);
                if(status!=-1)
                {
                    if (status == 1)
                        printf("Car ID: %u, parking on No.%d\n", tmpCar->ID, p->topPark + 1);
                    else
                        printf("Car ID: %u, queuing on No.%d\n", tmpCar->ID, q->size);
                }
                break;
            case 'D':
                scale=q->size;
                scanf("%u %u",&tmpCar->ID,&tmpCar->tick);
                getchar();// clean \n in buffer.

                while((p->parking)[p->topPark]->ID!=tmpCar->ID)
                {
                    arrival(tmpPark,(p->parking)[p->topPark],q);
                    departure(p);
                    if(parkIsEmpty(p))
                        break;
                }
                if(parkIsEmpty(p)){
                    //if not found that car in park, cover all cars from tmpPark to park.
                    while(!parkIsEmpty(tmpPark)){
                        arrival(p,(tmpPark->parking)[tmpPark->topPark],q);
                        departure(tmpPark);
                    }
                    // find that car in queue.
                    for(int i=0;i<scale;i++){
                        if(q->front->data->ID!=tmpCar->ID)
                        {
                            enQueue(q, q->front->data);
                            deQueue(q);
                        }
                        else
                        {
                            printf("Car No.%u left.",deQueue(q));
                        }
                    }
                    if(scale==q->size)
                    {
                        puts("That car not found!");
                        break;
                    }
                    break; // car already left in queue.
                }
                else{
                    Car deCar=departure(p);
                    carBill->delta=tmpCar->tick-deCar->tick;
                    if(carBill->delta>=0)
                    {
                        carBill->money = carBill->delta * PARK_PER_HOUR;
                        printf("Car No.%u\nTime: %d min\nBill: $%u\n", deCar->ID, carBill->delta, carBill->money);
                    }
                    else
                        puts("Error: Exit time > Enter time. Punishment: $100 should be paid.");
                    // call back.
                    while(!parkIsEmpty(tmpPark)){
                        arrival(p,(tmpPark->parking)[tmpPark->topPark],q);
                        departure(tmpPark);
                    }
                }
                if(!queueEmpty(q)){
                    tmpCar->ID=deQueue(q);
                    arrival(p,tmpCar,q);
                    printf("Car ID: %u, parking on No.%d\n", tmpCar->ID, p->topPark + 1);
                }
                break;
            default:
                puts("Undeclared symbol. Again.");
        }
        free(tmpCar);
        free(carBill);
    }
    puts("Bye!~");
}
