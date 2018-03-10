# include<conio.h>
# include<stdio.h>
# include<string.h>

int main()
{
	int h,m;
	
	printf("Ingrese la hora: ");
	scanf("%d:%d",&h,&m);
	
	if (h>=24 || m>=60)
	{
		printf("Hora erronea");
		return 0;
		
	}
	if (h>12)
	{
	
	if (m<10) {
		
		printf("%d:0%d PM",h-12,m);
		
	} 
	
	else
	{
		printf("%d:%d PM",h-12,m);
	} 
	}
	else
	if (m<10){
	
	printf("%d:0%d AM",h,m);
}
else
printf("%d:%d AM",h,m);
	getch();
	
	return 0;
}



