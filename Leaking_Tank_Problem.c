#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main()
{
    // PROBLEM 1: LEAKING TANK
    double amain[10000][20]={0};//main array for printing table
    double bmain[1000][20]={0}; // extention of main array since there's an error if size is 10k
    int pick;

        printf("\n====================================PROBLEM 1: LEAKING TANK====================================\n\n");
        printf("After manually solving, the mathematical model was known to be: \n\n dh/dt= (-0.00380682921)/(0.1875h^1.5 + 0.75h^.5 + 0.75h^-0.5) \t given h(0)=2\n\n");
        printf("Please check the Executive report for the full solution of the mathematical model.");
        printf("\n\n[NOTE]: Please open the file 'prob1data' to check the summary of calculated data for ALL methods. \n");

    do{
        printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\n1 - Analytical Method\t3 - Midpoint Method  \t\t    5 - SUMMARY of all methods"); printf("\n2 - Euler's Method\t4 - 4th Order Runge-Kutta Method");
        printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\nWhat method do you want to run? Pick a number:  ");
        scanf("%d", &pick);
        printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

        int i=0,j=0,k=0, iterations;
        double t, calc, c=4.146690742, a=-0.0009*sqrt(19.62);
        //double finala1[10000]={0}, finala2[10000]={0};
        double h=fabs(2.000); //PLEASE CHANGE TO 1

        switch (pick) {

        case 1: //ANALYTICAL METHOD
             h=fabs(2); //CHANGE if 1
             i=0, j=0, k=0, t=0;
             double time=0;
            printf("\n\n------------------ANALYTICAL METHOD------------------\nThe equation to be used is: \n t = ((pi/3)(0.075h^(2.5) + 0.5h^(1.5) + 1.5h(^.5)) - 4.146690742) / (-0.0039865) \n\n");
            printf("\n[NOTE]: step size is h= - 0.1, which is used in the height(h)\n\n");
            printf("_________________________________________\n");
            printf("n\t Time(sec)\t Height(m)\t|\n");
            printf("_________________________________________\n");
            do{
            amain[i][0]= fabs(h);
            calc= (((M_PI/(double)3)*((0.075*pow(h, 2.5))+(0.5*pow(h, 1.5))+(1.5*pow(h, 0.5))))-c)/a;
            amain[i][1]= fabs(calc);
            printf("%d\t| %.6lf\t %.10lf\t|\n",i, fabs(calc), h);
            time= calc;
            h=fabs(h-0.1);
            i++;
            }while(i<=20);
            printf("\nTime required to drain tank: %.4lf seconds\n", time);
            break;

        case 2: //EULER's Method
            h=fabs(2); //CHANGE if 1
            t=0; i=0; j=0, k=0; //initialization

            double calc1, calc2, calc3, t1=0, t2=0, t3=0, time1=0, time2=0, time3=0, tdummy;
            double h1=2, h2=2, h3=2; //CHANGE
            calc1=h1;
            calc2=h2;
            calc3=h3;
            printf("\n\n------------------EULER'S METHOD------------------\n");
            printf("____________________________________________________________\n");
            printf("n\t Time(sec)\t Height(m) [h=0.1]\t\n");
            printf("\n____________________________________________________________\n");

            do{
                if (i<=10000){
                amain[i][2]= t1;
                amain[i][3]= calc1;
                amain[i][4]= calc2;
                amain[i][6]= calc3;
                }

                if(h1>=0){
                    printf("%d\t| %.6lf \t %.6lf ",i, t1, h1);
                    tdummy=t1;
                    t1+=0.1;
                }else{
                    tdummy+=0.1;
                    printf("%d\t| %.6lf\t\t",i, tdummy);
                    time1= t1+0.1;
                }
                calc1= h1+ (0.1)*(a/((M_PI/(double)3)*((0.1875*pow(h1, 1.5))+(0.75*pow(h1, 0.5))+(0.75*pow(h1, -0.5)))));
                h1=calc1;

                //0.01
                printf("\t%.6lf", h2);
                for (k=0; k<10; k++){
                    calc2= h2+ (0.01)*(a/((M_PI/(double)3)*((0.1875*pow(h2, 1.5))+(0.75*pow(h2, 0.5))+(0.75*pow(h2, -0.5)))));
                    h2=calc2;
                    if(h2>=0){
                    t2+=0.01;
                    }else{
                    time2= t2;
                    }
                    }
                //0.001
                printf("\t%.6lf", h3);
                for (k=0; k<100; k++){
                calc3= h3+ (0.001)*(a/((M_PI/(double)3)*((0.1875*pow(h3, 1.5))+(0.75*pow(h3, 0.5))+(0.75*pow(h3, -0.5)))));
                h3=calc3;
                if(h3>=0){
                    t3+=0.001;
                    }else{
                    time3= t3;
                    }
                }
            i++;
            printf("\n");
            }while((h1>=0) || (h2>=0) || (h3>=0)) ; //
                printf("--------------------------------------------------------------------\n");
                printf("                          [h=0.1]      [h=0.01]        [h=0.001]\n");
                printf("Iterations  Time(sec)                HEIGHT (meters)\n");
                printf("--------------------------------------------------------------------\n");
                printf("____________________________________________________________________\n");
                printf("[EULER's | h=0.1]  Time required to drain tank: %.6lf seconds\n", time1);
                printf("[EULER's | h=0.01]  Time required to drain tank: %.6lf seconds\n", time2);
                printf("[EULER's | h=0.001]  Time required to drain tank: %.6lf seconds\n", time3);
                printf("____________________________________________________________________\n");
                printf("\n[Please look for the CSV file 'prob1data.csv' in the folder for the complete data]", t3);
            break;

        case 3 : //MIDPOINT METHOD
            h=fabs(2); //CHANGE if 1
            t=0; i=0; j=0, k=0;
            printf("\n\n\n\n\n\n\n\n\n\n\n------------------MIDPOINT METHOD------------------\n\n");
            printf("Euler Part: [10 iterations]\n\n");
            double ha, hb, hc, hb1, hc1, calca, calcb, calcc, eulera=2, eulerb=2, eulerc=2, s1=0,s2=0,s3=0;
            int enter;
            printf("__________________________________________________________________\n"); printf("t\t h=0.1\t           t\t h=0.01\t          t\th=0.001\t\n"); printf("__________________________________________________________________\n");
                //euler part
                for (k=0; k<1000; k++){
                    if (k<11){
                    printf("%.4lf\t%.6lf  |\t%.4lf\t%.6lf  |\t%.4lf\t%.6lf  |\n", s1, eulera, s2, eulerb, s3, eulerc);
                    }
                    if (k==10){
                    ha=calca;
                    hb=calcb;
                    hc=calcc;
                    } else if (k==100){
                    hb1= calcb;
                    }
                hc1= calcc;
                calca= eulera+ (0.01)*(a/((M_PI/(double)3)*((0.1875*pow(eulera, 1.5))+(0.75*pow(eulera, 0.5))+(0.75*pow(eulera, -0.5)))));
                calcb= eulerb+ (0.001)*(a/((M_PI/(double)3)*((0.1875*pow(eulerb, 1.5))+(0.75*pow(eulerb, 0.5))+(0.75*pow(eulerb, -0.5)))));
                calcc= eulerc+ (0.0001)*(a/((M_PI/(double)3)*((0.1875*pow(eulerc, 1.5))+(0.75*pow(eulerc, 0.5))+(0.75*pow(eulerc, -0.5)))));
                eulera=calca; eulerb=calcb; eulerc=calcc; s1+=0.01; s2+=0.001; s3+=0.0001;
                }calcb=0; calcc=0;

            char ch;
            printf("\n\nPlease enter any key to continue: \n\n\n");
            scanf("%c", &ch);
            getchar();
            printf("\n");

            t1=0; t3=0; t2=0; i=0; j=0;
            double mcalc1, mcalc2, mcalc3, mtime1=0, mtime2=0, mtime3=0, calc5, calc6, calc7;
            double mh1=2, mh2=2, mh3=2; //CHANGE
            //mcalc1=mh1; mcalc2=mh2; mcalc3=mh3;

            amain[i][7]= t1; amain[i][8]= mh1; amain[i][9]= mh2; amain[i][10]= mh3;
            printf("%d\t| %.6lf\t %.6lf \t%.6lf \t%.6lf\n",i, t1, mh1, mh2, mh3);
            i++; t1+=0.1; t2+=0.01; t3+=0.001;
            amain[i][7]= t1; amain[i][8]= mh1; amain[i][9]= hb1; amain[i][10]= hc1;
            printf("%d\t| %.6lf\t %.6lf",i, t1, ha); i++;    //wrong
                do{
                    //0.01
                        for (k=0; k<10; k++){
                        mcalc2= mh2+ (2*0.01)*(a/((M_PI/(double)3)*((0.1875*pow(hb, 1.5))+(0.75*pow(hb, 0.5))+(0.75*pow(hb, -0.5)))));
                        mh2=hb;
                        hb=mcalc2;
                        mtime2= t2;

                            if(hb>=0){
                            t2+=0.01;
                            }else{
                            mtime2= t2;
                            }
                            if (k==8){
                                if (mcalc2>=0){
                                printf("\t%.6lf", mcalc2);}
                            }}
                        //0.001
                        for (k=0; k<100; k++){
                        mcalc3= mh3+ (2*0.001)*(a/((M_PI/(double)3)*((0.1875*pow(hc, 1.5))+(0.75*pow(hc, 0.5))+(0.75*pow(hc, -0.5)))));
                        mh3=hc;
                        hc=mcalc3;
                        mtime3= t3;

                            if(hc>=0){
                            t3+=0.001;
                            }else{
                            mtime3= t3;
                            }
                            if (k==98){
                                if (mcalc3>=0){
                                printf("\t%.6lf\n", mcalc3);}
                            }}
                    //0.001
                    mcalc1= mh1+ (2*0.1)*(a/((M_PI/(double)3)*((0.1875*pow(ha, 1.5))+(0.75*pow(ha, 0.5))+(0.75*pow(ha, -0.5)))));
                    mh1=ha;
                    if (mcalc1>=0){
                                printf("%d\t| %.4lf\t %.6lf",i, t1, mcalc1);}
                    ha=mcalc1;
                    if(ha>=0){
                        t1+=0.1;
                    }else{
                        mtime1= t1;
                        }
                    //ASSIGNING to the array
                    if (i<10000){
                    amain[i][7]= t1;
                    amain[i][8]= mcalc1;
                    amain[i][9]= mcalc2;
                    amain[i][10]= mcalc3;
                    }
                i++;
                }while((mh1>=0) || (mh3>=0) || (mh2>=0));
                printf("\n--------------------------------------------------------------------\n");
                printf("                          [h=0.1]      [h=0.01]        [h=0.001]\n");
                printf("Iterations  Time(sec)                HEIGHT (meters)\n");
                printf("--------------------------------------------------------------------\n");
                printf("____________________________________________________________________\n");
                printf("[MIDPOINT METHOD | h=0.1]  Time required to drain tank: %.6lf seconds\n", mtime1);
                printf("[MIDPOINT METHOD | h=0.01]  Time required to drain tank: %.6lf seconds\n", mtime2);
                printf("[MIDPOINT METHOD | h=0.001]  Time required to drain tank: %.6lf seconds\n", mtime3);
                printf("____________________________________________________________________\n");
                printf("\n[Please look for the CSV file 'prob1data.csv' in the folder for the complete data]");


            break;

        case 4: //RK4 METHOD
            i=0; j=0; k=0, t1=0, t2=0, t3=0;
            double rtime1=0, rtime2=0, rtime3=0 ;
            h1=2, h2=2, h3=2; //CHANGE TO 1
            double ak1,ak2,ak3,ak4, bk1,bk2,bk3,bk4, ck1,ck2,ck3,ck4,dummy1, dummy2, dummy3, term1, term2, term3;

            printf ("time\tk1\tk2\tk3\tk4\th\n", t1, h1);
            printf ("%.1lf          \t\t\t\t\t%lf\n", t1, h1);
            t1+=0.1; t2+=0.01; t3+=0.001;
            dummy1=h1;
            do{
                //0.1
                ak1= (0.1)*(a/((M_PI/(double)3)*((0.1875*pow(h1, 1.5))+(0.75*pow(h1, 0.5))+(0.75*pow(h1, -0.5)))));
                ak2= (0.1)*(a/((M_PI/(double)3)*((0.1875*pow(h1+(ak1/2), 1.5))+(0.75*pow(h1+(ak1/2), 0.5))+(0.75*pow(h1+(ak1/2), -0.5)))));
                ak3= (0.1)*(a/((M_PI/(double)3)*((0.1875*pow(h1+(ak2/2), 1.5))+(0.75*pow(h1+(ak2/2), 0.5))+(0.75*pow(h1+(ak2/2), -0.5)))));
                ak4= (0.1)*(a/((M_PI/(double)3)*((0.1875*pow(h1+ak3, 1.5))+(0.75*pow(h1+ak3, 0.5))+(0.75*pow(h1+ak3, -0.5)))));

                h1= h1 + ((ak1+(2*ak2)+(2*ak3)+ak4)/6) ;

                if(h1>=0){
                        t1+=0.1;
                    }else{
                        rtime1= t1-0.1;
                    }
                if (h1>=0){
                        printf("%.1lf\t| %.4lf   ", t1, h1);
                    }
                //0.01
                for (i=0; i<10; i++){

                    bk1= (0.01)*(a/((M_PI/(double)3)*((0.1875*pow(h2, 1.5))+(0.75*pow(h2, 0.5))+(0.75*pow(h2, -0.5)))));
                    bk2= (0.01)*(a/((M_PI/(double)3)*((0.1875*pow(h2+(bk1/2), 1.5))+(0.75*pow(h2+(bk1/2), 0.5))+(0.75*pow(h2+(bk1/2), -0.5)))));
                    bk3= (0.01)*(a/((M_PI/(double)3)*((0.1875*pow(h2+(bk2/2), 1.5))+(0.75*pow(h2+(bk2/2), 0.5))+(0.75*pow(h2+(bk2/2), -0.5)))));
                    bk4= (0.01)*(a/((M_PI/(double)3)*((0.1875*pow(h2+bk3, 1.5))+(0.75*pow(h2+bk3, 0.5))+(0.75*pow(h2+bk3, -0.5)))));

                    h2= h2 + ((bk1+(2*bk2)+(2*bk3)+bk4)/6) ;

                    if(h2>=0){
                        t2+=0.01;
                    }else{
                        rtime2= t2-0.01;
                    }}
                    if (h2>=0){
                        printf("%.4lf   ", h2);
                    }
                //0.001
                for (i=0; i<100; i++){

                    ck1= (0.001)*(a/((M_PI/(double)3)*((0.1875*pow(h3, 1.5))+(0.75*pow(h3, 0.5))+(0.75*pow(h3, -0.5)))));
                    ck2= (0.001)*(a/((M_PI/(double)3)*((0.1875*pow(h3+(ck1/2), 1.5))+(0.75*pow(h3+(ck1/2), 0.5))+(0.75*pow(h3+(ck1/2), -0.5)))));
                    ck3= (0.001)*(a/((M_PI/(double)3)*((0.1875*pow(h3+(ck2/2), 1.5))+(0.75*pow(h3+(ck2/2), 0.5))+(0.75*pow(h3+(ck2/2), -0.5)))));
                    ck4= (0.001)*(a/((M_PI/(double)3)*((0.1875*pow(h3+ck3, 1.5))+(0.75*pow(h3+ck3, 0.5))+(0.75*pow(h3+ck3, -0.5)))));

                    h3= h3 + ((ck1+(2*ck2)+(2*ck3)+ck4)/6) ;

                    if(h3>=0){
                        t3+=0.001;
                    }else{
                        rtime3= t3-0.001;
                    }}
                    if (h3>=0){
                        printf("%.4lf\t", h3);
                    }
                    if ((h3>=0) || (h3>=0) || (h3>=0)){
                        printf("| %.2lf %.2lf %.2lf %.2lf  | %.2lf %.2lf %.2lf %.2lf  | %.2lf %.2lf %.2lf %.2lf", ak1, ak2, ak3, ak4, bk1, bk2, bk3, bk4, ck1, ck2, ck3, ck4);
                    }
                printf("\n");
            }while((h3>=0) || (h1>=0) || (h2>=0));
                printf("-----------------------------------------------------------------------------------------------------------------------\n");
                printf("         [h=0.1]  [h=0.01] [h=0.001]        k1    k2    k3    k4       k1    k2    k3    k4       k1    k2    k3    k4\n");
                printf("time                HEIGHT                      k for [h=0.1]             k for [h=0.01]             k for [h=0.001]  \n");
                printf("-----------------------------------------------------------------------------------------------------------------------\n");
                printf("____________________________________________________________________\n");
                printf("[RK 4 | h=0.1]  Time required to drain tank: %.6lf seconds\n", rtime1);
                printf("[RK 4 | h=0.01]  Time required to drain tank: %.6lf seconds\n", rtime2);
                printf("[RK 4 | h=0.001]  Time required to drain tank: %.6lf seconds\n", rtime3);
                printf("____________________________________________________________________\n");
                printf("\n[Please look for the CSV file 'prob1data.csv' in the folder for the complete data]");
            break;

        case 5: //SUMMARY
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n[WARNING!] Run all methods first before selecting summary. \n\n\n\n\n\n\n\n\n\n\n\nContinue? (yes=1, no=0): \n\n\n");
            int decide;
            scanf("%d", &decide);

            printf("\n");

            if (decide == 1){
            printf("\n\n\n\n\n\n\n\n\n\n---------------- SUMMARY OF ALL METHODS---------------- ");
            printf("\n\nANALYTICAL METHOD: ");
            printf("%lf\n", time);
            printf("________________________________________________________\n");
            printf("METHOD:\t\th=0.1\t\th=0.01\t\th=0.001");
            printf("\n________________________________________________________\n");
            printf("Euler's \t| %.3lf\t%.3lf\t%.3lf |\n", time1, time2, time3);
            printf("Midpoint \t| %.3lf\t%.3lf\t%.3lf |\n", mtime1, mtime2, mtime3);
            printf("RK4      \t| %.3lf\t%.3lf\t%.3lf |\n", rtime1, rtime2, rtime3);
            printf("\n________________________________________________________\n");
            } else{
            break;

            default :
                printf("Invalid keyword, please try again\n");
            }}

            printf("\n\n\n");

    //PRINTING in CSV file
    FILE *aPtr;
    aPtr = fopen("prob1data.csv", "w");
	//fprintf(aPtr, "t, .1,.01,.001");

    fprintf(aPtr, "Analytical Method,,,,Euler's Method,,,,,MIDPOINT METHOD,,,,,RK METHOD\n");
    fprintf(aPtr, "time (s), height (m),, time (s),,HEIGHT (m),,,time (s),,HEIGHT (m),, ,time (s),,HEIGHT (m) \n");
    fprintf(aPtr, ",,,, h=0.1, h=0.01, h=0.001,,,h=0.1, h=0.01, h=0.001,,,h=0.1, h=0.01, h=0.001 \n");
	for (i=0; i<10000; i++)
	{
	    fprintf(aPtr, "%.6lf, %.6lf, ,%.6lf, %.10lf, %.10lf, %.10lf,, %.10lf, %.10lf, %.10lf, %.10lf,, %.10lf, %.10lf, %.10lf, %.10lf\n", amain[i][1], amain[i][0], amain[i][2], amain[i][3], amain[i][4], amain[i][6], amain[i][7], amain[i][8], amain[i][9], amain[i][10], amain[i][11], amain[i][12], amain[i][13], amain[i][14] );
	}
	fclose(aPtr);
	aPtr = fopen("prob1data.csv", "a");
	for (i=0; i<1000; i++)
	{
	    fprintf(aPtr, "%.6lf, %.6lf, ,%.6lf, %.10lf, %.10lf, %.10lf\n", bmain[i][1], bmain[i][0], bmain[i][2], bmain[i][3], bmain[i][4], bmain[i][6]);
	}
	fclose(aPtr);
        }while (pick!=0);
}

