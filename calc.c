#include <stdio.h> 
#include <string.h> 
#define N 80 
#define CHAR_DIG(c) (c - '0')
#define DIG_CHAR(d) (d + 48)
char a[N], b[N], res[N + 1]; 


void add(const char a[], const char b[], char res[]){
    int s1 = strlen(a);
    int s2 = strlen(b);
    int st;
    int hold;
    int m;
    int n;
    int s = 0;
    int q = 0;
    //decide which string is bigger
    if (s1 >= s2){
        st = s1;
        q = 1;
    }
    if (s2 > s1){
        st = s2;
        s = 1;
    }
    //prints result in res until smallest string runs out
    for(int u = st - 1; u >= abs(s2 - s1); u-- ){
        m = CHAR_DIG(a[u - abs(s2 - s1) * s]);
       
        n = CHAR_DIG(b[u - abs(s2 - s1) * q]);
        
        res[u] = DIG_CHAR((m + n + hold) % 10);
        hold = (m + n + hold) / 10;
       
    }
    
    //prints longest string into res accounting for holdover
    if(s1 > s2){
        for(int x = s1 - s2 - 1; x >= 0; x--){
            m = CHAR_DIG(a[x]);
            res[x] = DIG_CHAR((m + hold) % 10);
            hold = (m + hold) / 10;
            
        }
    }
    if(s1 < s2){
        for(int x = s2 - s1 - 1; x >= 0; x--){
            m = CHAR_DIG(b[x]);
            res[x] = DIG_CHAR((m + hold) % 10);
            hold = (m +  hold) / 10;
        }
    }
    //deals with hold in result
    if(hold != 0){
        
        for(int h = st; h > 0; h--){
            res[h] = res[h - 1];
        }
        res[0] = DIG_CHAR(hold);
    }  
}
void sub(const char a[], const char b[], char res[]){
    int s1 = strlen(a);
    int s2 = strlen(b);
    int st;
    int hold;
    int m;
    int intval;
    int n;
    int s;
    int q;
    int i;
    int abig = 0;
    int bbig = 0;
    //finds longer string
    if (s1 > s2){
        st = s1;
        abig = 1;
        q = 1;
    }
    if (s2 > s1){
        st = s2;
        s = 1;
        bbig = 1;
    }
    int f = 0;
    //deals with strings of same size to still find bigger number
    if(s1 == s2){
        st = s1;
        while((abig == 0 && bbig == 0) && f <= s1){
            
            if(CHAR_DIG(a[f]) > CHAR_DIG(b[f])){
                abig = 1;
                
            }
            if(CHAR_DIG(a[f]) < CHAR_DIG(b[f])){
                bbig = 1;
            
            }
            f += 1;
            
        }
    }
    int v = 0;

    //sets bigger string as m and smaller as n and 
    for(int u = st - 1; u >= abs(s2 - s1); u--){
        if (abig == 1 && bbig == 0){
            m = CHAR_DIG(a[u - abs(s2 - s1) * s]);
            n = CHAR_DIG(b[u - abs(s2 - s1) * q]);
        }
        if (abig == 0 && bbig == 1){
            m = CHAR_DIG(b[u - abs(s2 - s1) * q]);
            n = CHAR_DIG(a[u - abs(s2 - s1) * s]);
        }
        if (i == 1){
            m -= 1;
            i = 0;
            v = 1;
        }
        
        if (m < n){
            i = 1;
            
        }
        
        intval = m + (10 * i) - n;
        

        res[u] = DIG_CHAR(intval);
        
       
    }
    if (s1 > s2){
        for(int h = s1 - s2 - 1; h>= 0; h--){
            m = CHAR_DIG(a[h]);
            if (i == 1 && m != 0){
                
                m -= 1;
               
                i = 0;
            }
            if (m == 0 && i == 1){
                m = 9;

            }
            res[h] = DIG_CHAR(m);
        }

    }
    if (s2 > s1){
        for(int h = s2 - s1 - 1; h>= 0; h--){
            m = CHAR_DIG(b[h]);
            
            if (i == 1 && m != 0){
                
                m -= 1;
                
                i = 0;
            }
            if (m == 0 && i == 1){
                m = 9;

            }
            res[h] = DIG_CHAR(m);
        }

    }
    //replaces leading 0's with null chars
    int z = 0;
    if(res[0] == 48){
        while (res[z] == 48){
            res[z] = 8;
            z += 1;
        }
    }
    //places negative sign in front of res if 2nd number is bigger
    if(bbig == 1){
        
        for(int min = st; min > z; min--){
                res[min] = res[min - 1];
            }
            res[z] = '-';
    }
    
 
    
    //case for if num 1 and 2 are same
    if( abig == 0 && bbig == 0){
        res[0] = '0';
    }

}

int main(){
  char op;
  scanf("%s %s %c", a, b, &op);
  switch (op)
  {
  case '+':
    add(a, b, res);
    break;
  case '-':
    sub(a, b, res);
  }
  // print result
  char buf[20];
  int l1 = strlen(a), l2 = strlen(b), l3 = strlen(res);
  int m = l1 > l2 ? l1 : l2;
  m = m > l3 ? m : l3;
  sprintf(buf, "%% %ds\n%% %ds\n%% %ds\n", m, m, m);
  printf(buf, a, b, res);
}