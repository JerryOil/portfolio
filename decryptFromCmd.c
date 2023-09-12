						/*Programma Apokryptografhshs Dedomenwn*/
								//apo lada Gerasimo

#include <stdio.h>
#include <stdlib.h> // gia thn exit();
#include <string.h> // gia th strlen();

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	int i, lengthOfKey;
	char ch;
	
    if (argc !=4) {
        printf("\n\nInvalid Arguements\n");
        printf("\nUsage: decrypt sourceFile destinationFile key\n\n");
    } 
	else {
        // des an uparxei to arxeio argv[1] kai anoije to gia anagnosi
        fopen_s(&fp1,argv[1],"rb"); // enallaktika fp1=fopen(argv[1],"rb");
        if (!fp1){
        	printf("file doesn't exist");
        	exit(0);
        }
        
        // dimiourgise to arxeio argv[2] kai anoije to gia eggrafi
        fopen_s(&fp2,argv[2],"wb"); // enallaktika fp2=fopen(argv[2],"wb");
        
        lengthOfKey=strlen(argv[3]);
        // printf("to mhkos toy kleidioy einai: %d",lengthOfKey); // elegxos mhkous kleidioy
        
        i=0;
        // diavazw edw to 1-o xarakthra gia na vgei teleio, alliws pros8etei 1 extra byte sto telos toy 2ou arxeiou(amelhteo, apla oxi teleio)
        fread(&ch,sizeof(char),1,fp1);// enallaktika ch=fgetc(fp1); (mono gia txt arxeia)
        while (!feof(fp1)) {
            // printf("Apo th 8esh %d toy 1ou arxeioy\n",ftell(fp1)); // elegxos dromea 1ou arxeioy
            // ENCRYPTION
            ch-=argv[3][i%lengthOfKey]; // (an olo to programma ginei copy-paste kai se ayth thn entolh antikatasthsoyme to (-)arnhtiko proshmo me (+)8etiko exoyme thn kryptografhsh)
            // printf("o cryptografhmenos xarakthras %c\n",ch); //L elegxos cryptoxarakthra
            // Grapse enan xaraktira sto argv[2];
            fwrite(&ch,sizeof(char),1,fp2);// enallaktika fputc(ch,fp2); (mono gia txt arxeia)
            // printf("   sth 8esh %d tou 2ou arxeioy\n",ftell(fp2)); //L elegxos dromea 2ou arxeioy
            // diavasma xarakthra apo 1-o arxeio edw, alliws pros8etei 1 extra byte sto telos toy 2-ou arxeia(amelhteo, apla oxi teleio)
            fread(&ch,sizeof(char),1,fp1);// enallaktika ch=fgetc(fp1); (mono gia txt arxeia)
			i++;
			// printf("PARAKALW PERIMENETE\nExoun apokryptografh8ei kai metafer8ei %dbytes\n",i); //L Wraiopoihmeno mhnuma pros xrhsth (to afairoyme an 8eloyme megalyterh taxythta)
        }
        // REMEMBER TO CLOSE THE FILES
        fclose(fp1);
        fclose(fp2);
        printf("\nH Apokryptografhsh OLOKLHRW8HKE\n"); // mhnyma telous
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
EOF = (end of file + error of file) = -1
feof = exclusive end of file
ferror = exclusive error of file
						
							GENIKES (XRHSIMES) ENTOLES
printf("mhnyma"); = Xrhsimopoieitai kyriws gia na doume, sthn o8onh mas, se ti katastash eimaste kai poy uparxei sfalma (otan ayto uparxei)
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
