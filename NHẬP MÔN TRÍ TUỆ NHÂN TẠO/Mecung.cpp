#include<stdio.h>
#include<graphics.h>
int main ()
{
	int i,j;
 printf ("ROW: 21\nCOL: 31\n");
	for (i=1;i<=21;i++)
	{
		for(j=1;j<=31;j++)
		{
			system("color 2");
			if (i==1||(j==1&&((i>=1&&i<=10)||(i>=12&&i<=21)))
			||i==21||j==31||(j>=3&&j<=29&&i==3)||(j==3&&i>=3&&i<=8)
			||(j==5&&i>=3&&i<=6)||(j>=7&&j<=11&&i==5)
			||(j==7&&i>5&&i<=11)||(j==9&&i>=7&&i<=11)||(j==11&&i>5&&i<12)
			||(j>=2&&j<=3&&i==10)||(j>=5&&j<=11&&i==13)
			||(j>=4&&j<=5&&i==8)||(j==5&&i>8&&i<13)||(j==13&&i>=5&&i<=13)
			||(j>=13&&j<=15&&i==5)||(j>13&&j<=15&&i==5)||(j>13&&j<=21&&i==9)
			||(j==17&&i>=5&&i<9)||(j>=15&&j<=16&&i==7)||(j==21&&i>=5&&i<9)
			||(j==19&&i>3&&i<=7)||(j>21&&j<=25&&i==7)||(j>=23&&j<27&&i==5)
			||(j==27&&i>=5&&i<11)||(j>=25&&j<=27&&i==11)||(j>23&&j<=25&&i==9)
			||(j==23&&i>=9&&i<13)||(j>13&&j<29&&i==13)||(j==19&&(i==10||i==12))
			||(j==29&&i>3&&i<=17)||(j>13&&j<29&&i==13)||(j>=21&&j<=22&&i==11)
			||(j==2&&i==12)||(j==3&&i>=12&&i<=17)||(j>3&&j<=9&&i==17)
			||(j>=5&&j<11&&i==15)||(j==11&i>=15&&i<21)||(j>=3&&j<11&&i==19)
			||(j>11&j<=18&&i==17)||(j>=13&&j<20&&(i==15||i==19))
			||(j==20&&i>=15&&i<=19)||(j==22&&i>13&&i<=19)||(j>=23&&j<=29&&i==19)
			||(j==24&&i>15&&i<=17)||(j>=24&&j<=27&&i==15)||(j>=26&&j<29&&i==17))
			{
			printf ("1 ");
			}
			else printf ("0 ");
		}
		printf ("\n");
	}
return 0;
}
