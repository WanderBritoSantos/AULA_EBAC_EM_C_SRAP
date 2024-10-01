//========bibliotecas========== ==============================
 #include <stdio.h> // biblioteca de comunição com o usuario.
  #include <stdlib.h> //biblioteca de alocação em memoria.
  #include <locale.h> //biblioteca de alocação de texto por regiã
  #include <string.h> // responsavel das funcoes de string 
   //========funcoes ≠=============== 
    int tela_principal(){
    	   setlocale(LC_ALL,"portuguese");//funcao serve pra ultilizar simbolos especiais na saida da tela, como caracteres da lingua pontuguesa
    	 
  //========variaveis===============
 char opcao[10];
 int num_opcao;
system("cls");
printf("\t\t##### Cartório EBAC #####\n\n");
printf("\tDigite 1 para acessar com login e senha.\n\n\tAinda não tem cadastro?\n\n\tDigite 2 para se cadastrar.\n\n\tDigite 0 para sair.");     
 scanf("%s9",opcao);
  
for(int i=0; i <strlen(opcao);i++){
	if(!isdigit(opcao[i])){
		Erros_entradas(opcao);
		opcao[0]='\0';
		tela_principal();
		
	     }
	}
	num_opcao=atoi(opcao);
	
       switch (num_opcao)
       {    
           case 1:
                   tela_login();
           break;
           case 2: 
                tela_cadastrar();
       	break;
       	case 0:
       	sair();
       	// exit(0);
         break;
         default:
            Erros_entradas(opcao);
    		opcao[0]='\0';
   		tela_principal();
           break;
       }
   
    }//fim funcao
    
 int Erros_entradas(char opcao[10]){
 	    printf("\n\n\t%s Não é uma opção valida! \n\tDigite um número valido!\n\n", opcao);
 	      opcao[0]='\0';
           system("pause");  
 }
    
int tela_cadastrar(){
         system("cls");
         char LoginSenhas[]="senhas.txt";
         char login[40];
         char senha[40];
			    printf("\t.........Cartório da EBAC...........\n\n");
			    printf("\tSistema de cadastros de login e senha.\n\n");
          printf("\tRegistre seu login: ");
            scanf("%s", login);
         printf("\tRegistre sua senha: ");
            scanf("%s", senha);
            FILE *file;
            file=fopen(LoginSenhas,"r");
               if(file==NULL){
                        file=fopen(LoginSenhas, "w");
                        fclose(file);
                                  }
                        fclose(file);
                    fopen(LoginSenhas,"a");
                      fprintf(file,":%s,%s;", login,senha);
                    fclose(file);
                    login[0]='\0';
                    senha[0]='\0';
              printf("\tLogin registrado com sucesso\n");
              system("pause");
              system("cls");
              tela_principal();
                	}  
            
 int tela_login(){
       system("cls");
       char LoginSenhas[]="senhas.txt";
        int LS;
        char L_usuario[40];//recebe o login do usuario
        char S_usuario[40]; //recebe o a senha do usuario 
         char L_comp[40];// login sera carregado
         char S_comp[40];//senha sera carregada
            int i=0;
            char  soma_string[40];
            printf("\t.........Cartório da EBAC...........\n\n\n"); 
    	    printf("\tAcesse usando seu login e senha\n\n");
        printf("\tDigite seu login: ");
                   scanf("%s",L_usuario);
        printf("\tDigite sua senha: ");
                   scanf("%s",S_usuario);
         FILE*file;
         file=fopen(LoginSenhas,"r");
              if(file== NULL){
              	printf("Erro ao abrir arquivo!");
              	fclose(file);
              	return 1;
                    }
                    
          while((LS=fgetc(file))!= EOF){
          	
       	if((LS!=':')&&(LS!=',')&&(LS!= ';')){
            		soma_string[i]=LS;
             		i++; 
              		}else {
          		 //marca o final da string para iniciar o processo de comparacao 
          		 soma_string[i]='\0';
       }
          		 if(LS==','){
          		  	strcpy(L_comp,soma_string);
          		  	i=0;
          		 	soma_string[0]='\0';
           		 	
          		 }else if(LS==';'){
           			strcpy(S_comp,soma_string);
          		  	i=0;
           			soma_string[0]='\0';
                      
             	if(strcmp(L_usuario,L_comp)==0&&strcmp(S_usuario,S_comp)==0){
            
           	L_comp[0]='\0';
           	S_comp[0]='\0';
               fclose(file);
               system("pause");
               int laco = 1;
               tela_registro(laco,L_usuario);
              // abrir a nova tela de add alunos aqui
           			}else{
           			L_comp[0]='\0';
           			S_comp[0]='\0';
           		}
           		}
          }
         	 	if(feof(file)){
          		fclose(file);
          		printf("\n\n\tUsuario  %s ou senha NÃO cadastrado. \n\n",L_usuario);
          		L_usuario[0]='\0';
          		S_usuario[0]='\0';
          		system("pause");
          		tela_principal();
          		
          	} 
 }//fim da funcao de tela login
 
     tela_registro(int laco,char L_usuario[]){
     	 char opcao[10];
     	 int num_opcao;
     	 char  usuario[40];
     	           usuario[0]='\0';
     	           
     	 setlocale(LC_ALL,"portuguese");
     	 strcpy(usuario,L_usuario);
 
 if(!(strcmp(usuario, " ")==0)&&laco==1){
		 for(laco;laco==1;){
		       system("cls");
		
		     system("cls");
			    printf("\t.........Cartório da EBAC...........\n\n\n");
			    	 printf("\t\t\t\t\t\t%s online.\n\n\n", usuario);
			    
		        printf(".....Selecione uma opção desejada:\n\n");
		       printf("\t1 - Registrar aluno............\n");
		       printf("\t2 - Consultar aluno............\n");
		       printf("\t3 - Deletar aluno..............\n\n"); 
		       printf("\tdigite a opção desejada: 1, 2, 3 ou aperte 0 para sair\n\n");
		       printf("\tOpção: ");
		       
		       scanf("%s",opcao);
		        
for(int i=0; i <strlen(opcao);i++){
	if(!isdigit(opcao[i])){
		Erros_entradas(opcao);
	}
	     }
	         num_opcao=atoi(opcao);
         system("cls");
		    
		    switch(num_opcao)
		    {
		       case 1:
		    	     add_alunos();
		        break;
		       case 2:
		           selecionar_aluno();
		       break;   
		       case 3:
		           deletar_aluno();
		       break;
		       case 0:	
		       sair();
		        break;
		       default:
		       
		    	   break;
		  }
		 }//fim do laço for
     }
		 
     }
 
 int add_alunos(){
 	        setlocale(LC_ALL,"portuguese");
 	             
 	        char arquivo[40];
 	        char cpf[11];
 	        char nome[40];
 	        char sobre_nome[40];
 	        char cargo[40]; 
 	        printf("\tOpção 1 escolhida.\n\t1 - Registrar alunos............\n");
                      
 	        printf("\tdigite o cpf:");
 	        scanf("%s",cpf);
 	        
 	        strcpy(arquivo,cpf);
 	        
 	        FILE *file;
 	        
 	        file= fopen(arquivo, "w");
 	        
 	        fprintf(file,cpf);
 	        
 	        fclose(file);
 	        
 	        printf("\tDigite o nome: ");
 	        scanf("  %s",nome);
 	        
 	        file=fopen(arquivo,"a");
 	        fprintf(file, nome);
 	        fclose(file);
 	        
 	        file=fopen(arquivo,"a");
 	        fprintf(file,",  ");
 	        fclose(file);
 	        
 	        printf("\tDigite o sobrenome: ");
 	        scanf("%s",sobre_nome);
 	        
 	        file=fopen(arquivo,"a");
 	        fprintf(file,sobre_nome);
 	        fclose(file);
 	        
 	        file=fopen(arquivo,"a");
 	        fprintf(file,",  ");
 	        fclose(file);
 	        
 	         printf("\tDigite o cargo:");
 	        scanf(" %s",cargo);
 	        
 	        file=fopen(arquivo,"a");
 	        fprintf(file,cargo);
 	        fclose(file);
	       
 	        file=fopen(arquivo,"a");
 	        fprintf(file,".");
 	        fclose(file); 	        
 	        system ("pause");	  	
 }       
 int selecionar_aluno(){	
 		    setlocale(LC_ALL,"portuguese");	    
 	        char cpf[40];
 	        char conteudo[200];      
 	       printf("\topção 2 escolhida.\n\t1 - Consulta alunos............\n");             
 	        printf("\tDigite o cpf:");
 	        scanf("%s",cpf);        
 	        FILE*file;   
 	        file= fopen(cpf, "r");  
 	        if(file == NULL){
 	        	printf("Não foi possivel abrir o aquivo,  cpf não localizado! \n");
 	        	system ("pause");
 	        	return 0;
 	        }
 	        	while (fgets(conteudo , 200, file) != NULL){
 	        		printf("Essas sao as informações do aluno! \n CPF:");
 	        		printf("%s \n\n",conteudo);
 	        	
               }
               system("pause");      
 }
 int deletar_aluno(){
 	        char cpf[40];      
 	      printf("\tDigite o cpf para ser excluido.");
 	        scanf("%s",cpf);
 	        remove(cpf);   
 	       FILE*file;
	        file =fopen(cpf,"r");        
       if(file == NULL){
    	printf( "Usuario não se emcontra no sistema.");
 	      	system("pause");
 	      } 	        
 }
 sair(){
 	    	system("cls");
                           printf("\n\n\n\n\t\t\tSitema finalizado!\n\n");
		                system("pause");
              exit(0);
 }
  int main(){   
        tela_principal();
    return 0;
}