#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <stdio.h>
#include <stdlib.h>

typedef  struct {
     char c;
     int h;
     short n;
     long m;
     float f;
     double d1;
     char *s;
     double d2;
}st;


void saveConfig(){
	 FILE *fp;
    st sa,sb;
    char *str = "abcdefg";
    sa.c= 'K';
    sa.h=- 3;
    sa.n= 20;
    sa.m= 100000000;
    sa.f= 33.32f;
    sa.d1= 78.572;
    sa.d2= 33.637;
    sa.s=str;
    fp=fopen( " st.txt ", " w+ ");
     if(!fp)
    {
        printf( " errror!\n ");
        exit(- 1);
    }
    printf( " sa:c=%c,h=%d,n=%d,m=%d,f=%f,d1=%f,s=%s,d2=%f\n\n ",sa.c,sa.h,sa.n,sa.m,sa.f,sa.d1,sa.s,sa.d2);
    printf( " sizeof(sa)=%d:&c=%x,&h=%x,&n=%x,&m=%x,&f=%x,&d1=%x,&s=%x,&d2=%x\n ", sizeof(sa),&sa.c,&sa.h,&sa.n,&sa.m,&sa.f,&sa.d1,&sa.s,&sa.d2);
    fwrite(&sa, sizeof(sa), 1,fp);
    rewind(fp);
    fread(&sb, sizeof(sb), 1,fp);
    printf( " sb:c=%c,h=%d,n=%d,m=%d,f=%f,d1=%f,s=%s,d2=%f\n ",sb.c,sb.h,sb.n,sb.m,sb.f,sb.d1,sb.s,sb.d2);
       
    fclose(fp);
    
}


void readConfig(){
    FILE *fp;
    st sb;
    fp=fopen( " st.txt ", " r ");
     if(!fp)
    {
        printf( " errror!\n ");
        exit(- 1);
    }
    fread(&sb, sizeof(sb), 1,fp);
    printf( " sb:c=%c,h=%d,n=%d,m=%d,f=%f,d1=%f,s=%s,d2=%f\n\n",sb.c,sb.h,sb.n,sb.m,sb.f,sb.d1,sb.s,sb.d2);
    printf( " sizeof(sb)=%d:&c=%x,&h=%x,&n=%x,&m=%x,&f=%x,&d1=%x,&s=%x,&d2=%x\n ", sizeof(sb),&sb.c,&sb.h,&sb.n,&sb.m,&sb.f,&sb.d1,&sb.s,&sb.d2);
       
    fclose(fp);
    
}



int main(int argc, char** argv) 
{
	saveConfig();
	std::cout<<std::endl<<std::endl;
	readConfig();
     return  0;
}
