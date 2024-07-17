#include <stdio.h>

struct item
{
	char name[50];
	int price,quantity,totamount;
};
void read(struct item *i)
{
	printf("Enter Name, Price and Quantity of item:");
	scanf("%s%d%d",i->name,&i->price,&i->quantity);
}

void display(struct item i)
{
	printf("Name=%s\nPrice=%d\nQuantity=%d\n",i.name,i.price,i.quantity);
	i.totamount=i.price*i.quantity;
	printf("Total Amount = %d",i.totamount);
}
void main()
{
	struct item i1;
	read(&i1);
	display(i1);
}