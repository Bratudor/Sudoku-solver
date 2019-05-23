#include <iostream>
#include <fstream>

using namespace std;
bool checkforsame(int a[]);
bool contineNr(int a[]);//verifica daca un array are -6
void transp1(int f[],int g[],int sq1[]);
void muncaGrea();
void linii(int a[], int i);
void coloane(int a[], int i);
void linii_pos(int a[], int i,int p[9][9]);
void coloane_pos(int a[], int i,int p[9][9]);
void scrietabloul(int a[9][9]);
void fctlinie(int p[9][9],int numar);
void fctcol(int p[9][9],int numar);
int num[9][9];
int sqGood=0;
int lineGood=0;
int colGood=0;
int f[]={0,1,2};
int g[]={0,1,2};
ifstream fin("sud.in");
ofstream fout("sud.out");
int pos_1[9][9],pos_2[9][9],pos_3[9][9],pos_4[9][9],pos_5[9][9];
int pos_6[9][9],pos_7[9][9],pos_8[9][9],pos_9[9][9];
int sq1[9],sq2[9],sq3[9],sq4[9],sq5[9],sq6[9],sq7[9],sq8[9],sq9[9];
int psq1[9],psq2[9],psq3[9],psq4[9],psq5[9],psq6[9],psq7[9],psq8[9],psq9[9];
int pl1[9],pl2[9],pl3[9],pl4[9],pl5[9],pl6[9],pl7[9],pl8[9],pl9[9];//liniile de tip pos
int pc1[9],pc2[9],pc3[9],pc4[9],pc5[9],pc6[9],pc7[9],pc8[9],pc9[9];//coloanele de tip pos
int c1[9],c2[9],c3[9],c4[9],c5[9],c6[9],c7[9],c8[9],c9[9];
int o1[9],o2[9],o3[9],o4[9],o5[9],o6[9],o7[9],o8[9],o9[9];

void creareposibilitati(int tablou[9][9], int numar);//astea 2 se ocupa cu matricele
void eliminarePosibilitati(int tablou[9][9], int numar);//pentru fiecare numar
void scriefunctia(int a[]);
void initializezValori(); //creeaza liiniile si coloanele;
void verificValori();
void modificarenum(int p[9][9],int numar);
void squareModif(int p[9][9]);
void muncaGrea2(int p[9][9]);
void sqr1(int p[9][9]);
void sqr2(int p[9][9]);
void sqr3(int p[9][9]);
void sqr4(int p[9][9]);
void sqr5(int p[9][9]);
void sqr6(int p[9][9]);
void sqr7(int p[9][9]);
void sqr8(int p[9][9]);
void sqr9(int p[9][9]);
void revsqr1(int p[9][9]);//umplul unicul spatiu gold cu cifra
void revsqr2(int p[9][9]);
void revsqr3(int p[9][9]);
void revsqr4(int p[9][9]);
void revsqr5(int p[9][9]);
void revsqr6(int p[9][9]);
void revsqr7(int p[9][9]);
void revsqr8(int p[9][9]);
void revsqr9(int p[9][9]);

int main()
{

    int x,y;
    for(int i=0;i<9;i++)
        for(int j =0;j<9;j++){
            fin>>num[i][j];
    }
    scrietabloul(num);

     muncaGrea();
     fout<<endl;

     if(checkforsame(sq1)==true &&
        checkforsame(sq2)==true &&
        checkforsame(sq3)==true &&
        checkforsame(sq4)==true &&
        checkforsame(sq5)==true &&
        checkforsame(sq6)==true &&
        checkforsame(sq7)==true &&
        checkforsame(sq8)==true &&
        checkforsame(sq9)==true)
        {
            fout<<"sarmale";
            sqGood=1;
        }else
        fout<<"nu sarmale"<<endl;

        initializezValori();
        verificValori();
        fout<<endl<<"Patrate:"<<sqGood<<endl<<"Linii:"<<lineGood<<endl<<"Coloane:"<<colGood;

        if(sqGood==1 && lineGood==1 &&colGood==1)
            fout<<endl<<"Ai rezolvat corect sudoku!"<<endl;
        else
            fout<<endl<<"Nu ai rezolvat corect sudoku!"<<endl;
    for(int z=0;z<30;z++){
        creareposibilitati(pos_1,1);    //creeze matricele
        creareposibilitati(pos_2,2);
        creareposibilitati(pos_3,3);
        creareposibilitati(pos_4,4);
        creareposibilitati(pos_5,5);
        creareposibilitati(pos_6,6);
        creareposibilitati(pos_7,7);
        creareposibilitati(pos_8,8);
        creareposibilitati(pos_9,9);
        fout<<endl;
        eliminarePosibilitati(pos_1,1); //elimin spatiile pe care
        eliminarePosibilitati(pos_2,2); //nu poate sta nr
        eliminarePosibilitati(pos_3,3);
        eliminarePosibilitati(pos_4,4);
        eliminarePosibilitati(pos_5,5);
        eliminarePosibilitati(pos_6,6);
        eliminarePosibilitati(pos_7,7);
        eliminarePosibilitati(pos_8,8);
        eliminarePosibilitati(pos_9,9);
        scrietabloul(pos_1);
        muncaGrea2(pos_1);

        modificarenum(pos_1,1);
        modificarenum(pos_2,2);
        modificarenum(pos_3,3);
        modificarenum(pos_4,4);
        modificarenum(pos_5,5);
        modificarenum(pos_6,6);
        modificarenum(pos_7,7);
        modificarenum(pos_8,8);
        modificarenum(pos_9,9);}
        scrietabloul(num);

        //fout<<"Pt pos1";
        /*scrietabloul(pos_1);
        fout<<"Pt pos2";
        scrietabloul(pos_2);
        fout<<"Pt pos3";
        scrietabloul(pos_3);
        fout<<"Pt pos4";
        scrietabloul(pos_4);
        fout<<"Pt pos5";
        scrietabloul(pos_5);
        fout<<"Pt pos6";
        scrietabloul(pos_6);
        fout<<"Pt pos7";
        scrietabloul(pos_7);
        fout<<"Pt pos8";
        scrietabloul(pos_8);
        fout<<"Pt pos9";
        scrietabloul(pos_9);*/
    return 0;
}

void transp1(int f[],int g[],int sq1[]){
     sq1[0]=num[f[0]][g[0]];
     sq1[1]=num[f[0]][g[1]];
     sq1[2]=num[f[0]][g[2]];
     sq1[3]=num[f[1]][g[0]];
     sq1[4]=num[f[1]][g[1]];
     sq1[5]=num[f[1]][g[2]];
     sq1[6]=num[f[2]][g[0]];
     sq1[7]=num[f[2]][g[1]];
     sq1[8]=num[f[2]][g[2]];

}
void muncaGrea(){
     sq1[0]=num[0][0];
     sq1[1]=num[0][1];
     sq1[2]=num[0][2];
     sq1[3]=num[1][0];
     sq1[4]=num[1][1];
     sq1[5]=num[1][2];
     sq1[6]=num[2][0];
     sq1[7]=num[2][1];
     sq1[8]=num[2][2];
    int n1=3;
    int y1=0;
     sq2[0]=num[0+y1][0+n1];
     sq2[1]=num[0+y1][1+n1];
     sq2[2]=num[0+y1][2+n1];
     sq2[3]=num[1+y1][0+n1];
     sq2[4]=num[1+y1][1+n1];
     sq2[5]=num[1+y1][2+n1];
     sq2[6]=num[2+y1][0+n1];
     sq2[7]=num[2+y1][1+n1];
     sq2[8]=num[2+y1][2+n1];

     n1=6;
     sq3[0]=num[0+y1][0+n1];
     sq3[1]=num[0+y1][1+n1];
     sq3[2]=num[0+y1][2+n1];
     sq3[3]=num[1+y1][0+n1];
     sq3[4]=num[1+y1][1+n1];
     sq3[5]=num[1+y1][2+n1];
     sq3[6]=num[2+y1][0+n1];
     sq3[7]=num[2+y1][1+n1];
     sq3[8]=num[2+y1][2+n1];

     n1=0;
     y1=3;
     sq4[0]=num[0+y1][0+n1];
     sq4[1]=num[0+y1][1+n1];
     sq4[2]=num[0+y1][2+n1];
     sq4[3]=num[1+y1][0+n1];
     sq4[4]=num[1+y1][1+n1];
     sq4[5]=num[1+y1][2+n1];
     sq4[6]=num[2+y1][0+n1];
     sq4[7]=num[2+y1][1+n1];
     sq4[8]=num[2+y1][2+n1];

     n1=3;
     sq5[0]=num[0+y1][0+n1];
     sq5[1]=num[0+y1][1+n1];
     sq5[2]=num[0+y1][2+n1];
     sq5[3]=num[1+y1][0+n1];
     sq5[4]=num[1+y1][1+n1];
     sq5[5]=num[1+y1][2+n1];
     sq5[6]=num[2+y1][0+n1];
     sq5[7]=num[2+y1][1+n1];
     sq5[8]=num[2+y1][2+n1];

     n1=6;
     sq6[0]=num[0+y1][0+n1];
     sq6[1]=num[0+y1][1+n1];
     sq6[2]=num[0+y1][2+n1];
     sq6[3]=num[1+y1][0+n1];
     sq6[4]=num[1+y1][1+n1];
     sq6[5]=num[1+y1][2+n1];
     sq6[6]=num[2+y1][0+n1];
     sq6[7]=num[2+y1][1+n1];
     sq6[8]=num[2+y1][2+n1];
     y1=6;
     n1=0;

     sq7[0]=num[0+y1][0+n1];
     sq7[1]=num[0+y1][1+n1];
     sq7[2]=num[0+y1][2+n1];
     sq7[3]=num[1+y1][0+n1];
     sq7[4]=num[1+y1][1+n1];
     sq7[5]=num[1+y1][2+n1];
     sq7[6]=num[2+y1][0+n1];
     sq7[7]=num[2+y1][1+n1];
     sq7[8]=num[2+y1][2+n1];
     n1=3;
     sq8[0]=num[0+y1][0+n1];
     sq8[1]=num[0+y1][1+n1];
     sq8[2]=num[0+y1][2+n1];
     sq8[3]=num[1+y1][0+n1];
     sq8[4]=num[1+y1][1+n1];
     sq8[5]=num[1+y1][2+n1];
     sq8[6]=num[2+y1][0+n1];
     sq8[7]=num[2+y1][1+n1];
     sq8[8]=num[2+y1][2+n1];
     n1=6;
     sq9[0]=num[0+y1][0+n1];
     sq9[1]=num[0+y1][1+n1];
     sq9[2]=num[0+y1][2+n1];
     sq9[3]=num[1+y1][0+n1];
     sq9[4]=num[1+y1][1+n1];
     sq9[5]=num[1+y1][2+n1];
     sq9[6]=num[2+y1][0+n1];
     sq9[7]=num[2+y1][1+n1];
     sq9[8]=num[2+y1][2+n1];
}
void scriefunctia(int a[]){
for(int ij=0;ij<9;ij++){
        fout<<a[ij]<<" ";
        }
        fout<<endl;
        fout<<endl;
            }
bool checkforsame(int a[]){
    int counter=1;
    int times=0;
    for(int h=0;h<9;h++){
    for(int i=0;i<9;i++){
        if(a[i]==counter){
            //cout<<" da";
            times++;
        }
    }
    if(times!=1){
        //cout<<"FALSE";
        return false;
        }
        counter++;
        times=0;
        //cout<<endl;

    }
        return true;
    }
void linii(int a[], int i){
    a[0]=num[i][0];
    a[1]=num[i][1];
    a[2]=num[i][2];
    a[3]=num[i][3];
    a[4]=num[i][4];
    a[5]=num[i][5];
    a[6]=num[i][6];
    a[7]=num[i][7];
    a[8]=num[i][8];
    a[9]=num[i][9];
}
void coloane(int a[], int i){
    a[0]=num[0][i];
    a[1]=num[1][i];
    a[2]=num[2][i];
    a[3]=num[3][i];
    a[4]=num[4][i];
    a[5]=num[5][i];
    a[6]=num[6][i];
    a[7]=num[7][i];
    a[8]=num[8][i];
    a[9]=num[9][i];
}
void initializezValori(){
    linii(o1,0);
    linii(o2,1);
    linii(o3,2);
    linii(o4,3);
    linii(o5,4);
    linii(o6,5);
    linii(o7,6);
    linii(o8,7);
    linii(o9,8);

    coloane(c1,0);
    coloane(c2,1);
    coloane(c3,2);
    coloane(c4,3);
    coloane(c5,4);
    coloane(c6,5);
    coloane(c7,6);
    coloane(c8,7);
    coloane(c9,8);
}
void verificValori(){
    if(checkforsame(o1)&&
       checkforsame(o2)&&
       checkforsame(o3)&&
       checkforsame(o4)&&
       checkforsame(o5)&&
       checkforsame(o6)&&
       checkforsame(o7)&&
       checkforsame(o8)&&
       checkforsame(o9))
       lineGood=1;

    if(checkforsame(c1)&&
       checkforsame(c2)&&
       checkforsame(c3)&&
       checkforsame(c4)&&
       checkforsame(c5)&&
       checkforsame(c6)&&
       checkforsame(c7)&&
       checkforsame(c8)&&
       checkforsame(c9))
        colGood=1;

}
void creareposibilitati(int tablou[9][9], int numar){
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++){
            if(num[i][j]==0){
                tablou[i][j]=-2;
            }else if(num[i][j]!=0 && num[i][j]!=numar)
                tablou[i][j]=-3;
            else
                tablou[i][j]=-6;
        }
}
void scrietabloul(int a[9][9]){
    fout<<endl;
    for(int ii=0;ii<9;ii++)
 {
    for(int jj=0;jj<9;jj++)
       fout<<a[ii][jj]<<" ";
fout<<"\n";
}
}
void eliminarePosibilitati(int tablou[9][9], int numar){
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++){
            if(tablou[i][j]==-6)
            {
               for(int h=0;h<9;h++)
                    if(tablou[h][j]==-2)//stanga dreapta cred
                        tablou[h][j]=-4;

               for(int e=0;e<9;e++)
                    if(tablou[i][e]==-2)//sus jos cred
                        tablou[i][e]=-4;

                if(i<3 && j<3)
                    sqr1(tablou);

                if(i<3 && j>=3 && j<6)
                    sqr2(tablou);

                if(i<3 && j>=6)
                    sqr3(tablou);
                if(i>=3 && i<6 && j<3)
                    sqr4(tablou);

                if(i>=3 && i<6 && j>=3 && j<6)
                    sqr5(tablou);

                if(i>=3 && i<6 && j>=6)
                    sqr6(tablou);

                if(i>=6 && j<3)
                    sqr7(tablou);

                if(i>=6 && j>=3 && j<6)
                    sqr8(tablou);

                if(i>=6 && j>=6)
                    sqr9(tablou);
            }
        }

}
void modificarenum(int p[9][9],int numar){
    int countter=0;
    int coord_i=0;
    int coord_j=0;
    int coord_i2=0;
    int coord_j2=0;
    int countter2=0;

    for(int i=0;i<9;i++){   //Verifica de la stanga la dreapta
        for(int j=0;j<9;j++){
           if(p[i][j]==-2){
                countter++;
                coord_i=i;
                coord_j=j;}
        }
        if(countter==1){
            num[coord_i][coord_j]=numar;
        creareposibilitati(p,numar);
        eliminarePosibilitati(p,numar);

        countter=0;}
    }
    for(int ii=0;ii<9;ii++){   //Verifica de sus in jos
        for(int jj=0;jj<9;jj++){
           if(p[jj][ii]==-2){
                countter2++;
                coord_i2=jj;
                coord_j2=ii;}
        }
        if(countter2==1){
            num[coord_i2][coord_j2]=numar;
        creareposibilitati(p,numar);
        eliminarePosibilitati(p,numar);

        countter2=0;}
    }
    //acum verific daca in vreun patrat am un singur loc
    //unde pot pune o anumita cifra;

    eliminarePosibilitati(p,numar);
    muncaGrea2(p);
        if(contineNr(psq1))
            revsqr1(p);

        if(contineNr(psq2))
            revsqr2(p);

        if(contineNr(psq3))
            revsqr3(p);

        if(contineNr(psq4))
            revsqr4(p);

        if(contineNr(psq5))
            revsqr5(p);

        if(contineNr(psq6))
            revsqr6(p);

        if(contineNr(psq7))
            revsqr7(p);

        if(contineNr(psq8))
            revsqr8(p);

        if(contineNr(psq9))
            revsqr9(p);
    //acum pentru fiecare -6 inlocuiesc cu numar in num[][]
    for(int xx=0;xx<9;xx++)
        for(int yy=0;yy<9;yy++){
            if(p[xx][yy]==-6){
                num[xx][yy]=numar;
                eliminarePosibilitati(p,numar);}
    }
    /*//acum verific daca pe o coloana este doar un -2
    creareposibilitati(p,numar);
    eliminarePosibilitati(p,numar);
    muncaGrea2(p);

    if(contineNr(pl1))
        for(int x1=0;x1<9;x1++){
            if(pl1[x1]==-2)
                num[0][x1]=numar;}

    if(contineNr(pl2))
        for(int x2=0;x2<9;x2++){
            if(pl2[x2]==-2)
                num[1][x2]=numar;}

    if(contineNr(pl3))
        for(int x3=0;x3<9;x3++){
            if(pl3[x3]==-2)
                num[2][x3]=numar;
                num[2][x3]=numar;}

    if(contineNr(pl4))
        for(int x4=0;x4<9;x4++){
            if(pl4[x4]==-2){
                num[3][x4]=numar;
                p[3][x4]=-6;
                eliminarePosibilitati(p,numar);}}

    if(contineNr(pl5))
        for(int x5=0;x5<9;x5++){
            if(pl5[x5]==-2){
                num[4][x5]=numar;
                p[4][x5]=-6;
                eliminarePosibilitati(p,numar);}}

    if(contineNr(pl6))
        for(int x6=0;x6<9;x6++){
            if(pl6[x6]==-2){
                num[5][x6]=numar;
                p[5][x6]=-6;
                eliminarePosibilitati(p,numar);}}

    if(contineNr(pl7))
        for(int x7=0;x7<9;x7++){
            if(pl7[x7]==-2){
                num[6][x7]=numar;
                p[6][x7]=-6;
                eliminarePosibilitati(p,numar);}}

    fout<<"NR"<<numar<<"are contine nr linia  8="<<contineNr(pl8)<<endl;
    if(contineNr(pl8))
        for(int x8=0;x8<9;x8++){
            if(pl8[x8]==-2){
                num[7][x8]=numar;
                p[7][x8]=-6;}}

    if(contineNr(pl9))
        for(int x9=0;x9<9;x9++){
            if(pl9[x9]==-2){
                num[8][x9]=numar;
                p[8][x9]=-6;}}
    //acum pt coloane

    if(contineNr(pc1))
        for(int x1=0;x1<9;x1++){
            if(pl1[x1]==-2)
                num[x1][0]=numar;}

    if(contineNr(pc2))
        for(int x2=0;x2<9;x2++){
            if(pl2[x2]==-2)
                num[x2][1]=numar;}

    if(contineNr(pc3))
        for(int x3=0;x3<9;x3++){
            if(pl3[x3]==-2)
                num[x3][2]=numar;}

    if(contineNr(pc4))
        for(int x4=0;x4<9;x4++){
            if(pl4[x4]==-2)
                num[x4][3]=numar;}

    if(contineNr(pc5))
        for(int x5=0;x5<9;x5++){
            if(pl5[x5]==-2)
                num[x5][4]=numar;}

    if(contineNr(pc6))
        for(int x6=0;x6<9;x6++){
            if(pl6[x6]==-2)
                num[x6][5]=numar;}

    if(contineNr(pc7))
        for(int x7=0;x7<9;x7++){
            if(pl7[x7]==-2)
                num[x7][6]=numar;}

    if(contineNr(pc8))
        for(int x8=0;x8<9;x8++){
            if(pl8[x8]==-2)
                num[x8][7]=numar;}
fout<<"NR"<<numar<<"are contine nr col  9="<<contineNr(pc9)<<endl;
for(int xj=0;xj<9;xj++)
    fout<<" "<<pc9[xj];

    if(contineNr(pc9)){
            fout<<"Adevarat la numarul "<<numar<<endl;
        for(int x9=0;x9<9;x9++){
            if(pl9[x9]==-2)
                num[x9][8]=numar;}}*/
    fctlinie(p,numar);
    fctcol(p,numar);

}
void sqr1(int p[9][9]){
    if(p[0][0]==-2)
        p[0][0]=-4;

    if(p[0][1]==-2)
        p[0][1]=-4;

    if(p[0][2]==-2)
        p[0][2]=-4;
    //randul din mjl
    if(p[1][0]==-2)
        p[1][0]=-4;

    if(p[1][1]==-2)
        p[1][1]=-4;

    if(p[1][2]==-2)
        p[1][2]=-4;
    //randul de jos
    if(p[2][0]==-2)
        p[2][0]=-4;

    if(p[2][1]==-2)
        p[2][1]=-4;

    if(p[2][2]==-2)
        p[2][2]=-4;
}
void sqr2(int p[9][9]){
    int x=0;
    int y=3;
    if(p[0+x][0+y]==-2)
        p[0+x][0+y]=-4;

    if(p[0+x][1+y]==-2)
        p[0+x][1+y]=-4;

    if(p[0+x][2+y]==-2)
        p[0+x][2+y]=-4;
    //randul din mjl
    if(p[1+x][0+y]==-2)
        p[1+x][0+y]=-4;

    if(p[1+x][1+y]==-2)
        p[1+x][1+y]=-4;

    if(p[1+x][2+y]==-2)
        p[1+x][2+y]=-4;
    //randul de jos
    if(p[2+x][0+y]==-2)
        p[2+x][0+y]=-4;

    if(p[2+x][1+y]==-2)
        p[2+x][1+y]=-4;

    if(p[2+x][2+y]==-2)
        p[2+x][2+y]=-4;
}
void sqr3(int p[9][9]){
    int x=0;
    int y=6;
    if(p[0+x][0+y]==-2)
        p[0+x][0+y]=-4;

    if(p[0+x][1+y]==-2)
        p[0+x][1+y]=-4;

    if(p[0+x][2+y]==-2)
        p[0+x][2+y]=-4;
    //randul din mjl
    if(p[1+x][0+y]==-2)
        p[1+x][0+y]=-4;

    if(p[1+x][1+y]==-2)
        p[1+x][1+y]=-4;

    if(p[1+x][2+y]==-2)
        p[1+x][2+y]=-4;
    //randul de jos
    if(p[2+x][0+y]==-2)
        p[2+x][0+y]=-4;

    if(p[2+x][1+y]==-2)
        p[2+x][1+y]=-4;

    if(p[2+x][2+y]==-2)
        p[2+x][2+y]=-4;
}
void sqr4(int p[9][9]){
    int x=3;
    int y=0;
    if(p[0+x][0+y]==-2)
        p[0+x][0+y]=-4;

    if(p[0+x][1+y]==-2)
        p[0+x][1+y]=-4;

    if(p[0+x][2+y]==-2)
        p[0+x][2+y]=-4;
    //randul din mjl
    if(p[1+x][0+y]==-2)
        p[1+x][0+y]=-4;

    if(p[1+x][1+y]==-2)
        p[1+x][1+y]=-4;

    if(p[1+x][2+y]==-2)
        p[1+x][2+y]=-4;
    //randul de jos
    if(p[2+x][0+y]==-2)
        p[2+x][0+y]=-4;

    if(p[2+x][1+y]==-2)
        p[2+x][1+y]=-4;

    if(p[2+x][2+y]==-2)
        p[2+x][2+y]=-4;
}
void sqr5(int p[9][9]){
    int x=3;
    int y=3;
    if(p[0+x][0+y]==-2)
        p[0+x][0+y]=-4;

    if(p[0+x][1+y]==-2)
        p[0+x][1+y]=-4;

    if(p[0+x][2+y]==-2)
        p[0+x][2+y]=-4;
    //randul din mjl
    if(p[1+x][0+y]==-2)
        p[1+x][0+y]=-4;

    if(p[1+x][1+y]==-2)
        p[1+x][1+y]=-4;

    if(p[1+x][2+y]==-2)
        p[1+x][2+y]=-4;
    //randul de jos
    if(p[2+x][0+y]==-2)
        p[2+x][0+y]=-4;

    if(p[2+x][1+y]==-2)
        p[2+x][1+y]=-4;

    if(p[2+x][2+y]==-2)
        p[2+x][2+y]=-4;
}
void sqr6(int p[9][9]){
    int x=3;
    int y=6;
    if(p[0+x][0+y]==-2)
        p[0+x][0+y]=-4;

    if(p[0+x][1+y]==-2)
        p[0+x][1+y]=-4;

    if(p[0+x][2+y]==-2)
        p[0+x][2+y]=-4;
    //randul din mjl
    if(p[1+x][0+y]==-2)
        p[1+x][0+y]=-4;

    if(p[1+x][1+y]==-2)
        p[1+x][1+y]=-4;

    if(p[1+x][2+y]==-2)
        p[1+x][2+y]=-4;
    //randul de jos
    if(p[2+x][0+y]==-2)
        p[2+x][0+y]=-4;

    if(p[2+x][1+y]==-2)
        p[2+x][1+y]=-4;

    if(p[2+x][2+y]==-2)
        p[2+x][2+y]=-4;
}
void sqr7(int p[9][9]){
    int x=6;
    int y=0;
    if(p[0+x][0+y]==-2)
        p[0+x][0+y]=-4;

    if(p[0+x][1+y]==-2)
        p[0+x][1+y]=-4;

    if(p[0+x][2+y]==-2)
        p[0+x][2+y]=-4;
    //randul din mjl
    if(p[1+x][0+y]==-2)
        p[1+x][0+y]=-4;

    if(p[1+x][1+y]==-2)
        p[1+x][1+y]=-4;

    if(p[1+x][2+y]==-2)
        p[1+x][2+y]=-4;
    //randul de jos
    if(p[2+x][0+y]==-2)
        p[2+x][0+y]=-4;

    if(p[2+x][1+y]==-2)
        p[2+x][1+y]=-4;

    if(p[2+x][2+y]==-2)
        p[2+x][2+y]=-4;
}
void sqr8(int p[9][9]){
    int x=6;
    int y=3;
    if(p[0+x][0+y]==-2)
        p[0+x][0+y]=-4;

    if(p[0+x][1+y]==-2)
        p[0+x][1+y]=-4;

    if(p[0+x][2+y]==-2)
        p[0+x][2+y]=-4;
    //randul din mjl
    if(p[1+x][0+y]==-2)
        p[1+x][0+y]=-4;

    if(p[1+x][1+y]==-2)
        p[1+x][1+y]=-4;

    if(p[1+x][2+y]==-2)
        p[1+x][2+y]=-4;
    //randul de jos
    if(p[2+x][0+y]==-2)
        p[2+x][0+y]=-4;

    if(p[2+x][1+y]==-2)
        p[2+x][1+y]=-4;

    if(p[2+x][2+y]==-2)
        p[2+x][2+y]=-4;
}
void sqr9(int p[9][9]){
    int x=6;
    int y=6;
    if(p[0+x][0+y]==-2)
        p[0+x][0+y]=-4;

    if(p[0+x][1+y]==-2)
        p[0+x][1+y]=-4;

    if(p[0+x][2+y]==-2)
        p[0+x][2+y]=-4;
    //randul din mjl
    if(p[1+x][0+y]==-2)
        p[1+x][0+y]=-4;

    if(p[1+x][1+y]==-2)
        p[1+x][1+y]=-4;

    if(p[1+x][2+y]==-2)
        p[1+x][2+y]=-4;
    //randul de jos
    if(p[2+x][0+y]==-2)
        p[2+x][0+y]=-4;

    if(p[2+x][1+y]==-2)
        p[2+x][1+y]=-4;

    if(p[2+x][2+y]==-2)
        p[2+x][2+y]=-4;
}
bool contineNr(int a[]){
    int spatiigoale=0;
    for(int i = 0;i<9;i++){
        if(a[i]==-2)
            spatiigoale++;}

    //fout<<"Spatii goale "<<spatiigoale;


    if(spatiigoale==1)
            return true;
        else
            return false;

}
void muncaGrea2(int p[9][9]){
     psq1[0]=p[0][0];
     psq1[1]=p[0][1];
     psq1[2]=p[0][2];
     psq1[3]=p[1][0];
     psq1[4]=p[1][1];
     psq1[5]=p[1][2];
     psq1[6]=p[2][0];
     psq1[7]=p[2][1];
     psq1[8]=p[2][2];
    int n1=3;
    int y1=0;
     psq2[0]=p[0+y1][0+n1];
     psq2[1]=p[0+y1][1+n1];
     psq2[2]=p[0+y1][2+n1];
     psq2[3]=p[1+y1][0+n1];
     psq2[4]=p[1+y1][1+n1];
     psq2[5]=p[1+y1][2+n1];
     psq2[6]=p[2+y1][0+n1];
     psq2[7]=p[2+y1][1+n1];
     psq2[8]=p[2+y1][2+n1];

     n1=6;
     psq3[0]=p[0+y1][0+n1];
     psq3[1]=p[0+y1][1+n1];
     psq3[2]=p[0+y1][2+n1];
     psq3[3]=p[1+y1][0+n1];
     psq3[4]=p[1+y1][1+n1];
     psq3[5]=p[1+y1][2+n1];
     psq3[6]=p[2+y1][0+n1];
     psq3[7]=p[2+y1][1+n1];
     psq3[8]=p[2+y1][2+n1];

     n1=0;
     y1=3;
     psq4[0]=p[0+y1][0+n1];
     psq4[1]=p[0+y1][1+n1];
     psq4[2]=p[0+y1][2+n1];
     psq4[3]=p[1+y1][0+n1];
     psq4[4]=p[1+y1][1+n1];
     psq4[5]=p[1+y1][2+n1];
     psq4[6]=p[2+y1][0+n1];
     psq4[7]=p[2+y1][1+n1];
     psq4[8]=p[2+y1][2+n1];

     n1=3;
     psq5[0]=p[0+y1][0+n1];
     psq5[1]=p[0+y1][1+n1];
     psq5[2]=p[0+y1][2+n1];
     psq5[3]=p[1+y1][0+n1];
     psq5[4]=p[1+y1][1+n1];
     psq5[5]=p[1+y1][2+n1];
     psq5[6]=p[2+y1][0+n1];
     psq5[7]=p[2+y1][1+n1];
     psq5[8]=p[2+y1][2+n1];

     n1=6;
     psq6[0]=p[0+y1][0+n1];
     psq6[1]=p[0+y1][1+n1];
     psq6[2]=p[0+y1][2+n1];
     psq6[3]=p[1+y1][0+n1];
     psq6[4]=p[1+y1][1+n1];
     psq6[5]=p[1+y1][2+n1];
     psq6[6]=p[2+y1][0+n1];
     psq6[7]=p[2+y1][1+n1];
     psq6[8]=p[2+y1][2+n1];
     y1=6;
     n1=0;

     psq7[0]=p[0+y1][0+n1];
     psq7[1]=p[0+y1][1+n1];
     psq7[2]=p[0+y1][2+n1];
     psq7[3]=p[1+y1][0+n1];
     psq7[4]=p[1+y1][1+n1];
     psq7[5]=p[1+y1][2+n1];
     psq7[6]=p[2+y1][0+n1];
     psq7[7]=p[2+y1][1+n1];
     psq7[8]=p[2+y1][2+n1];
     n1=3;
     psq8[0]=p[0+y1][0+n1];
     psq8[1]=p[0+y1][1+n1];
     psq8[2]=p[0+y1][2+n1];
     psq8[3]=p[1+y1][0+n1];
     psq8[4]=p[1+y1][1+n1];
     psq8[5]=p[1+y1][2+n1];
     psq8[6]=p[2+y1][0+n1];
     psq8[7]=p[2+y1][1+n1];
     psq8[8]=p[2+y1][2+n1];
     n1=6;
     psq9[0]=p[0+y1][0+n1];
     psq9[1]=p[0+y1][1+n1];
     psq9[2]=p[0+y1][2+n1];
     psq9[3]=p[1+y1][0+n1];
     psq9[4]=p[1+y1][1+n1];
     psq9[5]=p[1+y1][2+n1];
     psq9[6]=p[2+y1][0+n1];
     psq9[7]=p[2+y1][1+n1];
     psq9[8]=p[2+y1][2+n1];
     //acum pentru linii si coloane
     linii_pos(pl1,1,p);
     linii_pos(pl2,2,p);
     linii_pos(pl3,3,p);
     linii_pos(pl4,4,p);
     linii_pos(pl5,5,p);
     linii_pos(pl6,6,p);
     linii_pos(pl7,7,p);
     linii_pos(pl8,8,p);
     linii_pos(pl9,9,p);

     coloane_pos(pc1,1,p);
     coloane_pos(pc2,2,p);
     coloane_pos(pc3,3,p);
     coloane_pos(pc4,4,p);
     coloane_pos(pc5,5,p);
     coloane_pos(pc6,6,p);
     coloane_pos(pc7,7,p);
     coloane_pos(pc8,8,p);
     coloane_pos(pc9,9,p);
    //fout<<"Linia 1";
     //scriefunctia(pl1);
    //fout<<"Linia 2";
     //scriefunctia(pl2);
     //fout<<"Linia 3";
     //scriefunctia(pl3);
     //fout<<"Linia 4";
     //scriefunctia(pl4);
}
void revsqr1(int p[9][9]){
    if(p[0][0]==-2)
        p[0][0]=-6;

    if(p[0][1]==-2)
        p[0][1]=-6;

    if(p[0][2]==-2)
        p[0][2]=-6;
    //randul din mjl
    if(p[1][0]==-2)
        p[1][0]=-6;

    if(p[1][1]==-2)
        p[1][1]=-6;

    if(p[1][2]==-2)
        p[1][2]=-6;
    //randul de jos
    if(p[2][0]==-2)
        p[2][0]=-6;

    if(p[2][1]==-2)
        p[2][1]=-6;

    if(p[2][2]==-2)
        p[2][2]=-6;
}
void revsqr2(int p[9][9]){
    int x=0;
    int y=3;
    if(p[0+x][0+y]==-2)
        p[0+x][0+y]=-6;

    if(p[0+x][1+y]==-2)
        p[0+x][1+y]=-6;

    if(p[0+x][2+y]==-2)
        p[0+x][2+y]=-6;
    //randul din mjl
    if(p[1+x][0+y]==-2)
        p[1+x][0+y]=-6;

    if(p[1+x][1+y]==-2)
        p[1+x][1+y]=-6;

    if(p[1+x][2+y]==-2)
        p[1+x][2+y]=-6;
    //randul de jos
    if(p[2+x][0+y]==-2)
        p[2+x][0+y]=-6;

    if(p[2+x][1+y]==-2)
        p[2+x][1+y]=-6;

    if(p[2+x][2+y]==-2)
        p[2+x][2+y]=-6;
}
void revsqr3(int p[9][9]){
    int x=0;
    int y=6;
    if(p[0+x][0+y]==-2)
        p[0+x][0+y]=-6;

    if(p[0+x][1+y]==-2)
        p[0+x][1+y]=-6;

    if(p[0+x][2+y]==-2)
        p[0+x][2+y]=-6;
    //randul din mjl
    if(p[1+x][0+y]==-2)
        p[1+x][0+y]=-6;

    if(p[1+x][1+y]==-2)
        p[1+x][1+y]=-6;

    if(p[1+x][2+y]==-2)
        p[1+x][2+y]=-6;
    //randul de jos
    if(p[2+x][0+y]==-2)
        p[2+x][0+y]=-6;

    if(p[2+x][1+y]==-2)
        p[2+x][1+y]=-6;

    if(p[2+x][2+y]==-2)
        p[2+x][2+y]=-6;
}
void revsqr4(int p[9][9]){
    int x=3;
    int y=0;
    if(p[0+x][0+y]==-2)
        p[0+x][0+y]=-6;

    if(p[0+x][1+y]==-2)
        p[0+x][1+y]=-6;

    if(p[0+x][2+y]==-2)
        p[0+x][2+y]=-6;
    //randul din mjl
    if(p[1+x][0+y]==-2)
        p[1+x][0+y]=-6;

    if(p[1+x][1+y]==-2)
        p[1+x][1+y]=-6;

    if(p[1+x][2+y]==-2)
        p[1+x][2+y]=-6;
    //randul de jos
    if(p[2+x][0+y]==-2)
        p[2+x][0+y]=-6;

    if(p[2+x][1+y]==-2)
        p[2+x][1+y]=-6;

    if(p[2+x][2+y]==-2)
        p[2+x][2+y]=-6;
}
void revsqr5(int p[9][9]){
    int x=3;
    int y=3;
    if(p[0+x][0+y]==-2)
        p[0+x][0+y]=-6;

    if(p[0+x][1+y]==-2)
        p[0+x][1+y]=-6;

    if(p[0+x][2+y]==-2)
        p[0+x][2+y]=-6;
    //randul din mjl
    if(p[1+x][0+y]==-2)
        p[1+x][0+y]=-6;

    if(p[1+x][1+y]==-2)
        p[1+x][1+y]=-6;

    if(p[1+x][2+y]==-2)
        p[1+x][2+y]=-6;
    //randul de jos
    if(p[2+x][0+y]==-2)
        p[2+x][0+y]=-6;

    if(p[2+x][1+y]==-2)
        p[2+x][1+y]=-6;

    if(p[2+x][2+y]==-2)
        p[2+x][2+y]=-6;
}
void revsqr6(int p[9][9]){
    int x=3;
    int y=6;
    if(p[0+x][0+y]==-2)
        p[0+x][0+y]=-6;

    if(p[0+x][1+y]==-2)
        p[0+x][1+y]=-6;

    if(p[0+x][2+y]==-2)
        p[0+x][2+y]=-6;
    //randul din mjl
    if(p[1+x][0+y]==-2)
        p[1+x][0+y]=-6;

    if(p[1+x][1+y]==-2)
        p[1+x][1+y]=-6;

    if(p[1+x][2+y]==-2)
        p[1+x][2+y]=-6;
    //randul de jos
    if(p[2+x][0+y]==-2)
        p[2+x][0+y]=-6;

    if(p[2+x][1+y]==-2)
        p[2+x][1+y]=-6;

    if(p[2+x][2+y]==-2)
        p[2+x][2+y]=-6;
}
void revsqr7(int p[9][9]){
    int x=6;
    int y=0;
    if(p[0+x][0+y]==-2)
        p[0+x][0+y]=-6;

    if(p[0+x][1+y]==-2)
        p[0+x][1+y]=-6;

    if(p[0+x][2+y]==-2)
        p[0+x][2+y]=-6;
    //randul din mjl
    if(p[1+x][0+y]==-2)
        p[1+x][0+y]=-6;

    if(p[1+x][1+y]==-2)
        p[1+x][1+y]=-6;

    if(p[1+x][2+y]==-2)
        p[1+x][2+y]=-6;
    //randul de jos
    if(p[2+x][0+y]==-2)
        p[2+x][0+y]=-6;

    if(p[2+x][1+y]==-2)
        p[2+x][1+y]=-6;

    if(p[2+x][2+y]==-2)
        p[2+x][2+y]=-6;
}
void revsqr8(int p[9][9]){
    int x=6;
    int y=3;
    if(p[0+x][0+y]==-2)
        p[0+x][0+y]=-6;

    if(p[0+x][1+y]==-2)
        p[0+x][1+y]=-6;

    if(p[0+x][2+y]==-2)
        p[0+x][2+y]=-6;
    //randul din mjl
    if(p[1+x][0+y]==-2)
        p[1+x][0+y]=-6;

    if(p[1+x][1+y]==-2)
        p[1+x][1+y]=-6;

    if(p[1+x][2+y]==-2)
        p[1+x][2+y]=-6;
    //randul de jos
    if(p[2+x][0+y]==-2)
        p[2+x][0+y]=-6;

    if(p[2+x][1+y]==-2)
        p[2+x][1+y]=-6;

    if(p[2+x][2+y]==-2)
        p[2+x][2+y]=-6;
}
void revsqr9(int p[9][9]){
    int x=6;
    int y=6;
    if(p[0+x][0+y]==-2)
        p[0+x][0+y]=-6;

    if(p[0+x][1+y]==-2)
        p[0+x][1+y]=-6;

    if(p[0+x][2+y]==-2)
        p[0+x][2+y]=-6;
    //randul din mjl
    if(p[1+x][0+y]==-2)
        p[1+x][0+y]=-6;

    if(p[1+x][1+y]==-2)
        p[1+x][1+y]=-6;

    if(p[1+x][2+y]==-2)
        p[1+x][2+y]=-6;
    //randul de jos
    if(p[2+x][0+y]==-2)
        p[2+x][0+y]=-6;

    if(p[2+x][1+y]==-2)
        p[2+x][1+y]=-6;

    if(p[2+x][2+y]==-2)
        p[2+x][2+y]=-6;
}
void linii_pos(int a[], int i, int p[9][9]){
    a[0]=p[i][0];
    a[1]=p[i][1];
    a[2]=p[i][2];
    a[3]=p[i][3];
    a[4]=p[i][4];
    a[5]=p[i][5];
    a[6]=p[i][6];
    a[7]=p[i][7];
    a[8]=p[i][8];

}
void coloane_pos(int a[], int i, int p[9][9]){
    a[0]=p[0][i];
    a[1]=p[1][i];
    a[2]=p[2][i];
    a[3]=p[3][i];
    a[4]=p[4][i];
    a[5]=p[5][i];
    a[6]=p[6][i];
    a[7]=p[7][i];
    a[8]=p[8][i];


}
void fctlinie(int p[9][9],int numar){
    eliminarePosibilitati(p,numar);
    int ct1=0;
    int nr1=0;
    int xcord=-1;
    int ycord=-1;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(p[i][j]==-2){
                xcord=i;
                ycord=j;
                ct1++;
            }
            if(p[i][j]==-6)
                nr1++;
        }
        if(ct1==1){
          p[xcord][ycord]=-6;
          num[xcord][ycord]=numar;
          eliminarePosibilitati(p,numar);
        }
        ct1=0;
    }

}
void fctcol(int p[9][9],int numar){
    eliminarePosibilitati(p,numar);
    int ct1=0;
    int nr1=0;
    int xcord=-1;
    int ycord=-1;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(p[j][i]==-2){
                xcord=j;
                ycord=i;
                ct1++;
            }
            if(p[j][i]==-6)
                nr1++;
        }
        if(ct1==1){
          p[xcord][ycord]=-6;
          num[xcord][ycord]=numar;
          ct1=0;
          eliminarePosibilitati(p,numar);
        }
        ct1=0;
    }

}
