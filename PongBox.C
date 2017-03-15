#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <time.h>
#include <stdlib.h>
#define xmax 64
#define ymax 24
#define xmin 16

void inter(int vidas,int b)
{
	textcolor(15);
	gotoxy(2,6); cprintf("SCORE: ");
	gotoxy(2,10); cprintf("%c x ",3);
	textcolor(4);
		for(b=0;b<vidas;b++)
		{
			gotoxy(6+b,10);
			cprintf("%c",3);
		}
	return;
}
void marco(int a, int b)  //CREA EL MARCO
{
	textcolor(2);
	for(a=xmin;a<=xmax;a++)
	{
		gotoxy(a,1); cprintf("%c",205);
		gotoxy(a,ymax); cprintf("%c",205);
	}
	for(b=1;b<=ymax;b++)
	{
		gotoxy(xmin,b); cprintf("%c",186);
		gotoxy(xmax,b); cprintf("%c",186);
	}
	textcolor(2);
	gotoxy(xmin,1); cprintf("%c",254);
	gotoxy(xmin,ymax); cprintf("%c",254);
	gotoxy(xmax,1); cprintf("%c",254);
	gotoxy(xmax,ymax); cprintf("%c",254);
	return;
}
void palas(int a,int b,int c) //MOVIMIENTO DE LAS PALAS
{
	textcolor(15);
	for(a=0;a<3;a++)
	{
		gotoxy(xmin+1,((ymax/2)+(c-1))+a); cprintf(" ");
		gotoxy(xmin+2,((ymax/2)+(c-1))+a); cprintf(" ");
		gotoxy(xmax-1,((ymax/2)-c)+a); cprintf(" ");
		gotoxy(xmax-2,((ymax/2)-c)+a); cprintf(" ");
	}
	for(a=0;a<7;a++)
	{
		gotoxy(((((xmax+xmin)/2)-2)-(c*2))+a,2); cprintf(" ");
		gotoxy(((((xmax+xmin)/2)-4)+(c*2))+a,ymax-1); cprintf(" ");
	}
	for(a=0;a<3;a++)
	{
		gotoxy(xmin+1,((ymax/2)+(b-1))+a); cprintf("%c",219);
		gotoxy(xmin+2,((ymax/2)+(b-1))+a); cprintf("%c",219);
		gotoxy(xmax-1,((ymax/2)-b)+a); cprintf("%c",219);
		gotoxy(xmax-2,((ymax/2)-b)+a); cprintf("%c",219);
	}
	for(a=0;a<7;a++)
	{
		gotoxy(((((xmax+xmin)/2)-2)-(b*2))+a,2); cprintf("%c",219);
		gotoxy(((((xmax+xmin)/2)-4)+(b*2))+a,ymax-1); cprintf("%c",219);
	}
	return;
}
void pelota(int e,int d,int angulox, int anguloy, int ok) //MOVIMIENTO DE LA PELOTA
{
	if(ok==2)
	{
		gotoxy(((xmax+xmin)/2)+(angulox-e),(ymax/2)+(anguloy+d)); printf(" ");
		gotoxy(((xmax+xmin)/2)+angulox,(ymax/2)+anguloy); cprintf("O");// ¸
	}
	if(ok==1)
	{
		gotoxy(((xmax+xmin)/2)+(angulox-e),(ymax/2)+(anguloy-d)); printf(" ");
		gotoxy(((xmax+xmin)/2)+angulox,(ymax/2)+anguloy); cprintf("O");
	}
	return;
}
int randome(int d,int a)
{
	unsigned numero;
	numero=time(NULL);
	srand(numero);
	d=rand()%a;
	return d;
}
void countdown(int soundd,int cont)
{
	textcolor(15);
	gotoxy(((xmax+xmin)/2)-4,ymax/2); printf("GET READY");
	delay(500);
	gotoxy(((xmax+xmin)/2)-4,ymax/2); printf("         ");
	for(cont=3;cont>0;cont--)
	{
		gotoxy(((xmax+xmin)/2),ymax/2); printf("%i",cont);
		if(soundd==1)
			sound(500);
		delay(200);
		nosound();
		delay(600);
	}
	if(soundd==1)
		sound(700);
	delay(200);
	nosound();
	return;
}
int escuadra(int a,int b,int c)
{
	textcolor(15);
	if(b==-9)
		b=10;
	for(a=0;a<7;a++)
	{
		gotoxy(((((xmax+xmin)/2)-2)-(c*2))+a,2); cprintf(" ");
		gotoxy(((((xmax+xmin)/2)-4)+(c*2))+a,ymax-1); cprintf(" ");
	}
	for(a=0;a<3;a++)
	{
		gotoxy(xmin+1,((ymax/2)+(c-1))+a); cprintf(" ");
		gotoxy(xmin+2,((ymax/2)+(c-1))+a); cprintf(" ");
		gotoxy(xmax-1,((ymax/2)-c)+a); cprintf(" ");
		gotoxy(xmax-2,((ymax/2)-c)+a); cprintf(" ");
	}
	for(a=0;a<2;a++)
	{
		gotoxy(xmin+1,((ymax/2)+(b))+a); cprintf("%c",219);
		gotoxy(xmin+2,((ymax/2)+(b))+a); cprintf("%c",219);
		gotoxy(xmin+1,((ymax/2)+(-b))+a); cprintf("%c",219);
		gotoxy(xmin+2,((ymax/2)+(-b))+a); cprintf("%c",219);
		gotoxy(xmax-1,((ymax/2)+b)+a); cprintf("%c",219);
		gotoxy(xmax-2,((ymax/2)+b)+a); cprintf("%c",219);
		gotoxy(xmax-1,((ymax/2)-b)+a); cprintf("%c",219);
		gotoxy(xmax-2,((ymax/2)-b)+a); cprintf("%c",219);
	}
	for(a=0;a<3;a++)
	{
		gotoxy(((((xmax+xmin)/2)-2)-(b*2))+a,2); cprintf("%c",219);
		gotoxy(((((xmax+xmin)/2)-2)+(b*2))+(a+2),2); cprintf("%c",219);
		gotoxy(((((xmax+xmin)/2)-4)+(b*2))+(a+4),ymax-1); cprintf("%c",219);
		gotoxy(((((xmax+xmin)/2)-4)-(b*2))+(a+2),ymax-1); cprintf("%c",219);
	}
	return 1;
}
int score(int puntos)
{
	gotoxy(9,6);
	textcolor(15);
	cprintf("%i",puntos);
	return 1;

}
int derrota(int soundd,int a)
{
	if(soundd==1)
		sound(60);
	delay(200);
	if(soundd==1)
		sound(40);
	delay(300);
	nosound();
	a=26;
	return a;
}
int cuatropalas(int *vidas,int *puntos,int *soundd,int *speed,int a,int b,int c,int d,int e,int ok,int angulox,int anguloy,int cont) //MAIN DEL PONG
{
	int cont2,ok2;
	puntos=puntos;
	b=1;
	c=40;
	d=1;
	e=0;
	ok=1;
	anguloy=0;
	angulox=0;
	textbackground(16);
	textcolor(15);
	clrscr();
	inter(*vidas,b);
	marco(a,b);
	palas(a,b,c);
	cont=0;
	countdown(*soundd,cont);
	a=0;
	cont2=0;
	while(a!=27&&a!=26) //NO ESC NI SALIDA PROVOCADA
	{
		//gotoxy(1,1); printf("anguloy:%i",anguloy);
		//gotoxy(1,2); printf("angulox:%i",angulox);
		//gotoxy(1,3); printf("b:%i c:%i",b,c);
		gotoxy(2,3); printf("SPEED: %i",*speed);
		if(cont%12==0)
		{
			*puntos=*puntos+1;
			score(*puntos);
			if(*puntos%5000==0)
			{
				*vidas=*vidas+1;
				inter(*vidas,b);
			}
			if(*puntos%1500==0)
				*speed=*speed-10;
		}
		if(cont==*speed) //CADA 100 MS.
		{
			nosound();
			cont=0;
			angulox=angulox+e;
			if(ok==0)
			{
				cont2++;
				if(ok2==1)
					anguloy=anguloy+d;
				if(ok2==2)
					anguloy=anguloy-d;
				pelota(e,d,angulox,anguloy,ok2);
				if(cont2==2)
					a=derrota(*soundd,a);
			}
			if(anguloy<10&&ok==1)
				anguloy=anguloy+d;
			if(anguloy>-9&&ok==2)
				anguloy=anguloy-d;
			pelota(e,d,angulox,anguloy,ok);
			if(anguloy==10&&ok!=0)
			{
				if(d<0)
					d=-d;
				if(b<=-2+(angulox/2)||b>=3+(angulox/2)&&angulox+b!=10&&angulox+b!=0&&angulox+b!=-9)
				{
					ok2=ok;
					ok=0;
				}
				else
				{
					ok=2;
					e=b-(angulox/2);
					if(e==-1)
						e=-2;
					if(e==1)
						e=randome(e,2);
					if(e==0)
					{
						e=randome(e,2);
						e=-e;
					}
					if(b<-6)
						e=-1;
					if(b>6)
						e=1;
					e=-e;
					if(angulox+b==10&&angulox+b==0&&angulox+b==-9)
						e=-1;
					if(*soundd==1)
						sound(200);
				}
			}
			if(anguloy==-9&&ok!=0)
			{

				if(d<0)
					d=-d;
				if(b<=-2+(-angulox/2)||b>=3+(-angulox/2)&&angulox+b!=-28&&angulox+b!=29&&angulox+b!=1)
				{
					ok2=ok;
					ok=0;
				}
				else
				{
					ok=1;
					e=b+(angulox/2);
					if(e==-1)
						e=-2;
					if(e==1)
						e=randome(e,2);
					if(e==0)
					{
						e=randome(e,2);
						e=-e;
					}
					if(b<-6)
						e=-1;
					if(b>6)
						e=1;
					if(b+angulox==29||b+angulox==-28||b+angulox==1)
						e=-1;
					if(*soundd==1)
						sound(200);
				}
			}
			if(angulox==20&&ok!=0)
			{
				if(b<=-1-anguloy||b>=3-anguloy)
				{
					ok2=ok;
					ok=0;
				}
				else
				{
					d=(b/2)+(anguloy/2);
					if(d==1)
						d=-1;
					if(d==0)
					{
						d=randome(d,2);
						ok=2;
					}
					if(b<-7)
						d=-1;
					e=-e;
					if(*soundd==1)
						sound(200);
				}

			}
			if(angulox==-20&&ok!=0)
			{

				if(b<=-2+anguloy||b>=2+anguloy)
				{
					ok2=ok;
					ok=0;
				}
				else
				{
					d=(((b+1)/2)+(anguloy/2));
					if(d==0)
					{
						d=randome(d,2);
						d=-d;
						ok=1;
					}
					if(b>7)
						d=-1;
					e=-e;
					if(angulox+b==10&&angulox+b==0&&angulox+b==-9)
						e=-1;
					if(*soundd==1)
						sound(200);
				}
			}
		}
		cont++;
		delay(1); //CUENTA 1 MS. POR CADA VUELTA DEL PROGRAMA
		if(!kbhit())
		{
			if(a==77)
			{
				b++;
				if(b==10)
				{
					c=9;
					escuadra(a,b,c);
				}

				if(b>10)
				{
					b=-9;
					c=10;
				}
				else
					c=b-1;
				if(b!=10)
					palas(a,b,c);
				if(b==-8)
				{
					c=10;
					palas(a,b,c);
				}
			}
			if(a==75)
			{
				b--;
				if(b==-9)
				{
					c=-8;
					escuadra(a,b,c);
				}
				if(b<-9)
				{
					b=10;
					c=-9;
				}
				else
					c=b+1;
				if(b!=-9)
					palas(a,b,c);
				if(b==9)
				{
					c=-9;
					palas(a,b,c);
				}
			}
			if(a!=27&&a!=26)
				a=0;
		}
		if(kbhit()!=0&&ok!=0)
			a=getch();
	}
	return a;
}
void highscoresin(int a,int c,int e,int puntos,int mat[][9])
{
	int resp[6],o,v,s,mat2[10][9];
	FILE *op;
	for(c=0;c<10;c++)
	{
		a=2;
		e=0;
		while(mat[c][a]!='*')
		{
			a++;
			if(mat[c][a]!='*')
			{
				resp[a-3]=(mat[c][a])-48;
			}
		}
		resp[a-3]='*';
		a=-1;
		while(resp[a]!='*')
		{
			a++;
		}
		a=a-1;
		s=-1;
		o=1;
		for(a=a;a>=0;a--)
		{
			o=1;
			for(v=a;v>0;v--)
				o=o*10;
			s++;
			e=e+(resp[s])*o;
		}
		if(puntos>=e)
		{
			for(a=c;a<10;a++)
				for(e=0;e<9;e++)
					mat2[a][e]=mat[a][e];

			for(a=c;a<10;a++)
				for(e=0;e<9;e++)
					mat[a+1][e]=mat2[a][e];
			o=c;
			c=9;
		}
	}
	textcolor(3);
	gotoxy(35,9); cprintf("HIGHSCORE!");
	gotoxy(35,10); cprintf("SCORE: %i",puntos);
	textcolor(15);
	gotoxy(24,23); cprintf("ACEPTAR: %c%c",27,217);
	gotoxy(43,22); cprintf("          %c",30);
	gotoxy(40,23); cprintf("SELECCI¢N: %c %c %c ",17,31,16);
	gotoxy(33,13); cprintf("NOMBRE:");

    a=65; c=-2; e=0;
    while(c!=4)
    {
	c=c+2;
	e=0;
	while(e!=13)
	{
		while(!kbhit())
		{
			if(e==72)
			{
				a++;
				if(a==91)
					a=97;
				if(a==123)
					a=48;
				if(a==58)
					a=65;
				e=0;
			}
			if(e==80)
			{
				a--;
				if(a==64)
					a=57;
				if(a==47)
					a=122;
				if(a==96)
					a=90;
				e=0;
			}
			gotoxy(41+c,13); cprintf("%c",a);
		}
		mat[o][c/2]=a;
		e=getch();
	}
    }
	mat[o][3]=puntos;
	op=fopen("C:\\DAPONG\\PONGBOX.txt","w");
	for(a=0;a<10;a++)
	{
		for(c=0;c<=2;c++)
			fprintf(op,"%c",mat[a][c]);
		if(a==o)
			fprintf(op,"%i",mat[a][3]);
		else
		{
			e=2;
			while(mat[a][e]!='*')
			{
				e++;
				if(mat[a][e]!='*')
					fprintf(op,"%i",(mat[a][e])-48);
			}
		}
		fprintf(op,"*");
		fprintf(op,"\n");
	}
	fclose(op);
	return;
}
void highscores(int a,int c,int e,int mat[][9])
{
	FILE *ap;
	textcolor(15);
	gotoxy(27,8); cprintf("NOMBRE");
	gotoxy(40,8); cprintf("SCORE");
	ap=fopen("C:\\DAPONG\\PONGBOX.txt","r");
	for(e=0;e<10;e++)
	{
		for(a=0;a<=2;a++)
		{
			mat[e][a]=fgetc(ap);
			gotoxy(1+a,1+e);
		}
		a=2;
		while( (c=fgetc(ap))!='\n'&&c!=EOF)
		{
			a++;
			if(c!='\n')
				mat[e][a]=c;
		}
	}
	textcolor(15);
	for(a=0;a<10;a++)
	{
		gotoxy(26,10+a);
		cprintf("%i.- ",a+1);
		for(c=0;c<=2;c++)
		{
			gotoxy(30+c,10+a);
			cprintf("%c",mat[a][c]);
		}
		for(c=3;c<8;c++)
		{
			if(mat[a][c]!='*')
			{
				gotoxy(38+c,10+a);
				cprintf("%c",mat[a][c]);
			}
			else
				c=7;
		}
	}
	fclose(ap);
	getch();
	return;
}
void palasori(int a,int d,int c)
{
	textcolor(15);
	for(a=0;a<6;a++)
	{
		gotoxy(((((xmax+xmin)/2)-4)+(c))+a,ymax-1); cprintf(" ");
	}
	for(a=0;a<6;a++)
	{
		gotoxy(((((xmax+xmin)/2)-4)+(d))+a,ymax-1); cprintf("%c",219);
	}
	return;
}
void palaia(int a,int e,int f)
{
	textcolor(15);
	for(a=0;a<6;a++)
	{
		gotoxy(((((xmax+xmin)/2)-4)-(f))+a,2); cprintf(" ");
	}
	for(a=0;a<6;a++)
	{
		gotoxy(((((xmax+xmin)/2)-4)-(e))+a,2); cprintf("%c",219);
	}
	return;
}
int original(int *soundd,int a,int b,int c,int d,int e,int ok,int angulox,int anguloy,int cont)
{
	int f,ex,o,dific,punto,puntoia;
	cont=0;
	a=0;
	ok=1;
	punto=0;
	puntoia=0;
	e=-1;
	textbackground(8);
	clrscr();
	marco(a,b);
	palasori(a,1,c);
	palaia(a,e,f);
	gotoxy(25,9); cprintf("SELECCIONA NIVEL DE IA:");
	d=0;
	a=80;
	while(a!=27&a!=1)
	{
		if(a==72||a==80||a==13)
		{
			if(a==72)
				d--;
			if(a==80)
				d++;
			if(d>3)
				d=1;
			if(d<1)
				d=3;
			if(d==1)
			{
				textcolor(15);
				textbackground(8);
				gotoxy(25,12); cprintf("INTERMEDIO");
				gotoxy(25,13); cprintf("INVENCIBLE");
				textcolor(16);
				textbackground(6);
				gotoxy(25,11); cprintf("NOVATO");
			}
			if(d==2)
			{
				textcolor(15);
				textbackground(8);
				gotoxy(25,11); cprintf("NOVATO");
				gotoxy(25,13); cprintf("INVENCIBLE");
				textcolor(16);
				textbackground(6);
				gotoxy(25,12); cprintf("INTERMEDIO");
			}
			if(d==3)
			{
				textcolor(15);
				textbackground(8);
				gotoxy(25,12); cprintf("INTERMEDIO");
				gotoxy(25,11); cprintf("NOVATO");
				textcolor(16);
				textbackground(6);
				gotoxy(25,13); cprintf("INVENCIBLE");
			}
		}
		a=getch();
		if(a==13&&d==1)
		{
			dific=90;
			a=1;
		}
		if(a==13&&d==2)
		{
			dific=95;
			a=1;
		}
		if(a==13&&d==3)
		{
			dific=100;
			a=1;
		}
	}
	textbackground(8);
	clrscr();
	d=1;
	e=-1;
	marco(a,b);
	palasori(a,d,c);
	palaia(a,e,f);
	while(a!=27&&a!=26)
	{
		clrscr();
		marco(a,b);
		palasori(a,d,c);
		palaia(a,e,f);
		gotoxy(66,23);
		textcolor(15);
		cprintf("1P: %i",punto);
		gotoxy(66,2);
		textcolor(15);
		cprintf("IA: %i",puntoia);
		angulox=0;
		anguloy=0;
		ex=0;
		cont=0;
		while(ok==0)
			ok=randome(ok,3);
	   while(a!=2&&a!=27&&ok!=0)
	   {
		if(cont==100)
		{
			marco(a,b);
			nosound();
			cont=0;
			angulox=angulox+ex;
			if(anguloy<10&&ok==1)
			{
				anguloy=anguloy+1;
			}
			if(anguloy>-9&&ok==2)
			{
				anguloy=anguloy-1;
			}
			textcolor(15);
			pelota(ex,1,angulox,anguloy,ok);
			if(anguloy==10&&ok!=0)
			{
				if(d<=-3+angulox||d>=5+angulox)
				{
					puntoia++;
					delay(80);
					if(puntoia==6)
					{
						gotoxy(37,12);
						textcolor(4);
						cprintf("DERROTA!");
						gotoxy(66,2);
						cprintf("IA: %i",puntoia);
						while(a!=13)
							a=getch();
						a=27;
					}
					ok=0;
				}
				else
				{
					ok=2;
					ex=ex+(d-angulox);
					if(ex==0)
						ex=ex-1;
					ex=-ex;
					if(*soundd==1)
						sound(200);
				}
				if(*soundd==1)
					sound(200);
			}
			if(angulox>=21)
			{
				ex=-ex;
				if(*soundd==1)
					sound(500);
			}
			if(angulox<=-21)
			{
				ex=-ex;
				if(*soundd==1)
					sound(500);
			}
			if(anguloy==-9&&ok!=0)
			{
				if(e<=-5-angulox||e>=3-angulox)
				{
					punto++;
					delay(80);
					if(punto==6)
					{
						gotoxy(37,12);
						textcolor(3);
						cprintf("VICTORIA!");
						gotoxy(66,23);
						cprintf("1P: %i",punto);
						while(a!=13)
							a=getch();
						a=27;
					}
					ok=0;
				}
				else
				{
					ex=ex+(e+angulox);
					if(ex==0)
						ex=ex-1;
					ok=1;
					if(*soundd==1)
						sound(200);
				}
			}
			if(anguloy<4)
			{
				if(e!=-angulox&&ok!=1)
				{
					f=e;
					if(e<-angulox)
					{
						o=randome(o,100);
						if(o<dific)
							e=e+3;
					}
					if(e>-angulox)
					{
						o=randome(o,100);
						if(o<dific)
							e=e-3;
					}
					if(e<-22)
						e=-22;
					if(e>19)
						e=19;
				}
				if(e!=-1&&ok==1)
				{
					f=e;
					if(e<-1)
						e=e+3;
					if(e>-1)
						e=e-3;
				}
				palaia(a,e,f);
			}
		}
		delay(1);
		cont++;
		if(!kbhit())
		{
			if(a==77)
			{
				d=d+3;
				if(d>22)
					d=22;
				c=d-3;
				palasori(a,d,c);
			}
			if(a==75)
			{
				d=d-3;
				if(d<-19)
					d=-19;
				c=d+3;
				palasori(a,d,c);
			}
			if(a!=27&&a!=26)
				a=0;
		}
		if(kbhit()!=0&&ok!=0&&a!=2)
			a=getch();
	   }
	}
	nosound();
	return a;
}
void ayuda()
{
	textcolor(15);
	gotoxy(29,5); cprintf("CONTROLES:");
	gotoxy(29,8); cprintf("MOVIMIENTO");
	gotoxy(49,8); cprintf("%c %c",17,16);
	gotoxy(29,10); cprintf("SALIR");
	gotoxy(49,10); cprintf("ESC");
	gotoxy(50,23); cprintf("2014 POR JCCE");
	gotoxy(50,22); cprintf("VERSION: 1.0");
	getch();
	return;
}
int menu(int a,int b,int c,int d,int e,int ok,int angulox,int anguloy,int cont,int puntos,int mat[][9],int draw[][40],int *soundd)
{
	clrscr();
	for(e=0;e<25;e++)
	{
		for(a=0;a<40;a++)
		{
			gotoxy(43+a,6+e);
			if(draw[e][a]=='*')
			{
				textcolor(3);
				cprintf("%c",219);
			}
			else
				printf("%c",draw[e][a]);
		}
	}
	marco(a,b);
	textcolor(15);
	gotoxy(24,23); cprintf("ACEPTAR: %c%c",27,217);
	gotoxy(43,22); cprintf("          %c",30);
	gotoxy(40,23); cprintf("SELECCI¢N: %c %c %c ",17,31,16);
	gotoxy(20,14); cprintf("SONIDO: ON  OFF");
	gotoxy(20,12); cprintf("HIGHSCORES (PONGBOX)");
	gotoxy(20,16); cprintf("AYUDA");
	textbackground(6);
	textcolor(16);
	gotoxy(28,14); cprintf("ON");
	c=2;
	a=72;
	while(a!=27&&a!=10)
	{
		if(a==72||a==80||a==77||a==75)
		{
			if(a==80)
			{
				c++;
				if(c>6)
					c=1;
			}
			if(a==72)
			{
				c--;
				if(c<1)
					c=6;
			}
			if(c==5)
			{
				textbackground(8);
				textcolor(15);
				gotoxy(20,18); cprintf("SALIR");
				gotoxy(20,14); cprintf("SONIDO:");
				textbackground(6);
				textcolor(16);
				gotoxy(20,16); cprintf("AYUDA");
			}
			if(c==2)
			{
				textbackground(8);
				textcolor(15);
				gotoxy(20,8); cprintf("ORIGINAL");
				gotoxy(20,12); cprintf("HIGHSCORES (PONGBOX)");
				textbackground(6);
				textcolor(16);
				gotoxy(20,10); cprintf("PONGBOX");
			}
			if(c==4)
			{
				textbackground(8);
				textcolor(15);
				gotoxy(20,12); cprintf("HIGHSCORES (PONGBOX)");
				gotoxy(20,16); cprintf("AYUDA");
				textbackground(6);
				textcolor(16);
				gotoxy(20,14); cprintf("SONIDO:");
			}
			if((a==77||a==75)&&c==4)
			{
				textbackground(8);
				textcolor(15);
				gotoxy(20,10); cprintf("PONGBOX");
				gotoxy(20,8); cprintf("ORIGINAL");
				gotoxy(37,14);
				b=b+1;
				if(b==1)
				{
					textbackground(8);
					textcolor(15);
					gotoxy(32,14); cprintf("OFF");
					textbackground(6);
					textcolor(16);
					gotoxy(28,14); cprintf("ON");
				}
				else
				{
					textbackground(8);
					textcolor(15);
					gotoxy(28,14); cprintf("ON");
					textbackground(6);
					textcolor(16);
					gotoxy(32,14); cprintf("OFF");
				}
				if(b>1)
					b=0;
				*soundd=b;
				textbackground(6);
				textcolor(16);
				gotoxy(20,14); cprintf("SONIDO:");
			}
			if(c==1)
			{
				textbackground(8);
				textcolor(15);
				gotoxy(20,18); cprintf("SALIR");
				gotoxy(20,10); cprintf("PONGBOX");
				textbackground(6);
				textcolor(16);
				gotoxy(20,8); cprintf("ORIGINAL");
			}
			if(c==6)
			{
				textbackground(8);
				textcolor(15);
				gotoxy(20,8); cprintf("ORIGINAL");
				gotoxy(20,16); cprintf("AYUDA");
				textbackground(6);
				textcolor(16);
				gotoxy(20,18); cprintf("SALIR");
			}
			if(c==3)
			{
				textbackground(8);
				textcolor(15);
				gotoxy(20,10); cprintf("PONGBOX");
				gotoxy(20,14); cprintf("SONIDO:");
				textbackground(6);
				textcolor(16);
				gotoxy(20,12); cprintf("HIGHSCORES (PONGBOX)");
			}
		}
		a=getch();
		if(a==27)
			a=2;
		if(a==13&c==5)
		{
			textbackground(16);
			clrscr();
			marco(a,b);
			ayuda();
			a=menu(a,b,c,d,e,ok,angulox,anguloy,cont,puntos,mat,draw,soundd);
		}
		if(a==13&&c==2)
			a=10;
		if(a==13&&c==6)
			a=27;
		if(a==13&&c==1)
		{

			original(soundd,a,b,c,d,e,ok,angulox,anguloy,cont);
			a=menu(a,b,c,d,e,ok,angulox,anguloy,cont,puntos,mat,draw,soundd);
		}
		if(a==13&&c==3)
		{
			textbackground(16);
			clrscr();
			marco(a,b);
			highscores(a,c,e,mat);
			a=menu(a,b,c,d,e,ok,angulox,anguloy,cont,puntos,mat,draw,soundd);
		}
	}
	return a;
}
void main()
{
	int vidas,puntos,soundd,speed,a,b,c,d,e,ok,angulox,anguloy,cont;
	int mat[10][9],draw[25][40];
	clrscr();
	_setcursortype(_NOCURSOR);
	FILE *ad;
	for(e=0;e<25;e++)
		for(a=0;a<40;a++)
			draw[e][a]=0;
	ad=fopen("C:\\DAPONG\\main.txt","r");
	for(e=0;e<25;e++)
	{
		for(a=0;a<40;a++)
		{
			draw[e][a]=fgetc(ad);
			if(draw[e][a]=='\n')
				a=39;
			if(draw[e][a]==EOF)
			{
				a=39;
				e=24;
			}
		}
	}
	c=1;
	while(!kbhit())
	{
		c++;
		for(e=0;e<23;e++)
		{
			delay(65);
			for(a=0;a<40;a++)
			{
				gotoxy(23,25);
				textcolor(15);
				cprintf("PRESIONA UNA TECLA PARA COMENZAR");
				if(kbhit())
				{
					a=39;
					e=23;
				}
				gotoxy(23+a,2+e);
				if(draw[e][a]=='*')
				{
					textcolor(c);
					cprintf("%c",219);
				}
				else
					printf("%c",draw[e][a]);
			}
		}
	}
	fclose(ad);
	sound(783.991);
	delay(100);
	sound(1046.502);
	delay(185);
	nosound();
	getch();
	for(e=0;e<25;e++)
		for(a=0;a<40;a++)
			draw[e][a]=0;
	ad=fopen("C:\\DAPONG\\title.txt","r");
	for(e=0;e<25;e++)
	{
		for(a=0;a<40;a++)
		{
			draw[e][a]=fgetc(ad);
			if(draw[e][a]=='\n')
				a=39;
			if(draw[e][a]==EOF)
			{
				a=39;
				e=24;
			}
		}
	}
	fclose(ad);
	ad=fopen("C:\\DAPONG\\PONGBOX.txt","r");
	for(e=0;e<10;e++)
	{
		for(a=0;a<=2;a++)
		{
			mat[e][a]=fgetc(ad);
		}
		a=2;
		while( (c=fgetc(ad))!='\n'&&c!=EOF)
		{
			a++;
			if(c!='\n')
				mat[e][a]=c;
		}
	}
	fclose(ad);
	b=1;
	a=72;
	c=1;
	soundd=1;
	while(a!=27)
	{
		textbackground(8);
		a=menu(a,b,c,d,e,ok,angulox,anguloy,cont,puntos,mat,draw,&soundd);
		vidas=3;
		puntos=0;
		speed=110;
	   while(a!=1&&a!=27)
	   {
		a=cuatropalas(&vidas,&puntos,&soundd,&speed,a,b,c,d,e,ok,angulox,anguloy,cont);
		vidas--;
			if(vidas==0)
			{
				a=27;
				gotoxy(6,10); printf(" ");
				while(c!=13)
				{
					textcolor(12);
					gotoxy(36,10); cprintf("GAME OVER");
					gotoxy(35,12); cprintf("SCORE: %i",puntos);
					gotoxy(36,14); cprintf("PRESS %c%c",27,217);
					c=getch();
				}
				a=27;
				textbackground(16);
				clrscr();
				marco(a,b);
				highscoresin(a,c,e,puntos,mat);
				c=1;
			}
		if(a==27)
			a=1;
	   }
	}
	return;
}


