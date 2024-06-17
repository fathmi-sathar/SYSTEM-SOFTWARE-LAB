#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char bitmask[30];
char bit[20];
void bitmask_convert(char mask[])
{
  int len=strlen(mask);
  strcpy(bit,"");
  for(int i=0;i<len;++i)
  {
    switch(mask[i])
    {
      case '0': strcat(bit,"0000");
				  break;
			case '1': strcat(bit,"0001");
				  break;
			case '2': strcat(bit,"0010");
                                  break;
			case '3': strcat(bit,"0011");
                                  break;
			case '4': strcat(bit,"0100");
                                  break;
			case '5': strcat(bit,"0101");
                                  break;
			case '6': strcat(bit,"0110");
                                  break;
			case '7': strcat(bit,"0111");
                                  break;
			case '8': strcat(bit,"1000");
                                  break;
			case '9': strcat(bit,"1001");
                                  break;
			case 'A': strcat(bit,"1010");
                                  break;
			case 'B': strcat(bit,"1011");
                                  break;
			case 'C': strcat(bit,"1100");
                                  break;
	
			case 'D': strcat(bit,"1101");
                                  break;
			case 'E': strcat(bit,"1110");
                                  break;

			case 'F': strcat(bit,"1111");
                                  break;

			default : break;
      }
 }
 }
 void main()
 {
   char name[20],rec[20],first[3],second[5],bitmask[20];
   int bitmask_index=0,modifyobj;
   int i,address,add,length,start;
   printf("Enter the starting address\n");
   scanf("%X",&start);
   address=start;
   FILE *fp;
   fp=fopen("program.txt","r");
   fscanf(fp,"%s",rec);
   if(strcmp(rec,"H")==0)
   {
     fscanf(fp,"%s%X%X",name,&add,&length);
      printf("\nProgram name %s",name);
      printf("\nADRESS OBJECT CODE\n");
       printf("____________________________\n");
    }
    else
    {
      printf("inavlid object format\n");
      fclose(fp);
      exit(1);
    }
    strcpy(rec,"");
    fscanf(fp,"%s",rec);
 while(strcmp(rec,"E")!=0)
 {
   if(strcmp(rec,"T")==0)
   {
     fscanf(fp,"%X%X%s",&add,&length,bitmask);
     add+=start;
      bitmask_index=0;
     bitmask_convert(bitmask);
     fscanf(fp,"%s",rec);
     }
     if(bit[bitmask_index]=='1')
     {
     for(i=0;i<6;++i)
     {
       if(i<2)
       {
         first[i]=rec[i];
        }
        else{
         second[i-2]=rec[i];
       }
     }
 first[2]='\0';
 second[4]='\0';
 modifyobj=strtol(second,NULL,16);
 modifyobj+=start;
 printf("%X\t%s%X\n",add,first,modifyobj);
 }
 else
 {
   printf("%X\t%s\n",add,rec);
  }
  add+=3;
  bitmask_index++;
  fscanf(fp,"%s",rec);
  }
  fclose(fp);
  }
  
 
 
 
   
     
   
