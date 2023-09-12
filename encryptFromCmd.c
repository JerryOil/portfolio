				 	  	/*Programma Kryptografhshs Dedomenwn*/
						 //S = boh8hma apo k.Sagiako Gewrgio
				//L = epekshghsh h' enallaktikoi tropoi apo lada Gerasimo

#include <stdio.h>
#include <stdlib.h> //L gia thn exit();
#include <string.h> //L gia th strlen();

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	int i, lengthOfKey;
	char ch;
	
    if (argc !=4) {
        printf("\n\nInvalid Arguements\n");
        printf("\nUsage: encrypt sourceFile destinationFile key\n\n");
    } 
	else {
        //S des an uparxei to arxeio argv[1] kai anoije to gia anagnosi
        fopen_s(&fp1,argv[1],"rb"); //L enallaktika fp1=fopen(argv[1],"rb");
        if (!fp1){
        	printf("file doesn't exist");
        	exit(0);
        }
        
        //S dimiourgise to arxeio argv[2] kai anoije to gia eggrafi
        fopen_s(&fp2,argv[2],"wb"); //L enallaktika fp2=fopen(argv[2],"wb");
        
        lengthOfKey=strlen(argv[3]);
        //printf("to mhkos toy kleidioy einai: %d",lengthOfKey); //L elegxos mhkous kleidioy
        
        i=0;
        //L diavazw edw to 1-o xarakthra gia na vgei teleio, alliws pros8etei 1 extra byte sto telos toy 2-ou arxeiou(amelhteo, apla oxi teleio)
        fread(&ch,sizeof(char),1,fp1);//L enallaktika ch=fgetc(fp1); (mono gia txt arxeia)
        while (!feof(fp1)) {
            //printf("Apo th 8esh %d toy 1ou arxeioy\n",ftell(fp1)); //L elegxos dromea 1ou arxeioy
            //S ENCRYPTION
            ch+=argv[3][i%lengthOfKey]; //(an olo to programma ginei copy-paste kai se ayth thn entolh antikatasthsoyme to (+)8etiko proshmo me (-)arnhtiko exoyme thn apokryptografhsh)
            //printf("o cryptografhmenos xarakthras %c\n",ch); //L elegxos cryptoxarakthra
            //S Grapse enan xaraktira sto argv[2];
            fwrite(&ch,sizeof(char),1,fp2);//L enallaktika fputc(ch,fp2); (mono gia txt arxeia)
            //printf("   sth 8esh %d tou 2ou arxeioy\n",ftell(fp2)); //L elegxos dromea 2ou arxeioy
            //L diavasma xarakthra apo 1-o arxeio edw, alliws pros8etei 1 extra byte sto telos tou 2-ou arxeiou(amelhteo, apla oxi teleio)
            fread(&ch,sizeof(char),1,fp1);//L enallaktika ch=fgetc(fp1); (mono gia txt arxeia)
			i++;
			//printf("PARAKALW PERIMENETE\nExoun kryptografh8ei kai metafer8ei %dbytes\n",i); //L Wraiopoihmeno mhnuma pros xrhsth (to afairoyme an 8eloyme megalyterh taxythta)
        }
        //S REMEMBER TO CLOSE THE FILES
        fclose(fp1);
        fclose(fp2);
        printf("\nH Kryptografhsh OLOKLHRW8HKE\n"); //L mhnyma telous
    }
    return 0;
}

/*
								 EXTRA PLHROFORIES
							(gia epekshghsh-katanohsh)
& = dieu8unsh mnhmhs
* = deikths

argc = argument count
argv = argument value
fp = file pointer
NULL = 0
EOF = (end of file || error of file) = -1
feof = exclusive end of file
ferror = exclusive error of file

							GENIKES (XRHSIMES) ENTOLES
printf("mhnyma"); = Xrhsimopoieite kyriws gia na doume, sthn o8onh mas, se ti katastash eimaste kai poy uparxei sfalma (otan ayto uparxei)
break(); = stamataei thn epanalhpsh
exit(0); = termatizei to programma

        		ENTOLES GIA ARXEIA ME PLHROFORIES SE AN8RWPINH GLWSSA
fopen("onoma.eidos arxeiou","entolh ekteleshs"); = anoigei to arxeio (an yparxei)
fopen(" . ","r"); = gia anagnwsh, r=read
fopen(" . ","r+"); = gia anagnwsh kai tropopoihsh, r=read
fscanf(proerxomos plhroforias,"%eidos plhroforias",&metavlhth apo8hkeyshs); = anagnwsh plhroforias kai apo8hkeysh se metavlhth
fgetc(metavlhth apo8hkeyshs,proerxomos xarakthra); = anagnwsh xarakthra kai apo8hkeysh se metavlhth
fgets(onoma pinaka,mege8os pinaka,proerxomos symvoloseiras); = anagnwsh sumvoloseiras kai apo8hkeysh se pinaka
fopen(" . ","w"); = dhmiourgei to arxeio (an den uparxei hdh) gia eggrafh, w=write
fprintf(proorismos plhroforias,"plhrofories"); = perasma plhroforiwn se proorismo gia "ektypwsh"
fputc('',proorismos xarakthra); = perasma xarakthra se proorismo gia "ektypwsh"
fputs(" ",proorismos symvoloseiras); = perasma sumvoloseiras se proorismo gia "ektypwsh"

			ENTOLES GIA ARXEIA ME PLHROFORIES SE GLWSSA MHXANHS (DYADIKO SYSTHMA)
fopen(" . ","rb"); = gia anagnwsh glwssas mhxanhs, r=read b=binary
fopen(" . ","r+b"); = gia anagnwsh kai tropopoihsh glwssas mhxanhs, r=read b=binary
fread(dieu8unsh dedomenwn,mege8os dedomenwn,plh8os dedomenwn,onoma deikth arxeiou); = diavazoyme apo binary arxeio
fopen(" . ","wb"); = dhmiourgei to arxeio (an den uparxei hdh) gia eggrafh se glwssa mhxanhs, w=write b=binary
fwrite(dieu8unsh dedomenwn,mege8os dedomenwn,plh8os dedomenwn,onoma deikth arxeiou); = grafoyme se binary arxeio

							ENTOLES GIA KLEISIMO ARXEIWN
fclose(onoma deikth arxeiou); = kleinei to arxeio ths sygkekrimenhs 8eshs gia na apohkeytoyn oi allages
fcloseall(void); kleinei ola ta arxeia poy eixame anoiksei gia na apo8hkeytoyn oi allages
*/
