#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



int letter(char);
int digit(char);


char prog[100000], token[50];
char ch;

int TokenClass, p, m, n, sum, positionInStr, strNumber, positionNumber;
char *keyWordTab[9] = {
  "#include", "if", "else", "while", "for", "return", "stdio", "stdlib", "string"
};

char *dataTypeTab[5] = {
  "int", "char", "float", "double", "void"
};

int main(int argc, char const *argv[])
{
    p = 0;
    positionInStr = positionNumber = 0;
    strNumber = 1;
    

  FILE *fp = fopen("substr", "r");
    if (fp == NULL) {
      printf("Cannot open the input file.");
      exit(0);
    }


    do
    {
      ch = fgetc(fp);
      prog[p++] = ch;
    }while(ch != EOF);
    p = 0;
    do
    {   for (n = 0; n < 50; n++)
    {
      token[n] = NULL;
    }
    ch = prog[p++];
    positionInStr++;
    while(ch == ' '){
      ch = prog[p++];
      positionInStr++;
      TokenClass = 40;
      
      
    }
    if (ch == '\n'){
      strNumber++;
      positionInStr = 0;
      positionNumber = 0;
      TokenClass = 40;
      
    }
    if (ch == '\t'){
      
      positionInStr++;
      TokenClass = 40;
      
    }
    if (letter(ch))
    { 
      positionNumber = positionInStr ;
      
      m = 0;
      while(letter(ch) || digit(ch))
      {   
          token[m] = ch;
          m++;
          ch = prog[p++];
          positionInStr++;
        
      }
      
      token[m++] = '\0';
      p--;
      positionInStr--;
      TokenClass = 10;
      for (n = 0; n < 9; n++)
      {
          if (strcmp(token, keyWordTab[n]) == 0)
      {
          TokenClass = n + 1;
          break;
      }
      }
      for (n = 0; n < 5; n++)
      {
          if (strcmp(token, dataTypeTab[n]) == 0)
      {
          TokenClass = 47 + n ;
          break;
      }
      }
    }
    else if(digit(ch))
    { 
      positionNumber = positionInStr;
      sum = 0;
      while(digit(ch))
      {
          sum = sum * 10 + ch - '0';
          ch = prog[p++];
          positionInStr++;
      }
      
      p--;
      positionInStr--;
      TokenClass = 11;
    }
    else{
      
     positionNumber = positionInStr;
      
      switch(ch)
    {
      case'<':
          
          m = 0;
          token[m++] = ch;
          ch = prog[p++];
          positionInStr++;
          if (ch == '<')
          {
      TokenClass = 21;
      token[m++] = ch;
          }
          else if(ch == '=')
          {
      TokenClass = 22;
      token[m++] = ch;
          }
          else
          {
      TokenClass = 20;
      p--;
      positionInStr--;
          }
    break;

      case'>':
          
          m = 0;
          token[m++] = ch;
          ch = prog[p++];
          positionInStr++;
          if (ch == '=')
          {
      TokenClass = 24;
      token[m++] = ch;
          }
          else if(ch == '>')
          {
      TokenClass = 31;
      token[m++] = ch;
          }
          else
          {
      TokenClass = 23;
      p--;
      positionInStr--;
          }
          break;
      case'+':
       m = 0;
       token[m++] = ch;
       ch = prog[p++];
       positionInStr++;
       if(ch == '+'){
         TokenClass = 12;
         token[m++] = ch;
       }
       else{
         TokenClass = 13;
         p--;
         positionInStr--;
       }
        break;
      case'-':
       TokenClass = 14;
       m = 0;
       token[m++] = ch;
       ch = prog[p++];
       positionInStr++;
       if(ch == '-'){
         TokenClass = 19;
         token[m++] = ch;
       }
       else{
         TokenClass = 14;
         p--;
         positionInStr--;
       }
        break;
      case'*': TokenClass = 15;  token[0] = ch; break;
      case':': TokenClass = 17;  token[0] = ch; break;
      case';': TokenClass = 26;  token[0] = ch; break;
      case'(': TokenClass = 27;  token[0] = ch; break;
      case')': TokenClass = 28;  token[0] = ch; break;
      case'.': TokenClass = 32;  token[0] = ch; break;
      case',': TokenClass = 33;  token[0] = ch; break;
      case'{': TokenClass = 34;  token[0] = ch; break;
      case'}': TokenClass = 35;  token[0] = ch; break;
      case'%': TokenClass = 36;  token[0] = ch; break;
      case'[': TokenClass = 37;  token[0] = ch; break;
      case']': TokenClass = 38;  token[0] = ch; break;
      case'&':
       TokenClass = 41;
       m = 0;
       token[m++] = ch;
       ch = prog[p++];
       positionInStr++;
       if(ch == '&'){
         TokenClass = 46;
         token[m++] = ch;
       }
       else{
         TokenClass = 41;
         p--;
         positionInStr--;
       }
        break;
      case'|':
       TokenClass = 42;
       m = 0;
       token[m++] = ch;
       ch = prog[p++];
       positionInStr++;
       if(ch == '|'){
         TokenClass = 45;
         token[m++] = ch;
       }
       else{
         TokenClass = 42;
         p--;
         positionInStr--;
       }
        break;

      case'!':
       
       m = 0;
       token[m++] = ch;
       ch = prog[p++];
       positionInStr++;
       if(ch == '='){
         TokenClass = 44;
         token[m++] = ch;
       }
       else{
         TokenClass = 43;
         p--;
         positionInStr--;
       }
        break;
      case'/':
          TokenClass = 16;
          ch = prog[p++];
          if( ch == '/'){
            while(ch != '\n'){
              ch = prog[p++];
            }
            p--;
            TokenClass = 40;
          }
          else if(ch == '*'){
            TokenClass = 40;
            int t = p;
            int closed = 0;
            char chTest = ch;
            
            while(chTest != EOF){
              chTest = prog[t++];
              if(chTest == '*'){
                chTest = prog[t++];
                if(chTest == '/'){
                  closed = 1;
                }
              }

            }

            if(closed == 0){
              printf("Multi-line comment is not closed ");
              positionNumber = positionInStr;
              TokenClass = 52;

            }
            else if(closed == 1){
              while(prog[p] != '*' && prog[p+1] != '/'){
              if(prog[p] == '\n'){
                strNumber++;
                positionInStr = 0;
                positionNumber = 0;
              }
              p++;
            }
            p += 2;
            }
          }
          
          else{
          p--;
          }
          break;
      case'"': 
          TokenClass = 39;
          int t = p;
          int closed = 0;
          char chTest = ch;
          chTest = prog[t++];
          while(chTest != '\n'){
            if(chTest == '"'){
              closed = 1;
            }
              chTest = prog[t++];
          }

          if(closed == 0){
              printf("string litheral is not closed ");
              
          }
          else{
          m = 0;
          token[m++] = ch;
          ch = prog[p++];
          positionInStr++;
          while(ch != '"'){
          token[m++] = ch;
          ch = prog[p++];
          positionInStr++;
          }
          token[m++] = ch;
          }
          
           break;
      case'=':
          
          m = 0;
          token[m++] = ch;
          ch = prog[p++];
          positionInStr++;
          if (ch == '=')
          {
      TokenClass = 30;
       token[m++] = ch;
          }
          else
      {
          TokenClass = 29;
          p--;
          positionInStr--;
          }
           break;
      case'\n':
          
          TokenClass = 40;
          break;
      case'\0': TokenClass = 0;  token[0] = ch; break;
      
      default:
          TokenClass = -1;
          if(prog[p+1] == '\0'){
            TokenClass = 0;
          }

      }
    }
    
      switch(TokenClass)
          {
      case 1: printf("Loc=<%d:%d> directive %s\n", strNumber, positionNumber, token); break;
      case 2: printf("Loc=<%d:%d> keywordIf %s\n", strNumber, positionNumber, token); break;
      case 3: printf("Loc=<%d:%d> keywordElse %s\n", strNumber, positionNumber, token); break;
      case 4: printf("Loc=<%d:%d> cycleWhile %s\n", strNumber, positionNumber, token); break;
      case 5: printf("Loc=<%d:%d> cycleFor %s\n", strNumber, positionNumber, token); break;
      case 6: printf("Loc=<%d:%d> keywordReturn %s\n", strNumber, positionNumber, token); break;
      case 7: printf("Loc=<%d:%d> library %s\n", strNumber, positionNumber, token); break;
      case 8: printf("Loc=<%d:%d> library %s\n", strNumber, positionNumber, token); break;
      case 9: printf("Loc=<%d:%d> library %s\n", strNumber, positionNumber, token); break;
      case 10: printf("Loc=<%d:%d> id %s\n", strNumber, positionNumber, token); break;
      case 12: printf("Loc=<%d:%d> increment %s\n", strNumber, positionNumber, token); break;
      case 13: printf("Loc=<%d:%d> plus %s\n", strNumber, positionNumber, token); break;
      case 14: printf("Loc=<%d:%d> minus %s\n", strNumber, positionNumber, token); break;
      case 15: printf("Loc=<%d:%d> multiply %s\n", strNumber, positionNumber, token); break;
      case 16: printf("Loc=<%d:%d> divide %s\n", strNumber, positionNumber, token); break;
      case 19: printf("Loc=<%d:%d> decrement  %s\n", strNumber, positionNumber, token); break;
      case 20: printf("Loc=<%d:%d> less than %s\n", strNumber, positionNumber, token); break;
      case 21: printf("Loc=<%d:%d> bit_l_shift %s\n", strNumber, positionNumber, token); break;
      case 22: printf("Loc=<%d:%d> less_t_or_eq %s\n", strNumber, positionNumber, token); break;
      case 23: printf("Loc=<%d:%d> more than %s\n", strNumber, positionNumber, token); break;
      case 24: printf("Loc=<%d:%d> more_t_or_eq %s\n", strNumber, positionNumber, token); break;
      case 26: printf("Loc=<%d:%d> semi %s\n", strNumber, positionNumber, token); break;
      case 27: printf("Loc=<%d:%d> l_paren %s\n", strNumber, positionNumber, token); break;
      case 28: printf("Loc=<%d:%d> r_paren %s\n", strNumber, positionNumber, token); break;
      case 29: printf("Loc=<%d:%d> assignment %s\n", strNumber, positionNumber, token); break;
      case 30: printf("Loc=<%d:%d> comparison %s\n", strNumber, positionNumber, token); break;
      case 31: printf("Loc=<%d:%d> bit_r_shift %s\n", strNumber, positionNumber, token); break;
      case 32: printf("Loc=<%d:%d> point %s\n", strNumber, positionNumber, token); break;
      case 33: printf("Loc=<%d:%d> comma %s\n", strNumber, positionNumber, token); break;
      case 34: printf("Loc=<%d:%d> l_brace %s\n", strNumber, positionNumber, token); break;
      case 35: printf("Loc=<%d:%d> r_brace %s\n", strNumber, positionNumber, token); break;
      case 36: printf("Loc=<%d:%d> modulo %s\n", strNumber, positionNumber, token); break;
      case 37: printf("Loc=<%d:%d> l_sqparen %s\n", strNumber, positionNumber, token); break;
      case 38: printf("Loc=<%d:%d> r_sqparen %s\n", strNumber, positionNumber, token); break;
      case 39: printf("Loc=<%d:%d> string litheral %s\n", strNumber, positionNumber, token); break;
      case 41: printf("Loc=<%d:%d> bitwise_and %s\n", strNumber, positionNumber, token); break;
      case 42: printf("Loc=<%d:%d> bitwise_or %s\n", strNumber, positionNumber, token); break;
      case 43: printf("Loc=<%d:%d> logical negation %s\n", strNumber, positionNumber, token); break;
      case 44: printf("Loc=<%d:%d> not equal %s\n", strNumber, positionNumber, token); break;
      case 45: printf("Loc=<%d:%d> logical addition %s\n", strNumber, positionNumber, token); break;
      case 46: printf("Loc=<%d:%d> logical multiplication  %s\n", strNumber, positionNumber, token); break;
      case 47: printf("Loc=<%d:%d> int  %s\n", strNumber, positionNumber, token); break;
      case 48: printf("Loc=<%d:%d> char  %s\n", strNumber, positionNumber, token); break;
      case 49: printf("Loc=<%d:%d> float  %s\n", strNumber, positionNumber, token); break;
      case 50: printf("Loc=<%d:%d> double  %s\n", strNumber, positionNumber, token); break;
      case 51: printf("Loc=<%d:%d> void  %s\n", strNumber, positionNumber, token); break;
      case 52: printf("Loc=<%d:%d>   %s\n", strNumber, positionNumber, token); break;
      case 11: printf("Loc=<%d:%d> numeric_constant %d\n", strNumber, positionNumber, sum); break;
      case -1: printf("input error\n"); break;
      case 0:
        printf("end of file\n");
        break;
      case 40:
        break;
      default: printf("Loc=<%d:%d> %2d, %s\n", strNumber, positionNumber, TokenClass, token);
      
          }

    }while(TokenClass != 0);

    fclose(fp);

    return 0;
}





int letter(char cha)
{
    cha = tolower(cha);
    if(cha >= 'a' && cha <= 'z')
      return 1;
    else if(cha == '#')
      return 1;
    else
      return 0;
}

int digit(char cha)
{
    if(cha >= '0' && cha <= '9')
      return 1;
    else
      return 0;
}
