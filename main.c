#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i = 1000,j = 1000, k , l, count =0;//raw image size
    FILE *fp,*fd;  //file
    fp=fopen("/home/ksooji/MM/IMG_3032.raw","rb");  //open file
    if(!fp)
    {
        printf("ERROR!\n");
    }
    unsigned char pData [i][j];
    fread(pData,sizeof(unsigned char),(i*j),fp);  //pData is the image
    fclose(fp); //close fp point
    
    
    for (k = 0; k<i; ++k){
	for( l  = 0; l< j; ++l){		
		if(pData[k][l] != 0){
			printf("Data at k = %d, l = %d, %d\n",k,l,pData[k][l]);
			count++;}


	}
	}
	
printf("Count = %d\n", count);
    fd=fopen("/home/ksooji/MM/result.raw","wb");
    
    fwrite(pData,sizeof(unsigned char),sizeof(pData),fd);
    fclose(fd); //close
    return 0;
}
