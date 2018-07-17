/*-------------3D Rubik's Cube Simulation-----------------------*/
/*-------------By Prajnesh Shetty And Vikyath Naiga-------------*/
/*-------------SIT, Valachil, Mangalore-------------------------*/

#include<stdio.h>
#include<GL/glut.h>
#include<string.h>

int id1,id2,id3,id4,i=0,j,k;
int toggle=0,set=0,stopstring=0,idleno=0,idlevalue[10];
int fill=0,once=0,turn=0;
int change=0,allfill=0,fill_change=0;

int lfill[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
int rfill[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
int ffill[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
int bfill[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
int ufill[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
int dfill[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};

int lfillog[9]={5,3,3,2,4,4,2,0,2};
int rfillog[9]={2,4,4,1,3,3,0,5,5};
int ffillog[9]={0,5,4,0,2,2,3,3,3};                 //Red 0 Orange 1 Yellow 2 Green 3 Blue 4 White 5
int bfillog[9]={0,1,1,0,5,4,4,4,4};
int ufillog[9]={3,3,5,2,0,5,2,0,0};
int dfillog[9]={1,5,5,2,1,1,1,1,1};

char front_pos[9]={'Y','Y','Y','Y','Y','Y','Y','Y','Y'};
char back_pos[9]={'W','W','W','W','W','W','W','W','W'};
char up_pos[9]={'R','R','R','R','R','R','R','R','R'};
char down_pos[9]={'O','O','O','O','O','O','O','O','O'};
char left_pos[9]={'B','B','B','B','B','B','B','B','B'};
char right_pos[9]={'G','G','G','G','G','G','G','G','G'};
char fg[9];
char bg[9]; 
char ug[9];
char dg[9];
char lg[9];
char rg[9];

char setstr[]={'l','r','u','d','f','b','L','R','U','D','F','B'};      
char pos_arr[1000]="";                                          
char *rev_str;
char sample[1000];

char display1_str[]="Srinivas Institute of Technology";
char display1_str1[]="Valachil,Mangaluru";
char display1_str2[]="Department of Computer Science and Engineering";
char display1_str3[]="COMPUTER GRAPHICS AND VISUALIZATION";
char display1_str4[]="MINI PROJECT";
char display1_str5[]="ON";
char display1_str6[]="RUBIK'S CUBE SIMULATION";
char display1_str7[]="Team Members";
char display1_str8[]="Shetty Prajnesh Shivanath - 4SN15CS082";
char display1_str9[]="Vikyath K. Naiga - 4SN15CS097";
char display1_str10[]="Project Guide";
char display1_str11[]="Mr. Aravind Naik";
char display1_str12[]="Assistant Professor";
char display1_str13[]="Project Co-ordinator";
char display1_str14[]="Mr. Sudharshan K";
char display1_str15[]="Associate Professor";
char display1_str16[]="Press E/e to enter";

char display2_str1[]="Instructions";
char display2_str2[]="Following are the keys used to rotate the cube";
char display2_str3[]="l - LEFT clockwise direction";
char display2_str4[]="r - RIGHT clockwise direction";
char display2_str5[]="u - UP clockwise direction";
char display2_str6[]="d - DOWN clockwise direction";
char display2_str7[]="f - FRONT clockwise direction";
char display2_str8[]="b - BACK clockwise direction";
char display2_str9[]="L - LEFT anti-clockwise direction";
char display2_str10[]="R - RIGHT anti-clockwise direction";
char display2_str11[]="U - UP anti-clockwise direction";
char display2_str12[]="D - DOWN anti-clockwise direction";
char display2_str13[]="F - FRONT anti-clockwise direction";
char display2_str14[]="B - BACK anti-clockwise direction";
char display2_str15[]="Press W/w to demonstrate";

char display3_str1[]="Fill the colors in the given positions keeping the yellow centre in the front and green at the right";
char display3_str2[]="L";
char display3_str3[]="R";
char display3_str4[]="U";
char display3_str5[]="D";
char display3_str6[]="F";
char display3_str7[]="B";
char display3_str8[]="Press S/s to change the position number";
char display3_str9[]="Press T/t for toggling the color";
char display3_str10[]="Press N/n for next page";
char display3_str1_sub[]="Fill the remaining colors first";

char num_str0[]="0";
char num_str1[]="1";
char num_str2[]="2";
char num_str3[]="3";
char num_str4[]="4";
char num_str5[]="5";
char num_str6[]="6";
char num_str7[]="7";
char num_str8[]="8";

char ans_str[]="Press X/x for reset, Y/y for the solution and Q/q to quit";

double rotate_x1=0; 
double rotate_x2=0; 
double rotate_y1=0; 
double rotate_y2=0; 
double rotate_z1=0; 
double rotate_z2=0;

float l[9][3];
float r[9][3];
float u[9][3];
float d[9][3];
float f[9][3];
float b[9][3];
float max_idle;

float v[][3]={
    {-0.6,0.6,0.6},                //FRONT
    {-0.2,0.6,0.6},
    {0.2,0.6,0.6},
    {0.6,0.6,0.6},
    {-0.6,0.2,0.6},
    {-0.2,0.2,0.6},
    {0.2,0.2,0.6},
    {0.6,0.2,0.6},
    {-0.6,-0.2,0.6},
    {-0.2,-0.2,0.6},
    {0.2,-0.2,0.6},
    {0.6,-0.2,0.6},
    {-0.6,-0.6,0.6},
    {-0.2,-0.6,0.6},
    {0.2,-0.6,0.6},
    {0.6,-0.6,0.6},
    
    {0.6,0.6,0.2},                  //RIGHT
    {0.6,0.6,-0.2},
    {0.6,0.6,-0.6},
    {0.6,0.2,0.2},
    {0.6,0.2,-0.2},
    {0.6,0.2,-0.6},
    {0.6,-0.2,0.2},
    {0.6,-0.2,-0.2},
    {0.6,-0.2,-0.6},
    {0.6,-0.6,0.2},
    {0.6,-0.6,-0.2},
    {0.6,-0.6,-0.6},
    
    {-0.6,0.6,-0.6},                //BACK
    {-0.2,0.6,-0.6},
    {0.2,0.6,-0.6},
    {-0.6,0.2,-0.6},
    {-0.2,0.2,-0.6},
    {0.2,0.2,-0.6},
    {-0.6,-0.2,-0.6},
    {-0.2,-0.2,-0.6},
    {0.2,-0.2,-0.6},
    {-0.6,-0.6,-0.6},
    {-0.2,-0.6,-0.6},
    {0.2,-0.6,-0.6},
    
    {-0.6,0.6,0.2},                //LEFT
    {-0.6,0.6,-0.2},
    {-0.6,0.2,0.2},           
    {-0.6,0.2,-0.2},
    {-0.6,-0.2,0.2},                
    {-0.6,-0.2,-0.2},
    {-0.6,-0.6,0.2},                
    {-0.6,-0.6,-0.2},
    
    {-0.2,0.6,-0.2},                //TOP       
    {0.2,0.6,-0.2},
    {-0.2,0.6,0.2},                
    {0.2,0.6,0.2},
    
    {-0.2,-0.6,-0.2},                //BOTTOM       
    {0.2,-0.6,-0.2},
    {-0.2,-0.6,0.2},                
    {0.2,-0.6,0.2}
    
};
    
void swapTwoChar(char *a, char *b){

   char temp;
   temp  = *a;
   *a = *b;
   *b = temp;
}

void leftShiftChar(){                   //swapping according to left clockwise direction
    
    swapTwoChar(&fg[0],&dg[0]);       
    swapTwoChar(&fg[3],&dg[3]);
    swapTwoChar(&fg[6],&dg[6]);
    swapTwoChar(&fg[0],&bg[8]);
    swapTwoChar(&fg[3],&bg[5]);
    swapTwoChar(&fg[6],&bg[2]);
    swapTwoChar(&fg[0],&ug[0]);
    swapTwoChar(&fg[3],&ug[3]);
    swapTwoChar(&fg[6],&ug[6]);
    
    swapTwoChar(&lg[0],&lg[2]);
    swapTwoChar(&lg[0],&lg[8]);
    swapTwoChar(&lg[0],&lg[6]);
    swapTwoChar(&lg[1],&lg[5]);
    swapTwoChar(&lg[1],&lg[7]);
    swapTwoChar(&lg[1],&lg[3]);
    
}

void rightShiftChar(){                   //swapping according to right clockwise direction
    
    swapTwoChar(&fg[2],&ug[2]);       
    swapTwoChar(&fg[5],&ug[5]);
    swapTwoChar(&fg[8],&ug[8]);
    swapTwoChar(&fg[2],&bg[6]);       
    swapTwoChar(&fg[5],&bg[3]);
    swapTwoChar(&fg[8],&bg[0]);
    swapTwoChar(&fg[2],&dg[2]);       
    swapTwoChar(&fg[5],&dg[5]);
    swapTwoChar(&fg[8],&dg[8]);
    
    swapTwoChar(&rg[0],&rg[2]);
    swapTwoChar(&rg[0],&rg[8]);
    swapTwoChar(&rg[0],&rg[6]);
    swapTwoChar(&rg[1],&rg[5]);
    swapTwoChar(&rg[1],&rg[7]);
    swapTwoChar(&rg[1],&rg[3]);
    
}

void upShiftChar(){                   //swapping according to up clockwise direction
    
    swapTwoChar(&fg[0],&lg[0]);       
    swapTwoChar(&fg[1],&lg[1]);
    swapTwoChar(&fg[2],&lg[2]);
    swapTwoChar(&fg[0],&bg[0]);       
    swapTwoChar(&fg[1],&bg[1]);
    swapTwoChar(&fg[2],&bg[2]);
    swapTwoChar(&fg[0],&rg[0]);       
    swapTwoChar(&fg[1],&rg[1]);
    swapTwoChar(&fg[2],&rg[2]);
    
    swapTwoChar(&ug[0],&ug[2]);
    swapTwoChar(&ug[0],&ug[8]);
    swapTwoChar(&ug[0],&ug[6]);
    swapTwoChar(&ug[1],&ug[5]);
    swapTwoChar(&ug[1],&ug[7]);
    swapTwoChar(&ug[1],&ug[3]);
    
}

void downShiftChar(){                   //swapping according to down clockwise direction
    
    swapTwoChar(&fg[6],&rg[6]);       
    swapTwoChar(&fg[7],&rg[7]);
    swapTwoChar(&fg[8],&rg[8]);
    swapTwoChar(&fg[6],&bg[6]);       
    swapTwoChar(&fg[7],&bg[7]);
    swapTwoChar(&fg[8],&bg[8]);
    swapTwoChar(&fg[6],&lg[6]);       
    swapTwoChar(&fg[7],&lg[7]);
    swapTwoChar(&fg[8],&lg[8]);
    
    swapTwoChar(&dg[0],&dg[2]);
    swapTwoChar(&dg[0],&dg[8]);
    swapTwoChar(&dg[0],&dg[6]);
    swapTwoChar(&dg[1],&dg[5]);
    swapTwoChar(&dg[1],&dg[7]);
    swapTwoChar(&dg[1],&dg[3]);
    
}

void frontShiftChar(){                   //swapping according to front clockwise direction
    
    swapTwoChar(&ug[6],&rg[0]);       
    swapTwoChar(&ug[7],&rg[3]);
    swapTwoChar(&ug[8],&rg[6]);
    swapTwoChar(&ug[6],&dg[2]);       
    swapTwoChar(&ug[7],&dg[1]);
    swapTwoChar(&ug[8],&dg[0]);
    swapTwoChar(&ug[6],&lg[8]);       
    swapTwoChar(&ug[7],&lg[5]);
    swapTwoChar(&ug[8],&lg[2]);
    
    swapTwoChar(&fg[0],&fg[2]);
    swapTwoChar(&fg[0],&fg[8]);
    swapTwoChar(&fg[0],&fg[6]);
    swapTwoChar(&fg[1],&fg[5]);
    swapTwoChar(&fg[1],&fg[7]);
    swapTwoChar(&fg[1],&fg[3]);
    
}

void backShiftChar(){                   //swapping according to back clockwise direction
    
    swapTwoChar(&ug[2],&lg[0]);       
    swapTwoChar(&ug[1],&lg[3]);
    swapTwoChar(&ug[0],&lg[6]);
    swapTwoChar(&ug[2],&dg[6]);       
    swapTwoChar(&ug[1],&dg[7]);
    swapTwoChar(&ug[0],&dg[8]);
    swapTwoChar(&ug[2],&rg[8]);       
    swapTwoChar(&ug[1],&rg[5]);
    swapTwoChar(&ug[0],&rg[2]);
    
    swapTwoChar(&bg[0],&bg[2]);
    swapTwoChar(&bg[0],&bg[8]);
    swapTwoChar(&bg[0],&bg[6]);
    swapTwoChar(&bg[1],&bg[5]);
    swapTwoChar(&bg[1],&bg[7]);
    swapTwoChar(&bg[1],&bg[3]);
    
}

int checkCorrectAll(){
        
        int i;
        
        int count_front=0,count_back=0,count_up=0,count_down=0,count_left=0,count_right=0;
        
        for(i=0;i<9;i++)
            if(fg[i]==front_pos[i])
                count_front++;
            
        for(i=0;i<9;i++)
            if(bg[i]==back_pos[i])
                count_back++;
            
        for(i=0;i<9;i++)
            if(ug[i]==up_pos[i])
                count_up++;
            
        for(i=0;i<9;i++)
            if(dg[i]==down_pos[i])
                count_down++;
            
        for(i=0;i<9;i++)
            if(lg[i]==left_pos[i])
                count_left++;
            
        for(i=0;i<9;i++)
            if(rg[i]==right_pos[i])
                count_right++;
            
        if(count_front==9&&count_back==9&&count_up==9&&count_down==9&&count_left==9&&count_right==9)
            return 1;
        else
            return 0;
}

void action(char action_ch){
    
    switch(action_ch){
        
        case 'l':leftShiftChar();
                break;
                
        case 'r':rightShiftChar();
                break;
                
        case 'u':upShiftChar();
                break;
                
        case 'd':downShiftChar();
                break;
                
        case 'f':frontShiftChar();
                break;
                
        case 'b':backShiftChar();
                break;
                
        case 'L':leftShiftChar();
                 leftShiftChar();
                 leftShiftChar();
                break;
                
        case 'R':rightShiftChar();
                 rightShiftChar();
                 rightShiftChar();
                break;
                
        case 'U':upShiftChar();
                 upShiftChar();
                 upShiftChar();
                break;
                
        case 'D':downShiftChar();
                 downShiftChar();
                 downShiftChar();
                break;
                
        case 'F':frontShiftChar();
                 frontShiftChar();
                 frontShiftChar();
                break;
                
        case 'B':backShiftChar();
                 backShiftChar();
                 backShiftChar();
                break;
                
    }
    
}

void rev_action(char action_ch){
    
    switch(action_ch){
        
        case 'L':leftShiftChar();
                break;
                
        case 'R':rightShiftChar();
                break;
                
        case 'U':upShiftChar();
                break;
                
        case 'D':downShiftChar();
                break;
                
        case 'F':frontShiftChar();
                break;
                
        case 'B':backShiftChar();
                break;
                
        case 'l':leftShiftChar();
                 leftShiftChar();
                 leftShiftChar();
                break;
                
        case 'r':rightShiftChar();
                 rightShiftChar();
                 rightShiftChar();
                break;
                
        case 'u':upShiftChar();
                 upShiftChar();
                 upShiftChar();
                break;
                
        case 'd':downShiftChar();
                 downShiftChar();
                 downShiftChar();
                break;
                
        case 'f':frontShiftChar();
                 frontShiftChar();
                 frontShiftChar();
                break;
                
        case 'b':backShiftChar();
                 backShiftChar();
                 backShiftChar();
                break;
                
    }
    
}

void rev_test(char *rev_str){
    
    int i;
    for(i=0;rev_str[i]!='\0';i++)
        rev_action(rev_str[i]);
    
}

char *reverse(char *str){
    int i = 0,j = strlen(str) - 1;
    
    char temp;
 
   while (i < j) {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++;
      j--;
   }
   
   return str;
}

void test(char *test_str){
    
    if(stopstring!=1){
        for(i=0;i<strlen(test_str);i++)
            sample[i]=test_str[i];
        
        for(i=0;sample[i]!='\0';i++)
            action(sample[i]);

        if(checkCorrectAll()==1&&stopstring==0){
            printf("%s\n",sample);
            stopstring=1;
            return;
        }
    
        else if(stopstring!=1){
            rev_str=reverse(sample);
            rev_test(rev_str);
        }
    }
    return;

    
}

void get_pattern(char str[],char new_str[],int current_len,int n,int len){

    if(current_len==len)    //print string when length is equal to p
    {   
        test(new_str);
        
        return;
    }
    else
    {
        int q;
        for(q=0;q<n;q++)
        {
            new_str[current_len]=str[q];
            get_pattern(str,new_str,current_len+1,n,len);
        }
    }
}

void set_input(){
    
    for(i=0;i<9;i++){
            if(lfillog[i]==0)
                lg[i]='R';
            else if(lfillog[i]==1)
                lg[i]='O';
            else if(lfillog[i]==2)
                lg[i]='Y';
            else if(lfillog[i]==3)
                lg[i]='G';
            else if(lfillog[i]==4)
                lg[i]='B';
            else
                lg[i]='W';     
            
            if(rfillog[i]==0)
                rg[i]='R';
            else if(rfillog[i]==1)
                rg[i]='O';
            else if(rfillog[i]==2)
                rg[i]='Y';
            else if(rfillog[i]==3)
                rg[i]='G';
            else if(rfillog[i]==4)
                rg[i]='B';
            else
                rg[i]='W';     
            
            if(ufillog[i]==0)
                ug[i]='R';
            else if(ufillog[i]==1)
                ug[i]='O';
            else if(ufillog[i]==2)
                ug[i]='Y';
            else if(ufillog[i]==3)
                ug[i]='G';
            else if(ufillog[i]==4)
                ug[i]='B';
            else
                ug[i]='W';     
            
            if(dfillog[i]==0)
                dg[i]='R';
            else if(dfillog[i]==1)
                dg[i]='O';
            else if(dfillog[i]==2)
                dg[i]='Y';
            else if(dfillog[i]==3)
                dg[i]='G';
            else if(dfillog[i]==4)
                dg[i]='B';
            else
                dg[i]='W';     
            
            if(ffillog[i]==0)
                fg[i]='R';
            else if(ffillog[i]==1)
                fg[i]='O';
            else if(ffillog[i]==2)
                fg[i]='Y';
            else if(ffillog[i]==3)
                fg[i]='G';
            else if(ffillog[i]==4)
                fg[i]='B';
            else
                fg[i]='W';     
            
            if(bfillog[i]==0)
                bg[i]='R';
            else if(bfillog[i]==1)
                bg[i]='O';
            else if(bfillog[i]==2)
                bg[i]='Y';
            else if(bfillog[i]==3)
                bg[i]='G';
            else if(bfillog[i]==4)
                bg[i]='B';
            else
                bg[i]='W';     
            
    }
    
}

void swapColor(float *a,float *b){
    float temp[3];
    for(int i=0;i<3;i++){
        temp[i]=a[i];
        a[i]=b[i];
        b[i]=temp[i];
    }
}

void leftShift(){
    swapColor(f[0],d[0]);
    swapColor(f[3],d[3]);
    swapColor(f[6],d[6]);
    swapColor(f[0],b[8]);
    swapColor(f[3],b[5]);
    swapColor(f[6],b[2]);
    swapColor(f[0],u[0]);
    swapColor(f[3],u[3]);
    swapColor(f[6],u[6]);
    swapColor(l[0],l[2]);
    swapColor(l[0],l[8]);
    swapColor(l[0],l[6]);
    swapColor(l[1],l[5]);
    swapColor(l[1],l[7]);
    swapColor(l[1],l[3]);
}

void rightShift(){
    swapColor(f[2],d[2]);
    swapColor(f[5],d[5]);
    swapColor(f[8],d[8]);
    swapColor(f[2],b[6]);
    swapColor(f[5],b[3]);
    swapColor(f[8],b[0]);
    swapColor(f[2],u[2]);
    swapColor(f[5],u[5]);
    swapColor(f[8],u[8]);
    swapColor(r[0],r[6]);
    swapColor(r[0],r[8]);
    swapColor(r[0],r[2]);
    swapColor(r[1],r[3]);
    swapColor(r[1],r[7]);
    swapColor(r[1],r[5]);
}

void upShift(){
    swapColor(f[0],l[0]);
    swapColor(f[1],l[1]);
    swapColor(f[2],l[2]);
    swapColor(f[0],b[0]);
    swapColor(f[1],b[1]);
    swapColor(f[2],b[2]);
    swapColor(f[0],r[0]);
    swapColor(f[1],r[1]);
    swapColor(f[2],r[2]);
    swapColor(u[0],u[2]);
    swapColor(u[0],u[8]);
    swapColor(u[0],u[6]);
    swapColor(u[1],u[5]);
    swapColor(u[1],u[7]);
    swapColor(u[1],u[3]);
}

void downShift(){
    swapColor(f[6],l[6]);
    swapColor(f[7],l[7]);
    swapColor(f[8],l[8]);
    swapColor(f[6],b[6]);
    swapColor(f[7],b[7]);
    swapColor(f[8],b[8]);
    swapColor(f[6],r[6]);
    swapColor(f[7],r[7]);
    swapColor(f[8],r[8]);
    swapColor(d[0],d[6]);
    swapColor(d[0],d[8]);
    swapColor(d[0],d[2]);
    swapColor(d[1],d[3]);
    swapColor(d[1],d[7]);
    swapColor(d[1],d[5]);
}

void frontShift(){
    swapColor(u[6],r[0]);
    swapColor(u[7],r[3]);
    swapColor(u[8],r[6]);
    swapColor(u[6],d[2]);
    swapColor(u[7],d[1]);
    swapColor(u[8],d[0]);
    swapColor(u[6],l[8]);
    swapColor(u[7],l[5]);
    swapColor(u[8],l[2]);
    swapColor(f[0],f[2]);
    swapColor(f[0],f[8]);
    swapColor(f[0],f[6]);
    swapColor(f[1],f[5]);
    swapColor(f[1],f[7]);
    swapColor(f[1],f[3]);
}

void backShift(){
    swapColor(u[0],r[2]);
    swapColor(u[1],r[5]);
    swapColor(u[2],r[8]);
    swapColor(u[0],d[8]);
    swapColor(u[1],d[7]);
    swapColor(u[2],d[6]);
    swapColor(u[0],l[6]);
    swapColor(u[1],l[3]);
    swapColor(u[2],l[0]);
    swapColor(b[0],b[6]);
    swapColor(b[0],b[8]);
    swapColor(b[0],b[2]);
    swapColor(b[1],b[3]);
    swapColor(b[1],b[7]);
    swapColor(b[1],b[5]);
}

void makePoly(float *c,int v1,int v2,int v3,int v4){
    int play=0;
    
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0,0.0,0.0);     
        glVertex3fv(v[v1]);
        glVertex3fv(v[v2]);
        glVertex3fv(v[v3]);
        glVertex3fv(v[v4]);
    glEnd();
    
   
    for(int i=0;i<3;i++)
        if(c[i]==1.0)
            play++;
    
    glBegin(GL_POLYGON);
        if(play==3)
            glColor3f(0.5,0.5,0.5);
        else
            glColor3f(1.0,1.0,1.0);
        glVertex3fv(v[v1]);
        glColor3fv(c);     
        glVertex3fv(v[v2]);
        glVertex3fv(v[v3]);
        glVertex3fv(v[v4]);  
    glEnd();
    
}

void actual_cube(){
    
    if(once==0){
    glRotatef(35.0, 1.0, 0.0, 0.0 );
    glRotatef(45.0, 0.0, 1.0, 0.0 );
    }
    
    makePoly(f[2],7,3,2,6);
    makePoly(f[5],11,7,6,10);
    makePoly(f[8],15,11,10,14);
    makePoly(d[2],15,25,55,14);
    makePoly(d[5],25,26,53,55);
    makePoly(d[8],26,27,39,53);
    makePoly(b[6],27,24,36,39);
    makePoly(b[3],24,21,33,36);
    makePoly(b[0],21,18,30,33);
    makePoly(u[2],17,18,30,49);
    makePoly(u[5],16,17,49,51);
    makePoly(u[8],3,16,51,2);
    makePoly(r[0],19,16,3,7);
    makePoly(r[1],20,17,16,19);
    makePoly(r[2],21,18,17,20);
    makePoly(r[3],22,19,7,11);
    makePoly(r[4],23,20,19,22);
    makePoly(r[5],24,21,20,23);
    makePoly(r[6],25,22,11,15);
    makePoly(r[7],26,23,22,25);
    makePoly(r[8],27,24,23,26);
    makePoly(f[1],6,2,1,5);
    makePoly(f[4],10,6,5,9);
    makePoly(f[7],14,10,9,13);
    makePoly(d[1],14,55,54,13);
    makePoly(d[4],55,53,52,54);
    makePoly(d[7],53,39,38,52);
    makePoly(b[7],39,36,35,38);
    makePoly(b[4],36,33,32,35);
    makePoly(b[1],33,30,29,32);
    makePoly(u[1],49,30,29,48);
    makePoly(u[4],51,49,48,50);
    makePoly(u[7],2,51,50,1);
    makePoly(f[0],5,1,0,4);
    makePoly(f[3],9,5,4,8);
    makePoly(f[6],13,9,8,12);    
    makePoly(d[0],13,54,46,12);
    makePoly(d[3],54,52,47,46);
    makePoly(d[6],52,38,37,47);
    makePoly(b[8],38,35,34,37);
    makePoly(b[5],35,32,31,34);
    makePoly(b[2],32,29,28,31);
    makePoly(u[0],48,29,28,41);
    makePoly(u[3],50,48,41,40);
    makePoly(u[6],1,50,40,0);
    makePoly(l[0],31,28,41,43);
    makePoly(l[1],43,41,40,42);
    makePoly(l[2],42,40,0,4);
    makePoly(l[3],34,31,43,45);
    makePoly(l[4],45,43,42,44);
    makePoly(l[5],44,42,4,8);
    makePoly(l[6],37,34,45,47);
    makePoly(l[7],47,45,44,46);
    makePoly(l[8],46,44,8,12);
    
}

void xturncube(){
    
    glPushMatrix();
    
    glRotatef(rotate_x1, 1.0, 0.0, 0.0 );
    
    makePoly(f[2],7,3,2,6);
    makePoly(f[5],11,7,6,10);
    makePoly(f[8],15,11,10,14);
    makePoly(d[2],15,25,55,14);
    makePoly(d[5],25,26,53,55);
    makePoly(d[8],26,27,39,53);
    makePoly(b[6],27,24,36,39);
    makePoly(b[3],24,21,33,36);
    makePoly(b[0],21,18,30,33);
    makePoly(u[2],17,18,30,49);
    makePoly(u[5],16,17,49,51);
    makePoly(u[8],3,16,51,2);
    makePoly(r[0],19,16,3,7);
    makePoly(r[1],20,17,16,19);
    makePoly(r[2],21,18,17,20);
    makePoly(r[3],22,19,7,11);
    makePoly(r[4],23,20,19,22);
    makePoly(r[5],24,21,20,23);
    makePoly(r[6],25,22,11,15);
    makePoly(r[7],26,23,22,25);
    makePoly(r[8],27,24,23,26);
    
    glPopMatrix();
    
    makePoly(f[1],6,2,1,5);
    makePoly(f[4],10,6,5,9);
    makePoly(f[7],14,10,9,13);
    makePoly(d[1],14,55,54,13);
    makePoly(d[4],55,53,52,54);
    makePoly(d[7],53,39,38,52);
    makePoly(b[7],39,36,35,38);
    makePoly(b[4],36,33,32,35);
    makePoly(b[1],33,30,29,32);
    makePoly(u[1],49,30,29,48);
    makePoly(u[4],51,49,48,50);
    makePoly(u[7],2,51,50,1);
    
    glPushMatrix();
    
    glRotatef(rotate_x2, 1.0, 0.0, 0.0 );
    
    makePoly(f[0],5,1,0,4);
    makePoly(f[3],9,5,4,8);
    makePoly(f[6],13,9,8,12);    
    makePoly(d[0],13,54,46,12);
    makePoly(d[3],54,52,47,46);
    makePoly(d[6],52,38,37,47);
    makePoly(b[8],38,35,34,37);
    makePoly(b[5],35,32,31,34);
    makePoly(b[2],32,29,28,31);
    makePoly(u[0],48,29,28,41);
    makePoly(u[3],50,48,41,40);
    makePoly(u[6],1,50,40,0);
    makePoly(l[0],31,28,41,43);
    makePoly(l[1],43,41,40,42);
    makePoly(l[2],42,40,0,4);
    makePoly(l[3],34,31,43,45);
    makePoly(l[4],45,43,42,44);
    makePoly(l[5],44,42,4,8);
    makePoly(l[6],37,34,45,47);
    makePoly(l[7],47,45,44,46);
    makePoly(l[8],46,44,8,12);
    
    glPopMatrix();
    
}

void yturncube(){
    
    glPushMatrix();
    
    glRotatef(rotate_y1, 0.0, 1.0, 0.0 );
    
    makePoly(f[0],5,1,0,4);
    makePoly(f[1],6,2,1,5);
    makePoly(f[2],7,3,2,6); 
    makePoly(r[0],19,16,3,7);
    makePoly(r[1],20,17,16,19);
    makePoly(r[2],21,18,17,20);
    makePoly(b[0],21,18,30,33);
    makePoly(b[1],33,30,29,32);
    makePoly(b[2],32,29,28,31);
    makePoly(l[0],31,28,41,43);
    makePoly(l[1],43,41,40,42);
    makePoly(l[2],42,40,0,4);
    makePoly(u[0],48,29,28,41);
    makePoly(u[1],49,30,29,48);
    makePoly(u[2],17,18,30,49);
    makePoly(u[3],50,48,41,40);
    makePoly(u[4],51,49,48,50);
    makePoly(u[5],16,17,49,51);
    makePoly(u[6],1,50,40,0);
    makePoly(u[7],2,51,50,1);
    makePoly(u[8],3,16,51,2);

    glPopMatrix();
    
    makePoly(f[3],9,5,4,8);
    makePoly(f[4],10,6,5,9);
    makePoly(f[5],11,7,6,10);
    makePoly(r[3],22,19,7,11);
    makePoly(r[4],23,20,19,22);
    makePoly(r[5],24,21,20,23);
    makePoly(b[3],24,21,33,36);
    makePoly(b[4],36,33,32,35);
    makePoly(b[5],35,32,31,34);
    makePoly(l[3],34,31,43,45);
    makePoly(l[4],45,43,42,44);
    makePoly(l[5],44,42,4,8);
    
    glPushMatrix();
    
    glRotatef(rotate_y2, 0.0, 1.0, 0.0 );
    
    makePoly(f[6],13,9,8,12);    
    makePoly(f[7],14,10,9,13);    
    makePoly(f[8],15,11,10,14);
    makePoly(r[6],25,22,11,15);
    makePoly(r[7],26,23,22,25);
    makePoly(r[8],27,24,23,26);
    makePoly(b[6],27,24,36,39);
    makePoly(b[7],39,36,35,38);
    makePoly(b[8],38,35,34,37);
    makePoly(l[6],37,34,45,47);
    makePoly(l[7],47,45,44,46);
    makePoly(l[8],46,44,8,12);
    makePoly(d[0],13,54,46,12);
    makePoly(d[1],14,55,54,13);
    makePoly(d[2],15,25,55,14);
    makePoly(d[3],54,52,47,46);
    makePoly(d[4],55,53,52,54);
    makePoly(d[5],25,26,53,55);
    makePoly(d[6],52,38,37,47);
    makePoly(d[7],53,39,38,52);
    makePoly(d[8],26,27,39,53);
    
    glPopMatrix();
        
}

void zturncube(){
    
    glPushMatrix();
    
    glRotatef(rotate_z1, 0.0, 0.0, 1.0 );
    
    makePoly(f[0],5,1,0,4);
    makePoly(f[1],6,2,1,5);
    makePoly(f[2],7,3,2,6);    
    makePoly(f[3],9,5,4,8);
    makePoly(f[4],10,6,5,9);
    makePoly(f[5],11,7,6,10);
    makePoly(f[6],13,9,8,12);    
    makePoly(f[7],14,10,9,13);    
    makePoly(f[8],15,11,10,14);
    makePoly(u[6],1,50,40,0);
    makePoly(u[7],2,51,50,1);
    makePoly(u[8],3,16,51,2);
    makePoly(r[0],19,16,3,7);
    makePoly(r[3],22,19,7,11);
    makePoly(r[6],25,22,11,15);
    makePoly(d[2],15,25,55,14);
    makePoly(d[1],14,55,54,13);
    makePoly(d[0],13,54,46,12);
    makePoly(l[8],46,44,8,12);
    makePoly(l[5],44,42,4,8);
    makePoly(l[2],42,40,0,4);
    
    glPopMatrix();
    
    makePoly(u[3],50,48,41,40);
    makePoly(u[4],51,49,48,50);
    makePoly(u[5],16,17,49,51);
    makePoly(r[1],20,17,16,19);
    makePoly(r[4],23,20,19,22);
    makePoly(r[7],26,23,22,25);
    makePoly(d[5],25,26,53,55);
    makePoly(d[4],55,53,52,54);
    makePoly(d[3],54,52,47,46);
    makePoly(l[7],47,45,44,46);
    makePoly(l[4],45,43,42,44);
    makePoly(l[1],43,41,40,42);

    glPushMatrix();
    
    glRotatef(rotate_z2, 0.0, 0.0, 1.0 );
    
    makePoly(b[0],21,18,30,33);
    makePoly(b[1],33,30,29,32);
    makePoly(b[2],32,29,28,31);
    makePoly(b[3],24,21,33,36);
    makePoly(b[4],36,33,32,35);
    makePoly(b[5],35,32,31,34);
    makePoly(b[6],27,24,36,39);
    makePoly(b[7],39,36,35,38);
    makePoly(b[8],38,35,34,37);
    makePoly(u[0],48,29,28,41);
    makePoly(u[1],49,30,29,48);
    makePoly(u[2],17,18,30,49);
    makePoly(r[2],21,18,17,20);
    makePoly(r[5],24,21,20,23);
    makePoly(r[8],27,24,23,26);
    makePoly(d[8],26,27,39,53);
    makePoly(d[7],53,39,38,52);
    makePoly(d[6],52,38,37,47);
    makePoly(l[6],37,34,45,47);
    makePoly(l[3],34,31,43,45);
    makePoly(l[0],31,28,41,43);
    
    glPopMatrix();
    
}

void display4(){ 
    glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
     
    if(turn==0)
        actual_cube();
    else if(turn==1)
        xturncube();
    else if(turn==2)
        yturncube();
    else if(turn==3)
        zturncube();
    
    
    glFlush();
    glutSwapBuffers();
 
}

float color_tog[3]={1.0,0.0,0.0};

float color[][3]={
    
    {1.0,0.0,0.0},          //Red 0
    {1.0,0.5,0.0},          //Orange 1
    {1.0,1.0,0.0},          //Yellow 2
    {0.0,1.0,0.0},          //Green 3
    {0.0,0.0,1.0},          //Blue 4
    {1.0,1.0,1.0},          //White 5
};

void square(float x1,float y1,float x2,float y2){
    
    glBegin(GL_LINE_LOOP);
    
    glVertex2f(x1,y1);
    glVertex2f(x2,y1);
    glVertex2f(x2,y2);
    glVertex2f(x1,y2);
    
    glEnd();
}

void square_fill(float *v,float x1,float y1,float x2,float y2){
    
    glBegin(GL_POLYGON);
    
    glColor3fv(v);
    glVertex2f(x1,y1);
    glVertex2f(x2,y1);
    glVertex2f(x2,y2);
    glVertex2f(x1,y2);
    
    glEnd();
}

void set_square(){

    square(90,800,140,890);
    square(150,800,200,890);
    square(210,800,260,890);
    square(90,700,140,790);
    square(150,700,200,790);
    square(210,700,260,790);
    square(90,600,140,690);
    square(150,600,200,690);
    square(210,600,260,690);
        
    square(400,800,450,890);
    square(460,800,510,890);
    square(520,800,570,890);
    square(400,700,450,790);
    square(460,700,510,790);
    square(520,700,570,790);
    square(400,600,450,690);
    square(460,600,510,690);
    square(520,600,570,690);
    
    square(710,800,760,890);
    square(770,800,820,890);
    square(830,800,880,890);
    square(710,700,760,790);
    square(770,700,820,790);
    square(830,700,880,790);
    square(710,600,760,690);
    square(770,600,820,690);
    square(830,600,880,690);
    
    square(90,350,140,440);
    square(150,350,200,440);
    square(210,350,260,440);
    square(90,250,140,340);
    square(150,250,200,340);
    square(210,250,260,340);
    square(90,150,140,240);
    square(150,150,200,240);
    square(210,150,260,240);
    
    square(400,350,450,440);
    square(460,350,510,440);
    square(520,350,570,440);
    square(400,250,450,340);
    square(460,250,510,340);
    square(520,250,570,340);
    square(400,150,450,240);
    square(460,150,510,240);
    square(520,150,570,240);
    
    square(710,350,760,440);
    square(770,350,820,440);
    square(830,350,880,440);
    square(710,250,760,340);
    square(770,250,820,340);
    square(830,250,880,340);
    square(710,150,760,240);
    square(770,150,820,240);
    square(830,150,880,240);
    
}


void display1(void){
    
    int i;
    
	glClear(GL_COLOR_BUFFER_BIT);
	
    glBegin(GL_POLYGON);
    
    glColor3f(0.0,0.0,1.0);
    glVertex2f(0.0,0.0);
    
    glColor3f(0.0,0.0,0.0);
    glVertex2f(1000.0,0.0);
    
    glColor3f(0.0,0.0,1.0);
    glVertex2f(1000.0,1000.0);
    
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.0,1000.0);
    
    glEnd();
    
    glColor3f(0.941, 0.902, 0.549);
	
	glRasterPos2f(384,950);
	for(i=0;i<strlen(display1_str);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display1_str[i]);		
	
	glRasterPos2f(440.5,900);
	for(i=0;i<strlen(display1_str1);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,display1_str1[i]);		
	
    glRasterPos2f(350,850);
	for(i=0;i<strlen(display1_str2);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,display1_str2[i]);		
	
	glRasterPos2f(354,800);
	for(i=0;i<strlen(display1_str3);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,display1_str3[i]);
	
	glRasterPos2f(435,700);
	for(i=0;i<strlen(display1_str4);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display1_str4[i]);

	glRasterPos2f(485,600);
	for(i=0;i<strlen(display1_str5);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display1_str5[i]);
	
	glRasterPos2f(385,500);
	for(i=0;i<strlen(display1_str6);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display1_str6[i]);		

	glRasterPos2f(50,300);
	for(i=0;i<strlen(display1_str7);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display1_str7[i]);		

	glRasterPos2f(50,250);
	for(i=0;i<strlen(display1_str8);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,display1_str8[i]);

	glRasterPos2f(50,200);
	for(i=0;i<strlen(display1_str9);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,display1_str9[i]);

    glRasterPos2f(440,300);
	for(i=0;i<strlen(display1_str10);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display1_str10[i]);

	glRasterPos2f(440,250);
	for(i=0;i<strlen(display1_str11);i++) 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,display1_str11[i]);
    
    glRasterPos2f(430,200);
	for(i=0;i<strlen(display1_str12);i++) 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,display1_str12[i]);

	glRasterPos2f(789,300);
	for(i=0;i<strlen(display1_str13);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display1_str13[i]);

	glRasterPos2f(829,250);
	for(i=0;i<strlen(display1_str14);i++) 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,display1_str14[i]);
    
    glRasterPos2f(825,200);
	for(i=0;i<strlen(display1_str15);i++) 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,display1_str15[i]);
    
    glRasterPos2f(429,50);
	for(i=0;i<strlen(display1_str16);i++) 
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display1_str16[i]);		
	
    glRasterPos2f(825,200);
	for(i=0;i<strlen(display1_str15);i++) 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,display1_str15[i]);
    
    glRasterPos2f(429,50);
	for(i=0;i<strlen(display1_str16);i++) 
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display1_str16[i]);

	glFlush();
    
}

void display2(void){
    
	glClear(GL_COLOR_BUFFER_BIT);	
	
    glBegin(GL_POLYGON);
    
    glColor3f(0.855f, 0.647f, 0.125f);
    glVertex2f(0.0,0.0);
    
    glColor3f(0.627f, 0.322f, 0.176f);
    glVertex2f(1000.0,0.0);
    
    glColor3f(0.855f, 0.647f, 0.125f);
    glVertex2f(1000.0,1000.0);
    
    glColor3f(0.627f, 0.322f, 0.176f);
    glVertex2f(0.0,1000.0);
    
    glEnd();
    
    glColor3f(0.0f, 0.0f, 0.0f);
	
    if(change==0){
        glRasterPos2f(457,950);
        for(i=0;i<strlen(display2_str1);i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display2_str1[i]);
    }
    else{
        glRasterPos2f(290,950);
        for(i=0;i<strlen(ans_str);i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ans_str[i]);
    }
    
    glRasterPos2f(345,850);
	for(i=0;i<strlen(display2_str2);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display2_str2[i]);		
    
    glRasterPos2f(30,700);
	for(i=0;i<strlen(display2_str3);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display2_str3[i]);		
    
    glRasterPos2f(30,600);
	for(i=0;i<strlen(display2_str4);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display2_str4[i]);		
    
    glRasterPos2f(30,500);
	for(i=0;i<strlen(display2_str5);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display2_str5[i]);		
    
    glRasterPos2f(30,400);
	for(i=0;i<strlen(display2_str6);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display2_str6[i]);
    
    glRasterPos2f(30,300);
	for(i=0;i<strlen(display2_str7);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display2_str7[i]);		
    
    glRasterPos2f(30,200);
	for(i=0;i<strlen(display2_str8);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display2_str8[i]);
    
    glRasterPos2f(720,700);
	for(i=0;i<strlen(display2_str9);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display2_str9[i]);		
    
    glRasterPos2f(720,600);
	for(i=0;i<strlen(display2_str10);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display2_str10[i]);		
    
    glRasterPos2f(720,500);
	for(i=0;i<strlen(display2_str11);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display2_str11[i]);		
    
    glRasterPos2f(720,400);
	for(i=0;i<strlen(display2_str12);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display2_str12[i]);
    
    glRasterPos2f(720,300);
	for(i=0;i<strlen(display2_str13);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display2_str13[i]);		
    
    glRasterPos2f(720,200);
	for(i=0;i<strlen(display2_str14);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display2_str14[i]);
    
    glRasterPos2f(410,300);
	for(i=0;i<strlen(display2_str15);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display2_str15[i]);
    
    glFlush();
    
}

void just_fill(){
    
    if(lfill[0]!=-1)
        square_fill(color[lfill[0]],90,800,140,890);
    if(lfill[1]!=-1)
        square_fill(color[lfill[1]],150,800,200,890);
    if(lfill[2]!=-1)
        square_fill(color[lfill[2]],210,800,260,890);
    if(lfill[3]!=-1)
        square_fill(color[lfill[3]],90,700,140,790);
    if(lfill[4]!=-1)
        square_fill(color[lfill[4]],150,700,200,790);
    if(lfill[5]!=-1)
        square_fill(color[lfill[5]],210,700,260,790);
    if(lfill[6]!=-1)
        square_fill(color[lfill[6]],90,600,140,690);
    if(lfill[7]!=-1)
        square_fill(color[lfill[7]],150,600,200,690);
    if(lfill[8]!=-1)
        square_fill(color[lfill[8]],210,600,260,690);
        
    if(rfill[0]!=-1)
        square_fill(color[rfill[0]],400,800,450,890);
    if(rfill[1]!=-1)
        square_fill(color[rfill[1]],460,800,510,890);
    if(rfill[2]!=-1)
        square_fill(color[rfill[2]],520,800,570,890);
    if(rfill[3]!=-1)
        square_fill(color[rfill[3]],400,700,450,790);
    if(rfill[4]!=-1)
        square_fill(color[rfill[4]],460,700,510,790);
    if(rfill[5]!=-1)
        square_fill(color[rfill[5]],520,700,570,790);
    if(rfill[6]!=-1)
        square_fill(color[rfill[6]],400,600,450,690);
    if(rfill[7]!=-1)
        square_fill(color[rfill[7]],460,600,510,690);
    if(rfill[8]!=-1)
        square_fill(color[rfill[8]],520,600,570,690);
    
    if(ufill[0]!=-1)
        square_fill(color[ufill[0]],710,800,760,890);
    if(ufill[1]!=-1)
        square_fill(color[ufill[1]],770,800,820,890);
    if(ufill[2]!=-1)
        square_fill(color[ufill[2]],830,800,880,890);
    if(ufill[3]!=-1)
        square_fill(color[ufill[3]],710,700,760,790);
    if(ufill[4]!=-1)
        square_fill(color[ufill[4]],770,700,820,790);
    if(ufill[5]!=-1)
        square_fill(color[ufill[5]],830,700,880,790);
    if(ufill[6]!=-1)
        square_fill(color[ufill[6]],710,600,760,690);
    if(ufill[7]!=-1)
        square_fill(color[ufill[7]],770,600,820,690);
    if(ufill[8]!=-1)
        square_fill(color[ufill[8]],830,600,880,690);
    
    if(dfill[0]!=-1)
        square_fill(color[dfill[0]],90,350,140,440);
    if(dfill[1]!=-1)
        square_fill(color[dfill[1]],150,350,200,440);
    if(dfill[2]!=-1)
        square_fill(color[dfill[2]],210,350,260,440);
    if(dfill[3]!=-1)
        square_fill(color[dfill[3]],90,250,140,340);
    if(dfill[4]!=-1)
        square_fill(color[dfill[4]],150,250,200,340);
    if(dfill[5]!=-1)
        square_fill(color[dfill[5]],210,250,260,340);
    if(dfill[6]!=-1)
        square_fill(color[dfill[6]],90,150,140,240);
    if(dfill[7]!=-1)
        square_fill(color[dfill[7]],150,150,200,240);
    if(dfill[8]!=-1)
        square_fill(color[dfill[8]],210,150,260,240);
    
    if(ffill[0]!=-1)
        square_fill(color[ffill[0]],400,350,450,440);
    if(ffill[1]!=-1)
        square_fill(color[ffill[1]],460,350,510,440);
    if(ffill[2]!=-1)
        square_fill(color[ffill[2]],520,350,570,440);
    if(ffill[3]!=-1)
        square_fill(color[ffill[3]],400,250,450,340);
    if(ffill[4]!=-1)
        square_fill(color[ffill[4]],460,250,510,340);
    if(ffill[5]!=-1)
        square_fill(color[ffill[5]],520,250,570,340);
    if(ffill[6]!=-1)
        square_fill(color[ffill[6]],400,150,450,240);
    if(ffill[7]!=-1)
        square_fill(color[ffill[7]],460,150,510,240);
    if(ffill[8]!=-1)
        square_fill(color[ffill[8]],520,150,570,240);
    
    if(bfill[0]!=-1)
        square_fill(color[bfill[0]],710,350,760,440);
    if(bfill[1]!=-1)
        square_fill(color[bfill[1]],770,350,820,440);
    if(bfill[2]!=-1)
        square_fill(color[bfill[2]],830,350,880,440);
    if(bfill[3]!=-1)
        square_fill(color[bfill[3]],710,250,760,340);
    if(bfill[4]!=-1)
        square_fill(color[bfill[4]],770,250,820,340);
    if(bfill[5]!=-1)
        square_fill(color[bfill[5]],830,250,880,340);
    if(bfill[6]!=-1)
        square_fill(color[bfill[6]],710,150,760,240);
    if(bfill[7]!=-1)
        square_fill(color[bfill[7]],770,150,820,240);
    if(bfill[8]!=-1)
        square_fill(color[bfill[8]],830,150,880,240);
    
}

void sq_pos(int x,int y){
    
    glRasterPos2f(110+x,833+y);
	for(i=0;i<strlen(num_str0);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,num_str0[i]);
    
    glRasterPos2f(170+x,833+y);
	for(i=0;i<strlen(num_str1);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,num_str1[i]);
    
    glRasterPos2f(230+x,833+y);
	for(i=0;i<strlen(num_str2);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,num_str2[i]);
    
    glRasterPos2f(110+x,733+y);
	for(i=0;i<strlen(num_str3);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,num_str3[i]);
    
    glRasterPos2f(170+x,733+y);
	for(i=0;i<strlen(num_str4);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,num_str4[i]);
    
    glRasterPos2f(230+x,733+y);
	for(i=0;i<strlen(num_str5);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,num_str5[i]);
    
    glRasterPos2f(110+x,633+y);
	for(i=0;i<strlen(num_str6);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,num_str6[i]);
    
    glRasterPos2f(170+x,633+y);
	for(i=0;i<strlen(num_str7);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,num_str7[i]);
    
    glRasterPos2f(230+x,633+y);
	for(i=0;i<strlen(num_str8);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,num_str8[i]);
    
}

void display3(void){
    
    int i;
    
	glClear(GL_COLOR_BUFFER_BIT);	
	
    glColor3f(0.941, 0.902, 0.549);
	
	if(fill_change==0){
        glRasterPos2f(154,950);
        for(i=0;i<strlen(display3_str1);i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display3_str1[i]);
    }
    else{
        glRasterPos2f(384,950);
        for(i=0;i<strlen(display3_str1_sub);i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display3_str1_sub[i]);
    }
    set_square();
    
    glRasterPos2f(170,550);
	for(i=0;i<strlen(display3_str2);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display3_str2[i]);
    
    glRasterPos2f(480,550);
	for(i=0;i<strlen(display3_str3);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display3_str3[i]);
    
    glRasterPos2f(790,550);
	for(i=0;i<strlen(display3_str4);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display3_str4[i]);
    
    glRasterPos2f(170,100);
	for(i=0;i<strlen(display3_str5);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display3_str5[i]);
    
    glRasterPos2f(480,100);
	for(i=0;i<strlen(display3_str6);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display3_str6[i]);
    
    glRasterPos2f(790,100);
	for(i=0;i<strlen(display3_str7);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display3_str7[i]);

    glRasterPos2f(80,50);
	for(i=0;i<strlen(display3_str8);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display3_str8[i]);
    
    glRasterPos2f(700,50);
	for(i=0;i<strlen(display3_str9);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display3_str9[i]);
    
    glRasterPos2f(400,50);
	for(i=0;i<strlen(display3_str10);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,display3_str10[i]);
    
    sq_pos(0,0);
    sq_pos(310,0);
    sq_pos(620,0);
    sq_pos(0,-450);
    sq_pos(310,-450);
    sq_pos(620,-450);
    
    square(51,43,75,82);
    if(set==0){
        glRasterPos2f(60,50);
        for(i=0;i<strlen(num_str0);i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,num_str0[i]);
    }
    else if(set==1){
        glRasterPos2f(60,50);
        for(i=0;i<strlen(num_str1);i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,num_str1[i]);
    }
    else if(set==2){
        glRasterPos2f(60,50);
        for(i=0;i<strlen(num_str2);i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,num_str2[i]);
    }
    else if(set==3){
        glRasterPos2f(60,50);
        for(i=0;i<strlen(num_str3);i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,num_str3[i]);
    }
    else if(set==4){
        glRasterPos2f(60,50);
        for(i=0;i<strlen(num_str4);i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,num_str4[i]);
    }
    else if(set==5){
        glRasterPos2f(60,50);
        for(i=0;i<strlen(num_str5);i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,num_str5[i]);
    }
    else if(set==6){
        glRasterPos2f(60,50);
        for(i=0;i<strlen(num_str6);i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,num_str6[i]);
    }
    else if(set==7){
        glRasterPos2f(60,50);
        for(i=0;i<strlen(num_str7);i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,num_str7[i]);
    }
    else if(set==8){
        glRasterPos2f(60,50);
        for(i=0;i<strlen(num_str8);i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,num_str8[i]);
    }
    
    square_fill(color[toggle],667,43,691,82);
    
    just_fill();
    
    glFlush();
    
}

void myinit1(){
    
	glClearColor(1.0,1.0,1.0,1.0);
	glPointSize(10);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1000.0,0.0,1000.0); //pixels on the screen
	glMatrixMode(GL_MODELVIEW);

}

void myinit2(){
    
	glClearColor(1.0,1.0,1.0,1.0);
	glPointSize(10);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1000.0,0.0,1000.0); //pixels on the screen
	glMatrixMode(GL_MODELVIEW);

}

void myinit3(){
    
    glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1000.0,0.0,1000.0); //pixels on the screen
	glMatrixMode(GL_MODELVIEW);

}

void reset_cube(){
    for(i=0;i<9;i++){
        lfill[i]=lfillog[i];
        rfill[i]=rfillog[i];
        ffill[i]=ffillog[i];
        bfill[i]=bfillog[i];
        ufill[i]=ufillog[i];
        dfill[i]=dfillog[i];
    }
    
    for(i=0;i<9;i++){
        for(j=0;j<3;j++){
            l[i][j]=color[lfill[i]][j];
            r[i][j]=color[rfill[i]][j];
            f[i][j]=color[ffill[i]][j];
            b[i][j]=color[bfill[i]][j];
            u[i][j]=color[ufill[i]][j];
            d[i][j]=color[dfill[i]][j];
        }
    }
}

void Rmotion(float value){
    turn=1;
    rotate_x1 += value;
    if(((int)rotate_x1%90)==0){
        rightShift();
        rotate_x1=0;
        turn=0;
        once=1;
          
    }
}

void rmotion(float value){
        turn=1;
        rotate_x1 -= value;
        if(((int)rotate_x1%90)==0){
             rightShift();
             rightShift();
             rightShift();
             rotate_x1=0;
             turn=0;
             once=1;
         }
}

void Lmotion(float value){
    turn=1;
        rotate_x2 -= value;
        if(((int)rotate_x2%90)==0){
             leftShift();
             leftShift();
             leftShift();
             rotate_x2=0;
             turn=0;
             once=1;
         }
        
}

void lmotion(float value){
    turn=1;
        rotate_x2 += value;
         if(((int)rotate_x2%90)==0){
             leftShift();
             rotate_x2=0;
             turn=0;
             once=1;
         }
}
        
void Fmotion(float value){
    turn=3;
        rotate_z1 += value;
        if(((int)rotate_z1%90)==0){
             frontShift();
             frontShift();
             frontShift();
             rotate_z1=0;
             turn=0;
             once=1;
         }
}


void fmotion(float value){
    turn=3;
        rotate_z1 -= value;
        if(((int)rotate_z1%90)==0){
             frontShift();
             rotate_z1=0;
             turn=0;
             once=1;
        }
}


void Bmotion(float value){
    turn=3;
        rotate_z2 -= value;
        if(((int)rotate_z2%90)==0){
             backShift();
             rotate_z2=0;
             turn=0;
             once=1;
        }
}

void bmotion(float value){
    turn=3;
        rotate_z2 += value;
        if(((int)rotate_z2%90)==0){
             backShift();
             backShift();
             backShift();
             rotate_z2=0;
             turn=0;
             once=1;
        }
}

void Umotion(float value){
    turn=2;
        rotate_y1 += value;
        if(((int)rotate_y1%90)==0){
             upShift();
             upShift();
             upShift();
             rotate_y1=0;
             turn=0;
             once=1;
         }
        
}

void umotion(float value){
    turn=2;
        rotate_y1 -= value;
        if(((int)rotate_y1%90)==0){
             upShift();
             rotate_y1=0;
             turn=0;
             once=1;
         }
}


void Dmotion(float value){
    turn=2;
        rotate_y2 -= value;
        if(((int)rotate_y2%90)==0){
             downShift();
             rotate_y2=0;
             turn=0;
             once=1;
         }
}

void dmotion(float value){
    turn=2;
        rotate_y2 += value;
        if(((int)rotate_y2%90)==0){
             downShift();
             downShift();
             downShift();
             rotate_y2=0;
             turn=0;
             once=1;
         }
}

void set_idle(){
    
    max_idle=strlen(sample);
    
    for(i=0;i<strlen(sample);i++){
        if(sample[i]=='l')
            idlevalue[i]=1;
        else if(sample[i]=='r')
            idlevalue[i]=2;
        else if(sample[i]=='u')
            idlevalue[i]=3;
        else if(sample[i]=='d')
            idlevalue[i]=4;
        else if(sample[i]=='f')
            idlevalue[i]=5;
        else if(sample[i]=='b')
            idlevalue[i]=6;
        else if(sample[i]=='L')
            idlevalue[i]=7;
        else if(sample[i]=='R')
            idlevalue[i]=8;
        else if(sample[i]=='U')
            idlevalue[i]=9;
        else if(sample[i]=='D')
            idlevalue[i]=10;
        else if(sample[i]=='F')
            idlevalue[i]=11;
        else if(sample[i]=='B')
            idlevalue[i]=12;
    }
    
}

void do_idle(int value){
    
    if(value==1)
        lmotion(1.2);
    else if(value==2)
        rmotion(1.2);
    else if(value==3)
        umotion(1.2);
    else if(value==4)
        dmotion(1.2);
    else if(value==5)
        fmotion(1.2);
    else if(value==6)
        bmotion(1.2);
    else if(value==7)
        Lmotion(1.2);
    else if(value==8)
        Rmotion(1.2);
    else if(value==9)
        Umotion(1.2);
    else if(value==10)
        Dmotion(1.2);
    else if(value==11)
        Fmotion(1.2);
    else if(value==12)
        Bmotion(1.2);
        
}

void idle(){
    
    if(idleno<75&&max_idle!=0){
        do_idle(idlevalue[0]);
        idleno++;
        if(idleno==75)
            max_idle--;
    }
    else if(idleno<150&&max_idle!=0){
        do_idle(idlevalue[1]);
        idleno++;
        if(idleno==150)
            max_idle--;
    }
    else if(idleno<225&&max_idle!=0){
        do_idle(idlevalue[2]);
        idleno++;
        if(idleno==225)
            max_idle--;
    }
    else if(idleno<300&&max_idle!=0){
        do_idle(idlevalue[3]);
        idleno++;
        if(idleno==300)
            max_idle--;
    }
    else if(idleno<375&&max_idle!=0){
        do_idle(idlevalue[4]);
        idleno++;
        if(idleno==375)
            max_idle--;
    }
    else if(idleno<450&&max_idle!=0){
        do_idle(idlevalue[5]);
        idleno++;
        if(idleno==450)
            max_idle--;
    }
    else if(idleno<525&&max_idle!=0){
        do_idle(idlevalue[6]);
        idleno++;
        if(idleno==525)
            max_idle--;
    }
    
    glutPostRedisplay();
    
}

void keys4(unsigned char k, int x, int y ) {
 
    if (k == 'R')
        Rmotion(5);
        
    else if (k == 'r')
        rmotion(5);
 
    else if (k == 'L')
        Lmotion(5);
 
    else if (k == 'l')
        lmotion(5);
    
    else if (k == 'U')
        Umotion(5);
        
    else if (k == 'u')
        umotion(5);
 
    else if (k == 'D')
        Dmotion(5);
 
    else if (k == 'd')
        dmotion(5);
    
    else if (k == 'F')
        Fmotion(5);
        
    else if (k == 'f')
        fmotion(5);
 
    else if (k == 'B')
        Bmotion(5);
 
    else if (k == 'b')
        bmotion(5);
    
    else if(k=='Q'||k=='q')
        exit(0);
    
    else if (k=='X'||k=='x')
        reset_cube();
    
    else if(k=='Y'||k=='y'){
        set_input();
        for(i=1;i<=7;i++)
            get_pattern(setstr,pos_arr,0,12,i); 

        set_idle();
        glutIdleFunc(idle);
        idleno=0;
    }
    
    glutDisplayFunc(display4);
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
 
}

void myReshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5,1.5,-1.5,1.5,-1.5,1.5);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void set_prefeed(int value,float *arr){
    
    if(value==0){
        arr[0]=1.0;
        arr[1]=0.0;
        arr[2]=0.0;    
    }
    else if(value==1){
        arr[0]=1.0;
        arr[1]=0.5;
        arr[2]=0.0;    
    }
    else if(value==2){
        arr[0]=1.0;
        arr[1]=1.0;
        arr[2]=0.0;    
    }
    else if(value==3){
        arr[0]=0.0;
        arr[1]=1.0;
        arr[2]=0.0;    
    }
    else if(value==4){
        arr[0]=0.0;
        arr[1]=0.0;
        arr[2]=1.0;    
    }
    else if(value==5){
        arr[0]=1.0;
        arr[1]=1.0;
        arr[2]=1.0;    
    }
}

void prefeed(){
    
    for(i=0;i<9;i++){
        set_prefeed(lfillog[i],l[i]);
        set_prefeed(rfillog[i],r[i]);
        set_prefeed(ufillog[i],u[i]);
        set_prefeed(dfillog[i],d[i]);
        set_prefeed(ffillog[i],f[i]);
        set_prefeed(bfillog[i],b[i]);
        lfill[i]=lfillog[i];
        rfill[i]=rfillog[i];
        ufill[i]=ufillog[i];
        dfill[i]=dfillog[i];
        ffill[i]=ffillog[i];
        bfill[i]=bfillog[i];
    }
    
}

void check_fill(){
    
    for(i=0;i<9;i++){
        if(lfill[i]!=-1)
            allfill++;
        if(rfill[i]!=-1)
            allfill++;
        if(ffill[i]!=-1)
            allfill++;
        if(bfill[i]!=-1)
            allfill++;
        if(ufill[i]!=-1)
            allfill++;
        if(dfill[i]!=-1)
            allfill++;
    }
}

void keys2(unsigned char k,int x,int y){
	
	if(k=='S' || k=='s'){
        
        if(set==8)
            set=0;
        else
            set++;
        
        glutPostRedisplay();
    }
    
    else if(k=='T' || k=='t'){
     
        if(color_tog[0]==1.0&&color_tog[1]==0.0&&color_tog[2]==0.0){
            color_tog[0]=1.0;
            color_tog[1]=0.5;
            color_tog[2]=0.0;
            toggle=1;
        }
        else if(color_tog[0]==1.0&&color_tog[1]==0.5&&color_tog[2]==0.0){
            color_tog[0]=1.0;
            color_tog[1]=1.0;
            color_tog[2]=0.0;
            toggle=2;
        }
        else if(color_tog[0]==1.0&&color_tog[1]==1.0&&color_tog[2]==0.0){
            color_tog[0]=0.0;
            color_tog[1]=1.0;
            color_tog[2]=0.0;
            toggle=3;
        }
        else if(color_tog[0]==0.0&&color_tog[1]==1.0&&color_tog[2]==0.0){
            color_tog[0]=0.0;
            color_tog[1]=0.0;
            color_tog[2]=1.0;
            toggle=4;
        }
        else if(color_tog[0]==0.0&&color_tog[1]==0.0&&color_tog[2]==1.0){
            color_tog[0]=1.0;
            color_tog[1]=1.0;
            color_tog[2]=1.0;
            toggle=5;
        }
        else{
            color_tog[0]=1.0;
            color_tog[1]=0.0;
            color_tog[2]=0.0;
            toggle=0;
        }
        glutPostRedisplay();
        
    }
    
    else if(k=='L' || k=='l'){
             
        lfill[set]=toggle;
        lfillog[set]=toggle;
        glutPostRedisplay();
        l[set][0]=color[toggle][0];
        l[set][1]=color[toggle][1];
        l[set][2]=color[toggle][2];
    }
    
    else if(k=='R' || k=='r'){
             
        rfill[set]=toggle;
        rfillog[set]=toggle;
        glutPostRedisplay();
        r[set][0]=color[toggle][0];
        r[set][1]=color[toggle][1];
        r[set][2]=color[toggle][2];
    }
    
    else if(k=='U' || k=='u'){
             
        ufill[set]=toggle;
        ufillog[set]=toggle;
        glutPostRedisplay();
        u[set][0]=color[toggle][0];
        u[set][1]=color[toggle][1];
        u[set][2]=color[toggle][2];
    }
    
    else if(k=='D' || k=='d'){
             
        dfill[set]=toggle;
        dfillog[set]=toggle;
        glutPostRedisplay();
        d[set][0]=color[toggle][0];
        d[set][1]=color[toggle][1];
        d[set][2]=color[toggle][2];
    }
    
    else if(k=='F' || k=='f'){
             
        ffill[set]=toggle;
        ffillog[set]=toggle;
        glutPostRedisplay();
        f[set][0]=color[toggle][0];
        f[set][1]=color[toggle][1];
        f[set][2]=color[toggle][2];
    }
    
    else if(k=='B' || k=='b'){
             
        bfill[set]=toggle;
        bfillog[set]=toggle;
        glutPostRedisplay();
        b[set][0]=color[toggle][0];
        b[set][1]=color[toggle][1];
        b[set][2]=color[toggle][2];
    }
    
    else if(k=='M' || k=='m'){
        prefeed();
        allfill=54;
        glutPostRedisplay();
    }
    
    else if(k=='N' || k=='n'){
        
        check_fill();
        if(allfill>0&&allfill<54){
            fill_change=1;
            glutPostRedisplay();
        }
        else{
            glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
            glutInitWindowPosition(360,500);
            glutInitWindowSize(600,600);
            id4=glutCreateWindow("Rubik's Cube");
            glutDestroyWindow(id3);
            glutDisplayFunc(display4);
            glutReshapeFunc(myReshape);
            glutKeyboardFunc(keys4);
            glEnable(GL_DEPTH_TEST);
            glutMainLoop();
        }
    }
    
}

void keys1(unsigned char k,int x,int y){
	
	if(k=='W' || k=='w'){
        
        change=1;
        glutPostRedisplay();
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(1400,900);
        id3=glutCreateWindow("Receive the input");
        glutDisplayFunc(display3);
        glutKeyboardFunc(keys2);
        myinit3();
        glutMainLoop();
        
    }
    
}

void keys(unsigned char k,int x,int y){
	
    if(k=='E' || k=='e'){
        
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowSize(1400,900);
        id2=glutCreateWindow("Instructions");
        glutDisplayFunc(display2);
        glutKeyboardFunc(keys1);
        myinit2();
        glutMainLoop();
        
	}
}


int main(int argc,char **argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1400,900);
	glutInitWindowPosition(0,0);
	id1=glutCreateWindow("Rubik's Cube Simulation");
	glutDisplayFunc(display1);
	glutKeyboardFunc(keys);
	myinit1();
    
	glutMainLoop();	
    
}
