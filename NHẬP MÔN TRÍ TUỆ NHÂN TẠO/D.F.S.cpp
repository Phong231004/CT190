#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define out "out.txt"
int inx,iny,outx,outy;
int x[2500],y[2500],a[50][50],c[50][50],h,
dx[5]={0,0,1,0,-1},
dy[5]={0,-1,0,1,0};
char e[50][50], Namefile[50][50];
int m,n,i,j,d,s;
FILE *f,*f1;

void NHAP()
{    	
    f=fopen("C:\\Users\\HP\\OneDrive - ctu.edu.vn\\Desktop\\Code NHÓM II\\MECUNG.txt","r");
	printf("\t Mo file thanh cong: \n\n");
	fscanf(f,"%d %d",&m,&n);
	printf("\t\t So Hang         : %d \n",m);
	printf("\t\t So Cot          : %d \n",n);
	fscanf(f,"%d %d %d %d",&inx,&iny,&outx,&outy);
	printf("\t\t START		 : A[%d][%d]  \n",inx-1,iny-1);
	printf("\t\t GOAL DESCRIPTION: A[%d][%d]  \n",outx-1,outy-1);
	printf("\n\t An Enter de tiep tuc.......roi nhan di nhin gi nua\n");
	printf("\n\t Cho chut nhe, upload ma tran cai <<\n");
	getch();
	printf("\t HINH ANH CUA ME CUNG \n");
	printf("______________________________________________________________");
	
	for (i=0;i<m;++i)
		{
   	printf("\t\t\t");
   	printf("\n");
		for (j=0;j<n;++j)
   		{
    		fscanf(f,"%d",&a[i][j]);
    		printf(" %d",a[i][j]);
    		if(a[i][j]==1) system("color 9");
   		}
   	}
	printf("\n");
	printf("______________________________________________________________");
	printf("\n\t An Enter de tiep tuc:.......roi co chiu nhan nua khong?\n\n");
	getch();
	fclose(f);
}
int BUOCDITHOAMAN(int i,int j)
	{
	if ((i<0)||(i>=m)||(j<0)||(j>=n)) return 0;
	if ((a[i][j]!=0)||(c[i][j]!=0)) return 0;
	return 1;
	}

void DFS(int i,int j)
	{
	if ((i==outx-1)&&(j==outy-1)) d=1;
	else
		{
		int k;
		for (k=1;k<=4;++k)
		if (BUOCDITHOAMAN(i+dx[k],j+dy[k]))
			{
			c[i+dx[k]][j+dy[k]]=k;
			DFS(i+dx[k],j+dy[k]);
			}
		}
		}

void CHUANBI()
	{
	for (i=0;i<m;++i)
		for (j=0;j<n;++j) c[i][j]=0;
	c[inx-1][iny-1]=-1;
	d=0;
	}

void TIM()
	{
	s=0;
	x[0]=outx-1;
	y[0]=outy-1;
	i=outx-1;
	j=outy-1;
	int k;
	while (c[i][j]!=-1)
		{
		k=c[i][j];
		i=i-dx[k];
		j=j-dy[k];
		s++;
		x[s]=i;
		y[s]=j;
		}
	}

void XULY()
	{
	CHUANBI();
	DFS(inx-1,iny-1);
	if (d==1) TIM();
	e[2*(inx-1)][2*(iny-1)]='1';
	e[2*(outx-1)][2*(outy-1)]='2';
	}

void PRINT()
	{
	FILE *f;
	f=fopen("C:\\Users\\HP\\OneDrive - ctu.edu.vn\\Desktop\\Code NHÓM II\\OUTPT.txt","w");
	if (d != 1)
      {
   	fprintf(f,"KET LUAN: KHONG CO DUONG DI");
      printf("KET LUAN:\t KHONG CO DUONG DI\n\n");
      }
	if (d==1)
		{
      fprintf(f,"CAC TOA DO CAC DIEM TREN DUONG DI THOAT KHOI ME CUNG \n\n");
		for (i=s;i>=0;i--)
      fprintf(f,"\t%d.a[%d][%d]-->\t",i,x[i],y[i]);
      printf("K.E.T Q.U.A C.U.A B.A.N L.A:    \n");
      printf("DO DAI DUONG DI TRONG ME CUNG LA: %d\n",s);
      printf("Day cac toa do duong di da duoc luu ra file GIAIMECUNG.txt.....\n\n");

      fprintf(f,"\n\n DO DAI DUONG DI TRONG ME CUNG LA : %d\n",s);
		}
	fclose(f);
	}


int main ()
	{
		NHAP();
		XULY();
        PRINT();
        system("color 4");
		printf("Ban an EnTer de tiep tuc, an phim bat ky de ket thuc.....\n\n");
		getch();
	}


