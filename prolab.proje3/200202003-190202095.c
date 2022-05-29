#include <stdio.h>
#include <stdlib.h>

struct ucak
{

    int oncelik_id;
    int ucak_id;
    int kalkis_saati;
    int saat;
    int gecikme_suresi;


};

struct ucak std[50];
int oncelik_id[50];
int ucak_id[50];
int saat[50];
int gecikme[50];
int inis[50];
int yeni[50];
int step=0;

void menu()
{
    int secim;
    system("cls");
    printf("\n\n\n\n\t\t\t\** MENU **\n\n\n  ");
    printf("\t1-- Dosyadan  Input Oku Ve Sirala\n");
    printf("\t2-- Sirali Input Dosyasini Goster \n");
    printf("\tDiger-- Cikis\n\n");

    printf("\t\tYapmak istediginiz islemi seciniz!\n");
    scanf("%d",&secim);

    switch(secim)
    {
    case 1:
        inputOku();
        break;
    case 2:
        inputSiraliGoster();
        break;
    case 4:
        exit(1);
        break;

    }
}

void inputOku()
{
    FILE *fp;


    system("cls");
    printf("\n\n\t\t\t **  Index Dosyasini Goruntule ** \n\n\n\n");
    printf("           \t        Talep Edilen\t    Inis\n");
    printf("    Oncelik ID\tUcak ID\t Inis Saati\tYapilan Saat\n");
    printf("    ----------\t-------\t ----------\t------------\n");

    fp=fopen("input.txt","r");
    if(fp==NULL)
    {
        printf("Dosya acma hatasi!!");
        exit(1);
    }



    int i=0;
    while(!feof(fp))
    {
        fscanf(fp,"%d %d %d",&std[i].oncelik_id,&std[i].ucak_id,&std[i].saat);
        oncelik_id[i]=std[i].oncelik_id;
        ucak_id[i]=std[i].ucak_id;
        saat[i]=std[i].saat;
        inis[i]=std[i].saat;
        gecikme[i]=0;
        // printf("\t%d\t%d\t\t%d\t\n",std[i].oncelik_id,std[i].ucak_id,std[i].saat);
        step++;
        int res = input(step);
        i++;
        getch();
    }


    int sec;
    printf("Menuye donmek icin 1 'e basiniz:");
    scanf("%d",&sec);
    if(sec==1)
    {
        menu();
    }
    else
    {
        exit(1);
    }


}
/*
void elemankaldir(int i){
    int sil;
    i=sil;
    printf("%d",sil);

    for( int a =0; a< step; a++)
    {
      if(a==sil || a>sil){
       oncelik_id[a]=oncelik_id[a+1];
       ucak_id[a]=ucak_id[a+1];
       saat[a]=saat[a+1];
       inis[a]=inis[a+1];
       gecikme[a]=gecikme[a+1];
        }

    }


}*/

void input(int step)
{



    if(step==1)
    {
        //  printf("\t%d\t%d\t\t%d\t\n",oncelik_id[0],ucak_id[0],saat[0]);
    }
    else
    {

        for(int i=1; i<step; i++)
        {

            for(int j=0; j<step-1; j++)
            {

                if(inis[j]!=inis[j+1])
                {
                    if(inis[j]>inis[j+1])
                    {
                        int deger=saat[j+1];
                        saat[j+1]=saat[j];
                        saat[j]=deger;

                        deger=oncelik_id[j+1];
                        oncelik_id[j+1]=oncelik_id[j];
                        oncelik_id[j]=deger;

                        deger=ucak_id[j+1];
                        ucak_id[j+1]=ucak_id[j];
                        ucak_id[j]=deger;

                        deger=inis[j+1];
                        inis[j+1]=inis[j];
                        inis[j]=deger;

                        deger=gecikme[j+1];
                        gecikme[j+1]=gecikme[j];
                        gecikme[j]=deger;


                    }

                }

                if(inis[j]==inis[j+1])
                {


                    if(oncelik_id[j]>oncelik_id[j+1])
                    {

                        int deger=oncelik_id[j+1];
                        oncelik_id[j+1]=oncelik_id[j];
                        oncelik_id[j]=deger;

                        deger=ucak_id[j+1];
                        ucak_id[j+1]=ucak_id[j];
                        ucak_id[j]=deger;
                        //rpt=step-1;

                        deger=saat[j+1];
                        saat[j+1]=saat[j];
                        saat[j]=deger;

                        deger=inis[j+1];
                        inis[j+1]=inis[j];
                        inis[j]=deger;

                        deger=gecikme[j+1];
                        gecikme[j+1]=gecikme[j];
                        gecikme[j]=deger;

                    }
                    if(oncelik_id[j]==oncelik_id[j+1])
                    {

                        if(ucak_id[j]>ucak_id[j+1])
                        {

                            int deger=oncelik_id[j+1];
                            oncelik_id[j+1]=oncelik_id[j];
                            oncelik_id[j]=deger;

                            deger=ucak_id[j+1];
                            ucak_id[j+1]=ucak_id[j];
                            ucak_id[j]=deger;
                            //rpt=step-1;

                            deger=saat[j+1];
                            saat[j+1]=saat[j];
                            saat[j]=deger;

                            deger=inis[j+1];
                            inis[j+1]=inis[j];
                            inis[j]=deger;

                            deger=gecikme[j+1];
                        gecikme[j+1]=gecikme[j];
                        gecikme[j]=deger;

                        }
                    }
                    inis[j+1]++;
                    gecikme[j+1]++;
                   /* if(gecikme[j+1]==4){


                        for(int a =0; a< step; a++)
                        {

                            oncelik_id[a]=oncelik_id[a+1];
                            ucak_id[a]=ucak_id[a+1];
                            saat[a]=saat[a+1];
                            inis[a]=inis[a+1];
                            gecikme[a]=gecikme[a+1];


                        }



                  }*/

                }


           }
         }

     }
     FILE *fpr;
    fpr=fopen("output.txt","w");

    if(fpr==NULL)
    {
        printf("Dosya acma hatasi!!");
        exit(1);
    }

    system("cls");
    printf("\n\n\t\t\t **  Index Dosyasini Goruntule ** \n\n\n\n");
    printf("           \t        Talep Edilen\t    Inis\n");
    printf("    Oncelik ID\tUcak ID\t Inis Saati\tYapilan Saat\tGecikme\t\tKalkis\t\n");
    printf("    ----------\t-------\t ----------\t------------\t--------\t-------\n");
    for(int a =0; a< step; a++)
    {

        printf("\t%d\t%d\t\t%d\t\t%d\t\t%d\t%d\n",oncelik_id[a],ucak_id[a],saat[a],inis[a]%24,gecikme[a],(inis[a]+1)%24);
        fprintf(fpr,"%d %d %d %d %d %d\n",oncelik_id[a],ucak_id[a],saat[a],inis[a]%24,gecikme[a],(inis[a]+1)%24);


    }
    printf("\n    *********************\n");

    fclose(fpr);



}


void inputSiraliGoster()
{

    for(int j =1; j<step ; j++)
    {

        printf("\t%d\t%d\t%d\t\n",oncelik_id[j],ucak_id[j],saat[j]);
    }

    int sec;
    printf("Menuye donmek icin 1 'e basiniz:");
    scanf("%d",&sec);
    if(sec==1)
    {
        menu();
    }
    else
    {
        exit(1);
    }

}


int main()
{
    printf("\n\n\n\n\t\t\t\t   *** HAVALIMANI UCUS SISTEMI ***\n");
    printf("\n\n\t\t\t\t ** Menuye ulasmak icin bir tusa basiniz **\n");
    getch();
    menu();



    return 0;


}
