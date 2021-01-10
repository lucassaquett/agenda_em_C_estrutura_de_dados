#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<fcntl.h>

int reg;
int reg5;


struct identificacao{
               char nome   [20];
               char sobrenome [100];
               }identificacao;
                        
                      
          struct numtel {
            char ddd [4] ;
            char cel [9] ;          
            }numtel;
       
                  
                  
        struct endereco_residencial{
           char rua    [200];
           char num    [5];
           char complemento   [20];
           char bairro [50];
           char cidade [50];
           char estado [3];
           }endereco_residencial;
           
                       
         
         struct endereco_eletronico{
           char email  [200];
           char skype  [200];
               }endereco_eletronico;
                        
                      struct contato {
               struct identificacao identificacao;
               struct endereco_eletronico endereco_eletronico;
               struct endereco_residencial endereco_residencial;
               struct numtel numtel;
               }contato;                   



               

void todos(void){     
      FILE *file;
      file = fopen("agenda.txt","r");
      if(file == NULL){printf("\n\n\n==========BANCO DE DADOS CORROMPIDO OU INEXISTENTE===============");
      fclose(file);
      getch();
      return main();}
     else {fclose(file);
     file = fopen("agenda.txt","r+");}

       fclose(file);
       int i ;
       int reg2;
      file = fopen("registro.txt","r");
         if( file == NULL){printf("NAO EXISTE CONTATOS CADASTRADOS");}
         fscanf(file,"%i", &reg2);
        fclose(file);
      file = fopen("agenda.txt","r+");
printf("\n\n\n===FORAM ENCONTRADOS %i REGISTROS===\n\n",reg2);
                       for(i=0;i!=reg2;i+0){     
                        char compa[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
              fseek(file,i*sizeof(struct contato),SEEK_SET);
              fread(&contato,sizeof(struct contato),1,file);
                                              
                                                                     
              printf("\n\n===REGISTRO %i===\n\n\n",i+1);
              printf("NOME: %s\nSOBRENOME: %s\nRUA: %s\nNUMERO: %s\nCOMPLEMENTO: %s \nBAIRRO: %s \nCIDADE: %s \nESTADO: %s \nDDD: %s \nTELEFONE: %s \nEMAIL: %s \nSKYPE: %s\n\n", contato.identificacao.nome,contato.identificacao.sobrenome,
                                                         contato.endereco_residencial.rua,contato.endereco_residencial.num,
                                                         contato.endereco_residencial.complemento,contato.endereco_residencial.bairro,
                                                         contato.endereco_residencial.cidade, contato.endereco_residencial.estado,
                                                         contato.numtel.ddd,contato.numtel.cel,
                                                         contato.endereco_eletronico.email,contato.endereco_eletronico.skype); 
                            char pra; 
                             printf("(a)atualizar___\n");
                             printf("(p)proximo_____\n");
                             printf("(r)remover____\n\n");
                             printf("DIGITE UMA OPCAO: <");
                             fflush(stdin);
                             scanf("%c", &pra);
          
             //remover todos//
             
             if(pra == 'r'){
                              fclose(file);
                      int q;
     int w;
     for(q=0;q<20;q+0){
     contato.identificacao.nome[q]= '\0';
     q++;}
     for(w =0;w<20;w+0){
     contato.identificacao.sobrenome[w] = '\0';          
     w++;}        
                                       
                              
                              FILE *file;
     file = fopen("agenda.dat","rb+");
         if( file == NULL){file = fopen("agenda.dat","wb");
         fclose(file);
         file = fopen("agenda.dat","rb+");}
        
        fseek(file,i*sizeof(struct contato),SEEK_SET);
      
       fwrite(&contato,sizeof(struct contato),1,file);
       
     
     fclose(file); 
     file = fopen("agenda.dat","rb+");
     if ((fread(&contato,sizeof(struct contato),1,file)) != NULL){
                    
                    printf("\n\n");
                    printf("___________________CONTATO REMOVIDO__________________\n\n\n\n\n\n");             
                    fclose(file);    }
    
    else{
         printf("======================ERRO AO GRAVAR INFORMACOES==================");}
       fclose(file);
           getch();
         return main();
                            
                            
                            
                            }
             
             
             switch(pra){
                         case 'a':
                              fclose(file);
                               printf("\n\n\n========================ATUALIZAR CONTATO %i==========================\n\n",i+1);
                      char n;
                        
                         fflush(stdin);  
                        printf("NOME:    (MANTER=Manter   SPACO=Alterar  < ");   
                         scanf("%c", &n);
                         if(n ==' '){
                          printf("\n\nNOVO NOME:");
                          fflush(stdin);
                          gets(contato.identificacao.nome);}
                        printf("SOBRENOME: (MANTER=Manter   SPACO=Alterar  < ");
                        char s;
                        scanf("%c", &s);
                        
                        fflush(stdin); 
                         if(s == ' '){
                         printf("\n\nNOVO SOBRENOME: ");
                         fflush(stdin); 
                          gets(contato.identificacao.sobrenome);}
                          
              printf("DDD: (MANTER=Manter   SPACO=Alterar  < ");
              fflush(stdin);
              char d;
              scanf("%c", &d);
                 if(d == ' '){
                    fflush(stdin); 
                    printf("\n\nNOVO DDD: ");
                    gets(contato.numtel.ddd);}
                  printf("TELEFONE: (MANTER=Manter   SPACO=Alterar  < ");
                    fflush(stdin); 
                    char t;
                    scanf("%c", &t);
                  if(t == ' '){
                    fflush(stdin);
                    printf("\n\nNOVO TELEFONE: ");
                    gets(contato.numtel.cel);}
                    
              printf("RUA: (MANTER=Manter   SPACO=Alterar  < ");
                               fflush(stdin);
                               char r;
                               scanf("%c", &r);
                          if(r == ' '){
                               fflush(stdin); 
                               printf("\n\nNOVA RUA: ");
                               gets(contato.endereco_residencial.rua);}
                       printf("NUMERO: (MANTER=Manter   SPACO=Alterar  < ");
                               fflush(stdin);
                               fflush(stdin);
                               char num;
                               scanf("%c", &num);
                           if(num == ' '){
                                  fflush(stdin); 
                               printf("\n\nNOVO NUMERO: ");
                               gets(contato.endereco_residencial.num);}
                       printf("COMPLEMENTO: (MANTER=Manter  SPACO=Alterar  < ");
                              fflush(stdin);
                              char com;
                              scanf("%c", &com);
                          if(com == ' '){
                              fflush(stdin); 
                               printf("\n\nNOVO COMPLEMENTO: ");
                               gets(contato.endereco_residencial.complemento);}
                       printf("BAIRRO: (MANTER=Manter   SPACO=Alterar  < ");
                               fflush(stdin);
                               char bai;
                               scanf("%c", &bai);
                          if(bai == ' '){     
                               fflush(stdin); 
                              printf("\n\nNOVO BAIRRO: "); 
                               gets(contato.endereco_residencial.bairro);}
                       printf("CIDADE: (MANTER=Manter   SPACO=Alterar  < ");
                               fflush(stdin); 
                               char cid;
                               scanf("%c", &cid);
                         if(cid == ' '){
                               fflush(stdin);
                               printf("\n\nNOVA CIDADE: ");
                               gets(contato.endereco_residencial.cidade);}
                       printf("ESTADO: (MANTER=Manter   SPACO=Alterar  < ");
                               fflush(stdin);
                               char est;
                               scanf("%c", &est);
                        if(est == ' '){
                               fflush(stdin); 
                           printf("\n\nNOVO ESTADO: ");
                               gets(contato.endereco_residencial.estado);}
                               
               printf("EMAIL: (MANTER=Manter   SPACO=Alterar  < ");
                                fflush(stdin);
                                char ema;
                                scanf("%c", &ema);
                          if(ema == ' '){      
                                fflush(stdin); 
                                printf("\n\nNOVO EMAIL ");
                                gets(contato.endereco_eletronico.email);}
                          printf("SKYPE: (MANTER=Manter   SPACO=Alterar  < ");
                                fflush(stdin);
                               char sky;
                               scanf("%c", &sky);
                            if(sky == ' '){                                   
                                fflush(stdin); 
                                printf("\n\nNOVO SKYPE: ");
                                gets(contato.endereco_eletronico.skype);}              
     
     FILE *file;
     file = fopen("agenda.dat","rb+");
         if( file == NULL){file = fopen("agenda.dat","wb");
         fclose(file);
         file = fopen("agenda.dat","rb+");}
        
        fseek(file,i*sizeof(struct contato),SEEK_SET);
      
       fwrite(&contato,sizeof(struct contato),1,file);
       
     
     fclose(file); 
     file = fopen("agenda.dat","rb+");
     if ((fread(&contato,sizeof(struct contato),1,file)) != NULL){
                    
                    printf("\n\n");
                    printf("___________________CONTATO ATUALIZADO__________________\n\n\n\n\n\n");             
                    fclose(file);    }
    
    else{
         printf("======================ERRO AO GRAVAR INFORMACOES==================");}
       fclose(file);
           getch();
         return main();
                              
                         break;
                         
                         case 'p':
                              
                         break;
                         
                         case 'r':
                              
                               
                               
                        
                         break;     
                         
                         
                         }
                             i++;}
               
         return main();
}

void localizar(void){
      printf("============================LOCALIZAR ITEM============================\n\n\n");
      fflush(stdin);
      
      
       
       printf("(t) PARA MOSTRAR TODOS OS CONTATOS\n");
       printf("(L) PARA LOCALIZAR UM CONTATO\n\n");
       printf("OPCAO: <");
       char nomebusca[20];
       char l;
       fflush(stdin);
       gets(nomebusca);
       
          if(nomebusca[0] == 't'){     
                  todos();
                     }
          if (nomebusca[0] == 'T'){
                        todos();   
                           }        
              char busca[20];
              fflush(stdin);             
         printf("DIGITE UM NOME e SOBRENOME PARA LOCALIZAR:");  
              gets(busca);
         
         
                            FILE *file;
                            file = fopen("agenda.dat","rb");
                            if(file == NULL){printf("\n\n\n==========BANCO DE DADOS CORROMPIDO OU INEXISTENTE===============");}
                            fclose(file);
                    
                    int i;
                    int reg3;
                    int z;
      file = fopen("registro.dat","rb");
         if( file == NULL){printf("\n\n\nNAO EXISTE CONTATOS CADASTRADOS\n\n");
          getch();}
         fscanf(file,"%i", &reg3);
        fclose(file);
      file = fopen("agenda.dat","rb+");

                    for(i=0;i!=reg3;i+0){
                                    fseek(file,i*sizeof(struct contato),SEEK_SET);
                                    fread(&contato,sizeof(struct contato),1,file);
                                     if(strcmp(busca,contato.identificacao.nome) == 0){
                                                   
                                                   printf("\n\n===REGISTRO %i===\n\n\n",i+1);
                                                         printf("NOME: %s\nSOBRENOME: %s\nRUA: %s\nNUMERO: %s\nCOMPLEMENTO: %s \nBAIRRO: %s \nCIDADE: %s \nESTADO: %s \nDDD: %s \nTELEFONE: %s \nEMAIL: %s \nSKYPE: %s\n\n", contato.identificacao.nome,contato.identificacao.sobrenome,
                                                         contato.endereco_residencial.rua,contato.endereco_residencial.num,
                                                         contato.endereco_residencial.complemento,contato.endereco_residencial.bairro,
                                                         contato.endereco_residencial.cidade, contato.endereco_residencial.estado,
                                                         contato.numtel.ddd,contato.numtel.cel,
                                                         contato.endereco_eletronico.email,contato.endereco_eletronico.skype); 
                                 
                         char pra; 
                             printf("(a)atualizar___\n");
                             printf("(p)proximo_____\n");
                             printf("(r)remover____\n");
                             printf("(m)menu_____\n\n");
                             printf("DIGITE UMA OPCAO: <");
                             fflush(stdin);
                             scanf("%c", &pra);
                    
                    
                     if(pra == 'r'){
                              fclose(file);
                      int q;
     int w;
     for(q=0;q<20;q+0){
     contato.identificacao.nome[q]= '\0';
     q++;}
     for(w =0;w<20;w+0){
     contato.identificacao.sobrenome[w] = '\0';          
     w++;}        
                                       
                              
                              FILE *file;
     file = fopen("agenda.dat","rb+");
         if( file == NULL){file = fopen("agenda.dat","wb");
         fclose(file);
         file = fopen("agenda.dat","rb+");}
        
        fseek(file,i*sizeof(struct contato),SEEK_SET);
      
       fwrite(&contato,sizeof(struct contato),1,file);
       
     
     fclose(file); 
     file = fopen("agenda.dat","rb+");
     if ((fread(&contato,sizeof(struct contato),1,file)) != NULL){
                    
                    printf("\n\n");
                    printf("___________________CONTATO REMOVIDO__________________\n\n\n\n\n\n");             
                    fclose(file);    }
    
    else{
         printf("======================ERRO AO GRAVAR INFORMACOES==================");}
       fclose(file);
           getch();
         return main();
                            
                            
                            
                            }
            
             switch(pra){
                         case 'a':
                              fclose(file);
                               printf("\n\n\n========================ATUALIZAR CONTATO %i==========================\n\n",i+1);
                      char n;
                        
                         fflush(stdin);  
                        printf("NOME:    (MANTER=Manter   SPACO=Alterar  < ");   
                         scanf("%c", &n);
                         if(n ==' '){
                          printf("\n\nNOVO NOME:");
                          fflush(stdin);
                          gets(contato.identificacao.nome);}
                        printf("SOBRENOME: (MANTER=Manter   SPACO=Alterar  < ");
                        char s;
                        scanf("%c", &s);
                        
                        fflush(stdin); 
                         if(s == ' '){
                         printf("\n\nNOVO SOBRENOME: ");
                         fflush(stdin); 
                          gets(contato.identificacao.sobrenome);}
                          
              printf("DDD: (MANTER=Manter   SPACO=Alterar  < ");
              fflush(stdin);
              char d;
              scanf("%c", &d);
                 if(d == ' '){
                    fflush(stdin); 
                    printf("\n\nNOVO DDD: ");
                    gets(contato.numtel.ddd);}
                  printf("TELEFONE: (MANTER=Manter   SPACO=Alterar  < ");
                    fflush(stdin); 
                    char t;
                    scanf("%c", &t);
                  if(t == ' '){
                    fflush(stdin);
                    printf("\n\nNOVO TELEFONE: ");
                    gets(contato.numtel.cel);}
                    
              printf("RUA: (MANTER=Manter   SPACO=Alterar  < ");
                               fflush(stdin);
                               char r;
                               scanf("%c", &r);
                          if(r == ' '){
                               fflush(stdin); 
                               printf("\n\nNOVA RUA: ");
                               gets(contato.endereco_residencial.rua);}
                       printf("NUMERO: (MANTER=Manter   SPACO=Alterar  < ");
                               fflush(stdin);
                               fflush(stdin);
                               char num;
                               scanf("%c", &num);
                           if(num == ' '){
                                  fflush(stdin); 
                               printf("\n\nNOVO NUMERO: ");
                               gets(contato.endereco_residencial.num);}
                       printf("COMPLEMENTO: (MANTER=Manter  SPACO=Alterar  < ");
                              fflush(stdin);
                              char com;
                              scanf("%c", &com);
                          if(com == ' '){
                              fflush(stdin); 
                               printf("\n\nNOVO COMPLEMENTO: ");
                               gets(contato.endereco_residencial.complemento);}
                       printf("BAIRRO: (MANTER=Manter   SPACO=Alterar  < ");
                               fflush(stdin);
                               char bai;
                               scanf("%c", &bai);
                          if(bai == ' '){     
                               fflush(stdin); 
                              printf("\n\nNOVO BAIRRO: "); 
                               gets(contato.endereco_residencial.bairro);}
                       printf("CIDADE: (MANTER=Manter   SPACO=Alterar  < ");
                               fflush(stdin); 
                               char cid;
                               scanf("%c", &cid);
                         if(cid == ' '){
                               fflush(stdin);
                               printf("\n\nNOVA CIDADE: ");
                               gets(contato.endereco_residencial.cidade);}
                       printf("ESTADO: (MANTER=Manter   SPACO=Alterar  < ");
                               fflush(stdin);
                               char est;
                               scanf("%c", &est);
                        if(est == ' '){
                               fflush(stdin); 
                           printf("\n\nNOVO ESTADO: ");
                               gets(contato.endereco_residencial.estado);}
                               
               printf("EMAIL: (MANTER=Manter   SPACO=Alterar  < ");
                                fflush(stdin);
                                char ema;
                                scanf("%c", &ema);
                          if(ema == ' '){      
                                fflush(stdin); 
                                printf("\n\nNOVO EMAIL ");
                                gets(contato.endereco_eletronico.email);}
                          printf("SKYPE: (MANTER=Manter   SPACO=Alterar  < ");
                                fflush(stdin);
                               char sky;
                               scanf("%c", &sky);
                            if(sky == ' '){                                   
                                fflush(stdin); 
                                printf("\n\nNOVO SKYPE: ");
                                gets(contato.endereco_eletronico.skype);}
                               
                               
              FILE *file;
     file = fopen("agenda.dat","rb+");
         if( file == NULL){file = fopen("agenda.dat","wb");
         fclose(file);
         file = fopen("agenda.dat","rb+");}
        
        fseek(file,i*sizeof(struct contato),SEEK_SET);
      
       fwrite(&contato,sizeof(struct contato),1,file);
       
     
     fclose(file); 
     file = fopen("agenda.dat","rb+");
     if ((fread(&contato,sizeof(struct contato),1,file)) != NULL){
                    
                    printf("\n\n");
                    printf("___________________CONTATO ATUALIZADO__________________\n\n\n\n\n\n");             
                    fclose(file);    }
    
    else{
         printf("======================ERRO AO GRAVAR INFORMACOES==================");}
       fclose(file);
           getch();
         return main();
                               
                                break;
                     case 'm':
                          return main();
                      break;                                                    
                    
                     case'p':
                             printf("proximo");
                             break;
                     default:
                             getch();
                      break;
                      }                
                                                     
                                                }
                                              
                                              i++; 
                                         }
                            
              
              
             
       
       printf("\n\n===============================================================");
       getch();
       printf("\n\n\n\n");
       return main();
     }




void inserir(void){
                      printf("========================INSERIR CONTATO==========================\n\n");
                      
                         fflush(stdin);  
                        printf("NOME: ");   
                          gets(contato.identificacao.nome);
                        printf("SOBRENOME: "); 
                         fflush(stdin); 
                          gets(contato.identificacao.sobrenome);
                          
              printf("DDD: ");
                    fflush(stdin); 
                    gets(contato.numtel.ddd);
                  printf("TELEFONE: ");
                    fflush(stdin); 
                    gets(contato.numtel.cel);
                    
              printf("RUA: ");
                               fflush(stdin); 
                               gets(contato.endereco_residencial.rua);
                       printf("NUMERO: ");
                               fflush(stdin); 
                               gets(contato.endereco_residencial.num);
                       printf("COMPLEMENTO: ");
                              fflush(stdin); 
                               gets(contato.endereco_residencial.complemento);
                       printf("BAIRRO: ");
                               fflush(stdin); 
                               gets(contato.endereco_residencial.bairro);
                       printf("CIDADE: ");
                               fflush(stdin); 
                               gets(contato.endereco_residencial.cidade);
                       printf("ESTADO: ");
                               fflush(stdin); 
                               gets(contato.endereco_residencial.estado);
                               
               printf("EMAIL: ");
                                fflush(stdin); 
                                gets(contato.endereco_eletronico.email);
                          printf("SKYPE: ");
                                fflush(stdin); 
                                gets(contato.endereco_eletronico.skype); 
              
     
     FILE *file;
     file = fopen("agenda.dat","rb+");
         if( file == NULL){file = fopen("agenda.dat","wb");
         fclose(file);
         file = fopen("agenda.dat","rb+");}
        
        fseek(file,0,SEEK_END);
      
       fwrite(&contato,sizeof(struct contato),1,file);
       
       
     
     fclose(file); 
     
         file = fopen("registro.dat","rb");
         if( file == NULL){file = fopen("registro.dat","wb");
         fclose(file);
         file = fopen("registro.dat","wb");
         reg++;
         fprintf(file,"%i", reg);
            }
         else{fclose(file);
              file = fopen("registro.dat","rb");
              fscanf(file,"%i", &reg);
               reg++;
              fclose(file);
              file = fopen("registro.dat","wb");
              fprintf(file,"%i", reg);
              }
            fclose(file);
             file = fopen("agenda.dat","rb+");
     if ((fread(&contato,sizeof(struct contato),1,file)) != NULL){
                    
                    printf("\n\n");
                    printf("___________________CONTATO CADASTRADO__________________\n\n\n\n\n\n");                 }
    else{
         printf("======================ERRO AO GRAVAR INFORMACOES==================");}
       fclose(file);
           getch();
         return main();
     }
int main()
{
    
   printf("              (AGENDA AEDSII) LUCAS GONÇALVES SAQUETT\n\n\n\n\n");
   
   printf("=================MENU==================\n\n");  
   
   printf("SELECIONE SUA OPCAO:\n\n");
   printf("( I )inserir item\n( L )Localizar Item \n( S )Sair\n\nOPCAO: ( ");
   do{
   char apr;
   fflush(stdin);
   scanf("%c", &apr);
   printf("\n\n");  
                  
   
   
   switch(apr){
             case 'i':
                  inserir();
             break;
             case 'I':
                  inserir();
             break;
             case 'L':
                  localizar();
             break;
             
             case 's':
                  exit(0);
             break;
             
             case 'S':
                  exit(0);
             break;
             
             case 'l':
                  localizar();
             break;
             
             default:
                     printf("DIGITE UMA OPCAO VALIDA\n\n");
                     printf("( I )inserir item\n( L )Localizar item \n( S )Sair\n\nOPCAO: ( ");
             break;
             
                }
        }while("apr"!='s');
getch();
}
