#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define num 20            // number of opponent car
#define speed 1000000   //speed of loop...(i.e)movement of car
int k2;
int tx=1,ty=35,txx=tx-1,tyy=ty,bx[200]={0},by[200]={0},bull=0,bullhit[200]={0},bulldir[200]={0};
int opx[num]={0},opy[num]={0},opdash[num]={0},opdir[num]={0},life=5,p,s,no=3,balance,hitcount,maxbull=20;
int opbullx[num]={0},opbully[num]={0},opbullintake[num]={0},match_dir[num]={0},no_of_foll=2;
char name[10],ch,ccc;
int goalx[7]={10,20,30,40,50,10,30},goaly[7]={5,45,5,45,5,45,5},goal;
float time_taken ;
clock_t t;
double sec;
char hname[3][20];
int hscore[3];
void go(int x, int y)
{
    HANDLE a;
    COORD b;
    b .X= x;
    b .Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
}
void intro()
{
    go(1,1);
    puts("INSTRUCION : ");
    go(3,3);
    printf("- PRESS %c  RIGHT   %c  LEFT   %c  UP   %c  DOWN ",16,17,30,31);
    go(3,5);
    puts("- PRESS SPACE FOR BULLET");
    go(3,7);
    puts("- PRESS R TO RELOAD BULLET..");
    go(3,9);
    puts("- COMPLETE THE BELOW TASK WITHIN 3 MINS...");
    go(3,11);
    printf("- RUN AWAY FROM YOUR TRACKER...AND KEEP COLLECTING SMILIEYS %c",258);
    ch=getch();
}
void setcolor(int ForgC)
{
     WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}
void end()
{
	int j,l=0;
    for(j=0;j<10000000000;j++);
	system("cls");
	setcolor(54);
	go(10,10);
    printf("SCORE YOU GOT IS : %d ",goal);
    go(10,12);
	puts("HOPE YOU ENJOYED...");
	  FILE *ptr;
	ptr=fopen("scoree.txt","r");
    for(l=0;l<3;l++)
    {
        fscanf(ptr,"%s ",&hname[l]);
        fscanf(ptr,"%d",&hscore[l]);
    }
    for(l=0;l<3;l++)
    {
            if(hscore[l]<goal)
            {
                break;
            }
    }
    if(l!=3)
    {
        int key=l;
        for(l=l+1;l<3;l++)
        {
            strcpy(hname[l],hname[l-1]);
            hscore[l]=hscore[l-1];
        }
        strcpy(hname[key],name) ;
        hscore[key]=goal;
        ptr=fopen("scoree.txt","w");
        rewind(ptr);
            for(l=0;l<3;l++)
            {
                fprintf(ptr,"%s\n",hname[l]);
                fprintf(ptr,"%d\n",hscore[l]);
            }
    }
    go(12,14);
    puts("HIGH SCORE");
	int k=15;
    for(l=0;l<3;l++)
    {
        go(10,k++);
        printf("%d %s  %d",l+1,hname[l],hscore[l]);
    }
   
    ch=getch();
    ch=getch();
    exit(1);
}
void goalprint()
{
    if(goal<7)
    {
        int i,j;
        go(goalx[goal],goaly[goal]);
        printf("%c",258);
        go(goalx[goal]-2,goaly[goal]-1);
       // puts(" SAFE");
        for(i=tx;i<=tx+2;i++)
        {
            for(j=ty;j<=ty+2;j++)
            {
                if(goalx[goal]==i && goaly[goal]==j)
                goal++;
            }
        }
    }
    else
    {
        end();
    }
}
void corner_print()
{
    int i;
	for(i=0;i<=55;i++)
	{
	go(0,i);puts(".");
	go(78,i);puts(".");
	go(61,i);puts(".");
    }
}
void status_print()
{
	go(0,0);
    puts("______________________________________________________________________________");
    go(0,55);
    puts("______________________________________________________________________________");
	go(63,4);
	puts("OPPONENT CAR ");
	go(63,6);
	printf("LEFT : %d",num-balance);
	go(62,8);puts("  -------------");
	go(63,10);
	printf("LIFE  %c : %d",259,life);
	go(62,12);puts("  -------------");
	go(63,25);printf("TIME %.1f",sec);
}
void check_car_dashes()  //checks whether any of opponent car dashes us...
{
int a=0,b=0,k=0,j=0,i=0,k1=0;
	for(k=-1;k<no;)
	{
		nxt_car:
		k++;
		if(opdash[k]==0)
		 {
			for(i=tx;i<tx+3;i++)
			{
				for(j=ty;j<ty+3;j++)
				{
					for(a=opx[k];a<opx[k]+3;a++)
					{
						for(b=opy[k];b<opy[k]+3;b++)
						{
							if(i==a&&j==b)
							{
							life--;
					 		go(25,25);
					 		printf("life %d is wasted",5-life );
					   		for(j=0;j<10000000000;j++);
					   		tx=1; ty=51;
					   		txx=tx; tyy=ty;
					   		p==3;
					   		if(life<1)
							end();
							goto nxt_car;
							}
						}
					}
				}
			}
		}
	}
}
void check_mybull_dash_op()  //compare 1 car with each bullet
{
	int j=0,j1=0,i=0,k=0,k1=0;
	for(j=-1;j<no;)
    {
    	nxt_car :
    	j++;
		if(opdash[j]==0)
	   	{
	   		for(j1=0;j1<bull;j1++)
		    {
		    	if(bullhit[j1]==0)
				{
				  	for(i=opx[j];i<opx[j]+3;i++)
					{
						for(k=opy[j];k<opy[j]+3;k++)
						{
							if(bx[j1]==i && by[j1]==k)
							{
                                printf("\a");
                                opdash[j]=1;
                                bullhit[j1]=1;
                                ++hitcount;
                                balance++;
                                if(balance==20)
                                end();
			    			}
						}
				 	}
				}
			}
		}
	}
}
void opcar_bullet_dash_us()  //checks whether opponents bullet dashes us..if then moves our car to initial position
{
int j=0,i=0,k=0;
	for(i=-1;i<no;)
	{
		nxt_car:
		i++;
		if(opdash[i]==0)
		{
			if(opbullintake[i]==1)
			{
				for(j=tx;j<tx+3;j++)
				{
					for(k=ty;k<ty+3;k++)
					{
						if(opbullx[i]==j&&opbully[i]==k)
						{
							life--;
							go(25,25);
					 		printf("life %d is wasted",5-life );
					   		for(j=0;j<100000000;j++);
							opbullintake[i]=0;
							tx=1;ty=51;
							txx=tx;tyy=ty;p==3;
							if(life<1)
							end();
							goto nxt_car;
						}
					}
				}
			}
		}

	}
}
void mycar_print() // compares each car with its last position and prints according to its position
{
	if((tx>txx&&ty==tyy)||((tx==txx&&ty==tyy)&&(p==3)))
	{
	go(tx,ty);
	printf("%c%c",475,475);
	go(tx,ty+1);
	printf(" %c%c ",475,475);
	go(tx,ty+2);
	printf("%c%c",475,475);
	p=3;s=3;
	}
	else if((tx<txx&&ty==tyy)||((tx==txx&&ty==tyy)&&(p==2)))
	{
	go(tx,ty);
	printf(" %c%c",475,475);
	go(tx,ty+1);
	printf("%c%c ",475,475);
	go(tx,ty+2);
	printf(" %c%c",475,475);
	p=2;s=2;
	}

	else if((tx==txx&&ty<tyy)||((tx==txx&&ty==tyy)&&(p==1)))
	{
    go(tx,ty);
	printf(" %c",475);
	go(tx,ty+1);
	printf("%c%c%c",475,475,475);
	go(tx,ty+2);
	printf("%c %c",475,475);
	p=1;s=1;
	}
	else if((tx==txx&&ty>tyy)||((tx==txx&&ty==tyy)&&(p==4)))
	{
	go(tx,ty);
	printf("%c %c",475,475);
	go(tx,ty+1);
	printf("%c%c%c",475,475,475);
	go(tx,ty+2);
	printf(" %c",475);
	p=4;s=4;
	}
}
void opcar_print1()
{
    int j,carnum=0,i;
    char z;
	for(j=0;j<no;j++)
    {
        if(opdash[j]==0)
		{
		    z='#';
		    carnum++;
            if(carnum%no_of_foll==0)
             {
                 z=475;
                            if( match_dir[j]==0)
                            {
                                if(goal%2==0)
                                {
                                if(tx==opx[j]&&ty>goaly[goal])
                                {
                                    if(opy[j]>ty)
                                        opdir[j]=1;
                                    if(opy[j]<ty)
                                        opdir[j]=4;
                                        opbullintake[j]=0;
                                         match_dir[j]=1;
                                }
                                else if(ty==opy[j]&&ty>goaly[goal])
                                {
                                    if(opx[j]>tx)
                                        opdir[j]=2;
                                    if(opx[j]<tx)
                                        opdir[j]=3;
                                        opbullintake[j]=0;
                                        match_dir[j]=1;
                                }
                                }
                                else
                                {
                                     if(tx==opx[j]&&ty<goaly[goal])
                                {
                                    if(opy[j]>ty)
                                        opdir[j]=1;
                                    if(opy[j]<ty)
                                        opdir[j]=4;
                                        opbullintake[j]=0;
                                         match_dir[j]=1;
                                }
                                else if(ty==opy[j]&&ty<goaly[goal])
                                {
                                    if(opx[j]>tx)
                                        opdir[j]=2;
                                    if(opx[j]<tx)
                                        opdir[j]=3;
                                        opbullintake[j]=0;
                                        match_dir[j]=1;
                                }

                                }
                            }
             }
            if(opdir[j]==3)
			{
			 	go(opx[j],opy[j]);
				printf("##");
				go(opx[j],opy[j]+1);
				printf("#%c#",z);
				go(opx[j],opy[j]+2);
				puts("##");
			}
			else if(opdir[j]==2)
			{
			 	go(opx[j],opy[j]);
				puts(" ##");
				go(opx[j],opy[j]+1);
				printf("#%c#",z);
				go(opx[j],opy[j]+2);
				puts(" ##");
			}
			else if(opdir[j]==1)
			{
			 	go(opx[j],opy[j]);
				puts(" #");
				go(opx[j],opy[j]+1);
				printf("#%c#",z);
				go(opx[j],opy[j]+2);
				puts("###");
			}
			if(opdir[j]==4)
			{
			 	go(opx[j],opy[j]);
				puts("###");
				go(opx[j],opy[j]+1);
				printf("#%c#",z);
				go(opx[j],opy[j]+2);
				puts(" #");
            }
  	    }
	}
}
void opbull_print()
{
	int j,i=2;
	for(j=0;j<no;j++)
 	{
	 	if(opdash[j]==0)
	 	{
	 		if(opbullintake[j]==0)
	 		{
	 			if(opdir[j]==1)
	 			{
	 				opbullx[j]=opx[j]+5;
	 				opbully[j]=opy[j]-5;
	 				opbullintake[j]=1;
	        	}
	        	else if(opdir[j]==2)
	 			{
	 				opbullx[j]=opx[j]-2;
	 			 	opbully[j]=opy[j]+2;
	 			 	opbullintake[j]=1;
	        	}
	        	else if(opdir[j]==3)
	 			{
					opbullx[j]=opx[j]+4;
	 				opbully[j]=opy[j]+2;
	 				opbullintake[j]=1;
	        	}
	        	else if(opdir[j]==4)
	 			{
	 				opbullx[j]=opx[j]+2;
	 				opbully[j]=opy[j]+4;
	 				opbullintake[j]=1;
	        	}
			}
		}
	}
	for(j=0;j<no;j++)
 	{
        if(opdash[j]==0)
        {
            if(opbullintake[j]==1)
            {
                if(opdir[j]==2)
                {
                    go(opbullx[j],opbully[j]);
                    puts("*");
                    opbullx[j]-=i;
                        if(opbullx[j]<1)
                            opbullintake[j]=0;
                }
                else if(opdir[j]==1)
                {
                    go(opbullx[j],opbully[j]);
                    printf("*");
                    opbully[j]-=i;
                        if(opbully[j]<1)
                            opbullintake[j]=0;
                }
                else if(opdir[j]==3)
                {
                    go(opbullx[j],opbully[j]);
                    puts("*");
                    opbullx[j]+=i;
                        if(opbullx[j]>60)
                         opbullintake[j]=0;
                }
                else if(opdir[j]==4)
                {
                    go(opbullx[j],opbully[j]);
                    puts("*");
                    opbully[j]+=i;
                        if(opbully[j]>54)
                            opbullintake[j]=0;
                }
            }
        }
	}
}
void bullet_print()
{
	int j;
	if(bull>0)
	{   for(j=0;j<bull;j++)
     	{
     		if(bullhit[j]<1)
     		{
     			if(bulldir[j]==1)
     			{
					go(bx[j],by[j]);
	         		printf("*");
		     		by[j]-=2;
		     		if(by[j]<1)
		     			{ bullhit[j]=1; ++hitcount; }
	        	}
	        	else if(bulldir[j]==2)
     			{
					go(bx[j],by[j]);
	         		puts("*");
		     		bx[j]-=2;
		     		if(bx[j]<1)
		     			{ bullhit[j]=1; ++hitcount; }
	        	}
	        	else if(bulldir[j]==3)
     			{
					go(bx[j],by[j]);
	         		puts("*");
		     		bx[j]+=2;
		     		if(bx[j]>61)
		     			{ bullhit[j]=1; ++hitcount; }
	        	}
	        	else if(bulldir[j]==4)
     			{
					go(bx[j],by[j]);
	           		puts("*");
		     		by[j]+=2;
		     		if(by[j]>54)
		     			{ bullhit[j]=1; ++hitcount; }
	        	}
			}
		}
	}
}
void next_opcar()
{
	int count=0,j;
	for(j=0;j<no;j++)
	{
        if(opdash[j]==0)
        	count++;
	}
	if(count<5)
	{
		if(no<num)
		no=no+1;
	}
}
void opcar_turn()
{
	int j,carnum=0;
	for(j=0;j<no;j++)
	{
		if(opdash[j]==0)
		{
		    carnum++;
	   		if(opdir[j]==4)
	   		{
				if(opy[j]>51)
				{
					opdir[j]=1;
					opy[j]=51;
					if(carnum%no_of_foll==0)
					match_dir[j]=0;
				}
				else
					opy[j]++;
			}
			else if(opdir[j]==1)
			{
				if(opy[j]<4)
				{
					opdir[j]=4;
					opy[j]=1;
					if(carnum%no_of_foll==0)
                    match_dir[j]=0;
				}
				else
					opy[j]--;
			}
			else if(opdir[j]==3)
	   	    {
				if(opx[j]>58)
				{
					opdir[j]=2;
					opx[j]=58;
					if(carnum%no_of_foll==0)
                        match_dir[j]=0;
				}
				else
					opx[j]++;
			}
			else if(opdir[j]==2)
	   	    {
				if(opx[j]<2)
				{
					opdir[j]=3;
					opx[j]=1;
					if(carnum%no_of_foll==0)
                        match_dir[j]=0;
				}
				else
					opx[j]--;
			}
	    }
	}
}
void input(char c)
{
	int j,i;
	switch(c)
	{
		case 72 : ty=ty-5;
		           break;
		case 80 : ty=ty+5;
					break;
		case 75 : tx=tx-5;
					break;
		case 77 : tx=tx+5;
					break;
		case 'r' : if(hitcount>=maxbull)
					{
					if(life>0)
					life--;
		 			bull=0;
		 			for(i=0;i<=maxbull;i++)
                      {
                      	bullhit[i]=0;
					  }
					  hitcount=0;
				    }
					break;
		case ' ' :  if(bull<20)
					{
						bull++;
						j=bull-1;
						if(s==1)
						{
						bulldir[j]=1;
						bx[j]=tx+1;
						by[j]=ty-1;
						go(bx[j],by[j]);
						}
						else if(s==2)
						{
						bulldir[j]=2;
						bx[j]=tx-1;
						by[j]=ty+1;
						}
						else if(s==3)
						{
						bulldir[j]=3;
						bx[j]=tx+3;
						by[j]=ty+1;
						}
						else if(s==4)
						{
						bulldir[j]=4;
						bx[j]=tx+1;
						by[j]=ty+3;
						}
					}
					break;
	}
	if(ty>52)
		ty=52;
	if(tx>58)
		tx=58;
	if(ty<1)
		ty=1;
	if(tx<1)
		tx=1;
}
void reload()
{
    char c1;
	if(hitcount>=maxbull)
	{
		if(life>0)
		{
        go(63,14);
		puts("   PRESS ");
		go(63,16);
		puts("-- R RELOAD --");
		}
		if(life==0)
		{
		go(62,18);
		puts("NO LIFES TO RELOAD");
		go(63,20);
		puts("PRESS Q TO QUIT");
		c1=getch();
		if(c1=='q')
            end();
		}
	}
}
void game_start()
{
    int i,i1=35,j,j1,load[9]={176,176,176,177,177,178,178,178},l=0;
	char c;
	go(30,20);
	puts("ENTER YOUR NAME..");
	go(30,23);
	scanf("%s",name);
	system("cls");
    intro();
	for(i=0;i<9;i++,i1++)
	{
		go(35,23);
		puts("LOADING...");
		go(i1,24);
		printf("%c",load[i]);
		for(j=0;j<10000000;j++);
	}
 	opx[0]=0;opy[0]=3;  opdir[0]=3;
	opx[1]=55;opy[1]=25;opdir[1]=2;
	opx[2]=15;opy[2]=52;opdir[2]=1;
	opx[3]=40;opy[3]=0; opdir[3]=4;
	opy[4]=15;opx[4]=0;	opdir[4]=3;
	opy[5]=35;opx[5]=55;opdir[5]=2;
	opy[6]=51;opx[6]=40;opdir[6]=1;
	opy[7]=0;opx[7]=20; opdir[7]=4;
	opy[8]=35;opx[8]=0; opdir[8]=3;
	opy[9]=51;opx[9]=45;opdir[9]=2;
	opx[10]=0;opy[10]=3;opdir[10]=3;
	opx[11]=55;opy[11]=25;opdir[11]=2;
	opx[12]=15;opy[12]=52;opdir[12]=1;
	opx[13]=40;opy[13]=0;opdir[13]=4;
	opy[14]=15;opx[14]=0;opdir[14]=3;
	opy[15]=35;opx[15]=55;opdir[15]=2;
	opy[16]=51;opx[16]=40;opdir[16]=1;
	opy[17]=0;opx[17]=20;opdir[17]=4;
	opy[18]=35;opx[18]=0;opdir[18]=3;
	opy[19]=51;opx[19]=45;opdir[19]=2;
	game:
	do
	{
        t   = clock();
        sec = ((double)t)/CLOCKS_PER_SEC;
      if(sec>=500)
        end();
         for(i=0;i<speed;i++);
		system("cls");
		setcolor(77);
		status_print();
		setcolor(77);
		corner_print();
		check_car_dashes();
		opcar_bullet_dash_us();
		setcolor(63);
		mycar_print();
		setcolor(10);
		opcar_print1();
		check_mybull_dash_op();
		setcolor(15);
		bullet_print();
		setcolor(11);
		goalprint();
		setcolor(88);
		opbull_print();
		next_opcar();
		opcar_turn();
	    reload();
	}while(!kbhit());
	c=getch();
    ccc=getch();
    if(ccc=='q')
    exit(1);
	txx=tx;tyy=ty;
	input(c);
	goto game ;
}
main()
{
	setcolor(99);
	go(27,15);
	printf("- %c - TOP SHOOTER - %c -",258,258);
	game_start();
	    ch=getch();
	return 0;
}
