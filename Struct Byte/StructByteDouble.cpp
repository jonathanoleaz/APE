#include<stdio.h>
#include<stdio.h>  
#include<conio.h>  
#include<stdlib.h> 

//solo se aceptan int, debe ser unsigned, sino sera -1 y 1
//en estructuras tipo byte no se oermiten arreglos
struct byte
{
	unsigned int bit63:1;
	unsigned int bit62:1;
	unsigned int bit61:1;
	unsigned int bit60:1;
	unsigned int bit59:1;
	unsigned int bit58:1;
	unsigned int bit57:1;
	unsigned int bit56:1;
	
	unsigned int bit55:1;
	unsigned int bit54:1;
	unsigned int bit53:1;
	unsigned int bit52:1;
	unsigned int bit51:1;
	unsigned int bit50:1;
	unsigned int bit49:1;
	unsigned int bit48:1;
	
	unsigned int bit47:1;
	unsigned int bit46:1;
	unsigned int bit45:1;
	unsigned int bit44:1;
	unsigned int bit43:1;
	unsigned int bit42:1;
	unsigned int bit41:1;
	unsigned int bit40:1;
	
	unsigned int bit39:1;
	unsigned int bit38:1;
	unsigned int bit37:1;
	unsigned int bit36:1;
	unsigned int bit35:1;
	unsigned int bit34:1;
	unsigned int bit33:1;
	unsigned int bit32:1;
	
	unsigned int bit31:1;
	unsigned int bit30:1;
	unsigned int bit29:1;
	unsigned int bit28:1;
	unsigned int bit27:1;
	unsigned int bit26:1;
	unsigned int bit25:1;
	unsigned int bit24:1;
	
	unsigned int bit23:1;
	unsigned int bit22:1;
	unsigned int bit21:1;
	unsigned int bit20:1;
	unsigned int bit19:1;
	unsigned int bit18:1;
	unsigned int bit17:1;
	unsigned int bit16:1;
	
	unsigned int bit15:1;
	unsigned int bit14:1;
	unsigned int bit13:1;
	unsigned int bit12:1;
	unsigned int bit11:1;
	unsigned int bit10:1;
	unsigned int bit9:1;
	unsigned int bit8:1;
	
	unsigned int bit7:1;
	unsigned int bit6:1;
	unsigned int bit5:1;
	unsigned int bit4:1;
	unsigned int bit3:1;
	unsigned int bit2:1;
	unsigned int bit1:1;
	unsigned int bit0:1;
};
typedef struct byte Byte;

union BYTE
{
	Byte b;
	double c;
};

void print(BYTE b)
{
	printf("%d",b.b.bit0);
	printf("%d",b.b.bit1);
	printf("%d",b.b.bit2);
	printf("%d",b.b.bit3);
	printf("%d",b.b.bit4);
	printf("%d",b.b.bit5);
	printf("%d",b.b.bit6);
	printf("%d",b.b.bit7);
	
	printf("%d",b.b.bit8);
	printf("%d",b.b.bit9);
	printf("%d",b.b.bit10);
	printf("%d",b.b.bit11);
	printf("%d",b.b.bit12);
	printf("%d",b.b.bit13);
	printf("%d",b.b.bit14);
	printf("%d",b.b.bit15);
	
	printf("%d",b.b.bit16);
	printf("%d",b.b.bit17);
	printf("%d",b.b.bit18);
	printf("%d",b.b.bit19);
	printf("%d",b.b.bit20);
	printf("%d",b.b.bit21);
	printf("%d",b.b.bit22);
	printf("%d",b.b.bit23);
	
	printf("%d",b.b.bit24);
	printf("%d",b.b.bit25);
	printf("%d",b.b.bit26);
	printf("%d",b.b.bit27);
	printf("%d",b.b.bit28);
	printf("%d",b.b.bit29);
	printf("%d",b.b.bit30);
	printf("%d",b.b.bit31);
	
	printf("%d",b.b.bit32);
	printf("%d",b.b.bit33);
	printf("%d",b.b.bit34);
	printf("%d",b.b.bit35);
	printf("%d",b.b.bit36);
	printf("%d",b.b.bit37);
	printf("%d",b.b.bit38);
	printf("%d",b.b.bit39);
	
	printf("%d",b.b.bit40);
	printf("%d",b.b.bit41);
	printf("%d",b.b.bit42);
	printf("%d",b.b.bit43);
	printf("%d",b.b.bit44);
	printf("%d",b.b.bit45);
	printf("%d",b.b.bit46);
	printf("%d",b.b.bit47);
	
	printf("%d",b.b.bit48);
	printf("%d",b.b.bit49);
	printf("%d",b.b.bit50);
	printf("%d",b.b.bit51);
	printf("%d",b.b.bit52);
	printf("%d",b.b.bit53);
	printf("%d",b.b.bit54);
	printf("%d",b.b.bit55);
	
	printf("%d",b.b.bit56);
	printf("%d",b.b.bit57);
	printf("%d",b.b.bit58);
	printf("%d",b.b.bit59);
	printf("%d",b.b.bit60);
	printf("%d",b.b.bit61);
	printf("%d",b.b.bit62);
	printf("%d",b.b.bit63);
	
}

int main()
{
	Byte a;
	union BYTE b;
	
	printf("\t\tDouble a binario por struct tipo byte y union\n\n\n");
	b.c=1.7976931348623157E+308; //en la union de convierte, A (55 ASCII), en binario
	printf("Valor m\240ximo para double en binario: (1.7976931348623157E+308)\n");
	print(b);
	b.c=2.2250738585072014E-308; //en la union de convierte, A (55 ASCII), en binario
	printf("\nValor m\241nimo para double en binario: (2.2250738585072014E-308)\n");
	print(b); //en la union de convierte, A (55 ASCII), en binario
	printf("\n\nIngrese valor del double a convertir a binario: "); scanf("%lf",&b.c);
	print(b);

/*	a.bit7=0;
	a.bit6=1;
	a.bit5=0;
	a.bit4=0;
	a.bit3=0;
	a.bit2=1;
	a.bit1=1;
	a.bit0=1;*/
	getch();
}
